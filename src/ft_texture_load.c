/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_texture_load.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjalloul <kjalloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 18:27:28 by kjalloul          #+#    #+#             */
/*   Updated: 2018/05/11 12:05:29 by kjalloul         ###   ########.fr       */
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
	t_3dpt local_normal;

	scale = 1;
	ft_vec_quater_rot(&local_normal, &(prim->normal), &(prim->g_to_l_rot));
	ft_normalize_vector(&local_normal);
	tu = (asin(local_normal.x) / M_PI + 0.5) + prim->textur.xmove;
	tv = (asin(local_normal.y) / M_PI + 0.5) + prim->textur.ymove;
	if (tu > 1)
		tu = tu - 1;
	if (tv > 1)
		tv = tv - 1;
	x = prim->textur.width * tu * prim->textur.xscale;
	y = prim->textur.height * tv * prim->textur.yscale;
	if (x >= prim->textur.width && prim->textur.width > 0)
	{
		scale = x / prim->textur.width;
		x = x - (prim->textur.width * (int)scale);
	}
	if (y >= prim->textur.height && prim->textur.height > 0)
	{
		scale = y / prim->textur.height;
		y = y - (prim->textur.height * (int)scale);
	}
	color = ft_get_texture_color(&(prim->textur), x, y);
	return (color);
}
