/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvillepo <yvillepo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 12:04:54 by yvillepo          #+#    #+#             */
/*   Updated: 2018/06/25 19:11:15 by yvillepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include <stdio.h>

double		search_min(double num[4], int nb)
{
	double	min;
	int		i;

	if (!nb)
		return (0);
	i = 0;
	min = num[0];
	while (i < nb)
	{
		if (num[i] < min && num[i] > 0)
			min = num[i];
		i++;
	}
	return (min);
}

int			solve_linear(double a, double b, double *r)
{
	if (a == 0)
		return (0);
	else
	{
		*r = -b / a;
		return (1);
	}
}

double		solv_seconde(t_prim *prim, t_3dpt *param, t_3dpt *pos, t_3dpt *dir)
{
	double		d;
	double		t[4];

	d = param->y * param->y - 4 * param->x * param->z;
	if (d < 0)
		return (-1);
	if (param->x == 0)
		param->x = 0.000000000000001;
	t[0] = (-param->y - sqrt(d)) / (2 * param->x);
	t[1] = (-param->y + sqrt(d)) / (2 * param->x);
	if (prim->cut == NULL)
		return (t[0]);
	cut(prim->cut, pos, dir, t);
	return (t[3]);
}
