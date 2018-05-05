/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_refraction.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjalloul <kjalloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 15:01:24 by kjalloul          #+#    #+#             */
/*   Updated: 2018/05/03 20:03:43 by kjalloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	ft_refract(t_3dpt *result, t_prim *base, t_3dpt *origin, t_3dpt *dir)
{
	double n;
	t_3dpt	path_to_cam;
	double costhetai;
	double sinthetat;
	double n1;
	double n2;

	n = 1;
	n1 = VACUUM;
	n2 = base->refraction_index;
	if (n2 != 0)
		n = n1 / n2;
	else
		ft_error("Index of refraction NULL");
	ft_calculate_vector(&path_to_cam, &(base->p), origin);
	costhetai = ft_calculate_dot(&path_to_cam, &(base->normal));
	sinthetat = SQR(n) * (1 - SQR(costhetai));
	if ((sinthetat) > 1.0)
	{
		printf("sinthetat total internal reflection %f\n",sinthetat);
	}
	result->x = n * dir->x + (n * costhetai - sqrt(1 - (sinthetat))) * base->normal.x;
	result->y = n * dir->y + (n * costhetai - sqrt(1 - (sinthetat))) * base->normal.y;
	result->z = n * dir->z + (n * costhetai - sqrt(1 - (sinthetat))) * base->normal.z;
	ft_normalize_vector(result);
}
