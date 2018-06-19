/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonction_elem_3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfavart <tfavart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 16:22:53 by tfavart           #+#    #+#             */
/*   Updated: 2018/06/19 11:25:54 by tfavart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ui.h"

void			ft_create_spot(GtkWidget *widget, gpointer data)
{
	t_interface	*inter;
	t_elem		*elem;
	char		*tmp;
	char		*name;
	int			i;

	(void)widget;
	i = 0;
	elem = NULL;
	inter = (t_interface *)data;
	elem = ft_select_elem(inter);
	while (elem->next)
	{
		if (elem->type == SPOT)
			i++;
		elem = elem->next;
	}
	name = "spot";
	tmp = ft_itoa(i);
	name = ft_strjoin(name, tmp);
	ft_iter(&elem->iter, inter->list.store, i, name);
	elem->type = SPOT;
	elem->intensity = 0;
	free(tmp);
	free(name);
	ft_init_elem(elem);
}

void			ft_create_sun(GtkWidget *widget, gpointer data)
{
	t_interface	*inter;
	t_elem		*elem;
	char		*tmp;
	char		*name;
	int			i;

	(void)widget;
	i = 0;
	elem = NULL;
	inter = (t_interface *)data;
	elem = ft_select_elem(inter);
	while (elem->next)
	{
		if (elem->type == SUN)
			i++;
		elem = elem->next;
	}
	name = "sun";
	tmp = ft_itoa(i);
	name = ft_strjoin(name, tmp);
	ft_iter(&elem->iter, inter->list.store, i, name);
	elem->type = SUN;
	elem->intensity = 0;
	free(tmp);
	free(name);
	ft_init_elem(elem);
}

void			ft_create_ambiant(GtkWidget *widget, gpointer data)
{
	t_interface	*inter;
	t_elem		*elem;
	char		*tmp;
	char		*name;
	int			i;

	(void)widget;
	i = 0;
	elem = NULL;
	inter = (t_interface *)data;
	elem = ft_select_elem(inter);
	while (elem->next)
	{
		if (elem->type == AMBIANT)
			i++;
		elem = elem->next;
	}
	name = "ambiant";
	tmp = ft_itoa(i);
	name = ft_strjoin(name, tmp);
	ft_iter(&elem->iter, inter->list.store, i, name);
	elem->type = AMBIANT;
	elem->intensity = 0;
	free(tmp);
	free(name);
	ft_init_elem(elem);
}
