/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   carre.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvillepo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 20:24:41 by yvillepo          #+#    #+#             */
/*   Updated: 2018/05/03 21:09:14 by yvillepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static	double	ft_carre(t_carre carre, t_3dpt inter)
{
	if (p
}

double	ft_resolve_carre(t_prim *prim, t_3dpt *dir, t_3dpt *origin)
{
	t_3dpt	dir_local;
	t_3dpt	origin_local;

	ft_vec_quater_rot(&dir_local, dir, &(prim->g_to_l_rot));
	ft_normalize_vector(&dir_local);
	ft_swap_g_to_l(&origin_local, origin, &(prim->g_to_l_move),
													&(prim->g_to_l_rot));

}

double	ft_resolve_cyl(t_prim *prim, t_3dpt *dir, t_3dpt *origin)
{
	t_cyl	*cyl;
	t_3dpt	dir_local;
	t_3dpt	origin_local;

	cyl = &(prim->cyl);
	ft_vec_quater_rot(&dir_local, dir, &(prim->g_to_l_rot));
	ft_normalize_vector(&dir_local);
	ft_swap_g_to_l(&origin_local, origin, &(prim->g_to_l_move),
													&(prim->g_to_l_rot));
	ft_get_abcdet_cyl(cyl, &dir_local, &origin_local);
	if (cyl->det >= 0)
	{
		if (cyl->a == 0)
			cyl->a = cyl->a + 0.000000000000001;
		cyl->t1 = (-1 * (cyl->b) + sqrt(cyl->det)) / (2.0 * cyl->a);
		cyl->t2 = (-1 * (cyl->b) - sqrt(cyl->det)) / (2.0 * cyl->a);
		prim->isvalid = 1;
		if (cyl->t1 < cyl->t2 && cyl->t1 >= 0)
			return (cyl->t1);
		else if (cyl->t2 <= cyl->t1 && cyl->t2 >= 0)
			return (cyl->t2);
		else
			return (-1);
	}
	return (-1);
}
