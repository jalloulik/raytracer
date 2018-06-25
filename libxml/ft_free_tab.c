/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfavart <tfavart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/24 17:11:15 by tfavart           #+#    #+#             */
/*   Updated: 2018/06/24 17:11:24 by tfavart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libxml.h"
#include <stdlib.h>

void		ft_free_tab_2(char **tab)
{
	int i;

	i = 0;
	while (tab && tab[i] != 0)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void		ft_error_2(char *str)
{
	ft_putendl(str);
	exit(0);
}
