/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colonne8.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfavart <tfavart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 09:54:40 by tfavart           #+#    #+#             */
/*   Updated: 2018/06/23 10:00:46 by tfavart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ui.h"

void		ft_colonne8(t_interface *inter)
{
	inter->cont.colonne8 = gtk_box_new(GTK_ORIENTATION_VERTICAL, 6);
	gtk_container_add(GTK_CONTAINER(inter->cont.principal),
		inter->cont.colonne8);
	ft_3d_button(&(inter->cut.origin_3), inter->cont.colonne8, "origin_3 ");
	ft_3d_button(&(inter->cut.axe_3), inter->cont.colonne8, "axe_3 ");
	ft_3d_button(&(inter->cut.origin_4), inter->cont.colonne8, "origin_4 ");
	ft_3d_button(&(inter->cut.axe_4), inter->cont.colonne8, "axe_4 ");
}
