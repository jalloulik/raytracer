/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_list_e.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfavart <tfavart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 11:50:07 by tfavart           #+#    #+#             */
/*   Updated: 2018/06/20 16:58:04 by tfavart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ui.h"

static void			ft_create_camera(t_interface *inter)
{
	t_elem		*elem;

	elem = ft_select_elem(inter);
	elem->name = "camera";
	ft_iter(&elem->iter, inter->list.store, 0, elem->name);
	elem->type = CAM;
	ft_init_elem(elem);
	elem->pos.z = 20;
}

void				ft_init_list_e(t_interface *inter)
{
	ft_create_camera(inter);
}
