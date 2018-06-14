/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d1_button.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfavart <tfavart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 13:49:18 by tfavart           #+#    #+#             */
/*   Updated: 2018/06/14 13:49:20 by tfavart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ui.h"

static void		ft_x(t_1d_button *button, GtkWidget *box_h, char *name)
{
	button->label_x = gtk_label_new(name);
	gtk_container_add(GTK_CONTAINER(box_h), button->label_x);
	button->x = gtk_entry_new();
	gtk_entry_set_text(GTK_ENTRY(button->x), "0");
	gtk_container_add(GTK_CONTAINER(box_h), button->x);
}

void			ft_1d_button(t_1d_button *button, GtkWidget *container,
	char *name)
{
	GtkWidget	*box_h;

	box_h = gtk_box_new(GTK_ORIENTATION_VERTICAL, 2);
	gtk_box_set_homogeneous(GTK_BOX(box_h), TRUE);
	gtk_container_add(GTK_CONTAINER(container), box_h);
	ft_x(button, box_h, name);
}
