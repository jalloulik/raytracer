/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_option_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfavart <tfavart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 12:02:30 by tfavart           #+#    #+#             */
/*   Updated: 2018/06/18 14:55:28 by tfavart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ui.h"

void	ft_set_data_show_3d(t_3d_button button)
{
	gtk_widget_show_now(button.label_x);
	gtk_widget_show_now(button.x);
	gtk_widget_show_now(button.label_y);
	gtk_widget_show_now(button.y);
	gtk_widget_show_now(button.label_z);
	gtk_widget_show_now(button.z);
}

void	ft_set_data_show_2d(t_2d_button button)
{
	gtk_widget_show_now(button.label_x);
	gtk_widget_show_now(button.x);
	gtk_widget_show_now(button.label_y);
	gtk_widget_show_now(button.y);
}

void	ft_set_data_show_1d(t_1d_button button)
{
	gtk_widget_show_now(button.label_x);
	gtk_widget_show_now(button.x);
}
