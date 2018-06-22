/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   active_switch.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfavart <tfavart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/02 00:54:46 by tfavart           #+#    #+#             */
/*   Updated: 2018/06/22 18:19:53 by tfavart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ui.h"

void				ft_free_p_text(t_event_entry *e)
{
	free(e->p_text1);
	free(e->p_text2);
}

static void			ft_type1(GtkWidget *type, t_elem *elem,
		t_interface *inter)
{
	if (type == inter->tex_c.on_off.x)
	{
		elem->tex_c.on_off = gtk_switch_get_state(GTK_SWITCH(type));
		ft_show_texture_c(inter, type);
	}
	else if (type == inter->tex_n.on_off.x)
	{
		elem->tex_n.on_off = gtk_switch_get_state(GTK_SWITCH(type));
		ft_show_texture_n(inter, type);
	}
	else if (type == inter->sinus.on_off.x)
	{
		elem->sinus.on_off = gtk_switch_get_state(GTK_SWITCH(type));
		ft_show_sinus(inter, type);
	}
	else if (type == inter->checker.on_off.x)
	{
		elem->checker.on_off = gtk_switch_get_state(GTK_SWITCH(type));
		ft_show_checker(inter, type);
	}
	else if (type == inter->sepia.x)
		elem->sepia = gtk_switch_get_state(GTK_SWITCH(type));
}

static void			ft_type(GtkWidget *type, t_elem *elem,
	t_interface *inter)
{
	if (type == inter->refract.on_off.x)
	{
		elem->refract.on_off = gtk_switch_get_state(GTK_SWITCH(type));
		ft_show_refract(inter, type);
	}
	else if (type == inter->reflect.on_off.x)
	{
		elem->reflect.on_off = gtk_switch_get_state(GTK_SWITCH(type));
		ft_show_reflect(inter, type);
	}
	else if (type == inter->specular.x)
	{
		elem->specular = gtk_switch_get_state(GTK_SWITCH(type));
	}
	else
		ft_type1(type, elem, inter);
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
				&e->iter, 1, &e->p_text1, -1);
			gtk_tree_model_get(GTK_TREE_MODEL(e->inter->list.store),
				&elem->iter, 1, &e->p_text2, -1);
			if (ft_strcmp(e->p_text1, e->p_text2) == 0)
			{
				ft_free_p_text(e);
				ft_type(widget, elem, e->inter);
				break ;
			}
			ft_free_p_text(e);
			elem = elem->next;
		}
	}
}
