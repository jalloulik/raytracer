/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vect.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvillepo <yvillepo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 13:17:38 by yvillepo          #+#    #+#             */
/*   Updated: 2018/06/05 19:01:21 by kjalloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgraph.h"

t_3dpt	v_sub(t_3dpt *u1, t_3dpt *u2)
{
	t_3dpt	p;

	p.x = u1->x - u2->x;
	p.y = u1->y - u2->y;
	p.z = u1->z - u2->z;
	return (p);
}

t_3dpt	v_prod(t_3dpt *u1, t_3dpt *u2)
{
	t_3dpt	p;

	p.x = u1->y * u2->z - u1->z * u2->y;
	p.y = u1->z * u2->x - u1->x * u2->z;
	p.z = u1->x * u2->y - u1->y * u2->x;
	return (p);
}

double	v_scale(t_3dpt *u1, t_3dpt *u2)
{
	return (u1->x * u2->x + u1->y * u2->y + u1->z * u2->z);
}

int		is_nul(t_3dpt *v)
{
	if (v->x == 0 && v->y == 0 && v->z == 0)
		return (1);
	return (0);
}
