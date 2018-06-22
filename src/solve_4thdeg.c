/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_4thdeg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvillepo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 22:21:54 by yvillepo          #+#    #+#             */
/*   Updated: 2018/06/22 18:14:05 by yvillepo         ###   ########.fr       */
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

int SolveQuadric(double c[3], double s[2])
{
	double p, q, d;

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

void	solve_3(double s[3], double p_q[2], double *tmp)
{
		double phi = 1.0/3 * acos(-p_q[1] / sqrt(-tmp[0]));
		double t = 2 * sqrt(-p_q[0]);

		s[0] =   t * cos(phi);
		s[1] = - t * cos(phi + FT_PI / 3);
		s[2] = - t * cos(phi - FT_PI / 3);
}

int solve_cubic(double c[4], double s[3])
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


int		solve_quartic(double c[5], double s[4])
{
	double  coeffs[ 4 ];
	double  z, u, v, sub;
	double  A, B, C, D;
	double  sq_A, p, q, r;
	int     i, num;

	A = c[1] / c[0];
	B = c[2] / c[0];
	C = c[3] / c[0];
	D = c[4] / c[0];
	sq_A = A * A;
	p = - 3.0/8 * sq_A + B;
	q = 1.0/8 * sq_A * A - 1.0/2 * A * B + C;
	r = - 3.0/256*sq_A*sq_A + 1.0/16*sq_A*B - 1.0/4*A*C + D;
	if (r > -1e-9 && r < 1e-9)
	{
		coeffs[0] = q;
		coeffs[1] = p;
		coeffs[2] = 0;
		coeffs[3] = 1;
		num = solve_cubic(coeffs, s);
		s[num++] = 0;
	}
	else
	{
		coeffs[0] = 1.0/2 * r * p - 1.0/8 * q * q;
		coeffs[1] = - r;
		coeffs[2] = - 1.0/2 * p;
		coeffs[3] = 1;
		solve_cubic(coeffs, s);
		z = s[0];
		u = z * z - r;
		v = 2 * z - p;
		if (u > -1e-9 && u < 1e-9)
			u = 0;
		else if (u > 0)
			u = sqrt(u);
		else
			return 0;
		if (v > -1e-9 && v < 1e-9)
			v = 0;
		else if (v > 0)
			v = sqrt(v);
		else
			return 0;
		coeffs[0] = z - u;
		coeffs[1] = q < 0 ? -v : v;
		coeffs[2] = 1;
		num = SolveQuadric(coeffs, s);
		coeffs[0]= z + u;
		coeffs[1] = q < 0 ? v : -v;
		coeffs[2] = 1;
		num += SolveQuadric(coeffs, s + num);
	}
	sub = 1.0/4 * A;
	for (i = 0; i < num; ++i)
		s[i] -= sub;
	return num;
}
