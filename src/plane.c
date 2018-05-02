/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvillepo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 10:40:59 by yvillepo          #+#    #+#             */
/*   Updated: 2018/05/02 20:14:58 by yvillepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_3dpt		*inter_plane(t_3dpt *normal, double d, t_3dpt *pos, t_3dpt *dir)
{
	double	t;

	t = dir->x * plane->normal.x + dir->y * plane->normal.y
			+ dir->z * plane->normal.z;
	if (t == 0)
		return (NULL);
	t = (-((plane->normal.x * pos->x + plane->normal.y *
					pos->y + plane->normal.z
					* pos->z + plane->d) / t));
	return (calc_point(pos, dir, t);
}
