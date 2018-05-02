/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvillepo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 13:17:38 by yvillepo          #+#    #+#             */
/*   Updated: 2018/03/23 08:21:04 by yvillepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgraph.h"

t_3dpt	*v_add(t_3dpt *u1, t_3dpt *u2)
{
	return (new_vect(u1->x + u2->x, u1->y + u2->y, u1->z + u2->z));
}

t_3dpt	*v_sub(t_3dpt *u1, t_3dpt *u2)
{
	return (new_vect(u1->x - u2->x, u1->y - u2->y, u1->z - u2->z));
}

t_3dpt	*v_cross(t_3dpt *u1, t_3dpt *u2)
{
	return (new_vect(u1->y * u2->z - u1->z * u2->y,
			u1->z * u2->x - u1->x * u2->z,
			u1->x * u2->y - u1->y * u2->x));
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
