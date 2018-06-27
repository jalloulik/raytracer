/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calculate_normal_primitives2.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjalloul <kjalloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 20:02:39 by kjalloul          #+#    #+#             */
/*   Updated: 2018/06/25 20:16:31 by kjalloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	ft_rect_normal(t_prim *prim)
{
	ft_set_3dpt(&(prim->normal), prim->rect.dir.x, prim->rect.dir.y,
			prim->rect.dir.z);
	ft_initialise_texturing(prim);
}

void	ft_tore_normal_text(t_prim *prim)
{
	ft_tore_normal(prim);
	ft_initialise_texturing(prim);
}

void	ft_cercle_normal(t_prim *prim)
{
	ft_set_3dpt(&(prim->normal), prim->cercle.dir.x, prim->cercle.dir.y,
			prim->cercle.dir.z);
	ft_initialise_texturing(prim);
}
