/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve_rect.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvillepo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 03:18:25 by yvillepo          #+#    #+#             */
/*   Updated: 2018/06/05 17:48:28 by yvillepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static double	ft_resolve_t(t_rect *rect, t_3dpt *dir, t_3dpt *pos)
{
	double	d;
	double	t;
	t_3dpt	*pt;

	d = -(rect->pos.x * rect->dir.x + rect->pos.y * rect->dir.y +
			rect->pos.z * rect->dir.z);
	t = inter_plane(&(rect->dir), d, pos, dir);
	pt = calc_point(pos, dir, t);
	if (ft_absd(pt->x) < rect->width / 2 &&
			ft_absd(pt->y) < rect->height / 2)
		return (t);
	return (-1);
}

double			ft_resolve_rect(t_prim *prim, t_3dpt *dir, t_3dpt *origin)
{
	t_rect	*rect;
	t_3dpt	dir_local;
	t_3dpt	pos_local;

	rect = &(prim->rect);
	ft_vec_quater_rot(&dir_local, dir, &(prim->g_to_l_rot));
	ft_normalize_vector(&dir_local);
	ft_swap_g_to_l(&pos_local, origin, &(prim->g_to_l_move),
													&(prim->g_to_l_rot));
	return (ft_resolve_t(rect, &dir_local, &pos_local));
}
