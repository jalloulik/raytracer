/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvillepo <yvillepo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 12:04:54 by yvillepo          #+#    #+#             */
/*   Updated: 2018/06/02 03:04:03 by yvillepo         ###   ########.fr       */
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

double			solv_seconde(t_prim *p, t_3dpt *param, t_3dpt *pos, t_3dpt *dir)
{
	double		d;
	double		t[2];

	d = param->y * param->y - 4 * param->x * param->z;
	if (d < 0)
		return (-1);
	if (param->x == 0)
		param->x = 0.000000000000001;
	t[0] = (-param->y - sqrt(d)) / (2 * param->x);
	t[1] = (-param->y + sqrt(d)) / (2 * param->x);
	return (t[0]);
}
