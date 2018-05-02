/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvillepo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 11:44:22 by yvillepo          #+#    #+#             */
/*   Updated: 2018/03/23 02:21:55 by yvillepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgraph.h"
/*
t_3dpt		*calc_point(t_line *line, double t)
{
	return (new_vect(line->pos->x + line->dir->x * t,
			line->pos->y + line->dir->y * t,
			line->pos->z + line->dir->z * t));
}
*/
double		v_l2(t_3dpt *v)
{
	return (v->x * v->x + v->y * v->y + v->z * v->z);
}

double		v_l(t_3dpt *v)
{
	return (sqrt(v->x * v->x + v->y * v->y + v->z * v->z));
}

double		calc_angle(t_3dpt *v1, t_3dpt *v2)
{
	return (acos(v_scale(v1, v2) / (v_l(v1) * v_l(v2))));
}

void		v_unit(t_3dpt *v)
{
	double	norm;

	norm = v_l(v);
	v->x /= norm;
	v->y /= norm;
	v->z /= norm;
}
