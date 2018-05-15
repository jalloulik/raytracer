#include "rtv1.h"

double	cardan(t_3dpt *p)
{

}

double	resolve4deg(t_quater *p, double e)
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
