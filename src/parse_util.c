/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvillepo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 19:01:34 by yvillepo          #+#    #+#             */
/*   Updated: 2018/05/02 20:51:55 by yvillepo         ###   ########.fr       */
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
}
