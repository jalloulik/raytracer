/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entry_values.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfavart <tfavart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 12:12:58 by tfavart           #+#    #+#             */
/*   Updated: 2018/06/18 13:42:15 by tfavart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ui.h"

static void			ft_type_int(GtkWidget *type, int **value,
	t_elem *elem, t_interface *inter)
{
	ft_type_entry_1(type, value, elem, inter);
	ft_type_entry_2(type, value, elem, inter);
	ft_type_entry_3(type, value, elem, inter);
	ft_type_entry_4(type, value, elem, inter);
	ft_type_entry_5(type, value, elem, inter);
}

static void			ft_type_char(GtkWidget *type, char ***value,
	t_elem *elem, t_interface *inter)
{
	if (type == inter->tex_c.name.x)
		*value = &elem->tex_c.name;
	if (type == inter->tex_n.name.x)
		*value = &elem->tex_n.name;
	if (type == inter->refract.material.x)
		*value = &elem->refract.material;
}

static void			ft_char_int(t_event_entry *e,
	t_elem *elem, GtkWidget *widget)
{
	if (widget == e->inter->tex_n.name.x || widget == e->inter->tex_c.name.x
			|| widget == e->inter->refract.material.x)
	{
		ft_type_char(widget, &e->value_char, elem, e->inter);
		free(*e->value_char);
		*e->value_char = NULL;
		*e->value_char =
				ft_strdup((char*)gtk_entry_get_text(GTK_ENTRY(widget)));
	}
	else
	{
		ft_type_int(widget, &e->value, elem, e->inter);
		*e->value = ft_atoi(gtk_entry_get_text(GTK_ENTRY(widget)));
	}
}

void				ft_entry_value(GtkWidget *widget, gpointer data)
{
	t_event_entry	*e;
	t_elem			*elem;

	e = (t_event_entry *)data;
	elem = e->inter->list_e;
	if (gtk_combo_box_get_active_iter(GTK_COMBO_BOX(e->inter->list.button),
		&e->iter))
	{
		while (elem)
		{
			gtk_tree_model_get(GTK_TREE_MODEL(e->inter->list.store),
				&e->iter, 0, &e->index1, 1, &e->p_text1, -1);
			gtk_tree_model_get(GTK_TREE_MODEL(e->inter->list.store),
				&elem->iter, 0, &e->index2, 1, &e->p_text2, -1);
			if (ft_strcmp(e->p_text1, e->p_text2) == 0)
			{
				ft_char_int(e, elem, widget);
				break ;
			}
			elem = elem->next;
		}
	}
}
