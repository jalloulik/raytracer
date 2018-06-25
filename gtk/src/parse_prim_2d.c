/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_prim_2d.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfavart <tfavart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 14:35:37 by tfavart           #+#    #+#             */
/*   Updated: 2018/06/25 17:50:07 by tfavart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ui.h"

static void	ft_parse_cercle(t_elem *elem, int fd)
{
	ft_putstr_fd("<cercle>\n", fd);
	ft_parse_origin(elem, fd);
	ft_parse_vec(elem, fd);
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
	ft_parse_specular(elem, fd);
	ft_putstr_fd("</cercle>\n", fd);
}

static void	ft_parse_carre(t_elem *elem, int fd)
{
	ft_putstr_fd("<rect>\n", fd);
	ft_parse_origin(elem, fd);
	ft_parse_vec(elem, fd);
	ft_parse_rotation(elem, fd);
	ft_parse_translation(elem, fd);
	ft_parse_color(elem, fd);
	ft_parse_size(elem, fd);
	ft_parse_reflect(elem, fd);
	ft_parse_refract(elem, fd);
	ft_parse_texture(elem, fd);
	ft_parse_normal(elem, fd);
	ft_parse_sinus(elem, fd);
	ft_parse_checker(elem, fd);
	ft_parse_specular(elem, fd);
	ft_putstr_fd("</rect>\n", fd);
}

void		ft_parse_triangle(t_elem *elem, int fd)
{
	ft_putstr_fd("<triangle>\n", fd);
	ft_parse_triang_p(elem, fd);
	ft_parse_rotation(elem, fd);
	ft_parse_translation(elem, fd);
	ft_parse_color(elem, fd);
	ft_parse_reflect(elem, fd);
	ft_parse_refract(elem, fd);
	ft_parse_texture(elem, fd);
	ft_parse_normal(elem, fd);
	ft_parse_sinus(elem, fd);
	ft_parse_checker(elem, fd);
	ft_parse_specular(elem, fd);
	ft_putstr_fd("</triangle>\n", fd);
}

static void	ft_parse_torre(t_elem *elem, int fd)
{
	ft_putstr_fd("<tore>\n", fd);
	ft_parse_origin(elem, fd);
	ft_parse_rotation(elem, fd);
	ft_parse_vec(elem, fd);
	ft_parse_translation(elem, fd);
	ft_parse_color(elem, fd);
	ft_parse_rayon_torre(elem, fd);
	ft_parse_reflect(elem, fd);
	ft_parse_refract(elem, fd);
	ft_parse_texture(elem, fd);
	ft_parse_normal(elem, fd);
	ft_parse_sinus(elem, fd);
	ft_parse_checker(elem, fd);
	ft_parse_specular(elem, fd);
	ft_putstr_fd("</tore>\n", fd);
}

void		ft_parse_prim_2d(t_elem *elem, int fd)
{
	if (elem->type == CERCLE)
		ft_parse_cercle(elem, fd);
	if (elem->type == CARRE)
		ft_parse_carre(elem, fd);
	if (elem->type == TORRE)
		ft_parse_torre(elem, fd);
}
