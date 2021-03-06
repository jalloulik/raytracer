/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfavart <tfavart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 11:45:55 by tfavart           #+#    #+#             */
/*   Updated: 2018/06/20 22:05:35 by tfavart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ui.h"

void		ft_error(char *message)
{
	ft_putstr(message);
	ft_putstr("\n");
	exit(1);
}

t_elem		*ft_select_elem(t_interface *inter)
{
	t_elem	*elem;

	elem = NULL;
	if (inter->list_e == NULL)
	{
		if (!(inter->list_e = (t_elem*)malloc(sizeof(t_elem))))
			ft_error("erreur allocation");
		inter->list_e->next = NULL;
	}
	else
		ft_add_list(inter->list_e);
	elem = inter->list_e;
	return (elem);
}

void		ft_add_list(t_elem *elem)
{
	t_elem	*tmp;
	t_elem	*tmp2;

	tmp = elem;
	tmp2 = NULL;
	while (tmp->next)
		tmp = tmp->next;
	if (!(tmp2 = (t_elem*)malloc(sizeof(t_elem))))
		ft_error("erreur allocation");
	tmp->next = tmp2;
	tmp2->next = NULL;
}
