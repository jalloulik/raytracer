/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_4thdeg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvillepo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 22:21:54 by yvillepo          #+#    #+#             */
/*   Updated: 2018/06/25 15:13:53 by yvillepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static int	solve_linear(double a, double b, double *r)
{
	if (a == 0)
		return (0);
	else
	{
		*r = -b / a;
		return (1);
	}
}

static void	fill_roots(double *a, double d, double *r)
{
	double sgnb;
	double temp;
	double r1;
	double r2;

	sgnb = (a[1] > 0 ? 1 : -1);
	temp = -0.5 * (a[1] + sgnb * sqrt(d));
	r1 = temp / a[2];
	r2 = a[0] / temp;
	if (r1 < r2)
	{
		r[0] = r1;
		r[1] = r2;
	}
	else
	{
		r[0] = r2;
		r[1] = r1;
	}
}

int			solve_quadratic(double *a, double r[2])
{
	double	d;
	double	s;

	d = a[1] * a[1] - 4 * a[2] * a[0];
	if (a[2] == 0)
		return (solve_linear(a[1], a[0], &r[0]));
	if (d > 0)
	{
		if (a[1] == 0)
		{
			s = fabs(0.5 * sqrt(d) / a[0]);
			*r = -s;
			r[1] = s;
		}
		else
			fill_roots(a, d, r);
		return (2);
	}
	else if (d == 0)
	{
		r[0] = -0.5 * a[1] / a[2];
		r[1] = r[0];
		return (2);
	}
	return (0);
}

int			SolveQuadric(double c[3], double s[2])
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
		s[0] =  sqrt(d) - p;
		s[1] = -sqrt(d) - p;
		return (2);
	}
}

void		solve_3(double s[3], double p_q[2], double *tmp)
{
		double phi;
		double t;

		phi = 1.0/3 * acos(-p_q[1] / sqrt(-tmp[0]));
		t = 2 * sqrt(-p_q[0]);	
		s[0] =   t * cos(phi);
		s[1] = - t * cos(phi + FT_PI / 3);
		s[2] = - t * cos(phi - FT_PI / 3);
}

int			solve_cubic(double c[4], double s[3])
{
	int     i, num;
	double  pa[3];
	double  p_q[2];
	double  tmp[3];

	
	pa[0] = c[2] / c[3];
	pa[1] = c[1] / c[3];
	pa[2] = c[0] / c[3];
	p_q[0] = 1.0/3 * (-1.0/3 * pa[0] * pa[0] + pa[1]);
	p_q[1] = 1.0/2 * (2.0/27 * pa[0] * pa[0] * pa[0] - 1.0/3 * pa[0] * pa[1] + pa[2]);
	tmp[0] = p_q[0] * p_q[0] * p_q[0];
	tmp[1] = p_q[1] * p_q[1] + tmp[0];
	if (tmp[1] > -1e-9 && tmp[1] < 1e-9)
	{
		if (p_q[1] > -1e-9 && p_q[1] < 1e-9)
		{
			s[0] = 0;
			num = 1;
		}
		else 
		{
			s[0] = 2 * cbrt(-p_q[1]);
			s[1] = -cbrt(-p_q[1]);
			num = 2;
		}
	}
	else if (tmp[1] < 0) 
	{
		solve_3(s, p_q, tmp);
		num = 3;
	}
	else 
	{
		s[0] = cbrt(sqrt(tmp[1]) - p_q[1]) - cbrt(sqrt(tmp[1]) + p_q[1]);
		num = 1;
	}
	tmp[0] = 1.0 / 3 * pa[0];
	i = 0;
	while (i < num)
		s[i++] -= tmp[0];
	return (num);
}


int			solve_quartic(double c[5], double s[4])
{
	double  coeffs[ 4 ];
	t_3dpt	zuv;
	double  param[4];
	t_3dpt	pqr;
	int     i, num;
	double	sub;

	param[0] = c[1] / c[0];
	param[1] = c[2] / c[0];
	param[2] = c[3] / c[0];
	param[3] = c[4] / c[0];
	pqr.x = - 3.0 / 8 * param[0] * param[0]  + param[1];
	pqr.y = 1.0 / 8 * param[0] * param[0] * param[0] - 1.0 / 2 * param[0] * param[1] + param[2];
	pqr.z = - 3.0/256 * pow(param[0], 4) + 1.0/16 * param[0] * param[0] *
		param[1] - 1.0 / 4 * param[0] * param[2] + param[3];
	if (pqr.z > -1e-9 && pqr.z < 1e-9)
	{
		coeffs[0] =  pqr.y;
		coeffs[1] =  pqr.x;
		coeffs[2] = 0;
		coeffs[3] = 1;
		num = solve_cubic(coeffs, s);
		s[num++] = 0;
	}
	else
	{
		coeffs[0] = 1.0/2 *  pqr.z *  pqr.x - 1.0/8 *  pqr.y *  pqr.y;
		coeffs[1] = -  pqr.z;
		coeffs[2] = - 1.0/2 *  pqr.x;
		coeffs[3] = 1;
		solve_cubic(coeffs, s);
		zuv.x = s[0];
		zuv.y = zuv.x * zuv.x -  pqr.z;
		zuv.z = 2 * zuv.x -  pqr.x;
		if (zuv.y > -1e-9 && zuv.y < 1e-9)
			zuv.y = 0;
		else if (zuv.y > 0)
			zuv.y = sqrt(zuv.y);
		else
			return 0;
		if (zuv.z > -1e-9 && zuv.z < 1e-9)
			zuv.z = 0;
		else if (zuv.z > 0)
			zuv.z = sqrt(zuv.z);
		else
			return 0;
		coeffs[0] = zuv.x - zuv.y;
		coeffs[1] = pqr.y  < 0 ? -zuv.z : zuv.z;
		coeffs[2] = 1;
		num = SolveQuadric(coeffs, s);
		coeffs[0] = zuv.x + zuv.y;
		coeffs[1] =  pqr.y < 0 ? zuv.z : -zuv.z;
		coeffs[2] = 1;
		num += SolveQuadric(coeffs, s + num);
	}
	sub = 1.0/4 * param[0];
	for (i = 0; i < num; ++i)
		s[i] -= sub;
	return num;
}
