#include "rtv1.h"

static	double calc_param(t_prim *prim, double res[5], t_3dpt *pos, t_3dpt *dir)
{
	t_tore		*tore = NULL;
	t_3dpt		tmp;	
	double		rr;

	tore = &(prim->tore);
	rr = 4 * tore->r1 * tore->r1;
	tmp.x = v_scale(dir, dir);
	tmp.y = 2 * v_scale(dir, pos); 
	tmp.z = v_scale(pos, pos) + tore->r1 * tore->r1 - tore->r2 * tore->r2;
	res[0] = tmp.x * tmp.x;
	res[1] = 2 * tmp.x * tmp.y;  
	res[2] = pow(tmp.y, 2) + 2 * tmp.x * tmp.z -
		((dir->x * dir->x + dir->y * dir->y) * rr); 
	res[3] = 2 * tmp.y * tmp.z - (2 * (dir->x * pos->x + dir->y * pos->y) * rr);
	res[4] = pow(tmp.z, 2) -((pos->x * pos->x + pos->y * pos->y) * rr);
	return (0);
}

double	ft_resolve_tore(t_prim *prim, t_3dpt *dir, t_3dpt *origin)
{
	t_tore	*tore = NULL;
	t_3dpt	dir_local;
	t_3dpt	pos_local;
	double	s[4];
	double	r[5];
	int		nb_sol;
	double	t;

	tore = &(prim->tore);
	ft_vec_quater_rot(&dir_local, dir, &(prim->g_to_l_rot));
	ft_normalize_vector(&dir_local);
	ft_swap_g_to_l(&pos_local, origin, &(prim->g_to_l_move),
													&(prim->g_to_l_rot));
	
	calc_param(prim,  r, &pos_local, &dir_local);
	nb_sol = SolveQuartic(r, s);
	if (!nb_sol)
		return (-1);
	t = search_min(s, nb_sol);
	tore->l_p = calc_point(&pos_local, &dir_local, t);
	return (t);
}
/*
void	ft_cylinder_normal(t_prim *prim, t_3dpt *p)
{
	double	dist;
	t_3dpt	local_p;
	t_3dpt	global_o;

	dist = SQR(ft_calculate_dist(&(prim->cyl.origin), p)) -
														SQR(prim->cyl.radius);
	if (dist >= 0)
		dist = sqrt(dist);
	prim->cyl.o.x = prim->cyl.origin_local.x + dist * prim->cyl.vec_local.x;
	prim->cyl.o.y = prim->cyl.origin_local.y + dist * prim->cyl.vec_local.y;
	prim->cyl.o.z = prim->cyl.origin_local.z + dist * prim->cyl.vec_local.z;
	ft_swap_g_to_l(&local_p, p,
									&(prim->g_to_l_move), &(prim->g_to_l_rot));
	if (local_p.y < prim->cyl.origin_local.y)
		prim->cyl.o.y = prim->cyl.origin_local.y +
											dist * -1 * prim->cyl.vec_local.y;
	else if (local_p.y == prim->cyl.origin_local.y)
		ft_set_3dpt(&(prim->cyl.o), prim->cyl.origin_local.x,
							prim->cyl.origin_local.y, prim->cyl.origin_local.z);
	ft_swap_l_to_g(&global_o, &(prim->cyl.o),
									&(prim->l_to_g_move), &(prim->l_to_g_rot));
	ft_set_3dpt(&(prim->cyl.o), global_o.x, global_o.y, global_o.z);
	ft_calculate_vector(&(prim->normal), &(prim->cyl.o), p);
}*/

void	ft_tore_normal(t_prim *prim, t_3dpt *p)
{
	t_3dpt	o;

	o.x = prim->tore.l_p->x;
	if (o.x < 0)
		o.x = -o.x;
	o.y = prim->tore.l_p->y;
	o.z = 0;
	ft_normalize_vector(&o);
	o.x *= prim->tore.r1;
	o.y *= prim->tore.r1;
	prim->normal.x = prim->tore.l_p->x - o.x;
	prim->normal.y = prim->tore.l_p->y - o.y;
	prim->normal.x = prim->tore.l_p->z;
	free(prim->tore.l_p);
}
