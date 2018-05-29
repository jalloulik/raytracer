/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvillepo <yvillepo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 19:01:34 by yvillepo          #+#    #+#             */
/*   Updated: 2018/05/29 19:30:54 by yvillepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "stdio.h"

void	read_vect(char *str, t_3dpt *vect)
{
	char **tab;

	tab = ft_strsplit(str, ':');
	if (ft_count_tab(tab) < 4)
	{
		printf ("%d",ft_count_tab(tab));
		exit (0);
	}
	vect->x = ft_atoi(tab[1]);	
	vect->y = ft_atoi(tab[2]);	
	vect->z = ft_atoi(tab[3]);	
	ft_free_tab(tab);
}
/*
static void	init_cut(t_cut *cut)
{
	cut->c1.x = -10000000;
	cut->c1.y = -10000000;
	cut->c1.z = -10000000;
	cut->c2.x = 10000000;
	cut->c2.y = 10000000;
	cut->c2.z = 10000000;
}

static double	read_val(char *str)
{
	if (ft_strequ(str, "+"))
		return (10000000);
	else if (ft_strequ(str, "-"))
		return (-10000000);
	else
		return (ft_atof(str));
}

void	read_cut(char *str, t_prim *prim)
{
	char **tab;

	tab = ft_strsplit(str, ':');
	if (ft_count_tab(tab) < 3)
		exit (0);
	if (ft_strcmp(tab[0], "x") == 0)
	{
		prim->cut->c1.x = read_val(tab[1]);
		prim->cut->c2.x = read_val(tab[2]);
	}
	else if (ft_strcmp(tab[0], "y") == 0)
	{
		prim->cut->c1.y = read_val(tab[1]);
		prim->cut->c2.y = read_val(tab[2]);
	}
	else if (ft_strcmp(tab[0], "z") == 0)
	{
		prim->cut->c1.z = read_val(tab[1]);
		prim->cut->c2.z = read_val(tab[2]);
	}
	else
		exit(0);
	ft_free_tab(tab);
}

void	read_all_cut(char **str, t_prim *prim)
{
	int		i;

	i = ft_count_tab(str);
	if (!(prim->cut = (malloc(sizeof(*(prim->cut))))))
		exit (-1);
	init_cut(prim->cut);
	print_cut(prim->cut);
	while (i--)
		read_cut(str[i], prim);
	print_cut(prim->cut);
	trie(&(prim->cut->c1), &(prim->cut->c2));
	print_cut(prim->cut);
}*/
