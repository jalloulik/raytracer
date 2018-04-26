/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_if_lit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfavart <tfavart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 18:11:29 by kjalloul          #+#    #+#             */
/*   Updated: 2018/04/26 10:52:28 by tfavart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "rt_tf.h"

void	ft_get_shade(t_prim *prim, t_ray *ray, t_light *light)
{
	int		r;
	int		g;
	int		b;

	r = prim->color2.red * light->dotd * light->intensity + ray->color2.red;
	g = prim->color2.green * light->dotd * light->intensity + ray->color2.green;
	b = prim->color2.blue * light->dotd * light->intensity + ray->color2.blue;
	if (light->dotr >= 0 && light->dotr <= 1)
	{
		r = r + light->color.red * light->intensity * pow(light->dotr, HARD);
		g = g + light->color.green * light->intensity * pow(light->dotr, HARD);
		b = b + light->color.blue * light->intensity * pow(light->dotr, HARD);
	}
	if (r > 255)
		r = 255;
	if (g > 255)
		g = 255;
	if (b > 255)
		b = 255;
	ray->color2.red = (unsigned char)r;
	ray->color2.green = (unsigned char)g;
	ray->color2.blue = (unsigned char)b;
	ray->color2.alpha = 0;
}

int		ft_check_obst(t_3dpt *o, t_3dpt *p_to_light, t_prim *obst, double dist)
{
	double t;

	t = ft_return_prim_dist(obst, p_to_light, o);
	if (t >= 0 && t < dist)
		return (0);
	else
		return (1);
}

void	ft_get_dotr(t_prim *small, t_light *light, t_3dpt *p, t_ray *ray)
{
	t_3dpt	light_reflect;
	t_3dpt	p_to_cam;

	light_reflect.x = 2 * small->normal.x * light->dotd - p->x;
	light_reflect.y = 2 * small->normal.y * light->dotd - p->y;
	light_reflect.z = 2 * small->normal.z * light->dotd - p->z;
	ft_calculate_vector(&(p_to_cam), &(small->p), &(ray->cam->origin));
	light->dotr = ft_calculate_dot(&light_reflect, &p_to_cam);
}

void	ft_check_lit(t_prim *list, t_prim *small, t_light *light, t_ray *ray)
{
	t_3dpt	p_to_light;
	double	dist_to_light;
	int		lit;

	dist_to_light = ft_calculate_dist(&(small->p), &(light->origin));
	ft_calculate_vector(&(p_to_light), &(small->p), &(light->origin));
	while (list != NULL)
	{
		if (list != small)
		{
			lit = ft_check_obst(&(small->p), &p_to_light, list, dist_to_light);
			if (lit == 0)
				return ;
		}
		list = list->next;
	}
	if (light->type == LIGHT)
	{
		light->dotd = ft_calculate_dot(&p_to_light, &(small->normal));
		if (light->dotd >= 0 && light->dotd <= 1)
		{
			ft_get_dotr(small, light, &p_to_light, ray);
			ft_get_shade(small, ray, light);
		}
	}
	else if (light->type == AMBIANT)
		ft_get_ambiant(small, ray, light);
}
