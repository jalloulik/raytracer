/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvillepo <yvillepo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 12:04:54 by yvillepo          #+#    #+#             */
/*   Updated: 2018/05/29 22:28:55 by yvillepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include <stdio.h>

double			solv_seconde(t_prim *p, t_3dpt *param, t_3dpt *pos, t_3dpt *dir)
{
	double		d;
	double		t[2];
	t_3dpt		*p1;
	t_3dpt		*p2;

	d = param->y * param->y - 4 * param->x * param->z;
	if (d < 0)
		return (-1);
	if (param->x == 0)
		param->x = 0.000000000000001;
	t[0] = (-param->y - sqrt(d)) / (2 * param->x);
	t[1] = (-param->y + sqrt(d)) / (2 * param->x);
	if (!(p->cut))
		return (t[0]);
	p1 = calc_point(pos, dir, t[0]);
	p2 = calc_point(pos, dir, t[1]);
	//t[0] = cut(p1, p2, t, p->cut);
	free(p1);
	free(p2);
	return (t[0]);
}
