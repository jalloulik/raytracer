/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_entry.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfavart <tfavart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 17:12:47 by tfavart           #+#    #+#             */
/*   Updated: 2018/06/19 11:46:01 by tfavart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ui.h"

void		ft_set_3d_entry(t_3d_button *entry, t_3d elem)
{
	char	*tmp;

	tmp = ft_itoa(elem.x);
	gtk_entry_set_text(GTK_ENTRY(entry->x), tmp);
	free(tmp);
	tmp = ft_itoa(elem.y);
	gtk_entry_set_text(GTK_ENTRY(entry->y), tmp);
	free(tmp);
	tmp = ft_itoa(elem.z);
	gtk_entry_set_text(GTK_ENTRY(entry->z), tmp);
	free(tmp);
}

void		ft_set_2d_entry(t_2d_button *entry, t_2d elem)
{
	char	*tmp;

	tmp = ft_itoa(elem.x);
	gtk_entry_set_text(GTK_ENTRY(entry->x), tmp);
	free(tmp);
	tmp = ft_itoa(elem.y);
	gtk_entry_set_text(GTK_ENTRY(entry->y), tmp);
	free(tmp);
}

void		ft_set_1d_entry_int(t_1d_button *entry, int elem)
{
	char	*tmp;

	tmp = ft_itoa(elem);
	gtk_entry_set_text(GTK_ENTRY(entry->x), tmp);
	free(tmp);
}

void		ft_set_1d_entry_char(t_1d_button *entry, char *elem)
{
	gtk_entry_set_text(GTK_ENTRY(entry->x), elem);
}
