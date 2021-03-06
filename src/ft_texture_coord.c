/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_texture_coord.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjalloul <kjalloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 15:22:38 by kjalloul          #+#    #+#             */
/*   Updated: 2018/06/25 15:23:42 by kjalloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		ft_get_textur_sphere(t_prim *prim, t_3dpt *coord, t_texture *tx)
{
	t_uv	uv;
	t_3dpt	origin_n;
	t_3dpt	local_normal;

	ft_calculate_vector(&origin_n, &(prim->p), &(prim->sphere.origin));
	ft_vec_quater_rot(&local_normal, &(origin_n),
												&(prim->g_to_l_rot));
	ft_normalize_vector(&local_normal);
	uv.tu = (asin(local_normal.x) / FT_PI + 0.5) + tx->xmove;
	uv.tv = (asin(local_normal.y) / FT_PI + 0.5) + tx->ymove;
	while (uv.tu < 0)
		uv.tu = uv.tu + 1;
	while (uv.tv < 0)
		uv.tv = uv.tv + 1;
	if (uv.tu > 1)
		uv.tu = uv.tu - 1;
	if (uv.tv > 1)
		uv.tv = uv.tv - 1;
	ft_get_coord_from_uv(tx, coord, &uv);
}

void		ft_get_textur_cyl(t_prim *prim, t_3dpt *coord, t_texture *tx)
{
	t_uv	uv;
	t_3dpt	local_normal;
	t_3dpt	local_p;

	ft_swap_g_to_l(&local_p, &(prim->p), &(prim->g_to_l_move),
												&(prim->g_to_l_rot));
	ft_vec_quater_rot(&local_normal, &(prim->original_normal),
														&(prim->g_to_l_rot));
	ft_normalize_vector(&local_normal);
	uv.tu = (atan2(local_p.x, local_p.z) / (2 * FT_PI) + 0.5)
														+ tx->xmove;
	uv.tv = (local_p.y / 10) + tx->ymove;
	if (uv.tu > 1)
		uv.tu = uv.tu - 1;
	while (uv.tv < 0)
		uv.tv = uv.tv + 1;
	ft_get_coord_from_uv(tx, coord, &uv);
}

void		ft_get_textur_plane(t_prim *prim, t_3dpt *coord, t_texture *tx)
{
	t_uv	uv;
	t_3dpt	local_p;

	ft_swap_g_to_l(&local_p, &(prim->p), &(prim->g_to_l_move),
												&(prim->g_to_l_rot));
	uv.tu = (local_p.x / 10) + tx->xmove;
	if (prim->normal.x == 0 && prim->normal.y == 1 && prim->normal.z == 0)
		local_p.y = local_p.z;
	uv.tv = (local_p.y / 10) + tx->ymove;
	while (uv.tu < 0)
		uv.tu = uv.tu + 1;
	while (uv.tv < 0)
		uv.tv = uv.tv + 1;
	ft_get_coord_from_uv(tx, coord, &uv);
}
