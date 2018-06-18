/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjalloul <kjalloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 17:30:46 by kjalloul          #+#    #+#             */
/*   Updated: 2018/06/15 17:36:30 by kjalloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_color		ft_get_checkers_color(double x, double y, t_texture *textur)
{
	t_color color;

	if (x < (double)textur->width / 2 && y < (double)textur->height / 2)
		ft_set_color(&color, 20, 20, 20);
	else if (x < (double)textur->width / 2 && y >= (double)textur->height / 2)
		ft_set_color(&color, 255, 255, 255);
	else if (x >= (double)textur->width / 2 && y >= (double)textur->height / 2)
		ft_set_color(&color, 20, 20, 20);
	else
		ft_set_color(&color, 255, 255, 255);
	return (color);
}

t_color		ft_get_prim_texture_checker(t_prim *prim)
{
	t_3dpt	coord;
	t_color	color;

	ft_get_texture_prim_coord(prim, &coord, &(prim->checkers));
	color = ft_get_checkers_color(coord.x, coord.y, &(prim->checkers));
	return (color);
}
