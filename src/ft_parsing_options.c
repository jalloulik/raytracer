/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_options.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjalloul <kjalloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 11:20:59 by kjalloul          #+#    #+#             */
/*   Updated: 2018/06/19 11:44:22 by kjalloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	ft_check_refraction(t_prim *last, t_node *node, char *type)
{
	char *content;

	content = ft_get_content_mix_path(node, type, "/refract/status");
	if (ft_strequ(content, "true") != 1)
		return ;
	content = ft_get_content_mix_path(node, type, "/refract/material");
	if (ft_strequ(content, "DIAMOND") == 1)
		last->refraction_index = DIAMOND;
	else if (ft_strequ(content, "VACUUM") == 1)
		last->refraction_index = VACUUM;
	else if (ft_strequ(content, "AIR") == 1)
		last->refraction_index = AIR;
	else if (ft_strequ(content, "ICE") == 1)
		last->refraction_index = ICE;
	else if (ft_strequ(content, "WATER") == 1)
		last->refraction_index = WATER;
	else if (ft_strequ(content, "PLEXIGLAS") == 1)
		last->refraction_index = PLEXIGLAS;
	else if (ft_strequ(content, "DENSEFLINTGLASS") == 1)
		last->refraction_index = DENSEFLINTGLASS;
	else
		ft_error("Material not supported");
	last->refractive = 1;
	last->refract_ratio = 1;
	content = ft_get_content_mix_path(node, type, "/refract/ratio");
	if (content == NULL)
		return ;
	if (ft_atoi(content) <= 100 && ft_atoi(content) > 0)
		last->refract_ratio = (double)ft_atoi(content) / 100.0;
	else
		ft_error("Refraction percentage needs to be 1-100 range");
}

void	ft_check_reflection(t_prim *last, t_node *node, char *type)
{
	char *content;

	content = ft_get_content_mix_path(node, type, "/reflect/status");
	if (ft_strequ(content, "true") != 1)
		return ;
	content = ft_get_content_mix_path(node, type, "/reflect/ratio");
	last->reflective = 1;
	last->reflec_ratio = 1;
	if (content == NULL)
		return ;
	if (ft_atoi(content) <= 100 && ft_atoi(content) > 0)
		last->reflec_ratio = (double)ft_atoi(content) / 100.0;
	else
		ft_error("Reflection percentage needs to be 1-100 range");
}

void	ft_check_sin(t_prim *last, t_node *node, char *type)
{
	char *content;

	content = ft_get_content_mix_path(node, type, "/sinx/a");
	if (content)
	{
		if (ft_atoi(content) <= 0)
			ft_error("Value cannot be smaller or equal to zero");
		last->sin.x = ft_atoi(content);
		content = ft_get_content_mix_path(node, type, "/sinx/b");
		if (ft_atoi(content) <= 0)
			ft_error("Sin div cannot be smaller or equal to zero");
		last->sin.x_div = ft_atoi(content);
		last->sin.status = TRUE;
		last->sin.xstatus = TRUE;
	}
	content = ft_get_content_mix_path(node, type, "/siny/a");
	if (content)
	{
		if (ft_atoi(content) <= 0)
			ft_error("Value cannot be smaller or equal to zero");
		last->sin.y = ft_atoi(content);
		content = ft_get_content_mix_path(node, type, "/siny/b");
		if (ft_atoi(content) <= 0)
			ft_error("Sin div cannot be smaller or equal to zero");
		last->sin.y_div = ft_atoi(content);
		last->sin.status = TRUE;
		last->sin.ystatus = TRUE;
	}
	content = ft_get_content_mix_path(node, type, "/sinz/a");
	if (content)
	{
		if (ft_atoi(content) <= 0)
			ft_error("Value cannot be smaller or equal to zero");
		last->sin.z = ft_atoi(content);
		content = ft_get_content_mix_path(node, type, "/sinz/b");
		if (ft_atoi(content) <= 0)
			ft_error("Sin div cannot be smaller or equal to zero");
		last->sin.z_div = ft_atoi(content);
		last->sin.status = TRUE;
		last->sin.zstatus = TRUE;
	}
}

void	ft_initialise_texture(t_texture *texture)
{
	texture->xscale = 1;
	texture->yscale = 1;
	texture->xmove = 0;
	texture->ymove = 0;
	texture->valid = TRUE;
}

void	ft_check_ntexture(t_prim *last, t_node *node, char *type)
{
	char	*filename;
	t_texture *texture;
	char *content;

	content = NULL;
	content = ft_get_content_mix_path(node, type, "/normal/file");
	texture = &(last->textur_n);
	if (content)
	{
		filename = ft_strjoin("assets/", content);
		ft_initialise_texture(texture);
		ft_stb_load_textur(texture, filename);
		free(filename);
	}
	else
		return ;
	content = ft_get_content_mix_path(node, type, "/normal/scale/x");
	if (content)
		texture->xscale = (double)ft_atoi(content);
	content = ft_get_content_mix_path(node, type, "/normal/scale/y");
	if (content)
		texture->yscale = (double)ft_atoi(content);
	content = ft_get_content_mix_path(node, type, "/normal/mov/x");
	if (content)
		if (ft_atoi(content) < 0 || ft_atoi(content) > 100)
			texture->xmove = (double)ft_atoi(content) / 100;
	content = ft_get_content_mix_path(node, type, "/normal/mov/y");
	if (content)
		if (ft_atoi(content) < 0 || ft_atoi(content) > 100)
			texture->ymove = (double)ft_atoi(content) / 100;
}


void	ft_check_texture(t_prim *last, t_node *node, char *type)
{
	char	*filename;
	t_texture *texture;
	char *content;

	content = ft_get_content_mix_path(node, type, "/texture/file");
	texture = &(last->textur);
	if (content)
	{
		filename = ft_strjoin("assets/", content);
		ft_initialise_texture(texture);
		ft_stb_load_textur(texture, filename);
		free(filename);
	}
	else
		return ;
	content = ft_get_content_mix_path(node, type, "/texture/scale/x");
	if (content)
		texture->xscale = (double)ft_atoi(content);
	content = ft_get_content_mix_path(node, type, "/texture/scale/y");
	if (content)
		texture->yscale = (double)ft_atoi(content);
	content = ft_get_content_mix_path(node, type, "/texture/mov/x");
	if (content)
		if (ft_atoi(content) < 0 || ft_atoi(content) > 100)
			texture->xmove = (double)ft_atoi(content) / 100;
	content = ft_get_content_mix_path(node, type, "/texture/mov/y");
	if (content)
		if (ft_atoi(content) < 0 || ft_atoi(content) > 100)
			texture->ymove = (double)ft_atoi(content) / 100;
}

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
				last->checkers.xmove = (double)ft_atoi(content) / 100 ;
		content = ft_get_content_mix_path(node, type, "/checkers/mov/y");
		if (content)
			if (ft_atoi(content) < 0 || ft_atoi(content) > 100)
				last->checkers.ymove = (double)ft_atoi(content) / 100 ;
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
