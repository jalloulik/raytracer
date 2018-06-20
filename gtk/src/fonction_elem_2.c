/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonction_elem_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfavart <tfavart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 15:56:37 by tfavart           #+#    #+#             */
/*   Updated: 2018/06/20 18:42:25 by tfavart          ###   ########.fr       */
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
	ft_init_elem(elem);
	elem->type = CARRE;
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
	inter = (t_interface *)data;
	elem = ft_select_elem(inter);
	while (elem->next)
	{
		if (elem->type == TORRE)
			i++;
		elem = elem->next;
	}
	name = "tore";
	tmp = ft_itoa(i);
	name = ft_strjoin(name, tmp);
	ft_iter(&elem->iter, inter->list.store, i, name);
	ft_init_elem(elem);
	elem->type = TORRE;
	free(tmp);
	free(name);
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
	ft_init_elem(elem);
	elem->type = TRIANGLE;
	free(tmp);
	free(name);
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
	ft_init_elem(elem);
	elem->type = CERCLE;
	free(tmp);
	free(name);
}
