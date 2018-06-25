/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_primitives.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjalloul <kjalloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 16:46:22 by kjalloul          #+#    #+#             */
/*   Updated: 2018/06/25 13:41:01 by kjalloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

// void	ft_rotate_triangle(t_prim *prim)
// {
// 	ft_set_3dpt(&(prim->triangle.dir_local), 0, 0, 1);
// 	ft_set_3dpt(&(prim->vec_local_dr), 1, 0, 0);
// 	ft_find_quaters_between(&(prim->l_to_g_rot), &(prim->triangle.dir_local),
// 														&(prim->triangle.dir));
// 	ft_vec_quater_rot(&(prim->vec_dr), &(prim->vec_local_dr),
// 														&(prim->l_to_g_rot));
// 	ft_quater_rot(&(prim->triangle.dir), &(prim->triangle.dir),
// 								&(prim->rot_axis), (prim->rot_angle));
// 	ft_quater_rot(&(prim->vec_dr), &(prim->vec_dr), &(prim->rot_axis),
// 															(prim->rot_angle));
// 	ft_normalize_vector(&(prim->triangle.dir));
// 	ft_normalize_vector(&(prim->vec_dr));
//
// 	ft_swap_g_to_l(&(prim->triangle.p1), &(prim->triangle.p1), &(prim->g_to_l_move),
// 													&(prim->g_to_l_rot));
// 	ft_swap_g_to_l(&(prim->triangle.p2), &(prim->triangle.p2), &(prim->g_to_l_move),
// 															&(prim->g_to_l_rot));
// 	ft_swap_g_to_l(&(prim->triangle.p3), &(prim->triangle.p3), &(prim->g_to_l_move),
// 										&(prim->g_to_l_rot));
//
// }

void	ft_rotate_tore(t_prim *prim)
{
	ft_set_3dpt(&(prim->tore.dir_local), 0, 0, 1);
	ft_set_3dpt(&(prim->vec_local_dr), 1, 0, 0);
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

void	ft_rotate_rect(t_prim *prim)
{
	ft_set_3dpt(&(prim->rect.dir_local), 0, 0, 1);
	ft_set_3dpt(&(prim->vec_local_dr), 1, 0, 0);
	ft_find_quaters_between(&(prim->l_to_g_rot), &(prim->rect.dir_local),
														&(prim->rect.dir));
	ft_vec_quater_rot(&(prim->vec_dr), &(prim->vec_local_dr),
														&(prim->l_to_g_rot));
	ft_quater_rot(&(prim->rect.dir), &(prim->rect.dir),
								&(prim->rot_axis), (prim->rot_angle));
	ft_quater_rot(&(prim->vec_dr), &(prim->vec_dr), &(prim->rot_axis),
															(prim->rot_angle));
	ft_normalize_vector(&(prim->rect.dir));
	ft_normalize_vector(&(prim->vec_dr));
}

void	ft_rotate_cercle(t_prim *prim)
{
	ft_set_3dpt(&(prim->cercle.dir_local), 0, 0, 1);
	ft_set_3dpt(&(prim->vec_local_dr), 1, 0, 0);
	ft_find_quaters_between(&(prim->l_to_g_rot), &(prim->cercle.dir_local),
														&(prim->cercle.dir));
	ft_vec_quater_rot(&(prim->vec_dr), &(prim->vec_local_dr),
														&(prim->l_to_g_rot));
	ft_quater_rot(&(prim->cercle.dir), &(prim->cercle.dir),
								&(prim->rot_axis), (prim->rot_angle));
	ft_quater_rot(&(prim->vec_dr), &(prim->vec_dr), &(prim->rot_axis),
															(prim->rot_angle));
	ft_normalize_vector(&(prim->cercle.dir));
	ft_normalize_vector(&(prim->vec_dr));
}

void	ft_rotate_plan(t_prim *prim)
{
	ft_set_3dpt(&(prim->plane.normal_local), 0, 0, 1);
	ft_set_3dpt(&(prim->vec_local_dr), 1, 0, 0);
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
