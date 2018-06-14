/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colonne2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfavart <tfavart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 15:47:57 by tfavart           #+#    #+#             */
/*   Updated: 2018/06/14 11:55:39 by tfavart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ui.h"

void			ft_colonne2(t_interface *inter)
{
	inter->cont.colonne2 = gtk_box_new(GTK_ORIENTATION_VERTICAL, 8);
	gtk_container_add(GTK_CONTAINER(inter->cont.principal), inter->cont.colonne2);
	ft_3d_button(&(inter->fix.translation), inter->cont.colonne2, "translasion");
	ft_3d_button(&(inter->fix.rot), inter->cont.colonne2, "rot");
	ft_1d_button(&inter->fix.angle_rot, inter->cont.colonne2, "angle de rotation");
}
