/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_throw_rays.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjalloul <kjalloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 13:03:55 by kjalloul          #+#    #+#             */
/*   Updated: 2018/05/01 13:59:08 by kjalloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_prim	*ft_find_closest_exclude(t_prim *prim, t_prim *prev)
{
	t_prim *smallest;
	t_prim *start;

	smallest = NULL;
	start = prim;
	while (prim != NULL)
	{
		if (prim->t >= 0 && prim != prev)
		{
			smallest = prim;
			break ;
		}
		prim = prim->next;
	}
	prim = start;
	while (prim != NULL)
	{
		if (prim->t >= 0 && prim != prev)
		{
			if (prim->t < (smallest->t + 0.001))
				smallest = prim;
		}
		prim = prim->next;
	}
	return (smallest);
}

t_color		ft_trace_ray(t_obj *obj, t_3dpt *ray_dir, t_3dpt *origin, t_prim *prev)
{
	t_color point_color;
	t_color reflect_color;
	t_prim *base;

	g_limit++;
	ft_set_color(&reflect_color, 0, 0, 0);
	point_color = ft_throw_ray(obj, ray_dir, origin, prev);
	base = ft_find_closest_exclude(obj->prim, prev);
	if (base != NULL)
	{
		if (base->reflective == 1 && g_limit < 20)
		{
			t_3dpt light_reflect;
			t_3dpt	path_to_cam;
			double cam_dot;

			ft_calculate_vector(&path_to_cam, &(base->p), origin);
			cam_dot = ft_calculate_dot(&path_to_cam, &(base->normal));
			if (cam_dot >= 0 && cam_dot <= 1)
			{
				ft_calc_reflec_vec(&light_reflect, &(base->normal), &(base->p), origin);
				reflect_color = ft_trace_ray(obj, &light_reflect, &(base->p), base);
			}
		}
	}
	return (ft_combine_colors(&point_color, &reflect_color));
}
