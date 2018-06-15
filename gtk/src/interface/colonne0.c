/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colonne0.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfavart <tfavart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 15:16:34 by tfavart           #+#    #+#             */
/*   Updated: 2018/06/14 16:18:49 by tfavart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ui.h"

static void		ft_colonne0_0(t_interface *inter)
{
	inter->light.spot = gtk_button_new_with_label("new spot");
	gtk_container_add(GTK_CONTAINER(inter->cont.colonne0),
		inter->light.spot);
	inter->light.sun = gtk_button_new_with_label("new sun");
	gtk_container_add(GTK_CONTAINER(inter->cont.colonne0),
		inter->light.sun);
	inter->light.ambiant = gtk_button_new_with_label("new ambiant");
	gtk_container_add(GTK_CONTAINER(inter->cont.colonne0),
		inter->light.ambiant);
}

static void		ft_colonne0_1(t_interface *inter)
{
	inter->prim.torre = gtk_button_new_with_label("new torre");
	gtk_container_add(GTK_CONTAINER(inter->cont.colonne0),
		inter->prim.torre);
	inter->prim.carre = gtk_button_new_with_label("new carre");
	gtk_container_add(GTK_CONTAINER(inter->cont.colonne0),
		inter->prim.carre);
	inter->prim.cercle = gtk_button_new_with_label("new cercle");
	gtk_container_add(GTK_CONTAINER(inter->cont.colonne0),
		inter->prim.cercle);
	inter->prim.triangle = gtk_button_new_with_label("new triangle");
	gtk_container_add(GTK_CONTAINER(inter->cont.colonne0),
		inter->prim.triangle);
}

void			ft_colonne0(t_interface *inter)
{
	inter->cont.colonne0 = gtk_box_new(GTK_ORIENTATION_VERTICAL, 6);
	gtk_container_add(GTK_CONTAINER(inter->cont.principal),
		inter->cont.colonne0);
	ft_colonne0_0(inter);
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
	ft_colonne0_1(inter);
}
