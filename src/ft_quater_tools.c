/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quater_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjalloul <kjalloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 15:20:19 by kjalloul          #+#    #+#             */
/*   Updated: 2018/06/23 16:34:26 by kjalloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	ft_quater_mult(t_quater *first, t_quater *second, t_quater *result)
{
	result->w = (first->w * second->w - first->x * second->x -
								first->y * second->y - first->z * second->z);
	result->x = (first->w * second->x + first->x * second->w +
								first->y * second->z - first->z * second->y);
	result->y = (first->w * second->y - first->x * second->z +
								first->y * second->w + first->z * second->x);
	result->z = (first->w * second->z + first->x * second->y -
								first->y * second->x + first->z * second->w);
}

void	ft_normalize_quater(t_quater *source)
{
	double magnitude;

	magnitude = sqrt(SQR(source->w) + SQR(source->x) + SQR(source->y)
														+ SQR(source->z));
	if (magnitude == 0)
	{
		// ft_error(ERRDIV);
		magnitude = 0.00000000001;
	}
	source->w = source->w / magnitude;
	source->x = source->x / magnitude;
	source->y = source->y / magnitude;
	source->z = source->z / magnitude;
}

void	ft_quater_from_vec(t_quater *result, t_3dpt *source)
{
	result->w = 0;
	result->x = source->x;
	result->y = source->y;
	result->z = source->z;
}
