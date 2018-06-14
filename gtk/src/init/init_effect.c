/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_effect.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfavart <tfavart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 10:32:07 by tfavart           #+#    #+#             */
/*   Updated: 2018/06/14 11:30:54 by tfavart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ui.h"

void		ft_init_2d_button(t_2d_button *button)
{
	button->label_x = NULL;
	button->x = NULL;
	button->label_y = NULL;
	button->y = NULL;
}

static void	ft_init_reflect(t_interface *inter)
{
	ft_init_1d_button(&inter->reflect.on_off);
	ft_init_1d_button(&inter->reflect.pourcent);
}

static void	ft_init_refract(t_interface *inter)
{
	ft_init_1d_button(&inter->refract.on_off);
	ft_init_1d_button(&inter->refract.pourcent);
	ft_init_1d_button(&inter->refract.material);
}

static void	ft_init_texture(t_texture_ui *texture)
{
	ft_init_1d_button(&texture->on_off);
	ft_init_1d_button(&texture->name);
	ft_init_2d_button(&texture->move);
	ft_init_2d_button(&texture->scale);
}

void	ft_init_effect(t_interface *inter)
{
	ft_init_reflect(inter);
	ft_init_refract(inter);
	ft_init_texture(&inter->tex_c);
	ft_init_texture(&inter->tex_n);
	ft_init_sinus(inter);
}