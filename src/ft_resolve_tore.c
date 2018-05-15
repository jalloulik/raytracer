#include "rtv1.h"

static	double calc_param(t_prim *prim, t_quater *param, t_3dpt *pos, t_3dpt *dir)
{
	t_tore		*tore;
	t_3dpt		tmp;	
	double		rr;

	rr = 4 * tore->r1 * tore->r1;
	tore = &(prim->tore);
	tmp.x = pow(v_scale(dir, dir), 2);
	tmp.y = 2 * v_scale(dir, pos); 
	tmp.z = v_scale(pos, pos) + tore->r1 - tore->r2;
	param->x = tmp.x * tmp.x;
	param->y = 2 * tmp.x * tmp.y;  
	param->z = pow(tmp.y, 2) + 2 * tmp.x * tmp.z -
		(dir->x * dir->x + dir->y * dir->y + rr); 
	param->w = 2 * tmp.y * tmp.z - (2 * dir->x * pos->x + dir->y * pos->y + rr);
	return (pow(tmp.z, 2) -(pos->x * pos->x + pos->y * pos->y + rr));
}

double	ft_resolve_tore(t_prim *prim, t_3dpt *dir, t_3dpt *origin)
{
	t_tore	*tore;
	t_3dpt	dir_local;
	t_3dpt	pos_local;

	tore = &(prim->tore);
	ft_vec_quater_rot(&dir_local, dir, &(prim->g_to_l_rot));
	ft_normalize_vector(&dir_local);
	ft_swap_g_to_l(&pos_local, origin, &(prim->g_to_l_move),
													&(prim->g_to_l_rot));
	
	return (ft_resolve_t(tore, &dir_local, &pos_local));
}
