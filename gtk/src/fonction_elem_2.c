/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonction_elem_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfavart <tfavart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 15:56:37 by tfavart           #+#    #+#             */
/*   Updated: 2018/06/19 11:24:51 by tfavart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ui.h"

void			ft_create_carre(GtkWidget *widget, gpointer data)
{
	t_interface	*inter;
	t_elem		*elem;
	char		*name;
	char		*tmp;
	int			i;

	(void)widget;
	i = 0;
	elem = NULL;
	inter = (t_interface *)data;
	elem = ft_select_elem(inter);
	while (elem->next)
	{
		if (elem->type == CARRE)
			i++;
		elem = elem->next;
	}
	name = "rectangle";
	tmp = ft_itoa(i);
	name = ft_strjoin(name, tmp);
	ft_iter(&elem->iter, inter->list.store, i, name);
	elem->type = CARRE;
	elem->rad = 2;
	free(tmp);
	free(name);
	ft_init_elem(elem);
}

void			ft_create_torre(GtkWidget *widget, gpointer data)
{
	t_interface	*inter;
	t_elem		*elem;
	char		*name;
	char		*tmp;
	int			i;

	(void)widget;
	i = 0;
	elem = NULL;
	inter = (t_interface *)data;
	elem = ft_select_elem(inter);
	while (elem->next)
	{
		if (elem->type == TORRE)
			i++;
		elem = elem->next;
	}
	name = "torre";
	tmp = ft_itoa(i);
	name = ft_strjoin(name, tmp);
	ft_iter(&elem->iter, inter->list.store, i, name);
	elem->type = TORRE;
	elem->rad = 2;
	free(tmp);
	free(name);
	ft_init_elem(elem);
}

void			ft_create_triangle(GtkWidget *widget, gpointer data)
{
	t_interface	*inter;
	t_elem		*elem;
	char		*name;
	char		*tmp;
	int			i;

	(void)widget;
	i = 0;
	elem = NULL;
	inter = (t_interface *)data;
	elem = ft_select_elem(inter);
	while (elem->next)
	{
		if (elem->type == TRIANGLE)
			i++;
		elem = elem->next;
	}
	name = "triangle";
	tmp = ft_itoa(i);
	name = ft_strjoin(name, tmp);
	ft_iter(&elem->iter, inter->list.store, i, name);
	elem->type = TRIANGLE;
	elem->rad = 2;
	free(tmp);
	free(name);
	ft_init_elem(elem);
}

void			ft_create_cercle(GtkWidget *widget, gpointer data)
{
	t_interface	*inter;
	t_elem		*elem;
	char		*name;
	char		*tmp;
	int			i;

	(void)widget;
	i = 0;
	elem = NULL;
	inter = (t_interface *)data;
	elem = ft_select_elem(inter);
	while (elem->next)
	{
		if (elem->type == CERCLE)
			i++;
		elem = elem->next;
	}
	name = "cercle";
	tmp = ft_itoa(i);
	name = ft_strjoin(name, tmp);
	ft_iter(&elem->iter, inter->list.store, i, name);
	elem->type = CERCLE;
	elem->rad = 2;
	free(tmp);
	free(name);
	ft_init_elem(elem);
}
