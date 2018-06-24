/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_entry_cut.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfavart <tfavart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 11:38:40 by tfavart           #+#    #+#             */
/*   Updated: 2018/06/24 17:19:17 by tfavart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ui.h"

static void	ft_type_entry_cut_3(GtkWidget *type, int **value,
	t_elem *elem, t_interface *inter)
{
	if (type == inter->cut.origin_5.x)
		*value = &elem->cut.origin_5.x;
	if (type == inter->cut.origin_5.y)
		*value = &elem->cut.origin_5.y;
	if (type == inter->cut.origin_5.z)
		*value = &elem->cut.origin_5.z;
	if (type == inter->cut.axe_5.x)
		*value = &elem->cut.axe_5.x;
	if (type == inter->cut.axe_5.y)
		*value = &elem->cut.axe_5.y;
	if (type == inter->cut.axe_5.z)
		*value = &elem->cut.axe_5.z;
	if (type == inter->cut.origin_6.x)
		*value = &elem->cut.origin_6.x;
	if (type == inter->cut.origin_6.y)
		*value = &elem->cut.origin_6.y;
	if (type == inter->cut.origin_6.z)
		*value = &elem->cut.origin_6.z;
	if (type == inter->cut.axe_6.x)
		*value = &elem->cut.axe_6.x;
	if (type == inter->cut.axe_6.y)
		*value = &elem->cut.axe_6.y;
	if (type == inter->cut.axe_6.z)
		*value = &elem->cut.axe_6.z;
}

static void	ft_type_entry_cut_2(GtkWidget *type, int **value,
	t_elem *elem, t_interface *inter)
{
	if (type == inter->cut.origin_3.x)
		*value = &elem->cut.origin_3.x;
	if (type == inter->cut.origin_3.y)
		*value = &elem->cut.origin_3.y;
	if (type == inter->cut.origin_3.z)
		*value = &elem->cut.origin_3.z;
	if (type == inter->cut.axe_3.x)
		*value = &elem->cut.axe_3.x;
	if (type == inter->cut.axe_3.y)
		*value = &elem->cut.axe_3.y;
	if (type == inter->cut.axe_3.z)
		*value = &elem->cut.axe_3.z;
	if (type == inter->cut.origin_4.x)
		*value = &elem->cut.origin_4.x;
	if (type == inter->cut.origin_4.y)
		*value = &elem->cut.origin_4.y;
	if (type == inter->cut.origin_4.z)
		*value = &elem->cut.origin_4.z;
	if (type == inter->cut.axe_4.x)
		*value = &elem->cut.axe_4.x;
	if (type == inter->cut.axe_4.y)
		*value = &elem->cut.axe_4.y;
	if (type == inter->cut.axe_4.z)
		*value = &elem->cut.axe_4.z;
}

static void	ft_type_entry_cut_1(GtkWidget *type, int **value,
	t_elem *elem, t_interface *inter)
{
	if (type == inter->cut.origin_1.x)
		*value = &elem->cut.origin_1.x;
	if (type == inter->cut.origin_1.y)
		*value = &elem->cut.origin_1.y;
	if (type == inter->cut.origin_1.z)
		*value = &elem->cut.origin_1.z;
	if (type == inter->cut.axe_1.x)
		*value = &elem->cut.axe_1.x;
	if (type == inter->cut.axe_1.y)
		*value = &elem->cut.axe_1.y;
	if (type == inter->cut.axe_1.z)
		*value = &elem->cut.axe_1.z;
	if (type == inter->cut.origin_2.x)
		*value = &elem->cut.origin_2.x;
	if (type == inter->cut.origin_2.y)
		*value = &elem->cut.origin_2.y;
	if (type == inter->cut.origin_2.z)
		*value = &elem->cut.origin_2.z;
	if (type == inter->cut.axe_2.x)
		*value = &elem->cut.axe_2.x;
	if (type == inter->cut.axe_2.y)
		*value = &elem->cut.axe_2.y;
	if (type == inter->cut.axe_2.z)
		*value = &elem->cut.axe_2.z;
}

void		ft_type_entry_cut(GtkWidget *type, int **value,
	t_elem *elem, t_interface *inter)
{
	ft_type_entry_cut_1(type, value, elem, inter);
	ft_type_entry_cut_2(type, value, elem, inter);
	ft_type_entry_cut_3(type, value, elem, inter);
}
