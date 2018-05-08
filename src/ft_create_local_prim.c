/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_local_prim.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjalloul <kjalloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 16:51:11 by kjalloul          #+#    #+#             */
/*   Updated: 2018/05/08 20:15:08 by yvillepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	ft_create_local_cyl(t_prim *prim)
{
	ft_set_3dpt(&(prim->l_to_g_move), prim->cyl.origin.x, prim->cyl.origin.y,
														prim->cyl.origin.z);
	ft_set_3dpt(&(prim->g_to_l_move), -1 * prim->cyl.origin.x,
							-1 * prim->cyl.origin.y, -1 * prim->cyl.origin.z);
	ft_set_3dpt(&(prim->cyl.origin_local), 0, 0, 0);
	ft_set_3dpt(&(prim->cyl.vec_local), 0, 1, 0);
	ft_find_quaters_between(&(prim->l_to_g_rot), &(prim->cyl.vec_local),
															&(prim->cyl.vec));
	ft_find_quaters_between(&(prim->g_to_l_rot), &(prim->cyl.vec),
														&(prim->cyl.vec_local));
}

void	ft_create_local_cone(t_prim *prim)
{
	ft_set_3dpt(&(prim->l_to_g_move), prim->cone.origin.x, prim->cone.origin.y,
														prim->cone.origin.z);
	ft_set_3dpt(&(prim->g_to_l_move), -1 * prim->cone.origin.x,
						-1 * prim->cone.origin.y, -1 * prim->cone.origin.z);
	ft_set_3dpt(&(prim->cone.origin_local), 0, 0, 0);
	ft_set_3dpt(&(prim->cone.vec_local), 0, 1, 0);
	ft_find_quaters_between(&(prim->l_to_g_rot), &(prim->cone.vec_local),
														&(prim->cone.vec));
	ft_find_quaters_between(&(prim->g_to_l_rot), &(prim->cone.vec),
													&(prim->cone.vec_local));
}

void	ft_create_local(t_prim *prim, t_3dpt *pos, t_3dpt *dir, t_3dpt *expected_dir)
{

	t_3dpt	p1;
	t_3dpt	p2;

	ft_set_3dpt(&(prim->l_to_g_move), pos->.x, pos->.y,
														pos->.z);
	ft_set_3dpt(&(prim->g_to_l_move), -1 * pos->.x,
							-1 * pos->.y, -1 * pos->.z);
	ft_set_3dpt(&(pos->_local), 0, 0, 0);
	ft_set_3dpt(&(prim->cyl.vec_local), 0, 1, 0);
	ft_find_quaters_between(&(prim->l_to_g_rot), &(prim->cyl.vec_local),
															&(prim->cyl.vec));
	ft_find_quaters_between(&(prim->g_to_l_rot), &(prim->cyl.vec),
}
