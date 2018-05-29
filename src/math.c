#include "rtv1.h"
#include <stdio.h>
/*
double	cardan(t_3dpt *p)
{
	return (0);
}
*/
double			resolve4deg(t_quater *p, double e)
{
	t_3dpt	k;

	k.x = (-3 * p->y * p->y) / (8 * p->x * p->x) + p->z / p->x;
	k.y = pow(p->y / 2, 3) / pow (p->x, 3) -
		(0.5 * p->y * p->z) / (p->x * p->x) + p->y / p->x;
	k.z = -3 * pow((0.25 * p->y) / p->x, 4) +
		(p->z * pow((p->y / 4), 2)) / pow(p->x, 3) -
		0.25 * p->y * p->w / pow(p->x, 3) + e / p->x;
	return (-1);
}

void			trie(t_3dpt *p1, t_3dpt *p2)
{
	double	tmp;

	if (p1->x > p2->x)
	{
		tmp = p1->x;
		p1->x = p2->x;
		p2->x = tmp;

	}
	if (p1->y > p2->y)
	{
		tmp = p1->y;
		p1->y = p2->y;
		p2->y = tmp;
	}
	if (p1->z > p2->z)
	{
		tmp = p1->z;
		p1->z = p2->z;
		p2->z = tmp;
	}
}

static double	find_d(double nb1, double nb2, double c1, double c2, double t[2])
{
	if (nb1 < nb2)
	{
		printf("ok\n");
		if (c1 > nb1)
		{
			if (c1 < nb2)
				return ((c1 - nb1) * (t[1] - t[0]) / (nb2 - nb1) + t[0]);
			else
				return (-1);
		}
		else
		{
			if (c2 < nb1)
				return (-1);
			else if (c2 > nb1)
				return (t[0]);
		}
	}
	else
	{
		printf("ok2\n");
		if (c2 < nb1)
		{
			if (c2 > nb2)
				return (t[1]);
			else
				return (-1);
		}
		else
		{
			if (c1 > nb1)
				return (-1);
			else if (c1 < nb1)
				return (t[1]);
		}
	}
	return (-1);
}

static double	cut(t_3dpt *p1, t_3dpt *p2, double t[2], t_cut *cut)
{
	double	d1;
//	double	d2;
//	double	d3;

	d1 = find_d(p1->x, p2->x, cut->c1.x, cut->c2.x, t);
		if (d1 < 0)
			return (-1);
	return (d1);
	/*
	d2 = find_d(p1->y, p2->y, cut->c1.y, cut->c2.y);
	if (d2 < 0)
			return (-1);
	d3 = find_d(p1->z, p2->z, cut->c1.z, cut->c2.z);
	if (d3 < 0)
			return (-1);
	if (d2 < d1)
	{
		d1 = d2;
		if (d3 < d2)
			d1 = d3;
	}
	return (d1 * (t[2] - t[1]) + t[1]);*/
}


double			solv_seconde(t_prim *p, t_3dpt *param, t_3dpt *pos, t_3dpt *dir)
{
	double		d;
	double		t[2];
	t_3dpt		*p1;
	t_3dpt		*p2;

	d = param->y * param->y - 4 * param->x * param->z;
	if (d < 0)
		return (-1);
	if (param->x == 0)
		param->x = 0.000000000000001;
	t[0] = (-param->y - sqrt(d)) / (2 * param->x);
	t[1] = (-param->y + sqrt(d)) / (2 * param->x);
	if (!(p->cut))
		return (t[0]);
	p1 = calc_point(pos, dir, t[0]);
	p2 = calc_point(pos, dir, t[1]);
	t[0] = cut(p1, p2, t, p->cut);
	free(p1);
	free(p2);
	return (t[0]);
}
