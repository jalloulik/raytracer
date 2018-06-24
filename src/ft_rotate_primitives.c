/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_primitives.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjalloul <kjalloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 16:46:22 by kjalloul          #+#    #+#             */
/*   Updated: 2018/06/23 18:21:36 by kjalloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	ft_rotate_tore(t_prim *prim)
{
	ft_set_3dpt(&(prim->tore.dir_local), 0, 0, 1);
	ft_set_3dpt(&(prim->vec_local_dr), 1, 0, 0);
	// if (ft_compare_3dpt_prim(&(prim->tore.dir), &(prim->tore.dir_local), "z") == TRUE)
	// 	ft_set_3dpt(&(prim->tore.dir), 0, 0, 1);
	ft_find_quaters_between(&(prim->l_to_g_rot), &(prim->tore.dir_local),
														&(prim->tore.dir));
	ft_vec_quater_rot(&(prim->vec_dr), &(prim->vec_local_dr),
														&(prim->l_to_g_rot));
	ft_quater_rot(&(prim->tore.dir), &(prim->tore.dir),
								&(prim->rot_axis), (prim->rot_angle));
	ft_quater_rot(&(prim->vec_dr), &(prim->vec_dr), &(prim->rot_axis),
															(prim->rot_angle));
	ft_normalize_vector(&(prim->tore.dir));
	ft_normalize_vector(&(prim->vec_dr));
}

void	ft_rotate_plan(t_prim *prim)
{
	ft_set_3dpt(&(prim->plane.normal_local), 0, 0, 1);
	ft_set_3dpt(&(prim->vec_local_dr), 1, 0, 0);
	// if (ft_compare_3dpt_prim(&(prim->plane.normal), &(prim->plane.normal_local), "z") == TRUE)
	// 	{
	// 		ft_set_3dpt(&(prim->plane.normal), 0, 0, -1.5);
	// 		ft_normalize_vector(&(prim->plane.normal));
	// 		printf("%f\n", (prim->plane.normal.z));
	// 	}
	ft_find_quaters_between(&(prim->l_to_g_rot), &(prim->plane.normal_local),
														&(prim->plane.normal));
	ft_vec_quater_rot(&(prim->vec_dr), &(prim->vec_local_dr),
														&(prim->l_to_g_rot));
	ft_quater_rot(&(prim->plane.normal), &(prim->plane.normal),
								&(prim->rot_axis), (prim->rot_angle));
	ft_quater_rot(&(prim->vec_dr), &(prim->vec_dr), &(prim->rot_axis),
															(prim->rot_angle));
	ft_normalize_vector(&(prim->plane.normal));
	ft_normalize_vector(&(prim->vec_dr));
}

void	ft_rotate_cyl(t_prim *prim)
{
	ft_set_3dpt(&(prim->vec_local_dr), 1, 0, 0);
	ft_set_3dpt(&(prim->cyl.vec_local), 0, 1, 0);
	// if (ft_compare_3dpt_prim(&(prim->cyl.vec), &(prim->cyl.vec_local), "y") == TRUE)
	// 	ft_set_3dpt(&(prim->cyl.vec), 0, 1, 0);
	ft_find_quaters_between(&(prim->l_to_g_rot), &(prim->cyl.vec_local),
															&(prim->cyl.vec));
	ft_vec_quater_rot(&(prim->vec_dr), &(prim->vec_local_dr),
														&(prim->l_to_g_rot));
	ft_quater_rot(&(prim->cyl.vec), &(prim->cyl.vec),
								&(prim->rot_axis), (prim->rot_angle));
	ft_quater_rot(&(prim->vec_dr), &(prim->vec_dr), &(prim->rot_axis),
															(prim->rot_angle));
	ft_normalize_vector(&(prim->cyl.vec));
	ft_normalize_vector(&(prim->vec_dr));
}

void	ft_rotate_cone(t_prim *prim)
{
	ft_set_3dpt(&(prim->vec_local_dr), 1, 0, 0);
	ft_set_3dpt(&(prim->cone.vec_local), 0, 1, 0);
	// if (ft_compare_3dpt_prim(&(prim->cone.vec), &(prim->cone.vec_local), "y") == TRUE)
	// 	ft_set_3dpt(&(prim->cone.vec), 0, 1, 0);
	ft_find_quaters_between(&(prim->l_to_g_rot), &(prim->cone.vec_local),
															&(prim->cone.vec));
	ft_vec_quater_rot(&(prim->vec_dr), &(prim->vec_local_dr),
														&(prim->l_to_g_rot));
	ft_quater_rot(&(prim->cone.vec), &(prim->cone.vec),
								&(prim->rot_axis), (prim->rot_angle));
	ft_quater_rot(&(prim->vec_dr), &(prim->vec_dr), &(prim->rot_axis),
															(prim->rot_angle));
	ft_normalize_vector(&(prim->cone.vec));
	ft_normalize_vector(&(prim->vec_dr));
}

void	ft_rotate_sphere(t_prim *prim)
{
	ft_set_3dpt(&(prim->sphere.vec), 0, 1, 0);
	ft_set_3dpt(&(prim->vec_dr), 1, 0, 0);
	ft_quater_rot(&(prim->sphere.vec), &(prim->sphere.vec),
								&(prim->rot_axis), (prim->rot_angle));
	ft_quater_rot(&(prim->vec_dr), &(prim->vec_dr),
								&(prim->rot_axis), (prim->rot_angle));
	ft_normalize_vector(&(prim->sphere.vec));
	ft_normalize_vector(&(prim->vec_dr));
}
