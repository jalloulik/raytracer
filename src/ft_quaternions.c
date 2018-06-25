/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quaternions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjalloul <kjalloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 14:34:25 by kjalloul          #+#    #+#             */
/*   Updated: 2018/06/25 16:09:51 by kjalloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	ft_find_perpendicular_vec(t_3dpt *result, t_3dpt *source)
{
	if (source->z != 0)
	{
		result->x = 2;
		result->y = 2;
		result->z = (result->x * source->x + result->y * source->y) /
															(-1 * source->z);
	}
	else if (source->y != 0)
	{
		result->x = 2;
		result->z = 2;
		result->y = (result->x * source->x + result->z * source->z) /
															(-1 * source->y);
	}
	else if (source->x != 0)
	{
		result->y = 2;
		result->z = 2;
		result->x = (result->y * source->y + result->z * source->z) /
															(-1 * source->x);
	}
	ft_normalize_vector(result);
}

void	ft_find_quaters_between(t_quater *result, t_3dpt *start, t_3dpt *end)
{
	t_3dpt tmp;

	if (ft_calculate_dot(start, end) == -1)
		ft_find_perpendicular_vec(&tmp, start);
	else
		ft_cross_product(&tmp, start, end);
	result->w = 1 + ft_calculate_dot(start, end);
	result->x = tmp.x;
	result->y = tmp.y;
	result->z = tmp.z;
}

void	ft_vec_quater_rot(t_3dpt *result, t_3dpt *vec, t_quater *q1)
{
	t_quater q2;
	t_quater vec_tmp;
	t_quater tmp_res;
	t_quater tmp_res2;

	ft_quater_from_vec(&vec_tmp, vec);
	q2.w = q1->w;
	q2.x = -1 * q1->x;
	q2.y = -1 * q1->y;
	q2.z = -1 * q1->z;
	ft_normalize_quater(q1);
	ft_normalize_quater(&q2);
	ft_quater_mult(q1, &vec_tmp, &tmp_res);
	ft_quater_mult(&tmp_res, &q2, &tmp_res2);
	result->x = tmp_res2.x;
	result->y = tmp_res2.y;
	result->z = tmp_res2.z;
}

void	ft_quater_rot(t_3dpt *result, t_3dpt *source, t_3dpt *axe, double theta)
{
	t_quater h1;
	t_quater h2;
	t_quater tmp_src;
	t_quater tmp_res;
	t_quater tmp_res2;

	ft_quater_from_vec(&tmp_src, source);
	h1.w = cos(theta / 2);
	h1.x = axe->x * sin(theta / 2);
	h1.y = axe->y * sin(theta / 2);
	h1.z = axe->z * sin(theta / 2);
	h2.w = h1.w;
	h2.x = -1 * h1.x;
	h2.y = -1 * h1.y;
	h2.z = -1 * h1.z;
	ft_normalize_quater(&h1);
	ft_normalize_quater(&h2);
	ft_quater_mult(&h1, &tmp_src, &tmp_res);
	ft_quater_mult(&tmp_res, &h2, &tmp_res2);
	result->x = tmp_res2.x;
	result->y = tmp_res2.y;
	result->z = tmp_res2.z;
}
