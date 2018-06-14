/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonction_elem.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfavart <tfavart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 23:39:17 by tfavart           #+#    #+#             */
/*   Updated: 2018/06/12 11:53:26 by tfavart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ui.h"

void			ft_iter(GtkTreeIter *iter, GtkListStore *list,
int ind, char *label)
{
	gtk_list_store_append(list, iter);
	gtk_list_store_set(list, iter, 0, ind, 1, label, -1);
}

void			ft_create_sphere(GtkWidget *widget, gpointer data)
{
	t_interface	*inter;
	t_elem		*elem;
	char		*sphere;
	int			i;

	(void)widget;
	i = 0;
	elem = NULL;
	inter = (t_interface *)data;
	elem = ft_select_elem(inter);
	while (elem->next)
	{
		if (elem->type == SPHERE)
			i++;
		elem = elem->next;
	}
	sphere = "sphere";
	elem->name = ft_strjoin(sphere, ft_itoa(i));
	ft_iter(&elem->iter, inter->list.store, i, elem->name);
	elem->type = SPHERE;
	elem->rad = 2;
	ft_init_elem(elem);
}

void			ft_create_cone(GtkWidget *widget, gpointer data)
{
	t_interface	*inter;
	t_elem		*elem;
	char		*name;
	int			i;

	(void)widget;
	i = 0;
	elem = NULL;
	inter = (t_interface *)data;
	elem = ft_select_elem(inter);
	while (elem->next)
	{
		if (elem->type == CONE)
			i++;
		elem = elem->next;
	}
	name = "cone";
	elem->name = ft_strjoin(name, ft_itoa(i));
	ft_iter(&elem->iter, inter->list.store, i, elem->name);
	elem->type = CONE;
	elem->rad = 0;
	ft_init_elem(elem);
}

void			ft_create_cylindre(GtkWidget *widget, gpointer data)
{
	t_interface	*inter;
	t_elem		*elem;
	char		*name;
	int			i;

	(void)widget;
	i = 0;
	elem = NULL;
	inter = (t_interface *)data;
	elem = ft_select_elem(inter);
	while (elem->next)
	{
		if (elem->type == CYLINDRE)
			i++;
		elem = elem->next;
	}
	name = "cylindre";
	elem->name = ft_strjoin(name, ft_itoa(i));
	ft_iter(&elem->iter, inter->list.store, i, elem->name);
	elem->type = CYLINDRE;
	elem->rad = 0;
	ft_init_elem(elem);
}

void			ft_create_plan(GtkWidget *widget, gpointer data)
{
	t_interface	*inter;
	t_elem		*elem;
	char		*name;
	int			i;

	(void)widget;
	i = 0;
	elem = NULL;
	inter = (t_interface *)data;
	elem = ft_select_elem(inter);
	while (elem->next)
	{
		if (elem->type == PLAN)
			i++;
		elem = elem->next;
	}
	name = "plan";
	elem->name = ft_strjoin(name, ft_itoa(i));
	ft_iter(&elem->iter, inter->list.store, i, elem->name);
	elem->type = PLAN;
	elem->rad = 0;
	ft_init_elem(elem);
}
