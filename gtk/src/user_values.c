/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user_values.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfavart <tfavart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 14:13:12 by tfavart           #+#    #+#             */
/*   Updated: 2018/06/12 16:00:57 by tfavart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ui.h"

static void			ft_type(GtkWidget *type, int **value,
t_elem *elem, t_interface *inter)
{
	if (type == inter->fix.pos.x)
		*value = &elem->pos.x;
	if (type == inter->fix.pos.y)
		*value = &elem->pos.y;
	if (type == inter->fix.pos.z)
		*value = &elem->pos.z;
	if (type == inter->fix.translation.x)
		*value = &elem->translation.x;
	if (type == inter->fix.translation.y)
		*value = &elem->translation.y;
	if (type == inter->fix.translation.z)
		*value = &elem->translation.z;
	if (type == inter->fix.vec.x)
		*value = &elem->vec.x;
	if (type == inter->fix.vec.y)
		*value = &elem->vec.y;
	if (type == inter->fix.vec.z)
		*value = &elem->vec.z;
	if (type == inter->fix.rot.x)
		*value = &elem->rot.x;
	if (type == inter->fix.rot.y)
		*value = &elem->rot.y;
	if (type == inter->fix.rot.z)
		*value = &elem->rot.z;
}

void				ft_entry_value(GtkWidget *widget, gpointer data)
{
	t_event_entry	*e;
	t_elem			*elem;

	e = (t_event_entry *)data;
	elem = e->inter->list_e;
	if (gtk_combo_box_get_active_iter(GTK_COMBO_BOX(e->inter->list.button), &e->iter))
	{
		while (elem)
		{
			gtk_tree_model_get(GTK_TREE_MODEL(e->inter->list.store), &e->iter,
			0, &e->index1, 1, &e->p_text1, -1);
			gtk_tree_model_get(GTK_TREE_MODEL(e->inter->list.store), &elem->iter,
			0, &e->index2, 1, &e->p_text2, -1);
			if (ft_strcmp(e->p_text1, e->p_text2) == 0)
			{
				ft_type(widget, &e->value, elem, e->inter);
				*e->value = ft_atoi(gtk_entry_get_text(GTK_ENTRY(widget)));
				break ;
			}
			elem = elem->next;
		}
	}
}
