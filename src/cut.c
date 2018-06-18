/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cut.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvillepo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 16:13:36 by yvillepo          #+#    #+#             */
/*   Updated: 2018/06/18 10:50:29 by yvillepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void			read_one_cut(char **tab, t_prim *last, t_cut *cut)
{
	read_vect2(tab[1], &(cut->pos));
	cut->droit = 0;
	if (last->type == SPHERE)
	{
		cut->pos.x += last->sphere.origin.x;
		cut->pos.y += last->sphere.origin.y;
		cut->pos.z += last->sphere.origin.z;
	}
	read_vect2(tab[2], &(cut->dir));
	ft_normalize_vector(&(cut->dir));
	if (cut->dir.x == 1 || cut->dir.y == 1 || cut->dir.z == 1)
		cut->droit = 1;
	cut->d = -v_scale(&(cut->pos), &(cut->dir));
	cut->cut = 0;
	cut->next = 0;
}

int				read_cut(char **tab, t_prim *last)
{
	int		i;
	t_cut	*cut;

	if (!tab[0] || !ft_strequ(tab[0], "cut"))
	{
		last->cut = NULL;
		return (0);
	}
	last->cut = ft_malloc(sizeof(*(last->cut)));
	cut = last->cut;
	read_one_cut(tab, last, cut);
	i = 3;
	while (tab[i] && ft_strequ(tab[i], "cut"))
	{
		cut->next = ft_malloc(sizeof(*(last->cut)));
		cut = cut->next;
		read_one_cut(&tab[i], last, cut);
		i += 3;
	}
	return (i);
}

static int		choose_t(double *t, t_3dpt *d1, t_3dpt *d2)
{
	if (v_scale(d1, d2) > 0)
	{
		if (t[0] < t[1] && t[0] < t[2])
		{
			t[3] = t[0];
			return (2);
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
		return (2);
	}
}

static int		cut_one(t_cut *cut, t_cut *head, t_3dpt *cam[2], double *t)
{
	t[2] = inter_plane(&cut->dir, cut->d, cam[0], cam[1]);
	if (t[2] == -100000000000000)
	{
		if (cut->prec)
			t[3] = t[0];
		else
		{
			t[3] = -1;
			return (1);
		}
	}
	if ((cut->prec = choose_t(t, cam[1], &cut->dir)) == 1)
	{
		head->cut = 1;
		head->normal = &cut->dir;
	}
	if (t[3] == -1)
		return (1);
	t[0] = t[3];
	return (0);
}

void			cut(t_cut *cut, t_3dpt *c_pos, t_3dpt *c_dir, double *t)
{
	t_cut	*head;
	int		i;
	t_3dpt	*cam[2];

	i = 2;
	head = cut;
	head->cut = 0;
	cam[0] = c_pos;
	cam[1] = c_dir;
	while (i)
	{
		while (cut)
		{
			if ((i == 2 && !cut->droit) || (i == 1 && cut->droit))
			{
				if (cut_one(cut, head, cam, t))
					return ;
			}
			cut = cut->next;
		}
		cut = head;
		i--;
	}
	return ;
}
