/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colonne6.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfavart <tfavart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 13:25:34 by tfavart           #+#    #+#             */
/*   Updated: 2018/06/18 14:54:48 by tfavart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ui.h"

void		ft_colonne6(t_interface *inter)
{
	inter->cont.colonne6 = gtk_box_new(GTK_ORIENTATION_VERTICAL, 6);
	gtk_container_add(GTK_CONTAINER(inter->cont.principal),
		inter->cont.colonne6);
	ft_switch(&inter->tex_c.on_off, inter->cont.colonne6, "texture color");
	ft_1d_button(&(inter->tex_c.name), inter->cont.colonne6, "name");
	ft_2d_button(&(inter->tex_c.move), inter->cont.colonne6, "move");
	ft_2d_button(&(inter->tex_c.scale), inter->cont.colonne6, "scale");
	ft_switch(&inter->tex_n.on_off, inter->cont.colonne6, "texture normal");
	ft_1d_button(&(inter->tex_n.name), inter->cont.colonne6, "name");
	ft_2d_button(&(inter->tex_n.move), inter->cont.colonne6, "move");
	ft_2d_button(&(inter->tex_n.scale), inter->cont.colonne6, "scale");
}
