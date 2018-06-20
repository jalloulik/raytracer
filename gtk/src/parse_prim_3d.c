/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_prim_3d.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfavart <tfavart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 14:35:20 by tfavart           #+#    #+#             */
/*   Updated: 2018/06/20 21:45:34 by tfavart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ui.h"

static void	ft_parse_sphere(t_elem *elem, int fd)
{
	ft_putstr_fd("<sphere>\n", fd);
	ft_parse_origin(elem, fd);
	ft_parse_rotation(elem, fd);
	ft_parse_translation(elem, fd);
	ft_parse_color(elem, fd);
	ft_parse_rad(elem, fd);
	ft_parse_reflect(elem, fd);
	ft_parse_refract(elem, fd);
	ft_parse_texture(elem, fd);
	ft_parse_normal(elem, fd);
	ft_parse_sinus(elem, fd);
	ft_parse_checker(elem, fd);
	ft_putstr_fd("</sphere>\n", fd);
}

static void	ft_parse_cone(t_elem *elem, int fd)
{
	ft_putstr_fd("<cone>\n", fd);
	ft_parse_origin(elem, fd);
	ft_parse_rotation(elem, fd);
	ft_parse_translation(elem, fd);
	ft_parse_vec(elem, fd);
	ft_parse_color(elem, fd);
	ft_parse_angle(elem, fd);
	ft_parse_reflect(elem, fd);
	ft_parse_refract(elem, fd);
	ft_parse_texture(elem, fd);
	ft_parse_normal(elem, fd);
	ft_parse_sinus(elem, fd);
	ft_parse_checker(elem, fd);
	ft_putstr_fd("</cone>\n", fd);
}

static void	ft_parse_cylindre(t_elem *elem, int fd)
{
	ft_putstr_fd("<cylinder>\n", fd);
	ft_parse_origin(elem, fd);
	ft_parse_rotation(elem, fd);
	ft_parse_translation(elem, fd);
	ft_parse_vec(elem, fd);
	ft_parse_color(elem, fd);
	ft_parse_rad(elem, fd);
	ft_parse_reflect(elem, fd);
	ft_parse_refract(elem, fd);
	ft_parse_texture(elem, fd);
	ft_parse_normal(elem, fd);
	ft_parse_sinus(elem, fd);
	ft_parse_checker(elem, fd);
	ft_putstr_fd("</cylinder>\n", fd);
}

static void	ft_parse_plan(t_elem *elem, int fd)
{
	ft_putstr_fd("<plane>\n", fd);
	ft_parse_origin(elem, fd);
	ft_parse_rotation(elem, fd);
	ft_parse_translation(elem, fd);
	ft_parse_vec(elem, fd);
	ft_parse_color(elem, fd);
	ft_parse_reflect(elem, fd);
	ft_parse_refract(elem, fd);
	ft_parse_texture(elem, fd);
	ft_parse_normal(elem, fd);
	ft_parse_sinus(elem, fd);
	ft_parse_checker(elem, fd);
	ft_putstr_fd("</plane>\n", fd);
}

void		ft_parse_prim_3d(t_elem *elem, int fd)
{
	if (elem->type == SPHERE)
		ft_parse_sphere(elem, fd);
	if (elem->type == CONE)
		ft_parse_cone(elem, fd);
	if (elem->type == CYLINDRE)
		ft_parse_cylindre(elem, fd);
	if (elem->type == PLAN)
		ft_parse_plan(elem, fd);
}
