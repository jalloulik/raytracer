/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_local_prim2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjalloul <kjalloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 16:53:30 by kjalloul          #+#    #+#             */
/*   Updated: 2018/06/21 18:54:38 by kjalloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

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
	if (ft_compare_3dpt(&(prim->tore.dir), &(prim->rot_axis)) == FALSE)
	{
		ft_find_quaters_between(&(prim->l_to_g_rot), &(prim->tore.dir_local),
															&(prim->tore.dir));
		ft_find_quaters_between(&(prim->g_to_l_rot), &(prim->tore.dir),
														&(prim->tore.dir_local));
	}
	else
		ft_set_dir_rotations(prim);
}

void	ft_create_local_sphere(t_prim *prim)
{
	ft_set_3dpt(&(prim->l_to_g_move), prim->sphere.origin.x,
								prim->sphere.origin.y, prim->sphere.origin.z);
	ft_set_3dpt(&(prim->g_to_l_move), -1 * prim->sphere.origin.x,
						-1 * prim->sphere.origin.y, -1 * prim->sphere.origin.z);
	ft_set_3dpt(&(prim->sphere.origin_local), 0, 0, 0);
	ft_set_3dpt(&(prim->sphere.vec_local), 0, 1, 0);
	if (ft_compare_3dpt(&(prim->sphere.vec), &(prim->rot_axis)) == FALSE)
	{
		ft_find_quaters_between(&(prim->l_to_g_rot), &(prim->sphere.vec_local),
														&(prim->sphere.vec));
		ft_find_quaters_between(&(prim->g_to_l_rot), &(prim->sphere.vec),
													&(prim->sphere.vec_local));
	}
	else
		ft_set_dir_rotations(prim);
}

void	ft_create_local_plane(t_prim *prim)
{
	ft_set_3dpt(&(prim->l_to_g_move), prim->plane.point.x,
								prim->plane.point.y, prim->plane.point.z);
	ft_set_3dpt(&(prim->g_to_l_move), -1 * prim->plane.point.x,
						-1 * prim->plane.point.y, -1 * prim->plane.point.z);
	ft_set_3dpt(&(prim->plane.point_local), 0, 0, 0);
	ft_set_3dpt(&(prim->plane.normal_local), 0, 0, 1);
	if (ft_compare_3dpt(&(prim->plane.normal), &(prim->rot_axis)) == FALSE)
	{
		ft_find_quaters_between(&(prim->l_to_g_rot),
						&(prim->plane.normal_local), &(prim->plane.normal));
		ft_find_quaters_between(&(prim->g_to_l_rot),
						&(prim->plane.normal), &(prim->plane.normal_local));
	}
	else
		ft_set_dir_rotations(prim);
}
