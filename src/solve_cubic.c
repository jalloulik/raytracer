/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_cubic.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvillepo <yvillepo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/02 01:20:15 by yvillepo          #+#    #+#             */
/*   Updated: 2018/06/05 18:45:27 by kjalloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void		sol2(double tmp[12], double s[3], int *num)
{
	if (tmp[5] > -1e-9 && tmp[5] < 1e-9)
	{
		s[0] = 0;
		*num = 1;
	}
	else
	{
		s[0] = 2 * cbrt(-tmp[5]);
		s[1] = -cbrt(-tmp[5]);
		*num = 2;
	}
}

static void		sol3(double tmp[12], double s[3], int *num)
{
	double phi;
	double t;

	phi = 1.0 / 3 * acos(-tmp[5] / sqrt(-tmp[6]));
	t = 2 * sqrt(-tmp[4]);
	s[0] = t * cos(phi);
	s[1] = -t * cos(phi + FT_PI / 3);
	s[2] = -t * cos(phi - FT_PI / 3);
	*num = 3;
}

static void		sol1(double tmp[12], double s[3], int *num)
{
	tmp[9] = sqrt(tmp[7]);
	tmp[10] = cbrt(tmp[9] - tmp[5]);
	tmp[11] = -cbrt(tmp[9] + tmp[5]);
	s[0] = tmp[10] + tmp[11];
	*num = 1;
}

int				solve_cubic(double c[4], double s[3])
{
	int		i;
	int		num;
	double	tmp[12];

	tmp[0] = c[2] / c[3];
	tmp[1] = c[1] / c[3];
	tmp[2] = c[0] / c[3];
	tmp[3] = tmp[0] * tmp[0];
	tmp[4] = 1.0 / 3 * (-1.0 / 3 * tmp[3] + tmp[1]);
	tmp[5] = 1.0 / 2 * (2.0 / 27 * tmp[0] * tmp[3] - 1.0
			/ 3 * tmp[0] * tmp[1] + tmp[2]);
	tmp[6] = tmp[4] * tmp[4] * tmp[4];
	tmp[7] = tmp[5] * tmp[5] + tmp[6];
	if (tmp[7] > -1e-9 && tmp[7] < 1e-9)
		sol2(tmp, s, &num);
	else if (tmp[7] < 0)
		sol3(tmp, s, &num);
	else
		sol1(tmp, s, &num);
	tmp[8] = 1.0 / 3 * tmp[0];
	i = 0;
	while (i < num)
		s[i++] -= tmp[8];
	return (num);
}
