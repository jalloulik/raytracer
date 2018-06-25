/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_primitives2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjalloul <kjalloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 16:15:50 by kjalloul          #+#    #+#             */
/*   Updated: 2018/06/25 16:16:19 by kjalloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

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
