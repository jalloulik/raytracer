/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_entry.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfavart <tfavart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 17:12:47 by tfavart           #+#    #+#             */
/*   Updated: 2018/06/14 13:15:04 by tfavart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ui.h"

void		ft_set_3d_entry(t_3d_button *entry, t_3d elem)
{
	gtk_entry_set_text(GTK_ENTRY(entry->x), ft_itoa(elem.x));
	gtk_entry_set_text(GTK_ENTRY(entry->y), ft_itoa(elem.y));
	gtk_entry_set_text(GTK_ENTRY(entry->z), ft_itoa(elem.z));
}

void		ft_set_2d_entry(t_2d_button *entry, t_2d elem)
{
	gtk_entry_set_text(GTK_ENTRY(entry->x), ft_itoa(elem.x));
	gtk_entry_set_text(GTK_ENTRY(entry->y), ft_itoa(elem.y));
}

void		ft_set_1d_entry_int(t_1d_button *entry, int elem)
{
	gtk_entry_set_text(GTK_ENTRY(entry->x), ft_itoa(elem));
}

void		ft_set_1d_entry_char(t_1d_button *entry, char *elem)
{
	gtk_entry_set_text(GTK_ENTRY(entry->x), elem);
}
