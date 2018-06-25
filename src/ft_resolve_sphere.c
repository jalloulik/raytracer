/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve_sphere.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjalloul <kjalloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 17:28:34 by kjalloul          #+#    #+#             */
/*   Updated: 2018/06/25 16:10:28 by kjalloul         ###   ########.fr       */
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
	double		t[4];
	t_3dpt		dir_local;
	t_3dpt		origin_local;

	sphere = &(prim->sphere);
	ft_get_abcdet(sphere, dir, ray_origin);
	if (sphere->det >= 0)
	{
		if (sphere->a == 0)
			sphere->a = sphere->a + 0.000000000000001;
		t[0] = (-1 * (sphere->b) - sqrt(sphere->det)) / (2.0 * sphere->a);
		t[1] = (-1 * (sphere->b) + sqrt(sphere->det)) / (2.0 * sphere->a);
		prim->isvalid = 1;
	}
	else
		return (-1);
	if (prim->cut == NULL)
		return (t[0]);
	ft_vec_quater_rot(&dir_local, dir, &(prim->g_to_l_rot));
	ft_normalize_vector(&dir_local);
	ft_swap_g_to_l(&origin_local, ray_origin, &(prim->g_to_l_move),
													&(prim->g_to_l_rot));
	cut(prim->cut, &origin_local, &dir_local, t);
	return (t[3]);
}
