/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_direct_light.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfavart <tfavart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 15:34:51 by tfavart           #+#    #+#             */
/*   Updated: 2018/04/27 09:01:34 by kjalloul         ###   ########.fr       */
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

void			ft_resolve_light(t_light *light, t_ray *ray, t_cam *cam)
{
	light->t = -1;
	while (light != NULL)
	{
		if (light->type == LIGHT)
		{
			light->prim.sphere.origin.x = light->origin.x;
			light->prim.sphere.origin.y = light->origin.y;
			light->prim.sphere.origin.z = light->origin.z;
			light->t = ft_resolve_sphere(&(light->prim),
									&(ray->dir), &(cam->origin));
		}
		light = light->next;
	}
}
