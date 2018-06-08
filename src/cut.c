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
	vect->x = ft_atoi(tab[0]);
	vect->y = ft_atoi(tab[1]);
	vect->z = ft_atoi(tab[2]);
	ft_free_tab(tab);
}

int				read_cut(char **tab, t_prim **prims)
{
	t_prim	*last;
	t_prim	*list;

	list = *prims;
	list = ft_add_lst_file(list, PLANE);
	*prims = list;
	last = ft_get_last(list);
	last->cut.enable = 0;
	if (!tab[1] || !ft_strequ(tab[1], "cut"))
		return (0);

	read_vect2(tab[2], &(last->cut.pos));
	read_vect2(tab[3], &(last->cut.dir));
	last->cut.d = -v_scale(&(last->cut.pos), &(last->cut.dir));
	last->cut.enable = 1;
	return (1);
}

