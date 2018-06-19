/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvillepo <yvillepo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 19:01:34 by yvillepo          #+#    #+#             */
/*   Updated: 2018/06/18 09:35:00 by yvillepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	read_vect(char *str, t_3dpt *vect)
{
	char **tab;

	tab = ft_strsplit(str, ':');
	vect->x = ft_atoi(tab[1]);
	vect->y = ft_atoi(tab[2]);
	vect->z = ft_atoi(tab[3]);
	ft_free_tab(tab);
}

void		read_vect2(char *str, t_3dpt *vect)
{
	char **tab;

	tab = ft_strsplit(str, ':');
	vect->x = ft_atof(tab[0]);
	vect->y = ft_atof(tab[1]);
	vect->z = ft_atof(tab[2]);
	ft_free_tab(tab);
}
