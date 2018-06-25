/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve_triangle.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvillepo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 17:48:50 by yvillepo          #+#    #+#             */
/*   Updated: 2018/06/24 17:55:23 by yvillepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void	inv_vect(t_3dpt *pt)
{
	pt->x = -pt->x;
	pt->y = -pt->y;
	pt->z = -pt->z;
}

void		ft_normal_triangle(t_3dpt *result, t_3dpt *p1, t_3dpt *p2,
		t_3dpt *p3)
{
	t_3dpt	edge[2];

	edge[0] = v_sub(p2, p1);
	edge[1] = v_sub(p3, p1);
	*result = v_prod(&edge[0], &edge[1]);
}

double 		ft_resolve_triangle(t_prim *prim, t_3dpt *dir, t_3dpt *pos)
{
	t_triangle	*t;
	t_3dpt		edge[2];
	t_3dpt		vec[3];
	double		d;
	double		u[2];

	t = &(prim->triangle);
	edge[0] = v_sub(&t->p2, &t->p1);
	edge[1] = v_sub(&t->p3, &t->p1);
	prim->normal = v_prod(&edge[0], &edge[1]);
	ft_normalize_vector(&prim->normal);
	if (v_scale(&prim->normal, dir) > 0)
			inv_vect(&prim->normal);
	vec[0] = v_prod(dir, &edge[1]);
	d = v_scale(&edge[0], &vec[0]);
	if (d < 1e-8 && d > -1e-8)
		return (0);
	vec[1] = v_sub(pos, &(t->p1));
	u[0] = v_scale(&vec[1], &vec[0]) * (1.0f / d);
	if (u[0] < 0 || u[0] > 1)
		return (-1);
	vec[2] = v_prod(&vec[1], &edge[0]);
	u[1] = v_scale(dir, &vec[2]) * (1.0f / d);
	if (u[1] < 0 || u[0] + u[1] > 1)
		return (-1);
	return (v_scale(&edge[1], &vec[2]) * (1.0f / d));
}
