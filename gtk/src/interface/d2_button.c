/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d2_button.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfavart <tfavart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 13:50:37 by tfavart           #+#    #+#             */
/*   Updated: 2018/06/18 17:12:18 by tfavart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ui.h"

static void		ft_xy(t_2d_button *button, GtkWidget *box_h, char *name)
{
	char		*label;

	label = ft_strjoin(name, " a");
	button->label_x = gtk_label_new(label);
	free(label);
	gtk_container_add(GTK_CONTAINER(box_h), button->label_x);
	button->x = gtk_entry_new();
	gtk_entry_set_text(GTK_ENTRY(button->x), "0");
	gtk_container_add(GTK_CONTAINER(box_h), button->x);
	label = ft_strjoin(name, " b");
	button->label_y = gtk_label_new(label);
	free(label);
	gtk_container_add(GTK_CONTAINER(box_h), button->label_y);
	button->y = gtk_entry_new();
	gtk_entry_set_text(GTK_ENTRY(button->y), "0");
	gtk_container_add(GTK_CONTAINER(box_h), button->y);
}

void			ft_2d_button(t_2d_button *button,
	GtkWidget *container, char *name)
{
	button->box_v = gtk_box_new(GTK_ORIENTATION_VERTICAL, 2);
	gtk_container_add(GTK_CONTAINER(container), button->box_v);
	button->box_h = gtk_box_new(GTK_ORIENTATION_VERTICAL, 12);
	gtk_box_set_homogeneous(GTK_BOX(button->box_h), TRUE);
	gtk_container_add(GTK_CONTAINER(button->box_v), button->box_h);
	ft_xy(button, button->box_h, name);
}
