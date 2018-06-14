/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfavart <tfavart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 12:47:03 by tfavart           #+#    #+#             */
/*   Updated: 2018/06/11 15:47:37 by tfavart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ui.h"

void		ft_init_checker(t_interface *inter)
{
	ft_init_1d_button(&inter->checker.on_off);
	ft_init_2d_button(&inter->checker.move);
	ft_init_2d_button(&inter->checker.scale);
}