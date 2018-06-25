/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perturbation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjalloul <kjalloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 16:06:49 by kjalloul          #+#    #+#             */
/*   Updated: 2018/06/05 16:27:27 by kjalloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	ft_sine_perturbation(t_prim *prim, t_3dpt *p)
{
	t_3dpt local_p;
	t_3dpt local_vec;

	if (prim->sin.status == TRUE)
	{
		ft_swap_g_to_l(&local_p, p, &(prim->g_to_l_move),
													&(prim->g_to_l_rot));
		ft_vec_quater_rot(&local_vec, &(prim->normal), &(prim->g_to_l_rot));
		if (prim->sin.xstatus == TRUE)
			ft_set_3dpt(&(local_vec), sin(local_p.x * prim->sin.x)
								/ prim->sin.x_div, local_vec.y, local_vec.z);
		if (prim->sin.ystatus == TRUE)
			ft_set_3dpt(&(local_vec), local_vec.x, sin(local_p.y * prim->sin.y)
												/ prim->sin.y_div, local_vec.z);
		if (prim->sin.zstatus == TRUE)
			ft_set_3dpt(&(local_vec), local_vec.x, local_vec.y,
								sin(local_p.z * prim->sin.z) / prim->sin.z_div);
		ft_normalize_vector(&local_vec);
		ft_vec_quater_rot(&(prim->normal), &local_vec, &(prim->l_to_g_rot));
		ft_normalize_vector(&(prim->normal));
	}
}
