/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d2_button.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfavart <tfavart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 13:50:37 by tfavart           #+#    #+#             */
/*   Updated: 2018/06/14 13:51:53 by tfavart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ui.h"

static void		ft_xy(t_2d_button *inter, GtkWidget *box_h, char *name)
{
	inter->label_x = gtk_label_new(ft_strjoin(name, " a"));
	gtk_container_add(GTK_CONTAINER(box_h), inter->label_x);
	inter->x = gtk_entry_new();
	gtk_entry_set_text(GTK_ENTRY(inter->x), "0");
	gtk_container_add(GTK_CONTAINER(box_h), inter->x);
	inter->label_y = gtk_label_new(ft_strjoin(name, " b"));
	gtk_container_add(GTK_CONTAINER(box_h), inter->label_y);
	inter->y = gtk_entry_new();
	gtk_entry_set_text(GTK_ENTRY(inter->y), "0");
	gtk_container_add(GTK_CONTAINER(box_h), inter->y);
}

void			ft_2d_button(t_2d_button *inter,
	GtkWidget *container, char *name)
{
	GtkWidget	*box_v;
	GtkWidget	*box_h;

	box_v = gtk_box_new(GTK_ORIENTATION_VERTICAL, 2);
	gtk_container_add(GTK_CONTAINER(container), box_v);
	box_h = gtk_box_new(GTK_ORIENTATION_VERTICAL, 12);
	gtk_box_set_homogeneous(GTK_BOX(box_h), TRUE);
	gtk_container_add(GTK_CONTAINER(box_v), box_h);
	ft_xy(inter, box_h, name);
}
