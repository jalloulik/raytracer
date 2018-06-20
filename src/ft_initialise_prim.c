/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialise_prim.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjalloul <kjalloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 16:21:43 by kjalloul          #+#    #+#             */
/*   Updated: 2018/06/20 21:30:42 by kjalloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		ft_initialise_cut(t_prim *prim)
{
	if (prim->cut && prim->cut->cut)
	{
		//potential leak, why?
		// prim->normal = *prim->cut->normal;
		prim->cut->cut = 0;
		ft_vec_quater_rot(&prim->normal, prim->cut->normal, &(prim->l_to_g_rot));
		return (0);
	}
	return (1);
}

void	ft_initialise_texturing(t_prim *prim)
{
	if (prim->textur.valid == TRUE)
		ft_set_3dpt(&(prim->original_normal), prim->normal.x,
									prim->normal.y, prim->normal.z);
	if (prim->textur_n.valid == TRUE)
		ft_get_texture_prim_normal(prim);
}

void	ft_intialise_primitives(t_prim *last)
{
	ft_set_3dpt(&(last->rot_axis), 0, 1, 0);
	last->rot_angle = ft_degree_to_rad(0.0);
	ft_set_3dpt(&(last->transl), 0, 0, 0);
	last->sin.status = FALSE;
	last->sin.xstatus = FALSE;
	last->sin.ystatus = FALSE;
	last->sin.zstatus = FALSE;
	last->reflective = FALSE;
	last->refractive = FALSE;
	last->textur.valid = FALSE;
	last->textur_n.valid = FALSE;
	last->checkers.valid = FALSE;
	last->cut = NULL;
}

void	ft_init_obj(t_obj *obj, t_light *light, t_prim *list)
{
	obj->light = light;
	obj->prim = list;
}
