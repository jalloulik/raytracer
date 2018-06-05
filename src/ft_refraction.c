/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_refraction.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjalloul <kjalloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 15:01:24 by kjalloul          #+#    #+#             */
/*   Updated: 2018/05/29 17:17:56 by kjalloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	ft_refract(t_3dpt *rslt, t_prim *base, t_3dpt *origin, t_3dpt *dir)
{
	t_3dpt	path_to_cam;
	double	costhetai;
	double	sinthetat;
	double	n[3];

	n[0] = 1;
	n[1] = VACUUM;
	n[2] = base->refraction_index;
	if (n[2] != 0)
		n[0] = n[1] / n[2];
	else
		ft_error("Index of refraction NULL");
	ft_calculate_vector(&path_to_cam, &(base->p), origin);
	costhetai = ft_calculate_dot(&path_to_cam, &(base->normal));
	sinthetat = SQR(n[0]) * (1 - SQR(costhetai));
	if ((sinthetat) > 1.0)
		ft_putendl("sinthetat total internal reflection");
	rslt->x = n[0] * dir->x + (n[0] * costhetai - sqrt(1 - (sinthetat)))
														* base->normal.x;
	rslt->y = n[0] * dir->y + (n[0] * costhetai - sqrt(1 - (sinthetat)))
														* base->normal.y;
	rslt->z = n[0] * dir->z + (n[0] * costhetai - sqrt(1 - (sinthetat)))
														* base->normal.z;
	ft_normalize_vector(rslt);
}
