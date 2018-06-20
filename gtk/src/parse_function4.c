/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_function4.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfavart <tfavart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 12:38:42 by tfavart           #+#    #+#             */
/*   Updated: 2018/06/20 21:35:00 by tfavart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ui.h"

void		ft_parse_reflect(t_elem *elem, int fd)
{
	if (elem->reflect.on_off == 1)
	{
		ft_putstr_fd("<reflect>\n", fd);
		ft_putstr_fd("<status>true</status>\n", fd);
		ft_putstr_fd("<ratio>", fd);
		ft_putnbr_fd(elem->reflect.pourcent, fd);
		ft_putstr_fd("</ratio>\n", fd);
		ft_putstr_fd("</reflect>\n", fd);
	}
}

void		ft_parse_refract(t_elem *elem, int fd)
{
	if (elem->refract.on_off == 1)
	{
		ft_putstr_fd("<refract>\n", fd);
		ft_putstr_fd("<status>true</status>\n", fd);
		ft_putstr_fd("<ratio>", fd);
		ft_putnbr_fd(elem->refract.pourcent, fd);
		ft_putstr_fd("</ratio>\n", fd);
		ft_putstr_fd("<material>", fd);
		ft_putstr_fd(elem->refract.material, fd);
		ft_putstr_fd("</material>\n", fd);
		ft_putstr_fd("</refract>\n", fd);
	}
}

void		ft_parse_texture(t_elem *elem, int fd)
{
	if (elem->tex_c.on_off == 1)
	{
		ft_putstr_fd("<texture>\n", fd);
		ft_putstr_fd("<status>true</status>\n", fd);
		ft_putstr_fd("<file>", fd);
		ft_putstr_fd(elem->tex_c.name, fd);
		ft_putstr_fd("</file>\n", fd);
		ft_putstr_fd("<scale>", fd);
		ft_put_2d(elem->tex_c.scale, fd);
		ft_putstr_fd("</scale>\n", fd);
		ft_putstr_fd("<mov>", fd);
		ft_put_2d(elem->tex_c.move, fd);
		ft_putstr_fd("</mov>\n", fd);
		ft_putstr_fd("</texture>\n", fd);
	}
}

void		ft_parse_normal(t_elem *elem, int fd)
{
	if (elem->tex_n.on_off == 1)
	{
		ft_putstr_fd("<normal>\n", fd);
		ft_putstr_fd("<status>true</status>\n", fd);
		ft_putstr_fd("<file>", fd);
		ft_putstr_fd(elem->tex_n.name, fd);
		ft_putstr_fd("</file>\n", fd);
		ft_putstr_fd("<scale>", fd);
		ft_put_2d(elem->tex_n.scale, fd);
		ft_putstr_fd("</scale>\n", fd);
		ft_putstr_fd("<mov>", fd);
		ft_put_2d(elem->tex_n.move, fd);
		ft_putstr_fd("</mov>\n", fd);
		ft_putstr_fd("</normal>\n", fd);
	}
}
