/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d3_button.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfavart <tfavart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 13:50:48 by tfavart           #+#    #+#             */
/*   Updated: 2018/06/18 17:07:00 by tfavart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ui.h"

static void		ft_x(GtkWidget **label, GtkWidget **button,
	GtkWidget *box_h, char *name)
{
	*label = gtk_label_new(name);
	gtk_container_add(GTK_CONTAINER(box_h), *label);
	*button = gtk_entry_new();
	gtk_entry_set_text(GTK_ENTRY(*button), "0");
	gtk_container_add(GTK_CONTAINER(box_h), *button);
	free(name);
}

static void		ft_xyz(t_3d_button *button, GtkWidget *box_h, char *name)
{
	if (ft_strcmp(name, "color") == 0)
	{
		ft_x(&button->label_x, &button->x, box_h, ft_strjoin(name, " red"));
		ft_x(&button->label_y, &button->y, box_h, ft_strjoin(name, " green"));
		ft_x(&button->label_z, &button->z, box_h, ft_strjoin(name, " blue"));
	}
	else
	{
		ft_x(&button->label_x, &button->x, box_h, ft_strjoin(name, " x"));
		ft_x(&button->label_y, &button->y, box_h, ft_strjoin(name, " y"));
		ft_x(&button->label_z, &button->z, box_h, ft_strjoin(name, " z"));
	}
}

void			ft_3d_button(t_3d_button *button, GtkWidget *container,
		char *name)
{
	button->box_h = gtk_box_new(GTK_ORIENTATION_VERTICAL, 6);
	gtk_box_set_homogeneous(GTK_BOX(button->box_h), TRUE);
	gtk_container_add(GTK_CONTAINER(container), button->box_h);
	ft_xyz(button, button->box_h, name);
}
