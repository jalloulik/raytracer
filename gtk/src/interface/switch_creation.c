/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switch_creation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfavart <tfavart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 15:51:40 by tfavart           #+#    #+#             */
/*   Updated: 2018/06/11 15:52:03 by tfavart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ui.h"

void			ft_switch(t_1d_button *swit, GtkWidget *container, char *name)
{
	GtkWidget		*box;

	box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 2);
	gtk_box_set_homogeneous(GTK_BOX(box), TRUE);
	gtk_container_add(GTK_CONTAINER(container), box);
	swit->label_x = gtk_label_new(name);
	gtk_container_add(GTK_CONTAINER(box), swit->label_x);
	swit->x = gtk_switch_new();
	gtk_container_add(GTK_CONTAINER(box), swit->x);
	gtk_switch_set_state(GTK_SWITCH(swit->x), FALSE);
}