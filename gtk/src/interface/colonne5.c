/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colonne5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfavart <tfavart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 11:58:11 by tfavart           #+#    #+#             */
/*   Updated: 2018/06/14 11:49:29 by tfavart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ui.h"

void	ft_colonne5(t_interface *inter)
{
	inter->cont.colonne5 = gtk_box_new(GTK_ORIENTATION_VERTICAL, 6);
	gtk_container_add(GTK_CONTAINER(inter->cont.principal), inter->cont.colonne5);
	ft_switch(&inter->sinus.on_off, inter->cont.colonne5, "sinus");
	ft_2d_button(&(inter->sinus.sin_x), inter->cont.colonne5, "sin.x");
	ft_2d_button(&(inter->sinus.sin_y), inter->cont.colonne5, "sin.y");
	ft_2d_button(&(inter->sinus.sin_z), inter->cont.colonne5, "sin.z");
	ft_switch(&inter->checker.on_off, inter->cont.colonne5, "checker");
	ft_2d_button(&(inter->checker.move), inter->cont.colonne5, "move");
	ft_2d_button(&(inter->checker.scale), inter->cont.colonne5, "scale");
}