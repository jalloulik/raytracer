/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfavart <tfavart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 15:21:15 by tfavart           #+#    #+#             */
/*   Updated: 2018/06/19 14:09:00 by tfavart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ui.h"

void			ft_render(GtkWidget *widget, gpointer data)
{
	int			fd;
	t_elem		*elem;
	t_interface	*inter;

	(void)widget;
	inter = (t_interface*)data;
	elem = inter->list_e;
	fd = open("./scene.xml", O_WRONLY);
	while (elem)
	{
		printf("%d\n", elem->type);
		elem = elem->next;
	}
	close(fd);
}
