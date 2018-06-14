/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_show.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfavart <tfavart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 13:41:40 by tfavart           #+#    #+#             */
/*   Updated: 2018/06/14 11:50:39 by tfavart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ui.h"

void		ft_init_show(t_interface *inter)
{
	gtk_widget_hide(inter->refract.pourcent.label_x);
	gtk_widget_hide(inter->refract.pourcent.x);
	gtk_widget_hide(inter->refract.material.label_x);
	gtk_widget_hide(inter->refract.material.x);

	gtk_widget_hide(inter->reflect.pourcent.label_x);
	gtk_widget_hide(inter->reflect.pourcent.x);

	gtk_widget_hide(inter->tex_c.name.label_x);
	gtk_widget_hide(inter->tex_c.name.x);
	gtk_widget_hide(inter->tex_c.move.label_x);
	gtk_widget_hide(inter->tex_c.move.x);
	gtk_widget_hide(inter->tex_c.move.label_y);
	gtk_widget_hide(inter->tex_c.move.y);
	gtk_widget_hide(inter->tex_c.scale.label_x);
	gtk_widget_hide(inter->tex_c.scale.x);
	gtk_widget_hide(inter->tex_c.scale.label_y);
	gtk_widget_hide(inter->tex_c.scale.y);

	gtk_widget_hide(inter->tex_n.name.label_x);
	gtk_widget_hide(inter->tex_n.name.x);
	gtk_widget_hide(inter->tex_n.move.label_x);
	gtk_widget_hide(inter->tex_n.move.x);
	gtk_widget_hide(inter->tex_n.move.label_y);
	gtk_widget_hide(inter->tex_n.move.y);
	gtk_widget_hide(inter->tex_n.scale.label_x);
	gtk_widget_hide(inter->tex_n.scale.x);
	gtk_widget_hide(inter->tex_n.scale.label_y);
	gtk_widget_hide(inter->tex_n.scale.y);

	gtk_widget_hide(inter->sinus.sin_x.label_x);
	gtk_widget_hide(inter->sinus.sin_x.x);
	gtk_widget_hide(inter->sinus.sin_x.label_y);
	gtk_widget_hide(inter->sinus.sin_x.y);
	gtk_widget_hide(inter->sinus.sin_y.label_x);
	gtk_widget_hide(inter->sinus.sin_y.x);
	gtk_widget_hide(inter->sinus.sin_y.label_y);
	gtk_widget_hide(inter->sinus.sin_y.y);
	gtk_widget_hide(inter->sinus.sin_z.label_x);
	gtk_widget_hide(inter->sinus.sin_z.x);
	gtk_widget_hide(inter->sinus.sin_z.label_y);
	gtk_widget_hide(inter->sinus.sin_z.y);

	gtk_widget_hide(inter->checker.move.label_x);
	gtk_widget_hide(inter->checker.move.x);
	gtk_widget_hide(inter->checker.move.label_y);
	gtk_widget_hide(inter->checker.move.y);
	gtk_widget_hide(inter->checker.scale.label_x);
	gtk_widget_hide(inter->checker.scale.x);
	gtk_widget_hide(inter->checker.scale.label_y);
	gtk_widget_hide(inter->checker.scale.y);
}