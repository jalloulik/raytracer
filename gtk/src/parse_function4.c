/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_function4.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfavart <tfavart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 12:38:42 by tfavart           #+#    #+#             */
/*   Updated: 2018/06/20 14:02:07 by tfavart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ui.h"

void		ft_parse_reflect(t_elem *elem, int fd)
{
	ft_putstr_fd("<reflect>", fd);
	if (elem->reflect.on_off == 1)
	{
		ft_putstr_fd("<status>true</status>", fd);
		ft_putstr_fd("<ratio>", fd);
		ft_putnbr_fd(elem->reflect.pourcent, fd);
		ft_putstr_fd("</ratio>", fd);
	}
	else
		ft_putstr_fd("<status>false</status>", fd);
	ft_putstr_fd("</reflect>", fd);
}

void		ft_parse_refract(t_elem *elem, int fd)
{
	ft_putstr_fd("<refract>", fd);
	if (elem->refract.on_off == 1)
	{
		ft_putstr_fd("<status>true</status>", fd);
		ft_putstr_fd("<ratio>", fd);
		ft_putnbr_fd(elem->refract.pourcent, fd);
		ft_putstr_fd("</ratio>", fd);
		ft_putstr_fd("<material>", fd);
		ft_putstr_fd(elem->refract.material, fd);
		ft_putstr_fd("</material>", fd);
	}
	else
		ft_putstr_fd("<status>false</status>", fd);
	ft_putstr_fd("</refract>", fd);
}

void		ft_parse_texture(t_elem *elem, int fd)
{
	ft_putstr_fd("<texture>", fd);
	if (elem->tex_c.on_off == 1)
	{
		ft_putstr_fd("<status>true</status>", fd);
		ft_putstr_fd("<file>", fd);
		ft_putstr_fd(elem->tex_c.name, fd);
		ft_putstr_fd("</file>", fd);
		ft_putstr_fd("<scale>", fd);
		ft_put_2d(elem->tex_c.scale, fd);
		ft_putstr_fd("</scale>", fd);
		ft_putstr_fd("<move>", fd);
		ft_put_2d(elem->tex_c.move, fd);
		ft_putstr_fd("</move>", fd);
	}
	else
		ft_putstr_fd("<status>false</status>", fd);
	ft_putstr_fd("</texture>", fd);
}

void		ft_parse_normal(t_elem *elem, int fd)
{
	ft_putstr_fd("<normal>", fd);
	if (elem->tex_n.on_off == 1)
	{
		ft_putstr_fd("<status>true</status>", fd);
		ft_putstr_fd("<file>", fd);
		ft_putstr_fd(elem->tex_n.name, fd);
		ft_putstr_fd("</file>", fd);
		ft_putstr_fd("<scale>", fd);
		ft_put_2d(elem->tex_n.scale, fd);
		ft_putstr_fd("</scale>", fd);
		ft_putstr_fd("<move>", fd);
		ft_put_2d(elem->tex_n.move, fd);
		ft_putstr_fd("</move>", fd);
	}
	else
		ft_putstr_fd("<status>false</status>", fd);
	ft_putstr_fd("</normal>", fd);
}
