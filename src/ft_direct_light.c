/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_direct_light.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfavart <tfavart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 15:34:51 by tfavart           #+#    #+#             */
/*   Updated: 2018/04/26 20:49:30 by tfavart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "rt_tf.h"
#include <stdio.h>

double			ft_test_smallest(t_light *light, t_prim *prim)
{
	while (light != NULL)
	{
		if (light->type == LIGHT)
		{
			if (prim != NULL)
			{
				while (prim != NULL)
				{
					if ((prim->t > light->t || prim->t < 0) && light->t >= 0)
						return (1);
					prim = prim->next;
				}
			}
			else
			{
				if (light->t >= 0)
					return (1);
			}
		}
		light = light->next;
	}
	return (0);
}

static void		ft_get_abcdet(t_sphere *sphere, t_3dpt *dir, t_3dpt *ray_origin)
{
	sphere->a = SQR(dir->x) + SQR(dir->y) + SQR(dir->z);
	sphere->b = 2.0 * (dir->x * (ray_origin->x - sphere->origin.x) +
		dir->y * (ray_origin->y - sphere->origin.y) + dir->z *
		(ray_origin->z - sphere->origin.z));
	sphere->c = SQR(ray_origin->x - sphere->origin.x) +
		SQR(ray_origin->y - sphere->origin.y) +
		SQR(ray_origin->z - sphere->origin.z) - SQR(sphere->radius);
	sphere->det = SQR(sphere->b) - (4.0 * sphere->a * sphere->c);
}

static double	ft_resolve(t_light *light, t_3dpt *dir, t_3dpt *ray_origin)
{
	t_sphere	*sphere;

	sphere = &(light->sphere);
	ft_get_abcdet(sphere, dir, ray_origin);
	if (sphere->det >= 0)
	{
		if (sphere->a == 0)
			sphere->a = sphere->a + 0.000000000000001;
		sphere->t1 = (-1 * (sphere->b) + sqrt(sphere->det)) / (2.0 * sphere->a);
		sphere->t2 = (-1 * (sphere->b) - sqrt(sphere->det)) / (2.0 * sphere->a);
		if (sphere->t1 < sphere->t2 && sphere->t1 >= 0)
			return (sphere->t1);
		else if (sphere->t2 <= sphere->t1 && sphere->t2 >= 0)
			return (sphere->t2);
		else
			return (-1);
	}
	return (-1);
}

void			ft_resolve_light(t_light *light, t_ray *ray, t_cam *cam)
{
	light->t = -1;
	while (light != NULL)
	{
		if (light->type == LIGHT)
		{
			light->sphere.origin.x = light->origin.x;
			light->sphere.origin.y = light->origin.y;
			light->sphere.origin.z = light->origin.z;
			light->t = ft_resolve(light, &(ray->dir), &(cam->origin));
		}
		light = light->next;
	}
}
