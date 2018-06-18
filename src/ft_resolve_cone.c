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

static void	ft_get_abcdet_cone(t_cone *cone, t_3dpt *dir, t_3dpt *origin, t_3dpt *param)
{
	double temp;

	temp = SQR(tan(cone->angle));
	param->x = SQR(dir->x) - SQR(dir->y) * temp + SQR(dir->z);
	param->y = 2.0 * (dir->x * (origin->x) -
		dir->y * (origin->y) * temp + dir->z *
		(origin->z));
	param->z = SQR(origin->x) -
		SQR(origin->y) * temp +
		SQR(origin->z);
}

double		ft_resolve_cone(t_prim *prim, t_3dpt *dir, t_3dpt *origin)
{
	t_cone	*cone;
	t_3dpt	dir_local;
	t_3dpt	origin_local;
	t_3dpt	param;

	cone = &(prim->cone);
	ft_vec_quater_rot(&dir_local, dir, &(prim->g_to_l_rot));
	ft_normalize_vector(&dir_local);
	ft_swap_g_to_l(&origin_local, origin, &(prim->g_to_l_move),
													&(prim->g_to_l_rot));
	ft_get_abcdet_cone(cone, &dir_local, &origin_local, &param);
	return (solv_seconde(prim, &param, &origin_local, &dir_local));
}
