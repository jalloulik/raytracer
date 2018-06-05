/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve_tore.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvillepo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 17:51:12 by yvillepo          #+#    #+#             */
/*   Updated: 2018/06/05 18:10:51 by yvillepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static	double	calc_param(t_prim *prim, double res[5],
		t_3dpt *pos, t_3dpt *dir)
{
	t_tore		*tore;
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
	res[4] = pow(tmp.z, 2) - ((pos->x * pos->x + pos->y * pos->y) * rr);
	return (0);
}

double			ft_resolve_tore(t_prim *prim, t_3dpt *dir, t_3dpt *origin)
{
	t_3dpt	dir_local;
	t_3dpt	pos_local;
	double	s[4];
	double	r[5];
	double	t;

	ft_vec_quater_rot(&dir_local, dir, &(prim->g_to_l_rot));
	ft_normalize_vector(&dir_local);
	ft_swap_g_to_l(&pos_local, origin, &(prim->g_to_l_move),
													&(prim->g_to_l_rot));
	calc_param(prim, r, &pos_local, &dir_local);
	if (!(t = solve_quartic(r, s)))
		return (-1);
	t = search_min(s, t);
	prim->tore.l_p = calc_point(&pos_local, &dir_local, t);
	return (t);
}

void			ft_tore_normal(t_prim *prim, t_3dpt *p)
{
	t_3dpt	o;

	o.x = prim->tore.l_p->x;
	o.y = prim->tore.l_p->y;
	o.z = 0;
	ft_normalize_vector(&o);
	o.x *= prim->tore.r1;
	o.y *= prim->tore.r1;
	prim->normal.x = prim->tore.l_p->x - o.x;
	prim->normal.y = prim->tore.l_p->y - o.y;
	prim->normal.z = prim->tore.l_p->z;
	ft_normalize_vector(&prim->normal);
	ft_swap_l_to_g(&(prim->normal), &(prim->normal),
									&(prim->l_to_g_move), &(prim->l_to_g_rot));
	free(prim->tore.l_p);
}
