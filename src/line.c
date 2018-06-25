/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvillepo <yvillepo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 11:44:22 by yvillepo          #+#    #+#             */
/*   Updated: 2018/06/05 19:26:39 by yvillepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		calc_point(t_3dpt *result, t_3dpt *pos, t_3dpt *dir, double t)
{
	result->x = pos->x + dir->x * t;
	result->y = pos->y + dir->y * t;
	result->z = pos->z + dir->z * t;
}

double		v_l(t_3dpt *v)
{
	return (sqrt(v->x * v->x + v->y * v->y + v->z * v->z));
}

double		dist(t_3dpt *v, t_3dpt *v2)
{
	t_3dpt	u;
	double	res;

	u = v_sub(v, v2);
	res = v_l(&u);
	return (res);
}

void		v_unit(t_3dpt *v)
{
	double	norm;

	norm = v_l(v);
	v->x /= norm;
	v->y /= norm;
	v->z /= norm;
}
