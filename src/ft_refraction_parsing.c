/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_refraction_parsing.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjalloul <kjalloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 18:08:11 by kjalloul          #+#    #+#             */
/*   Updated: 2018/06/20 18:12:29 by kjalloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void	ft_check_material(char *content, t_prim *last)
{
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
}

void		ft_check_refraction(t_prim *last, t_node *node, char *type)
{
	char *content;

	content = ft_get_content_mix_path(node, type, "/refract/status");
	if (ft_strequ(content, "true") != 1)
		return ;
	content = ft_get_content_mix_path(node, type, "/refract/material");
	ft_check_material(content, last);
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

void		ft_check_reflection(t_prim *last, t_node *node, char *type)
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
