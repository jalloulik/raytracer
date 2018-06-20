/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonction_elem.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfavart <tfavart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 23:39:17 by tfavart           #+#    #+#             */
/*   Updated: 2018/06/20 16:53:55 by tfavart          ###   ########.fr       */
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
	char		*name;
	char		*tmp;
	int			i;

	(void)widget;
	i = 0;
	inter = (t_interface *)data;
	elem = ft_select_elem(inter);
	while (elem->next)
	{
		if (elem->type == SPHERE)
			i++;
		elem = elem->next;
	}
	name = "sphere";
	tmp = ft_itoa(i);
	name = ft_strjoin(name, tmp);
	ft_iter(&elem->iter, inter->list.store, i, name);
	ft_init_elem(elem);
	elem->type = SPHERE;
	free(tmp);
	free(name);
}

void			ft_create_cone(GtkWidget *widget, gpointer data)
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
		if (elem->type == CONE)
			i++;
		elem = elem->next;
	}
	name = "cone";
	tmp = ft_itoa(i);
	name = ft_strjoin(name, tmp);
	ft_iter(&elem->iter, inter->list.store, i, name);
	ft_init_elem(elem);
	elem->type = CONE;
	free(tmp);
	free(name);
}

void			ft_create_cylindre(GtkWidget *widget, gpointer data)
{
	t_interface	*inter;
	t_elem		*elem;
	char		*tmp;
	char		*name;
	int			i;

	(void)widget;
	i = 0;
	inter = (t_interface *)data;
	elem = ft_select_elem(inter);
	while (elem->next)
	{
		if (elem->type == CYLINDRE)
			i++;
		elem = elem->next;
	}
	name = "cylindre";
	tmp = ft_itoa(i);
	name = ft_strjoin(name, tmp);
	ft_iter(&elem->iter, inter->list.store, i, name);
	ft_init_elem(elem);
	elem->type = CYLINDRE;
	free(tmp);
	free(name);
}

void			ft_create_plan(GtkWidget *widget, gpointer data)
{
	t_interface	*inter;
	t_elem		*elem;
	char		*tmp;
	char		*name;
	int			i;

	(void)widget;
	i = 0;
	inter = (t_interface *)data;
	elem = ft_select_elem(inter);
	while (elem->next)
	{
		if (elem->type == PLAN)
			i++;
		elem = elem->next;
	}
	name = "plan";
	tmp = ft_itoa(i);
	name = ft_strjoin(name, tmp);
	ft_iter(&elem->iter, inter->list.store, i, name);
	ft_init_elem(elem);
	elem->type = PLAN;
	free(tmp);
	free(name);
}
