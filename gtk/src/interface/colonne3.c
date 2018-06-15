/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colonne3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfavart <tfavart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 16:42:31 by tfavart           #+#    #+#             */
/*   Updated: 2018/06/15 15:04:01 by tfavart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ui.h"

void			ft_colonne3(t_interface *inter)
{
	inter->cont.colonne3 = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);
	gtk_container_add(GTK_CONTAINER(inter->cont.principal),
		inter->cont.colonne3);
	ft_3d_button(&(inter->fix.translation), inter->cont.colonne3,
		"translasion");
	ft_3d_button(&(inter->fix.vec), inter->cont.colonne3, "vec");
}
