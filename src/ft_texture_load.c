/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_texture_load.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjalloul <kjalloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 18:27:28 by kjalloul          #+#    #+#             */
/*   Updated: 2018/05/11 16:18:41 by kjalloul         ###   ########.fr       */
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
	ft_vec_quater_rot(&local_normal, &(prim->textur_normal), &(prim->g_to_l_rot));
	// ft_vec_quater_rot(&local_normal, &(prim->normal), &(prim->g_to_l_rot));
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

void	ft_get_sphere_texture_normal(t_prim *prim)
{
	double tu;
	double tv;
	double x;
	double y;
	double scale;
	t_3dpt local_normal;

	scale = 1;
	ft_vec_quater_rot(&local_normal, &(prim->textur_normal), &(prim->g_to_l_rot));
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
	ft_get_texture_normal(&(prim->normal), &(prim->textur_n), x, y);
	ft_normalize_vector(&(prim->normal));

	t_3dpt local_normal2;
	t_quater textur_normal_g_l;
	t_3dpt textur_test;

	ft_set_3dpt(&textur_test, 0, 0, 1);
	// ft_find_quaters_between(&textur_normal_g_l, &(prim->textur_normal), &textur_test);
	ft_find_quaters_between(&textur_normal_g_l, &textur_test, &(prim->textur_normal));
	ft_vec_quater_rot(&local_normal2, &(prim->normal), &(textur_normal_g_l));
	ft_set_3dpt(&(prim->normal), local_normal2.x, local_normal2.y, local_normal2.z);
	ft_normalize_vector(&(prim->normal));
}
