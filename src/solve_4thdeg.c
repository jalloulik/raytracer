#include "rtv1.h"

#define PI          3.14159265358979323846

/* epsilon surrounding for near zero values */

#define     EQN_EPS     1e-9
#define	    IsZero(x)	((x) > -EQN_EPS && (x) < EQN_EPS)

#ifdef NOCBRT
#define     cbrt(x)     ((x) > 0.0 ? pow((double)(x), 1.0/3.0) : \
                          ((x) < 0.0 ? -pow((double)-(x), 1.0/3.0) : 0.0))
#endif

double search_min(double num[4], double nb)
{
	double	min;
	int		i;

	if (!nb)
		return (0);
	i = 0;
	min = num[0];
	if (i < nb)
	{
		if (num[i] < min && num[i] > 0)
			min = num[i];
		i++;
	}
	return (min);
}
static int	solve_linear(double a, double b, double *r)
{
	if (a == 0.)
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
	if (a[2] == 0.)
		return (solve_linear(a[1], a[0], &r[0]));
	if (d > 0)
	{
		if (a[1] == 0.)
		{
			s = fabs(0.5 * sqrt(d) / a[0]);
			*r = -s;
			r[1] = s;
		}
		else
			fill_roots(a, d, r);
		return (2);
	}
	else if (d == 0.)
	{
		r[0] = -0.5 * a[1] / a[2];
		r[1] = r[0];
		return (2);
	}
	return (0);
}

int SolveQuadric(c, s)
    double c[ 3 ];
    double s[ 2 ];
{
    double p, q, D;

    /* normal form: x^2 + px + q = 0 */

    p = c[ 1 ] / (2 * c[ 2 ]);
    q = c[ 0 ] / c[ 2 ];

    D = p * p - q;

    if (IsZero(D))
    {
	s[ 0 ] = - p;
	return 1;
    }
    else if (D < 0)
    {
	return 0;
    }
    else /* if (D > 0) */
    {
	double sqrt_D = sqrt(D);

	s[ 0 ] =   sqrt_D - p;
	s[ 1 ] = - sqrt_D - p;
	return 2;
    }
}


int SolveCubic(c, s)
    double c[ 4 ];
    double s[ 3 ];
{
    int     i, num;
    double  sub;
    double  A, B, C;
    double  sq_A, p, q;
    double  cb_p, D;

    /* normal form: x^3 + Ax^2 + Bx + C = 0 */

    A = c[ 2 ] / c[ 3 ];
    B = c[ 1 ] / c[ 3 ];
    C = c[ 0 ] / c[ 3 ];

    /*  substitute x = y - A/3 to eliminate quadric term:
	x^3 +px + q = 0 */

    sq_A = A * A;
    p = 1.0/3 * (- 1.0/3 * sq_A + B);
    q = 1.0/2 * (2.0/27 * A * sq_A - 1.0/3 * A * B + C);

    /* use Cardano's formula */

    cb_p = p * p * p;
    D = q * q + cb_p;

    if (IsZero(D))
    {
	if (IsZero(q)) /* one triple solution */
	{
	    s[ 0 ] = 0;
	    num = 1;
	}
	else /* one single and one double solution */
	{
	    double u = cbrt(-q);
	    s[ 0 ] = 2 * u;
	    s[ 1 ] = - u;
	    num = 2;
	}
    }
    else if (D < 0) /* Casus irreducibilis: three real solutions */
    {
	double phi = 1.0/3 * acos(-q / sqrt(-cb_p));
	double t = 2 * sqrt(-p);

	s[ 0 ] =   t * cos(phi);
	s[ 1 ] = - t * cos(phi + PI / 3);
	s[ 2 ] = - t * cos(phi - PI / 3);
	num = 3;
    }
    else /* one real solution */
    {
	double sqrt_D = sqrt(D);
	double u = cbrt(sqrt_D - q);
	double v = - cbrt(sqrt_D + q);

	s[ 0 ] = u + v;
	num = 1;
    }

    /* resubstitute */

    sub = 1.0/3 * A;

    for (i = 0; i < num; ++i)
	s[ i ] -= sub;

    return num;
}


double	SolveQuartic(c, s)
    double c[ 5 ]; 
    double s[ 4 ];
{
    double  coeffs[ 4 ];
    double  z, u, v, sub;
    double  A, B, C, D;
    double  sq_A, p, q, r;
    int     i, num;

    /* normal form: x^4 + Ax^3 + Bx^2 + Cx + D = 0 */

    A = c[ 1 ] / c[ 0 ];
    B = c[ 2 ] / c[ 0 ];
    C = c[ 3 ] / c[ 0 ];
    D = c[ 4 ] / c[ 0 ];

    /*  substitute x = y - A/4 to eliminate cubic term:
	x^4 + px^2 + qx + r = 0 */

    sq_A = A * A;
    p = - 3.0/8 * sq_A + B;
    q = 1.0/8 * sq_A * A - 1.0/2 * A * B + C;
    r = - 3.0/256*sq_A*sq_A + 1.0/16*sq_A*B - 1.0/4*A*C + D;

    if (IsZero(r))
    {
	/* no absolute term: y(y^3 + py + q) = 0 */

	coeffs[ 0 ] = q;
	coeffs[ 1 ] = p;
	coeffs[ 2 ] = 0;
	coeffs[ 3 ] = 1;

	num = SolveCubic(coeffs, s);

	s[ num++ ] = 0;
    }
    else
    {
	/* solve the resolvent cubic ... */

	coeffs[ 0 ] = 1.0/2 * r * p - 1.0/8 * q * q;
	coeffs[ 1 ] = - r;
	coeffs[ 2 ] = - 1.0/2 * p;
	coeffs[ 3 ] = 1;

	(void) SolveCubic(coeffs, s);

	/* ... and take the one real solution ... */

	z = s[ 0 ];

	/* ... to build two quadric equations */

	u = z * z - r;
	v = 2 * z - p;

	if (IsZero(u))
	    u = 0;
	else if (u > 0)
	    u = sqrt(u);
	else
	    return 0;

	if (IsZero(v))
	    v = 0;
	else if (v > 0)
	    v = sqrt(v);
	else
	    return 0;

	coeffs[ 0 ] = z - u;
	coeffs[ 1 ] = q < 0 ? -v : v;
	coeffs[ 2 ] = 1;

	num = SolveQuadric(coeffs, s);

	coeffs[ 0 ]= z + u;
	coeffs[ 1 ] = q < 0 ? v : -v;
	coeffs[ 2 ] = 1;

	num += SolveQuadric(coeffs, s + num);
    }

    /* resubstitute */

    sub = 1.0/4 * A;

    for (i = 0; i < num; ++i)
	s[ i ] -= sub;
	printf ("ok\n");
    return num;
}
