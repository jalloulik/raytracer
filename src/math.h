#include "rtv1.h"

double	solv_2nd(t_3pt *deg2)
{
	double d;
	double res;

	d = deg2->y * deg2->y - 4 * deg2->x * deg2->z;
	if (d < 0)
		return (-1);
	res = (-deg2->y - sqrt(d)) / (2 * deg2->x);
	if (res < 0)
		res = (-deg2->y + sqrt(d)) / (2 * deg2->x);
	return (res);
}
