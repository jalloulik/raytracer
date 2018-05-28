/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_if_lit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjalloul <kjalloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 18:11:29 by kjalloul          #+#    #+#             */
/*   Updated: 2018/05/28 16:23:38 by kjalloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "rt_tf.h"

int		ft_check_obst(t_3dpt *o, t_3dpt *p_to_light, t_prim *obst, double dist)
{
	double	t;

	t = ft_return_prim_dist(obst, p_to_light, o);
	if (t >= 0 && t < dist)
		return (0);
	else
		return (1);
}

void	ft_get_dotr(t_prim *small, t_light *light, t_3dpt *p, t_3dpt *origin)
{
	t_3dpt	light_reflect;
	t_3dpt	p_to_cam;

	light_reflect.x = 2 * small->normal.x * light->dotd - p->x;
	light_reflect.y = 2 * small->normal.y * light->dotd - p->y;
	light_reflect.z = 2 * small->normal.z * light->dotd - p->z;
	ft_calculate_vector(&(p_to_cam), &(small->p), origin);
	light->dotr = ft_calculate_dot(&light_reflect, &p_to_cam);
}

double	ft_get_dist_to_light(t_obj *obj, t_prim *small)
{
	double	dist_to_light;
	// t_3dpt	point;

	dist_to_light = 0;
	// if (obj->light->type == LIGHT)
	// {
	// 	dist_to_light = ft_calculate_dist(&(small->p), &(obj->light->origin));
	// }
	// else if (obj->light->type == SUN)
	// {
	// 	ft_set_3dpt(&point, 0, 0, 0);
	// 	dist_to_light = ft_calculate_dist(&point, &(obj->light->origin));
	// }
	dist_to_light = ft_calculate_dist(&(small->p), &(obj->light->origin));
	return (dist_to_light);
}

void	ft_calculate_vec_to_light(t_3dpt *p_to_light, t_obj *obj, t_prim *small)
{
	t_3dpt point;

	if (obj->light->type == LIGHT)
	{
		ft_calculate_vector(p_to_light, &(small->p), &(obj->light->origin));
	}
	else if (obj->light->type == SUN)
	{
		ft_set_3dpt(&point, 0, 0, 0);
		ft_calculate_vector(p_to_light, &point, &(obj->light->origin));
	}
}

void	ft_calc_reflec_vec(t_3dpt *result, t_3dpt *norm, t_3dpt *p, t_3dpt *src)
{
	t_3dpt	path_to_cam;
	double cam_dot;

	ft_calculate_vector(&path_to_cam, p, src);
	cam_dot = ft_calculate_dot(&path_to_cam, norm);
	if (cam_dot >= 0 && cam_dot <= 1)
	{
		if (result == NULL)
			ft_error("Vector is NULL");
		result->x = 2 * norm->x * cam_dot - path_to_cam.x;
		result->y = 2 * norm->y * cam_dot - path_to_cam.y;
		result->z = 2 * norm->z * cam_dot - path_to_cam.z;
		ft_normalize_vector(result);
	}
}

void	ft_check_lit(t_obj *obj, t_prim *small, t_color *color, t_3dpt *origin)
{
	t_3dpt	p_to_light;
	double	dist_to_light;
	int		lit;
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
			lit = ft_check_obst(&(small->p), &p_to_light, prim, dist_to_light);
			if (lit == 0)
			{
				if (prim->refractive == 1)
				{
					percentage = (percentage + (1 - prim->refract_ratio)) / 2;
				}
				else
					percentage = (percentage + (1)) / 2;
			}

		}
		prim = prim->next;
	}
	obj->light->dotd = ft_calculate_dot(&p_to_light, &(small->normal));
	if (obj->light->dotd >= 0 && obj->light->dotd <= 1)
	{
		ft_get_dotr(small, obj->light, &p_to_light, origin);
		ft_get_shade(small, color, obj->light);
	}
	if (lit == 0)
		ft_get_shadow(color, percentage);
}
