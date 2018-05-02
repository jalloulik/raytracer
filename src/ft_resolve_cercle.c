/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve_plane.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjalloul <kjalloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 12:05:16 by kjalloul          #+#    #+#             */
/*   Updated: 2018/05/02 20:15:05 by yvillepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double		ft_resolve_cercle(t_prim *prim, t_3dpt *dir, t_3dpt *ray_origin)
{
	t_cercle	*cercle;
	t_line		*line;
	t_3dpt		*pt;

	cercle = &(prim->cercle);
	pt = inter_plane(cercle.pos, cercle.dir
	if (sphere->det >= 0)
	{
		if (sphere->a == 0)
			sphere->a = sphere->a + 0.000000000000001;
		sphere->t1 = (-1 * (sphere->b) + sqrt(sphere->det)) / (2.0 * sphere->a);
		sphere->t2 = (-1 * (sphere->b) - sqrt(sphere->det)) / (2.0 * sphere->a);
		prim->isvalid = 1;
		if (sphere->t1 < sphere->t2 && sphere->t1 >= 0)
			return (sphere->t1);
		else if (sphere->t2 <= sphere->t1 && sphere->t2 >= 0)
			return (sphere->t2);
		else
			return (-1);
	}
	return (-1);
}

