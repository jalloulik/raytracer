/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve_cylindre.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjalloul <kjalloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 16:31:08 by kjalloul          #+#    #+#             */
/*   Updated: 2018/06/05 19:20:36 by yvillepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	ft_get_abcdet_cyl(t_cyl *cyl, t_3dpt *dir,
		t_3dpt *origin, t_3dpt *param)
{
	param->x = SQR(dir->x) + SQR(dir->z);
	param->y = 2.0 * (dir->x * origin->x + dir->z * origin->z);
	param->z = SQR(origin->x) + SQR(origin->z) - SQR(cyl->radius);
}

double	ft_resolve_cyl(t_prim *prim, t_3dpt *dir, t_3dpt *origin)
{
	t_cyl	*cyl;
	t_3dpt	dir_local;
	t_3dpt	origin_local;
	t_3dpt	param;

	cyl = &(prim->cyl);
	ft_vec_quater_rot(&dir_local, dir, &(prim->g_to_l_rot));
	ft_normalize_vector(&dir_local);
	ft_swap_g_to_l(&origin_local, origin, &(prim->g_to_l_move),
													&(prim->g_to_l_rot));
	ft_get_abcdet_cyl(cyl, &dir_local, &origin_local, &param);
	return (solv_seconde(&param));
}
