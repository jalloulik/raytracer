/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colonne0.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfavart <tfavart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 15:16:34 by tfavart           #+#    #+#             */
/*   Updated: 2018/06/14 13:42:00 by tfavart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ui.h"

void			ft_colonne0(t_interface *inter)
{
	inter->cont.colonne0 = gtk_box_new(GTK_ORIENTATION_VERTICAL, 6);
	gtk_container_add(GTK_CONTAINER(inter->cont.principal),
		inter->cont.colonne0);
	inter->prim.sphere = gtk_button_new_with_label("new sphere");
	gtk_container_add(GTK_CONTAINER(inter->cont.colonne0),
		inter->prim.sphere);
	inter->prim.plan = gtk_button_new_with_label("new plan");
	gtk_container_add(GTK_CONTAINER(inter->cont.colonne0),
		inter->prim.plan);
	inter->prim.cone = gtk_button_new_with_label("new cone");
	gtk_container_add(GTK_CONTAINER(inter->cont.colonne0),
		inter->prim.cone);
	inter->prim.cylindre = gtk_button_new_with_label("new cylindre");
	gtk_container_add(GTK_CONTAINER(inter->cont.colonne0),
		inter->prim.cylindre);
}
