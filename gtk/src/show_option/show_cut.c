/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_cut.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfavart <tfavart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 10:43:03 by tfavart           #+#    #+#             */
/*   Updated: 2018/06/23 12:28:22 by tfavart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ui.h"

static void	ft_show_cut_4(t_interface *inter)
{
	gtk_widget_show_now(inter->cut.origin_1.label_x);
	gtk_widget_show_now(inter->cut.origin_1.x);
	gtk_widget_show_now(inter->cut.origin_1.label_y);
	gtk_widget_show_now(inter->cut.origin_1.y);
	gtk_widget_show_now(inter->cut.origin_1.label_z);
	gtk_widget_show_now(inter->cut.origin_1.z);
	gtk_widget_show_now(inter->cut.axe_1.label_x);
	gtk_widget_show_now(inter->cut.axe_1.x);
	gtk_widget_show_now(inter->cut.axe_1.label_y);
	gtk_widget_show_now(inter->cut.axe_1.y);
	gtk_widget_show_now(inter->cut.axe_1.label_z);
	gtk_widget_show_now(inter->cut.axe_1.z);
	gtk_widget_show_now(inter->cut.origin_6.label_x);
	gtk_widget_show_now(inter->cut.origin_6.x);
	gtk_widget_show_now(inter->cut.origin_6.label_y);
	gtk_widget_show_now(inter->cut.origin_6.y);
	gtk_widget_show_now(inter->cut.origin_6.label_z);
	gtk_widget_show_now(inter->cut.origin_6.z);
	gtk_widget_show_now(inter->cut.axe_6.label_x);
	gtk_widget_show_now(inter->cut.axe_6.x);
	gtk_widget_show_now(inter->cut.axe_6.label_y);
	gtk_widget_show_now(inter->cut.axe_6.y);
	gtk_widget_show_now(inter->cut.axe_6.label_z);
	gtk_widget_show_now(inter->cut.axe_6.z);
}

static void	ft_show_cut_3(t_interface *inter)
{
	gtk_widget_show_now(inter->cut.origin_4.label_x);
	gtk_widget_show_now(inter->cut.origin_4.x);
	gtk_widget_show_now(inter->cut.origin_4.label_y);
	gtk_widget_show_now(inter->cut.origin_4.y);
	gtk_widget_show_now(inter->cut.origin_4.label_z);
	gtk_widget_show_now(inter->cut.origin_4.z);
	gtk_widget_show_now(inter->cut.axe_4.label_x);
	gtk_widget_show_now(inter->cut.axe_4.x);
	gtk_widget_show_now(inter->cut.axe_4.label_y);
	gtk_widget_show_now(inter->cut.axe_4.y);
	gtk_widget_show_now(inter->cut.axe_4.label_z);
	gtk_widget_show_now(inter->cut.axe_4.z);
	gtk_widget_show_now(inter->cut.origin_5.label_x);
	gtk_widget_show_now(inter->cut.origin_5.x);
	gtk_widget_show_now(inter->cut.origin_5.label_y);
	gtk_widget_show_now(inter->cut.origin_5.y);
	gtk_widget_show_now(inter->cut.origin_5.label_z);
	gtk_widget_show_now(inter->cut.origin_5.z);
	gtk_widget_show_now(inter->cut.axe_5.label_x);
	gtk_widget_show_now(inter->cut.axe_5.x);
	gtk_widget_show_now(inter->cut.axe_5.label_y);
	gtk_widget_show_now(inter->cut.axe_5.y);
	gtk_widget_show_now(inter->cut.axe_5.label_z);
	gtk_widget_show_now(inter->cut.axe_5.z);
}

static void	ft_show_cut_2(t_interface *inter)
{
	gtk_widget_show_now(inter->cut.origin_2.label_x);
	gtk_widget_show_now(inter->cut.origin_2.x);
	gtk_widget_show_now(inter->cut.origin_2.label_y);
	gtk_widget_show_now(inter->cut.origin_2.y);
	gtk_widget_show_now(inter->cut.origin_2.label_z);
	gtk_widget_show_now(inter->cut.origin_2.z);
	gtk_widget_show_now(inter->cut.axe_2.label_x);
	gtk_widget_show_now(inter->cut.axe_2.x);
	gtk_widget_show_now(inter->cut.axe_2.label_y);
	gtk_widget_show_now(inter->cut.axe_2.y);
	gtk_widget_show_now(inter->cut.axe_2.label_z);
	gtk_widget_show_now(inter->cut.axe_2.z);
	gtk_widget_show_now(inter->cut.origin_3.label_x);
	gtk_widget_show_now(inter->cut.origin_3.x);
	gtk_widget_show_now(inter->cut.origin_3.label_y);
	gtk_widget_show_now(inter->cut.origin_3.y);
	gtk_widget_show_now(inter->cut.origin_3.label_z);
	gtk_widget_show_now(inter->cut.origin_3.z);
	gtk_widget_show_now(inter->cut.axe_3.label_x);
	gtk_widget_show_now(inter->cut.axe_3.x);
	gtk_widget_show_now(inter->cut.axe_3.label_y);
	gtk_widget_show_now(inter->cut.axe_3.y);
	gtk_widget_show_now(inter->cut.axe_3.label_z);
	gtk_widget_show_now(inter->cut.axe_3.z);
}

void		ft_show_cut(t_interface *inter, t_elem *elem)
{
	if (elem->cut.on_off == 1)
	{
		ft_show_cut_2(inter);
		ft_show_cut_3(inter);
		ft_show_cut_4(inter);
	}
	if (elem->cut.on_off == 0)
	{
		ft_init_show_cut(inter);
	}
}
