/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_texture_load.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjalloul <kjalloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 18:27:28 by kjalloul          #+#    #+#             */
/*   Updated: 2018/05/10 19:24:49 by kjalloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_color		ft_get_sphere_texture(t_prim *prim)
{
	double tu;
	double tv;
	double x;
	double y;
	double scale;
	t_color color;

	scale = 1;
	tu = asin(prim->normal.x) / M_PI + 0.5;
	tv = asin(prim->normal.y) / M_PI + 0.5;
	x = prim->textur.width * tu * 10;
	y = prim->textur.height * tv * 10;
	if (x >= prim->textur.width)
	{
		scale = x / prim->textur.width;
		x = x - (prim->textur.width * (int)scale);
	}
	if (y >= prim->textur.height)
	{
		scale = y / prim->textur.height;
		y = y - (prim->textur.height * (int)scale);
	}
	color = ft_get_texture_color(&(prim->textur), x, y);
	return (color);
}
