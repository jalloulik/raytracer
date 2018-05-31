/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_local_prim.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjalloul <kjalloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 16:51:11 by kjalloul          #+#    #+#             */
/*   Updated: 2018/05/29 22:55:36 by yvillepo         ###   ########.fr       */
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

void	ft_create_local_rect(t_prim *prim)
{
	ft_set_3dpt(&(prim->l_to_g_move), prim->rect.pos.x, prim->rect.pos.y,
														prim->rect.pos.z);
	ft_set_3dpt(&(prim->g_to_l_move), -1 * prim->rect.pos.x,
						-1 * prim->rect.pos.y, -1 * prim->rect.pos.z);
	ft_set_3dpt(&(prim->rect.pos_local), 0, 0, 0);
	ft_set_3dpt(&(prim->rect.dir_local), 0, 1, 0);
	ft_find_quaters_between(&(prim->l_to_g_rot), &(prim->rect.pos_local),
														&(prim->rect.dir));
	ft_find_quaters_between(&(prim->g_to_l_rot), &(prim->rect.dir),
													&(prim->rect.pos_local));
}

void	ft_create_local_tore(t_prim *prim)
{
	ft_set_3dpt(&(prim->l_to_g_move), prim->tore.pos.x, prim->tore.pos.y,
														prim->tore.pos.z);
	ft_set_3dpt(&(prim->g_to_l_move), -1 * prim->tore.pos.x,
						-1 * prim->tore.pos.y, -1 * prim->tore.pos.z);
	ft_set_3dpt(&(prim->tore.pos_local), 0, 0, 0);
	ft_set_3dpt(&(prim->tore.dir_local), 0, 0, 1);
	ft_find_quaters_between(&(prim->l_to_g_rot), &(prim->tore.dir_local),
														&(prim->tore.dir));
	ft_find_quaters_between(&(prim->g_to_l_rot), &(prim->tore.dir),
													&(prim->tore.dir_local));
}
