/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjalloul <kjalloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 11:28:51 by kjalloul          #+#    #+#             */
/*   Updated: 2018/03/21 16:05:05 by kjalloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_prim		*ft_add_lst_file(t_prim *list, int type)
{
	t_prim *start;

	if (list == NULL)
	{
		if ((list = (t_prim*)malloc(sizeof(*list))) == NULL)
			ft_error(ERROR);
		start = list;
	}
	else
	{
		start = list;
		while (list->next != NULL)
			list = list->next;
		if (((list->next) = (t_prim*)malloc(sizeof(*list))) == NULL)
			ft_error(ERROR);
		list = list->next;
	}
	list->type = type;
	list->next = NULL;
	return (start);
}

t_light		*ft_add_lst_light(t_light *list)
{
	t_light *start;

	if (list == NULL)
	{
		if ((list = (t_light*)malloc(sizeof(*list))) == NULL)
			ft_error(ERROR);
		start = list;
	}
	else
	{
		start = list;
		while (list->next != NULL)
			list = list->next;
		if (((list->next) = (t_light*)malloc(sizeof(*list))) == NULL)
			ft_error(ERROR);
		list = list->next;
	}
	list->next = NULL;
	return (start);
}

int			ft_count_tab(char **tab)
{
	int i;

	i = 0;
	if (tab == NULL)
		ft_error(ERROR);
	while (tab[i] != 0)
		i++;
	return (i);
}

void		ft_free_tab(char **tab)
{
	int i;

	i = 0;
	while (tab[i] != 0)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}
