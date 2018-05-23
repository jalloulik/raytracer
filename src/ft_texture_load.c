/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_texture_load.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjalloul <kjalloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 18:27:28 by kjalloul          #+#    #+#             */
/*   Updated: 2018/05/23 05:17:40 by kjalloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		ft_get_textur_sphere(t_prim *prim, t_3dpt *coord)
{
	double tu;
	double tv;
	double scale;
	t_3dpt local_normal;

	scale = 1;
	ft_vec_quater_rot(&local_normal, &(prim->original_normal), &(prim->g_to_l_rot));
	ft_normalize_vector(&local_normal);
	tu = (asin(local_normal.x) / M_PI + 0.5) + prim->textur.xmove;
	tv = (asin(local_normal.y) / M_PI + 0.5) + prim->textur.ymove;
	if (tu > 1)
		tu = tu - 1;
	if (tv > 1)
		tv = tv - 1;
	coord->x = prim->textur.width * tu * prim->textur.xscale;
	coord->y = prim->textur.height * tv * prim->textur.yscale;
	if (coord->x >= prim->textur.width && prim->textur.width > 0)
	{
		scale = coord->x / prim->textur.width;
		coord->x = coord->x - (prim->textur.width * (int)scale);
	}
	if (coord->y >= prim->textur.height && prim->textur.height > 0)
	{
		scale = coord->y / prim->textur.height;
		coord->y = coord->y - (prim->textur.height * (int)scale);
	}
}

void		ft_get_textur_cyl(t_prim *prim, t_3dpt *coord)
{
	double tu;
	double tv;
	double scale;
	t_3dpt local_normal;

	scale = 1;
	ft_vec_quater_rot(&local_normal, &(prim->cyl.o_to_p), &(prim->g_to_l_rot));
	ft_normalize_vector(&local_normal);
	tu = (atan2(local_normal.x, local_normal.z) / (2 * M_PI) + 0.5) + prim->textur.xmove;
	tv = (local_normal.y * 0.5 + 0.5) + prim->textur.ymove;
	// tu = (asin(local_normal.x) / M_PI + 0.5) + prim->textur.xmove;
	// tv = (asin(local_normal.y) / M_PI + 0.5) + prim->textur.ymove;
	if (tu > 1)
		tu = tu - 1;
	if (tv > 1)
		tv = tv - 1;
	coord->x = prim->textur.width * tu * prim->textur.xscale;
	coord->y = prim->textur.height * tv * prim->textur.yscale;
	if (coord->x >= prim->textur.width && prim->textur.width > 0)
	{
		scale = coord->x / prim->textur.width;
		coord->x = coord->x - (prim->textur.width * (int)scale);
	}
	if (coord->y >= prim->textur.height && prim->textur.height > 0)
	{
		scale = coord->y / prim->textur.height;
		coord->y = coord->y - (prim->textur.height * (int)scale);
	}
}

void		ft_get_textur_plane(t_prim *prim, t_3dpt *coord)
{
	double tu;
	double tv;
	double scale;
	t_3dpt local_p;

	scale = 1;
	// ft_vec_quater_rot(&local_p, &(prim->cyl.o_to_p), &(prim->g_to_l_rot));
	ft_swap_g_to_l(&local_p, &(prim->p), &(prim->g_to_l_move), &(prim->g_to_l_rot));
	tu = local_p.x / 10;
	tv = local_p.y / 10;
	while (tu < 0)
		tu = tu + 1;
	while (tv < 0)
		tv = tv + 1;
	// tu = (atan2(local_normal.x, local_normal.z) / (2 * M_PI) + 0.5) + prim->textur.xmove;
	// tv = (local_normal.y * 0.5 + 0.5) + prim->textur.ymove;
	// tu = (asin(local_normal.x) / M_PI + 0.5) + prim->textur.xmove;
	// tv = (asin(local_normal.y) / M_PI + 0.5) + prim->textur.ymove;
	// if (tu > 1)
	// 	tu = tu - 1;
	// if (tv > 1)
	// 	tv = tv - 1;
	coord->x = prim->textur.width * tu * prim->textur.xscale;
	coord->y = prim->textur.height * tv * prim->textur.yscale;
	if (coord->x >= prim->textur.width && prim->textur.width > 0)
	{
		scale = coord->x / prim->textur.width;
		coord->x = coord->x - (prim->textur.width * (int)scale);
	}
	if (coord->y >= prim->textur.height && prim->textur.height > 0)
	{
		scale = coord->y / prim->textur.height;
		coord->y = coord->y - (prim->textur.height * (int)scale);
	}
}

t_color		ft_get_sphere_texture(t_prim *prim)
{
	t_3dpt coord;
	t_color color;

	if (prim->type == SPHERE)
		ft_get_textur_sphere(prim, &coord);
	else if (prim->type == CYLINDER)
		ft_get_textur_cyl(prim, &coord);
	else if (prim->type == PLANE)
		ft_get_textur_plane(prim, &coord);
	color = ft_get_texture_color(&(prim->textur), coord.x, coord.y);
	return (color);
}

void	ft_convert_normal_map(t_3dpt *result, t_3dpt *source)
{
	result->x = source->x / 128 - 1;
	result->y = source->y / 128 - 1;
	result->z = source->z / 255;
}

void	ft_get_texture_prim_normal(t_prim *prim)
{
	t_3dpt coord;
	t_3dpt	text_normal;
	t_3dpt textur_test;
	t_3dpt normal_bent;

	if (prim->type == SPHERE)
		ft_get_textur_sphere(prim, &coord);
	else if (prim->type == CYLINDER)
		ft_get_textur_cyl(prim, &coord);
	else if (prim->type == PLANE)
		ft_get_textur_plane(prim, &coord);
	else
		return;
	ft_get_texture_normal(&(text_normal), &(prim->textur_n), coord.x, coord.y);
	ft_convert_normal_map(&(text_normal), &(text_normal));
	ft_normalize_vector(&(text_normal));

	ft_set_3dpt(&textur_test, 0, 0, 1);

	t_quater origin_to_textur;
	t_quater textur_to_origin;

	ft_find_quaters_between(&origin_to_textur, &(prim->original_normal), &textur_test);
	ft_find_quaters_between(&textur_to_origin, &textur_test, &(prim->original_normal));
	// ft_vec_quater_rot(&normal_bent, &text_normal, &(origin_to_textur));
	ft_vec_quater_rot(&normal_bent, &text_normal, &(textur_to_origin));

	ft_set_3dpt(&(prim->normal), normal_bent.x, normal_bent.y, normal_bent.z);

	ft_normalize_vector(&(prim->normal));
}
