/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvillepo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 10:40:59 by yvillepo          #+#    #+#             */
/*   Updated: 2018/05/03 18:49:25 by yvillepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double		inter_plane(t_3dpt *normal, double d, t_3dpt *pos, t_3dpt *dir)
{
	double	t;

	t = dir->x * normal->x + dir->y * normal->y
			+ dir->z * normal->z;
	if (t == 0)
		return (-1);
	t = (-((normal->x * pos->x + normal->y *
					pos->y + normal->z
					* pos->z + d )/ t));
	return (t);
}

/*
double		inter_plane(t_plane *plane, t_line *line)
{
	double	d;

	d = v_scale(line->dir, plane->n);
	return (-(v_scale(plane->n, line->pos) + plane->d / d));
}
*/
