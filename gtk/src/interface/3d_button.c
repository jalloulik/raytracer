/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3d_button.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfavart <tfavart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 12:36:17 by tfavart           #+#    #+#             */
/*   Updated: 2018/06/12 16:09:36 by tfavart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ui.h"

static void		ft_x(GtkWidget **label, GtkWidget **button, GtkWidget *box_h, char *name, char *name_value)
{

	*label = gtk_label_new(ft_strjoin(name, name_value));
	gtk_container_add(GTK_CONTAINER(box_h), *label);
	*button = gtk_entry_new();
	gtk_entry_set_text(GTK_ENTRY(*button), "0");
	gtk_container_add(GTK_CONTAINER(box_h), *button);
}

static void		ft_xyz(t_3d_button *button, GtkWidget *box_h, char *name)
{
	if (ft_strcmp(name, "color") == 0)
	{
		ft_x(&button->label_x, &button->x, box_h, name, " red");
		ft_x(&button->label_y, &button->y, box_h, name, " green");
		ft_x(&button->label_z, &button->z, box_h, name, " blue");
	}
	else
	{
		ft_x(&button->label_x, &button->x, box_h, name, " x");
		ft_x(&button->label_y, &button->y, box_h, name, " y");
		ft_x(&button->label_z, &button->z, box_h, name, " z");
	}
}

void			ft_3d_button(t_3d_button *button, GtkWidget *container,
		char *name)
{
	GtkWidget	*box_h;

	box_h = gtk_box_new(GTK_ORIENTATION_VERTICAL, 6);
	gtk_box_set_homogeneous(GTK_BOX(box_h), TRUE);
	gtk_container_add(GTK_CONTAINER(container), box_h);
	ft_xyz(button, box_h, name);
}
