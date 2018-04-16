/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve_cone.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjalloul <kjalloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 16:37:05 by kjalloul          #+#    #+#             */
/*   Updated: 2018/03/22 13:09:02 by kjalloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void	ft_get_abcdet_cone(t_cone *cone, t_3dpt *dir, t_3dpt *origin)
{
	double temp;

	temp = SQR(tan(cone->angle));
	cone->a = SQR(dir->x) - SQR(dir->y) * temp + SQR(dir->z);
	cone->b = 2.0 * (dir->x * (origin->x) -
		dir->y * (origin->y) * temp + dir->z *
		(origin->z));
	cone->c = SQR(origin->x) -
		SQR(origin->y) * temp +
		SQR(origin->z);
	cone->det = SQR(cone->b) - (4.0 * cone->a * cone->c);
}

double		ft_resolve_cone(t_prim *prim, t_3dpt *dir, t_3dpt *origin)
{
	t_cone	*cone;
	t_3dpt	dir_local;
	t_3dpt	origin_local;

	cone = &(prim->cone);
	ft_vec_quater_rot(&dir_local, dir, &(prim->g_to_l_rot));
	ft_normalize_vector(&dir_local);
	ft_swap_g_to_l(&origin_local, origin, &(prim->g_to_l_move),
													&(prim->g_to_l_rot));
	ft_get_abcdet_cone(cone, &dir_local, &origin_local);
	if (cone->det >= 0)
	{
		if (cone->a == 0)
			cone->a = cone->a + 0.000000000000001;
		cone->t1 = (-1 * (cone->b) + sqrt(cone->det)) / (2.0 * cone->a);
		cone->t2 = (-1 * (cone->b) - sqrt(cone->det)) / (2.0 * cone->a);
		prim->isvalid = 1;
		if (cone->t1 < cone->t2 && cone->t1 >= 0)
			return (cone->t1);
		else if (cone->t2 <= cone->t1 && cone->t2 >= 0)
			return (cone->t2);
		else
			return (-1);
	}
	return (-1);
}
