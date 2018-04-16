/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_primitives.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjalloul <kjalloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 16:46:22 by kjalloul          #+#    #+#             */
/*   Updated: 2018/03/21 17:49:36 by kjalloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	ft_rotate_plan(t_prim *prim)
{
	ft_quater_rot(&(prim->plane.normal), &(prim->plane.normal),
								&(prim->rot_axis), (prim->rot_angle));
	ft_normalize_vector(&(prim->plane.normal));
}

void	ft_rotate_cyl(t_prim *prim)
{
	ft_quater_rot(&(prim->cyl.vec), &(prim->cyl.vec),
								&(prim->rot_axis), (prim->rot_angle));
	ft_normalize_vector(&(prim->cyl.vec));
}

void	ft_rotate_cone(t_prim *prim)
{
	ft_quater_rot(&(prim->cone.vec), &(prim->cone.vec),
								&(prim->rot_axis), (prim->rot_angle));
	ft_normalize_vector(&(prim->cone.vec));
}
