/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_global_local_swap.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjalloul <kjalloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 15:28:11 by kjalloul          #+#    #+#             */
/*   Updated: 2018/05/10 18:22:57 by kjalloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	ft_swap_g_to_l(t_3dpt *result, t_3dpt *src, t_3dpt *move, t_quater *rot)
{
	t_3dpt tmp;

	ft_sum_vectors(&tmp, src, move);
	ft_vec_quater_rot(result, &tmp, rot);
}

void	ft_swap_l_to_g(t_3dpt *result, t_3dpt *src, t_3dpt *move, t_quater *rot)
{
	t_3dpt tmp;

	ft_vec_quater_rot(&tmp, src, rot);
	ft_sum_vectors(result, &tmp, move);
}

void	ft_rotate_all(t_prim *prim)
{
	while (prim != NULL)
	{
		if (prim->type == SPHERE)
		{
		}
		else if (prim->type == PLANE)
			ft_rotate_plan(prim);
		else if (prim->type == CYLINDER)
			ft_rotate_cyl(prim);
		else if (prim->type == CONE)
			ft_rotate_cone(prim);
		prim = prim->next;
	}
}

void	ft_create_local_vector_spaces(t_prim *prim)
{
	while (prim != NULL)
	{
		if (prim->type == SPHERE)
		{
			ft_stb_load_textur(&(prim->textur), "assets/Stone_02_COLOR.tga");
		}
		else if (prim->type == PLANE)
		{
		}
		else if (prim->type == CYLINDER)
			ft_create_local_cyl(prim);
		else if (prim->type == CONE)
			ft_create_local_cone(prim);
		prim = prim->next;
	}
}

void	ft_translante_all(t_prim *prim)
{
	while (prim != NULL)
	{
		if (prim->type == SPHERE)
			ft_sum_vectors(&(prim->sphere.origin), &(prim->sphere.origin),
															&(prim->transl));
		else if (prim->type == PLANE)
			ft_sum_vectors(&(prim->plane.point), &(prim->plane.point),
															&(prim->transl));
		else if (prim->type == CYLINDER)
			ft_sum_vectors(&(prim->cyl.origin), &(prim->cyl.origin),
															&(prim->transl));
		else if (prim->type == CONE)
			ft_sum_vectors(&(prim->cone.origin), &(prim->cone.origin),
															&(prim->transl));
		prim = prim->next;
	}
}
