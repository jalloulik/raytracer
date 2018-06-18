/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonction_elem_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfavart <tfavart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 15:56:37 by tfavart           #+#    #+#             */
/*   Updated: 2018/06/18 14:00:18 by tfavart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ui.h"

void			ft_create_carre(GtkWidget *widget, gpointer data)
{
	t_interface	*inter;
	t_elem		*elem;
	char		*carre;
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
	carre = "rectangle";
	elem->name = ft_strjoin(carre, ft_itoa(i));
	ft_iter(&elem->iter, inter->list.store, i, elem->name);
	elem->type = CARRE;
	elem->rad = 2;
	ft_init_elem(elem);
}

void			ft_create_torre(GtkWidget *widget, gpointer data)
{
	t_interface	*inter;
	t_elem		*elem;
	char		*torre;
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
	torre = "torre";
	elem->name = ft_strjoin(torre, ft_itoa(i));
	ft_iter(&elem->iter, inter->list.store, i, elem->name);
	elem->type = TORRE;
	elem->rad = 2;
	ft_init_elem(elem);
}

void			ft_create_triangle(GtkWidget *widget, gpointer data)
{
	t_interface	*inter;
	t_elem		*elem;
	char		*triangle;
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
	triangle = "triangle";
	elem->name = ft_strjoin(triangle, ft_itoa(i));
	ft_iter(&elem->iter, inter->list.store, i, elem->name);
	elem->type = TRIANGLE;
	elem->rad = 2;
	ft_init_elem(elem);
}

void			ft_create_cercle(GtkWidget *widget, gpointer data)
{
	t_interface	*inter;
	t_elem		*elem;
	char		*cercle;
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
	cercle = "cercle";
	elem->name = ft_strjoin(cercle, ft_itoa(i));
	ft_iter(&elem->iter, inter->list.store, i, elem->name);
	elem->type = CERCLE;
	elem->rad = 2;
	ft_init_elem(elem);
}
