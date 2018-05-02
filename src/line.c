/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvillepo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 11:44:22 by yvillepo          #+#    #+#             */
/*   Updated: 2018/05/02 18:25:21 by yvillepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_3dpt		*calc_point(t_3dpt *pos, t_3dpt *dir, double t)
{
	return (new_vect(pos->x + dir->x * t,
			pos->y + dir->y * t,
			pos->z + dir->z * t));
}

double		v_l(t_3dpt *v)
{
	return (sqrt(v->x * v->x + v->y * v->y + v->z * v->z));
}

double		v_scale(t_3dpt *u, t_3dpt *v)
{
	return (u->x * v->x + u->y * u->y + u->z * u->z);
}

double		calc_angle(t_3dpt *v1, t_3dpt *v2)
{
	return (acos(v_mult(v1, v2) / (v_l(v1) * v_l(v2))));
}

void		v_unit(t_3dpt *v)
{
	double	norm;

	norm = v_l(v);
	v->x /= norm;
	v->y /= norm;
	v->z /= norm;
}
