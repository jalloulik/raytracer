/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colonne1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfavart <tfavart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 00:33:51 by tfavart           #+#    #+#             */
/*   Updated: 2018/06/15 15:03:51 by tfavart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ui.h"

static void			ft_list_elem(t_interface *inter)
{
	GtkCellRenderer *p_cell;

	p_cell = NULL;
	p_cell = gtk_cell_renderer_text_new();
	inter->list.store = gtk_list_store_new(3, G_TYPE_INT, G_TYPE_STRING);
	inter->list.button =
		gtk_combo_box_new_with_model(GTK_TREE_MODEL(inter->list.store));
	gtk_cell_layout_pack_start(GTK_CELL_LAYOUT(inter->list.button),
		p_cell, FALSE);
	gtk_cell_layout_set_attributes(GTK_CELL_LAYOUT(inter->list.button),
		p_cell, "text", 1, NULL);
	gtk_container_add(GTK_CONTAINER(inter->cont.colonne1),
		inter->list.button);
}

void				ft_colonne1(t_interface *inter)
{
	inter->cont.colonne1 = gtk_box_new(GTK_ORIENTATION_VERTICAL, 8);
	gtk_container_add(GTK_CONTAINER(inter->cont.principal),
		inter->cont.colonne1);
	ft_list_elem(inter);
}
