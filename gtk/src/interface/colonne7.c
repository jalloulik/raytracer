/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colonne7.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfavart <tfavart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 09:54:44 by tfavart           #+#    #+#             */
/*   Updated: 2018/06/23 10:04:01 by tfavart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ui.h"

void		ft_colonne7(t_interface *inter)
{
	inter->cont.colonne7 = gtk_box_new(GTK_ORIENTATION_VERTICAL, 6);
	gtk_container_add(GTK_CONTAINER(inter->cont.principal),
		inter->cont.colonne7);
	ft_switch(&(inter->cut.on_off), inter->cont.colonne7, "decoupe");
	ft_3d_button(&(inter->cut.origin_1), inter->cont.colonne7, "origin_1 ");
	ft_3d_button(&(inter->cut.axe_1), inter->cont.colonne7, "axe_1 ");
	ft_3d_button(&(inter->cut.origin_2), inter->cont.colonne7, "origin_2 ");
	ft_3d_button(&(inter->cut.axe_2), inter->cont.colonne7, "axe_2 ");
}
