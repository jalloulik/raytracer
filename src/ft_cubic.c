/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cubic.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvillepo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 19:26:51 by yvillepo          #+#    #+#             */
/*   Updated: 2018/06/25 19:35:11 by yvillepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void		solve_3(double s[3], double p_q[2], double *tmp)
{
	double phi;
	double t;

	phi = 1.0 / 3 * acos(-p_q[1] / sqrt(-tmp[0]));
	t = 2 * sqrt(-p_q[0]);
	s[0] = t * cos(phi);
	s[1] = -t * cos(phi + FT_PI / 3);
	s[2] = -t * cos(phi - FT_PI / 3);
}

static void		epur_cubic(double s[3], int *num, double p_q[2], double tmp[2])
{
	if (tmp[1] > -1e-9 && tmp[1] < 1e-9)
	{
		if (p_q[1] > -1e-9 && p_q[1] < 1e-9)
		{
			s[0] = 0;
			*num = 1;
		}
		else
		{
			s[0] = 2 * cbrt(-p_q[1]);
			s[1] = -cbrt(-p_q[1]);
			*num = 2;
		}
	}
	else if (tmp[1] < 0)
	{
		solve_3(s, p_q, tmp);
		*num = 3;
	}
	else
	{
		s[0] = cbrt(sqrt(tmp[1]) - p_q[1]) - cbrt(sqrt(tmp[1]) + p_q[1]);
		*num = 1;
	}
}

int				solve_cubic(double c[4], double s[3])
{
	int		i;
	int		num;
	double	pa[3];
	double	p_q[2];
	double	tmp[2];

	fill_tab(pa, c[2] / c[3], c[1] / c[3], c[0] / c[3]);
	p_q[0] = 1.0 / 3 * (-1.0 / 3 * pa[0] * pa[0] + pa[1]);
	p_q[1] = 1.0 / 2 * (2.0 / 27 * pa[0] * pa[0] * pa[0] -
			1.0 / 3 * pa[0] * pa[1] + pa[2]);
	tmp[0] = p_q[0] * p_q[0] * p_q[0];
	tmp[1] = p_q[1] * p_q[1] + tmp[0];
	tmp[0] = 1.0 / 3 * pa[0];
	epur_cubic(s, &num, p_q, tmp);
	i = 0;
	while (i < num)
		s[i++] -= tmp[0];
	return (num);
}
