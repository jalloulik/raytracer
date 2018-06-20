/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colonne4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfavart <tfavart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 15:17:48 by tfavart           #+#    #+#             */
/*   Updated: 2018/06/20 18:08:36 by tfavart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ui.h"

void	ft_colonne4(t_interface *inter)
{
	inter->cont.colonne4 = gtk_box_new(GTK_ORIENTATION_VERTICAL, 6);
	gtk_container_add(GTK_CONTAINER(inter->cont.principal),
		inter->cont.colonne4);
	ft_3d_button(&(inter->triang.p3), inter->cont.colonne4, "point 3");
	ft_3d_button(&(inter->fix.rot), inter->cont.colonne4, "rot");
	ft_1d_button(&inter->fix.angle_rot, inter->cont.colonne4,
		"angle de rotation");
	ft_3d_button(&(inter->fix.color), inter->cont.colonne4, "color");
	ft_2d_button(&(inter->size), inter->cont.colonne4, "size");
}
