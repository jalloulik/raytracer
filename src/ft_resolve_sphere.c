/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve_sphere.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjalloul <kjalloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 17:28:34 by kjalloul          #+#    #+#             */
/*   Updated: 2018/06/08 19:08:17 by yvillepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void	ft_get_abcdet(t_sphere *sphere, t_3dpt *dir, t_3dpt *ray_origin)
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

double		ft_resolve_sphere(t_prim *prim, t_3dpt *dir, t_3dpt *ray_origin)
{
	t_sphere	*sphere;
	double		t[6];

	sphere = &(prim->sphere);
	ft_get_abcdet(sphere, dir, ray_origin);
	if (sphere->det >= 0)
	{
		if (sphere->a == 0)
			sphere->a = sphere->a + 0.000000000000001;
		t[2] = (-1 * (sphere->b) - sqrt(sphere->det)) / (2.0 * sphere->a);
		t[3] = (-1 * (sphere->b) + sqrt(sphere->det)) / (2.0 * sphere->a);
		if (sphere->t2 < 0)
			return (-1);
		prim->isvalid = 1;
	}
	else
		return (-1);
	if (!(prim->cut.enable))
		return (t[2]);
	cut(&(prim->cut), ray_origin, dir, t);
	return (t[4]);
}

