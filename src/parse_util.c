/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvillepo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 19:01:34 by yvillepo          #+#    #+#             */
/*   Updated: 2018/05/16 10:43:10 by yvillepo         ###   ########.fr       */
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

void	read_cut(char *str, t_prim *prim)
{
	char **tab;

	tab = ft_strsplit(str, ':');
	if (ft_count_tab(tab) < 2)
		exit (0);
	if (ft_strcmp(tab[0], "x"))
		prim->cut.x = ft_atof(tab[1]);
	else if (ft_strcmp(tab[0], "y"))
		prim->cut.y = ft_atof(tab[1]);
	else if (ft_strcmp(tab[0], "z"))
		prim->cut.z = ft_atof(tab[1]);
	else
		exit(0);
	ft_free_tab(tab);
}

void	read_all_cut(char **str, t_prim *prim)
{
	int		i;

	i = ft_count_tab(str);

	while (i--)
		read_cut(str[i], prim);
}
