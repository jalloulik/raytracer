/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_options.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjalloul <kjalloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 11:20:59 by kjalloul          #+#    #+#             */
/*   Updated: 2018/06/21 16:44:04 by kjalloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	ft_initialise_checkers(t_prim *last)
{
	last->checkers.valid = TRUE;
	last->checkers.xscale = 1;
	last->checkers.yscale = 1;
	last->checkers.xmove = 0;
	last->checkers.ymove = 0;
	last->checkers.width = PROCED_WIDTH;
	last->checkers.height = PROCED_HEIGHT;
}

void	ft_create_cut(t_prim *last, t_node *node, char *type, char *num)
{
	char *pos;
	char *axis;

	pos = ft_strjoin("/cut/pos", num);
	axis = ft_strjoin("/cut/axis", num);
	pos = ft_get_content_mix_path(node, type, pos);
	axis = ft_get_content_mix_path(node, type, axis);
	if (pos && axis)
	{
		last->cut = ft_add_lst_cut(last->cut);
		ft_set_3dpt_from_string(&(last->cut->pos), pos);
		ft_set_3dpt_from_string(&(last->cut->dir), axis);
		ft_normalize_vector(&(last->cut->dir));
	}
}

void	ft_cut_parsing(t_prim *last, t_node *node, char *type)
{
	char *pos;
	char *axis;

	pos = NULL;
	axis = NULL;
	ft_create_cut(last, node, type, "1");
	ft_create_cut(last, node, type, "2");
	ft_create_cut(last, node, type, "3");
	ft_create_cut(last, node, type, "4");
	ft_create_cut(last, node, type, "5");
	ft_create_cut(last, node, type, "6");
	init_cut(last->cut, last);
}

void	ft_check_checkers(t_prim *last, t_node *node, char *type)
{
	char *content;

	content = ft_get_content_mix_path(node, type, "/checkers/status");
	if (ft_strequ(content, "true") == 1)
	{
		ft_initialise_checkers(last);
		content = ft_get_content_mix_path(node, type, "/checkers/scale/x");
		if (content)
			last->checkers.xscale = (double)ft_atoi(content);
		content = ft_get_content_mix_path(node, type, "/checkers/scale/y");
		if (content)
			last->checkers.yscale = (double)ft_atoi(content);
		content = ft_get_content_mix_path(node, type, "/checkers/mov/x");
		if (content)
			if (ft_atoi(content) < 0 || ft_atoi(content) > 100)
				last->checkers.xmove = (double)ft_atoi(content) / 100;
		content = ft_get_content_mix_path(node, type, "/checkers/mov/y");
		if (content)
			if (ft_atoi(content) < 0 || ft_atoi(content) > 100)
				last->checkers.ymove = (double)ft_atoi(content) / 100;
	}
}

void	ft_count_options(t_prim *last, t_node *node, char *type)
{
	ft_check_reflection(last, node, type);
	ft_check_refraction(last, node, type);
	ft_check_texture(last, node, type);
	ft_check_ntexture(last, node, type);
	ft_check_sin(last, node, type);
	ft_check_checkers(last, node, type);
	if (last->textur.valid == TRUE && last->checkers.valid == TRUE)
		ft_error("Can't have both checkers and color texture on");
}
