/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_options.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjalloul <kjalloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 11:20:59 by kjalloul          #+#    #+#             */
/*   Updated: 2018/06/20 18:09:08 by kjalloul         ###   ########.fr       */
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
