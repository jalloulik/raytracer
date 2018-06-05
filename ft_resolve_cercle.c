/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve_cercle.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvillepo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 17:27:07 by yvillepo          #+#    #+#             */
/*   Updated: 2018/05/02 17:48:38 by yvillepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"


ray_origin cam_pos
dir			cam_dir


static void	ft_get_abc(t_cercle *cercle, t_3dpt *dir, t_3dpt *ray_origin)
{
	t_plane		*plane;

	plane->normal = cercle->dir;
	plane->point = cercle->pos;
	sphere->a = SQR(dir->x) + SQR(dir->y) + SQR(dir->z);
	sphere->b = 2.0 * (dir->x * (ray_origin->x - sphere->origin.x) +
		dir->y * (ray_origin->y - sphere->origin.y) + dir->z *
		(ray_origin->z - sphere->origin.z));
	sphere->c = SQR(ray_origin->x - sphere->origin.x) +
		SQR(ray_origin->y - sphere->origin.y) +
		SQR(ray_origin->z - sphere->origin.z) - SQR(sphere->radius);
	sphere->det = SQR(sphere->b) - (4.0 * sphere->a * sphere->c);
}

double		ft_resolve_sphere(t_prim *prim, t_3dpt *dir, t_3dpt *ray_origin)
{
	t_cercle	*cercle;

	cercle = &(prim->cercle);
	ft_get_abc(sphere, dir, ray_origin);
	if (sphere->det >= 0)
	{
		if (sphere->a == 0)
			sphere->a = sphere->a + 0.000000000000001;
		sphere->t1 = (-1 * (sphere->b) + sqrt(sphere->det)) / (2.0 * sphere->a);
		sphere->t2 = (-1 * (sphere->b) - sqrt(sphere->det)) / (2.0 * sphere->a);
		prim->isvalid = 1;
		if (sphere->t1 < sphere->t2 && sphere->t1 >= 0)
			return (sphere->t1);
		else if (sphere->t2 <= sphere->t1 && sphere->t2 >= 0)
			return (sphere->t2);
		else
			return (-1);
	}
	return (-1);
}
