/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cut.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvillepo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 16:13:36 by yvillepo          #+#    #+#             */
/*   Updated: 2018/06/14 02:36:41 by yvillepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void		read_vect2(char *str, t_3dpt *vect)
{
	char **tab;

	tab = ft_strsplit(str, ':');
	vect->x = ft_atof(tab[0]);
	vect->y = ft_atof(tab[1]);
	vect->z = ft_atof(tab[2]);
	ft_free_tab(tab);
}

int				read_cut(char **tab, t_prim *last)
{
	if (!tab[1] || !ft_strequ(tab[1], "cut"))
	{
		last->cut.enable = 0;
		last->cut.cut = 0;
		return (0);
	}
	last->cut.enable = 1;
	read_vect2(tab[2], &(last->cut.pos));
	if (last->type == SPHERE)
	{
		last->cut.pos.x += last->sphere.origin.x; 
		last->cut.pos.y += last->sphere.origin.y; 
		last->cut.pos.z += last->sphere.origin.z; 
	}
	read_vect2(tab[3], &(last->cut.dir));
	ft_normalize_vector(&(last->cut.dir));
	last->cut.d = -v_scale(&(last->cut.pos), &(last->cut.dir));
	if (last->type == SPHERE)
		last->cut.d0 = -v_scale(&(last->sphere.origin), &(last->cut.dir));
	else
		last->cut.d0 = 0;
	last->cut.cut = 0;
	return (1);
}

static int	choose_t2(double *t, t_3dpt *d1, t_3dpt *d2)
{
	if (v_scale(d1, d2) > 0)
	{
		if (t[0] < t[1] && t[0] < t[2])
		{
			t[3] = t[0];
			return (0);
		}
		t[3] = -1;
		return (0);
	}
	else
	{
		if (t[0] < t[1] && t[0] < t[2])
		{
			if (t[1] < t[2])
			{
				t[3] = -1;
				return (0);
			}
			t[3] = t[2];
			return (1);
		}
		t[3] = t[0];
		return (0);
	}
}

int			cut(t_cut *cut, t_3dpt *c_pos, t_3dpt *c_dir, double *t)
{
	t[2] = inter_plane(&cut->dir, cut->d, c_pos, c_dir);
	if (choose_t2(t, c_dir, &cut->dir))
		cut->cut = 1;
	return (1);
}
