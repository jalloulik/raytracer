/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve_plane.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjalloul <kjalloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 12:05:16 by kjalloul          #+#    #+#             */
/*   Updated: 2018/06/05 17:34:51 by yvillepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double		ft_resolve_cercle(t_prim *prim, t_3dpt *dir, t_3dpt *ray_origin)
{
	t_cercle	*cercle;
	t_3dpt		*pt;
	double		d;
	double		t;

	cercle = &(prim->cercle);
	d = -(cercle->pos.x * cercle->dir.x + cercle->pos.y * cercle->dir.y +
			cercle->pos.z * cercle->dir.z);
	t = inter_plane(&(cercle->dir), d, ray_origin, dir);
	pt = calc_point(ray_origin, dir, t);
	if (dist(pt, &(cercle->pos)) < cercle->r)
	{
		free(pt);
		return (t);
	}
	free(pt);
	return (-1);
}
