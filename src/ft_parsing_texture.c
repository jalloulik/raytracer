/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_texture.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjalloul <kjalloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 17:45:10 by kjalloul          #+#    #+#             */
/*   Updated: 2018/06/21 16:41:23 by kjalloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		ft_initialise_texture(t_texture *texture)
{
	texture->xscale = 1;
	texture->yscale = 1;
	texture->xmove = 0;
	texture->ymove = 0;
	texture->valid = TRUE;
	// ft_putendl("Texture");
}

static void	ft_load_textur(t_texture *texture, char *content)
{
	char *filename;

	filename = ft_strjoin("assets/", content);
	ft_initialise_texture(texture);
	ft_stb_load_textur(texture, filename);
	free(filename);
}

void		ft_check_ntexture(t_prim *last, t_node *node, char *type)
{
	t_texture	*texture;
	char		*content;

	content = NULL;
	content = ft_get_content_mix_path(node, type, "/normal/status");
	if (ft_strequ(content, "true") == 0)
		return ;
	content = ft_get_content_mix_path(node, type, "/normal/file");
	texture = &(last->textur_n);
	if (content)
		ft_load_textur(texture, content);
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

void		ft_check_texture(t_prim *last, t_node *node, char *type)
{
	t_texture	*texture;
	char		*content;

	texture = &(last->textur);
	content = NULL;
	content = ft_get_content_mix_path(node, type, "/texture/status");
	if (ft_strequ(content, "true") == 0)
		return ;
	content = ft_get_content_mix_path(node, type, "/texture/file");
	if (content)
		ft_load_textur(texture, content);
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
