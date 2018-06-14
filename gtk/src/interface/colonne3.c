/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colonne3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfavart <tfavart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 16:42:31 by tfavart           #+#    #+#             */
/*   Updated: 2018/06/11 15:55:32 by tfavart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ui.h"

void			ft_colonne3(t_interface *inter)
{
	inter->cont.colonne3 = gtk_box_new(GTK_ORIENTATION_VERTICAL, 8);
	gtk_container_add(GTK_CONTAINER(inter->cont.principal), inter->cont.colonne3);
	ft_3d_button(&(inter->fix.color), inter->cont.colonne3, "color");
	ft_switch(&inter->specular, inter->cont.colonne3, "specular");
	ft_switch(&inter->refract.on_off, inter->cont.colonne3, "refract");
	ft_1d_button(&(inter->refract.material), inter->cont.colonne3, "refract material");
	ft_1d_button(&(inter->refract.value), inter->cont.colonne3, "refract %");
	ft_switch(&inter->reflect.on_off, inter->cont.colonne3, "reflect");
	ft_1d_button(&(inter->reflect.value), inter->cont.colonne3, "reflect %");
}
