/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonction_elem_3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfavart <tfavart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 16:22:53 by tfavart           #+#    #+#             */
/*   Updated: 2018/06/14 16:48:06 by tfavart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ui.h"

void			ft_create_spot(GtkWidget *widget, gpointer data)
{
	t_interface	*inter;
	t_elem		*elem;
	char		*spot;
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
	spot = "spot";
	elem->name = ft_strjoin(spot, ft_itoa(i));
	ft_iter(&elem->iter, inter->list.store, i, elem->name);
	elem->type = SPOT;
	elem->intensity = 0;
	ft_init_elem(elem);
}

void			ft_create_sun(GtkWidget *widget, gpointer data)
{
	t_interface	*inter;
	t_elem		*elem;
	char		*sun;
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
	sun = "sun";
	elem->name = ft_strjoin(sun, ft_itoa(i));
	ft_iter(&elem->iter, inter->list.store, i, elem->name);
	elem->type = SUN;
	elem->intensity = 0;
	ft_init_elem(elem);
}

void			ft_create_ambiant(GtkWidget *widget, gpointer data)
{
	t_interface	*inter;
	t_elem		*elem;
	char		*ambiant;
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
	ambiant = "ambiant";
	elem->name = ft_strjoin(ambiant, ft_itoa(i));
	ft_iter(&elem->iter, inter->list.store, i, elem->name);
	elem->type = AMBIANT;
	elem->intensity = 0;
	ft_init_elem(elem);
}
