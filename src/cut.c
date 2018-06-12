/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cut.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvillepo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 16:13:36 by yvillepo          #+#    #+#             */
/*   Updated: 2018/06/08 17:01:37 by yvillepo         ###   ########.fr       */
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
	last->cut.d = -v_scale(&(last->cut.pos), &(last->cut.dir));
	if (last->type == SPHERE)
		last->cut.d0 = -v_scale(&(last->sphere.origin), &(last->cut.dir));
	else
		last->cut.d0 = 0;
	return (1);
}

static int	choose_t(double *t)
{
	if (t[0] == t[5] || t[1] == t[5])
	{
		if (t[0] < t[1] && t[1] < t[2])
			t[4] = -1;
		else
			t[4] = t[2];
		return (0);
	}
	else if (t[2] == t[5])
	{
		if (t[0] < t[1])
		{
			t[4] = t[2];
			return (0);
		}
		else if (t[3] < t[1] && t[3] < t[0] && t[1] < t[0])
		{
			t[4] = -1;
			return (0);
		}
		printf("oui\n");
		t[4] = t[1];
		return (1);
	}
	/*
	else if (t[2] < t[0])
	{
		t[4] = t[2];
		return (0);
	}
	else if (t[1] < t[0])
	{
	}
	*/
	return (0);
}

#include <stdio.h>

int			cut(t_cut *cut, t_3dpt *c_pos, t_3dpt *c_dir, double *t)
{
	t[0] = inter_plane(&cut->dir, cut->d0, c_pos, c_dir);
	t[1] = inter_plane(&cut->dir, cut->d, c_pos, c_dir);
	if (cut->d0 == cut->d)
	{
		if (t[2] > t[0])
		{
			t[4] = -1;
			return (0);
		}
		ft_putendl("ok");
		if (t[3] > t[0])
		{
			t[4] = t[0];
			return (1);
		}
		t[4] = t[2];
		return (0);
	}
	t[5] = t[3];
	t[5] = search_min(t, 4);
	printf ("%f %f %f %f %f\n", t[0], t[1], t[2], t[3], t[5]);
	if (choose_t(t))
		cut->cut = 1;
	return (1);
}
