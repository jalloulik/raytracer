/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve_cylindre.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjalloul <kjalloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 16:31:08 by kjalloul          #+#    #+#             */
/*   Updated: 2018/05/23 05:00:55 by kjalloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	ft_get_abcdet_cyl(t_cyl *cyl, t_3dpt *dir, t_3dpt *origin)
{
	cyl->a = SQR(dir->x) + SQR(dir->z);
	cyl->b = 2.0 * (dir->x * origin->x + dir->z * origin->z);
	cyl->c = SQR(origin->x) + SQR(origin->z) - SQR(cyl->radius);
	cyl->det = SQR(cyl->b) - (4.0 * cyl->a * cyl->c);
}

double	ft_resolve_cyl(t_prim *prim, t_3dpt *dir, t_3dpt *origin)
{
	t_cyl	*cyl;
	t_3dpt	dir_local;
	t_3dpt	origin_local;

	cyl = &(prim->cyl);
	ft_vec_quater_rot(&dir_local, dir, &(prim->g_to_l_rot));
	ft_normalize_vector(&dir_local);
	ft_swap_g_to_l(&origin_local, origin, &(prim->g_to_l_move),
													&(prim->g_to_l_rot));
	ft_get_abcdet_cyl(cyl, &dir_local, &origin_local);
	if (cyl->det >= 0)
	{
		if (cyl->a == 0)
			cyl->a = cyl->a + 0.000000000000001;
		cyl->t1 = (-1 * (cyl->b) + sqrt(cyl->det)) / (2.0 * cyl->a);
		cyl->t2 = (-1 * (cyl->b) - sqrt(cyl->det)) / (2.0 * cyl->a);
		prim->isvalid = 1;
		if (cyl->t1 < cyl->t2 && cyl->t1 >= 0)
			return (cyl->t1);
		else if (cyl->t2 <= cyl->t1 && cyl->t2 >= 0)
			return (cyl->t2);
		else
			return (-1);
	}
	return (-1);
}
