/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colonne2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfavart <tfavart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 15:47:57 by tfavart           #+#    #+#             */
/*   Updated: 2018/06/18 13:22:03 by tfavart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ui.h"

void			ft_colonne2(t_interface *inter)
{
	inter->cont.colonne2 = gtk_box_new(GTK_ORIENTATION_VERTICAL, 8);
	gtk_container_add(GTK_CONTAINER(inter->cont.principal),
		inter->cont.colonne2);
	ft_3d_button(&(inter->fix.pos), inter->cont.colonne2, "pos");
	ft_3d_button(&(inter->triang.p1), inter->cont.colonne2, "point 1");
	ft_1d_button(&(inter->angle), inter->cont.colonne2, "angle");
	ft_1d_button(&(inter->rad), inter->cont.colonne2, "rad");
	ft_switch(&(inter->specular), inter->cont.colonne2, "specular");
	ft_switch(&(inter->sepia), inter->cont.colonne2, "sepia");
	ft_switch(&(inter->refract.on_off), inter->cont.colonne2, "refract");
	ft_1d_button(&(inter->refract.material), inter->cont.colonne2,
		"refract material");
	ft_1d_button(&(inter->refract.pourcent), inter->cont.colonne2,
		"refract %");
	ft_switch(&(inter->reflect.on_off), inter->cont.colonne2, "reflect");
	ft_1d_button(&(inter->reflect.pourcent), inter->cont.colonne2,
		"reflect %");
}
