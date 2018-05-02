/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvillepo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 11:51:30 by yvillepo          #+#    #+#             */
/*   Updated: 2018/03/20 11:52:02 by yvillepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vect	unit_scale(double k, t_vect *v)
{
	t_vect res;

	res.x = v->x * k;
	res.y = v->y * k;
	res.z = v->z * k;
	return (res);
}

t_plane	*calc_plane(t_vect *normal, t_vect *va)
{
	t_plane	*p;

	p = ft_malloc(sizeof(*p));
	p->n = normal;
	p->d = -(va->x * normal->x + va->y * normal->y + va->z * normal->z);
	return (p);
}

double	solv_2nd(double a, double b, double c)
{
	double d;
	double res;

	d = b * b - 4 * a * c;
	if (d < 0)
		return (-1);
	res = (-b - sqrt(d)) / (2 * a);
	if (res < 0)
		res = (-b + sqrt(d)) / (2 * a);
	return (res);
}

double	deg_to_rad(double a)
{
	double ret;

	ret = a * PI / 180.0;
	return (ret);
}
