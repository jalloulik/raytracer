/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   active_switch.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfavart <tfavart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/02 00:54:46 by tfavart           #+#    #+#             */
/*   Updated: 2018/06/14 13:09:47 by tfavart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ui.h"

static void			ft_type1(GtkWidget *type, int **value, t_elem *elem,
		t_interface *inter)
{
	if (type == inter->tex_c.on_off.x)
	{
		*value = (int*)&(elem->tex_c.on_off);
		**value = gtk_switch_get_state(GTK_SWITCH(type));
		ft_show_texture_c(inter, type);
	}
	else if (type == inter->tex_n.on_off.x)
	{
		*value = (int*)&(elem->tex_n.on_off);
		**value = gtk_switch_get_state(GTK_SWITCH(type));
		ft_show_texture_n(inter, type);
	}
	else if (type == inter->sinus.on_off.x)
	{
		*value = (int*)&(elem->sinus.on_off);
		**value = gtk_switch_get_state(GTK_SWITCH(type));
		ft_show_sinus(inter, type);
	}
	else if (type == inter->checker.on_off.x)
	{
		*value = (int*)&(elem->checker.on_off);
		**value = gtk_switch_get_state(GTK_SWITCH(type));
		ft_show_checker(inter, type);
	}
}

static void			ft_type(GtkWidget *type, int **value, t_elem *elem,
	t_interface *inter)
{
	if (type == inter->specular.x)
	{
		*value = (int*)&elem->specular;
		**value = gtk_switch_get_state(GTK_SWITCH(type));
	}
	else if (type == inter->refract.on_off.x)
	{
		*value = (int*)&(elem->refract.on_off);
		**value = gtk_switch_get_state(GTK_SWITCH(type));
		ft_show_refract(inter, type);
	}
	else if (type == inter->reflect.on_off.x)
	{
		*value = (int*)&(elem->reflect.on_off);
		**value = gtk_switch_get_state(GTK_SWITCH(type));
		ft_show_reflect(inter, type);
	}
	ft_type1(type, value, elem, inter);
}

void				ft_active_switch(GtkWidget *widget, GParamSpec *pspec,
gpointer data)
{
	t_event_entry	*e;
	t_elem			*elem;

	e = (t_event_entry *)data;
	elem = e->inter->list_e;
	(void)pspec;
	if (gtk_combo_box_get_active_iter(GTK_COMBO_BOX(e->inter->list.button),
		&e->iter))
	{
		while (elem)
		{
			gtk_tree_model_get(GTK_TREE_MODEL(e->inter->list.store),
				&e->iter, 0, &e->index1, 1, &e->p_text1, -1);
			gtk_tree_model_get(GTK_TREE_MODEL(e->inter->list.store),
				&elem->iter, 0, &e->index2, 1, &e->p_text2, -1);
			if (ft_strcmp(e->p_text1, e->p_text2) == 0)
			{
				ft_type(widget, &e->value, elem, e->inter);
				break ;
			}
			elem = elem->next;
		}
	}
}
