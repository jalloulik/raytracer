/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colonne9.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfavart <tfavart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 09:54:14 by tfavart           #+#    #+#             */
/*   Updated: 2018/06/23 10:01:32 by tfavart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ui.h"

void		ft_colonne9(t_interface *inter)
{
	inter->cont.colonne9 = gtk_box_new(GTK_ORIENTATION_VERTICAL, 6);
	gtk_container_add(GTK_CONTAINER(inter->cont.principal),
		inter->cont.colonne9);
	ft_3d_button(&(inter->cut.origin_5), inter->cont.colonne9, "origin_5 ");
	ft_3d_button(&(inter->cut.axe_5), inter->cont.colonne9, "axe_5 ");
	ft_3d_button(&(inter->cut.origin_6), inter->cont.colonne9, "origin_6 ");
	ft_3d_button(&(inter->cut.axe_6), inter->cont.colonne9, "axe_6 ");
}
