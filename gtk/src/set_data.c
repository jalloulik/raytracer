/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfavart <tfavart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 11:01:39 by tfavart           #+#    #+#             */
/*   Updated: 2018/06/23 11:04:17 by tfavart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ui.h"

static void			ft_set_data(t_interface *inter, t_elem *elem)
{
	ft_set_entry_3d(inter, elem);
	ft_set_entry_2d(inter, elem);
	ft_set_entry_1d(inter, elem);
	gtk_switch_set_active(GTK_SWITCH(inter->specular.x),
		elem->specular);
	gtk_switch_set_active(GTK_SWITCH(inter->reflect.on_off.x),
		elem->reflect.on_off);
	gtk_switch_set_active(GTK_SWITCH(inter->refract.on_off.x),
		elem->refract.on_off);
	gtk_switch_set_active(GTK_SWITCH(inter->tex_c.on_off.x),
		elem->tex_c.on_off);
	gtk_switch_set_active(GTK_SWITCH(inter->tex_n.on_off.x),
		elem->tex_n.on_off);
	gtk_switch_set_active(GTK_SWITCH(inter->sinus.on_off.x),
		elem->sinus.on_off);
	gtk_switch_set_active(GTK_SWITCH(inter->checker.on_off.x),
		elem->checker.on_off);
	gtk_switch_set_active(GTK_SWITCH(inter->sepia.x), elem->sepia);
	gtk_switch_set_active(GTK_SWITCH(inter->cut.on_off.x),
		elem->cut.on_off);
}

static void			ft_set_select(t_event_entry *e, t_elem *elem)
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
			ft_set_data_show(e->inter, elem);
			ft_set_data(e->inter, elem);
			break ;
		}
		ft_free_p_text(e);
		elem = elem->next;
	}
}

void				ft_select_elem_actif(GtkWidget *widget, gpointer data)
{
	t_event_entry	*e;
	t_elem			*elem;

	e = (t_event_entry *)data;
	elem = e->inter->list_e;
	(void)widget;
	if (gtk_combo_box_get_active_iter(GTK_COMBO_BOX(e->inter->list.button),
		&e->iter))
	{
		ft_set_select(e, elem);
	}
}
