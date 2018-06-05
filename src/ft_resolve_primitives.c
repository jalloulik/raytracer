/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve_primitives.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjalloul <kjalloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 08:45:46 by kjalloul          #+#    #+#             */
/*   Updated: 2018/06/05 18:30:54 by kjalloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdio.h"
#include "rtv1.h"

double	ft_return_prim_dist(t_prim *prim, t_3dpt *ray, t_3dpt *origin)
{
	double t;

	t = -1;
	if (prim == NULL)
		return (t);
	if (prim->type == SPHERE)
		t = ft_resolve_sphere(prim, ray, origin);
	else if (prim->type == PLANE)
		t = ft_resolve_plane(prim, ray, origin);
	else if (prim->type == CYLINDER)
		t = ft_resolve_cyl(prim, ray, origin);
	else if (prim->type == CONE)
		t = ft_resolve_cone(prim, ray, origin);
	else if (prim->type == CERCLE)
		t = ft_resolve_cercle(prim, ray, origin);
	else if (prim->type == RECT)
		t = ft_resolve_rect(prim, ray, origin);
	else if (prim->type == TORE)
		t = ft_resolve_tore(prim, ray, origin);
	else if (prim->type == TRIANGLE)
		t = ft_resolve_triangle(prim, ray, origin);
	return (t);
}

void	ft_resolve_prim(t_prim *prim, t_3dpt *ray_dir, t_3dpt *origin)
{
	while (prim != NULL)
	{
		prim->t = ft_return_prim_dist(prim, ray_dir, origin);
		if (prim->t > 0)
		{
			ft_calculate_vec_end(&(prim->p), origin,
											ray_dir, prim->t);
			ft_calculate_normal(prim, &(prim->p));
		}
		prim = prim->next;
	}
}
