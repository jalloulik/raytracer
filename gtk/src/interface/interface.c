/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfavart <tfavart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 13:48:52 by tfavart           #+#    #+#             */
/*   Updated: 2018/06/14 11:47:55 by tfavart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ui.h"

void			ft_interface(t_interface *inter, GtkWidget *window)
{
	inter->cont.principal = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5);
	gtk_container_add(GTK_CONTAINER(window), inter->cont.principal);
	ft_colonne0(inter);
	ft_colonne1(inter);
	ft_colonne2(inter);
	ft_colonne3(inter);
	ft_colonne4(inter);
	ft_colonne5(inter);
}
