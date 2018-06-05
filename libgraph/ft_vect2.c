/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vect2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvillepo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 18:21:36 by yvillepo          #+#    #+#             */
/*   Updated: 2018/06/05 18:21:38 by yvillepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgraph.h"

t_3dpt	*new_vect(double x, double y, double z)
{
	t_3dpt	*new;

	if (!(new = malloc(sizeof(*new))))
		return (NULL);
	new->x = x;
	new->y = y;
	new->z = z;
	return (new);
}

t_3dpt	v_mult(t_3dpt *v1, t_3dpt *v2)
{
	t_3dpt	res;

	res.x = v1->x * v2->x;
	res.y = v1->y * v2->y;
	res.z = v1->z * v2->z;
	return (res);
}
