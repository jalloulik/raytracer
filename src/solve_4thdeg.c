/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_4thdeg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvillepo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 22:21:54 by yvillepo          #+#    #+#             */
/*   Updated: 2018/06/02 03:15:19 by yvillepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static int	sol2(double c[3], double s[2])
{
	double	p;
	double	q;
	double	d;

	p = c[1] / (2 * c[2]);
	q = c[0] / c[2];
	d = p * p - q;
	if (d < 1e-9 && d > -1e-9)
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

static void	fill_coeff(double *coef, double a, double b, double c)
{
	coef[0] = a;
	coef[1] = b;
	coef[2] = c;
}

static void	solv0(double *tmp, double *s, int *num)
{
	double	coeffs[4];

	coeffs[0] = tmp[10];
	coeffs[1] = tmp[9];
	coeffs[2] = 0;
	coeffs[3] = 1;
	*num = solve_cubic(coeffs, s);
	s[(*num)++] = 0;
}

static int	solv1(double *tmp, double *s, int *num)
{
	double	coeffs[4];

	fill_coeff(coeffs, 1.0 / 2 * tmp[11] * tmp[9] - 1.0
			/ 8 * tmp[10] * tmp[10], -tmp[11], -1.0 / 2 * tmp[9]);
	coeffs[3] = 1;
	solve_cubic(coeffs, s);
	fill_coeff(tmp, s[0], s[0] * s[0] - tmp[11], 2 * s[0] - tmp[9]);
	if (tmp[1] > -1e-9 && tmp[1] < 1e-9)
		tmp[1] = 0;
	else if (tmp[1] > 0)
		tmp[1] = sqrt(tmp[1]);
	else
		return (0);
	if (tmp[2] > 1e-9 && tmp[2] < -1e-9)
		tmp[2] = 0;
	else if (tmp[2] > 0)
		tmp[2] = sqrt(tmp[2]);
	else
		return (0);
	fill_coeff(coeffs, tmp[0] - tmp[1], tmp[10] < 0 ? -tmp[2] : tmp[2], 1);
	*num = sol2(coeffs, s);
	fill_coeff(coeffs, tmp[0] + tmp[1], tmp[10] < 0 ? tmp[2] : -tmp[2], 1);
	num += sol2(coeffs, s + *num);
	return (1);
}

int			solve_quartic(double c[5], double s[4])
{
	double	tmp[12];
	int		i;
	int		num;

	tmp[4] = c[1] / c[0];
	tmp[5] = c[2] / c[0];
	tmp[6] = c[3] / c[0];
	tmp[7] = c[4] / c[0];
	tmp[8] = tmp[4] * tmp[4];
	tmp[9] = -3.0 / 8 * tmp[8] + tmp[5];
	tmp[10] = 1.0 / 8 * tmp[8] * tmp[4] - 1.0 / 2 * tmp[4] * tmp[5] + tmp[6];
	tmp[11] = -3.0 / 256 * tmp[8] * tmp[8] + 1.0 /
		16 * tmp[8] * tmp[5] - 1.0 / 4 * tmp[4] * tmp[6] + tmp[7];
	if (tmp[11] > -1e-9 && tmp[11] < 1e-9)
		solv0(tmp, s, &num);
	else
	{
		if (!solv1(tmp, s, &num))
			return (0);
	}
	tmp[3] = 1.0 / 4 * tmp[4];
	i = 0;
	while (i < num)
		s[i++] -= tmp[3];
	return (num);
}
