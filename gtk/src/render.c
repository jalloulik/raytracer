/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfavart <tfavart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 15:21:15 by tfavart           #+#    #+#             */
/*   Updated: 2018/06/19 16:11:58 by tfavart          ###   ########.fr       */
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
	ft_putstr_fd("<scene>\n", fd);
	while (elem)
	{
		ft_parse_camera(elem, fd);
		ft_parse_prim_3d(elem, fd);
		//ft_parse_prim_2d(elem, fd);
		ft_parse_light(elem, fd);
		elem = elem->next;
	}
	ft_putstr_fd("</scene>\n", fd);
	close(fd);
	system("./test");
}
