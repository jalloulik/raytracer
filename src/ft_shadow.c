/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shadow.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjalloul <kjalloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 16:00:08 by kjalloul          #+#    #+#             */
/*   Updated: 2018/05/31 17:20:27 by kjalloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		ft_check_obst(t_3dpt *o, t_3dpt *p_to_light, t_prim *obst, double dist)
{
	double	t;

	t = ft_return_prim_dist(obst, p_to_light, o);
	if (t >= 0 && t < dist)
		return (0);
	else
		return (1);
}

void	ft_resolve_single_prim(t_prim *prim, t_3dpt *ray_dir, t_3dpt *origin)
{
	double t;

	t = ft_return_prim_dist(prim, ray_dir, origin);
	if (t > 0)
	{
		ft_calculate_vec_end(&(prim->p), origin,
										ray_dir, t);
		ft_calculate_normal(prim, &(prim->p));
	}
}

void	ft_shad_rfrct(t_prim *prim, t_prim *small, t_color *clr, t_3dpt *p_to_l)
{
	if (prim->textur.valid == TRUE)
	{
		ft_resolve_single_prim(prim, p_to_l, &(small->p));
		prim->color2 = ft_get_sphere_texture(prim);
		ft_shadow_texture(clr, &(prim->color2));
	}
}

double	ft_shadow_percent(t_obj *obj, t_prim *small, int *lit, t_color *color)
{
	double	dist_to_light;
	t_3dpt	p_to_light;
	t_prim	*prim;
	double	percentage;

	percentage = 1;
	prim = obj->prim;
	dist_to_light = ft_get_dist_to_light(obj, small);
	ft_calculate_vec_to_light(&p_to_light, obj, small);
	while (prim != NULL)
	{
		if (prim != small)
		{
			*lit = ft_check_obst(&(small->p), &p_to_light, prim, dist_to_light);
			if (*lit == 0)
			{
				if (prim->refractive == 1)
				{
					percentage = (percentage + (1 - prim->refract_ratio)) / 2;
					ft_shad_rfrct(prim, small, color, &p_to_light);
				}
				else
					percentage = (percentage + (1)) / 2;
			}
		}
		prim = prim->next;
	}
	return (percentage);
}
