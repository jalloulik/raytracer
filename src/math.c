#include "rtv1.h"
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
		p2->x = p1->x;

	}
	if (p1->y > p2->y)
	{
		tmp = p1->y;
		p1->y = p2->y;
		p2->y = p1->y;
	}
	if (p1->z > p2->z)
	{
		tmp = p1->z;
		p1->z = p2->z;
		p2->z = p1->z;
	}
}

static double	find_d(double nb1, double nb2, double t[2], t_cut *cut)
{
	if (nb1 < nb2)
	{
		if (cut->c1 > nb1 && cut->c1 < nb2)
			return ((cut->c1 - nb1) / (nb2 - nb1) * (t))
	}
	if (nb1 > nb2)
	{
		if (cut->c1 > nb1 && cut->c1 < nb2)
			return ((cut->c1 - nb1) / (nb2 - nb1))
	}
	return (-1);
}

static double	cut(t_3dpt *p1, t_3dpt *p2, double t[2], t_cut *cut)
{
	int	d1;
	int d2;
	int d3;

	d1 = find_d(p1->x, p2->x, cut);
		if (d1 < 0)
			return (-1);
	d2 = find_d(p1->y, p2->y, cut);
	if (d2 < 0)
			return (-1);
	d3 = find_d(p1->z, p2->z, cut);
	if (d3 < 0)
			return (-1);
	if (d2 < d1)
	{
		d1 = d2;
		if (d3 < d2)
			d1 = d3;
	}
	return (d1);
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
	if (!p->)
		return (t[0]);
	p1 = calc_point(pos, dir, t[0]);
	p2 = calc_point(pos, dir, t[1]);
	free(p1);
	free(p2);
}
