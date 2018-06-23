/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cut.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfavart <tfavart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 09:25:55 by tfavart           #+#    #+#             */
/*   Updated: 2018/06/23 10:59:25 by tfavart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ui.h"

void		ft_init_cut(t_interface *inter)
{
	ft_init_1d_button(&(inter->cut.on_off));
	ft_init_3d_button(&(inter->cut.origin_1));
	ft_init_3d_button(&(inter->cut.axe_1));
	ft_init_3d_button(&(inter->cut.origin_2));
	ft_init_3d_button(&(inter->cut.axe_2));
	ft_init_3d_button(&(inter->cut.origin_3));
	ft_init_3d_button(&(inter->cut.axe_3));
	ft_init_3d_button(&(inter->cut.origin_4));
	ft_init_3d_button(&(inter->cut.axe_4));
	ft_init_3d_button(&(inter->cut.origin_5));
	ft_init_3d_button(&(inter->cut.axe_5));
	ft_init_3d_button(&(inter->cut.origin_6));
	ft_init_3d_button(&(inter->cut.axe_6));
}
