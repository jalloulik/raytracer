/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sinus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfavart <tfavart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 10:49:30 by tfavart           #+#    #+#             */
/*   Updated: 2018/06/11 15:47:16 by tfavart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ui.h"

void		ft_init_sinus(t_interface *inter)
{
	ft_init_1d_button(&inter->sinus.on_off);
	ft_init_2d_button(&inter->sinus.sin_x);
	ft_init_2d_button(&inter->sinus.sin_y);
	ft_init_2d_button(&inter->sinus.sin_z);
}