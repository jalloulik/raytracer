/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_4thdeg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvillepo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 22:21:54 by yvillepo          #+#    #+#             */
/*   Updated: 2018/06/25 19:36:56 by yvillepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int			fill_result(double *s, double *param, int num)
{
	double	sub;
	int		i;

	sub = 1.0 / 4 * param[0];
	i = 0;
	while (i < num)
	{
		s[i] -= sub;
		i++;
	}
	return (num);
}

int			solve_2nd(double c[3], double s[2])
{
	double p;
	double q;
	double d;

	p = c[1] / (2 * c[2]);
	q = c[0] / c[2];
	d = p * p - q;
	if (d > -1e-9 && d < 1e-9)
	{
		s[0] = -p;
		return (1);
	}
	else if (d < 0)
		return (0);
	else
	{
		s[0] = sqrt(d) - p;
		s[1] = -sqrt(d) - p;
		return (2);
	}
}

int			epure_4th(double *coeffs, double *s, t_3dpt *pqr)
{
	int		num;
	t_3dpt	zuv;

	coeffs[0] = 1.0 / 2 * pqr->z * pqr->x - 1.0 / 8 * pqr->y * pqr->y;
	fill_tab(coeffs + 1, -pqr->z, -1.0 / 2 * pqr->x, 1);
	solve_cubic(coeffs, s);
	ft_set_3dpt(&zuv, s[0], s[0] * s[0] - pqr->z, 2 * s[0] - pqr->x);
	if (zuv.y > -1e-9 && zuv.y < 1e-9)
		zuv.y = 0;
	else if (zuv.y > 0)
		zuv.y = sqrt(zuv.y);
	else
		return (-1);
	if (zuv.z > -1e-9 && zuv.z < 1e-9)
		zuv.z = 0;
	else if (zuv.z > 0)
		zuv.z = sqrt(zuv.z);
	else
		return (-1);
	fill_tab(coeffs, zuv.x - zuv.y, pqr->y < 0 ? -zuv.z : zuv.z, 1);
	num = solve_2nd(coeffs, s);
	coeffs[1] = pqr->y < 0 ? zuv.z : -zuv.z;
	num += solve_2nd(coeffs, s + num);
	return (num);
}

int			solve_quartic(double c[5], double s[4])
{
	double	coeffs[4];
	double	param[4];
	t_3dpt	pqr;
	int		num;

	fill_tab(param, c[1] / c[0], c[2] / c[0], c[3] / c[0]);
	param[3] = c[4] / c[0];
	pqr.x = -3.0 / 8 * param[0] * param[0] + param[1];
	pqr.y = 1.0 / 8 * param[0] * param[0] * param[0] - 1.0 / 2
		* param[0] * param[1] + param[2];
	pqr.z = -3.0 / 256 * pow(param[0], 4) + 1.0 / 16 * param[0] * param[0] *
		param[1] - 1.0 / 4 * param[0] * param[2] + param[3];
	if (pqr.z > -1e-9 && pqr.z < 1e-9)
	{
		fill_tab(coeffs, pqr.y, pqr.x, 0);
		coeffs[3] = 1;
		num = solve_cubic(coeffs, s);
		s[num++] = 0;
	}
	else
	{
		if ((num = epure_4th(coeffs, s, &pqr)) == -1)
			return (0);
	}
	return (fill_result(s, param, num));
}
