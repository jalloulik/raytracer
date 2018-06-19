/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_prim_2d.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfavart <tfavart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 14:35:37 by tfavart           #+#    #+#             */
/*   Updated: 2018/06/19 16:34:43 by tfavart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ui.h"

static void	ft_parse_cercle(t_elem *elem, int fd)
{
	ft_putstr_fd("<cercle>\n", fd);
	ft_putstr_fd("<origin>", fd);
	ft_put_3d(elem->pos, fd);
	ft_putstr_fd("</origin>\n", fd);
	ft_putstr_fd("</cercle>\n", fd);
}

static void	ft_parse_carre(t_elem *elem, int fd)
{
	ft_putstr_fd("<carre>\n", fd);
	ft_putstr_fd("<origin>", fd);
	ft_put_3d(elem->pos, fd);
	ft_putstr_fd("</origin>\n", fd);
	ft_putstr_fd("</carre>\n", fd);
}

static void	ft_parse_triangle(t_elem *elem, int fd)
{
	ft_putstr_fd("<triangle>\n", fd);
	ft_putstr_fd("<origin>", fd);
	ft_put_3d(elem->pos, fd);
	ft_putstr_fd("</origin>\n", fd);
	ft_putstr_fd("</triangle>\n", fd);
}

static void	ft_parse_torre(t_elem *elem, int fd)
{
	ft_putstr_fd("<torre>\n", fd);
	ft_putstr_fd("<origin>", fd);
	ft_put_3d(elem->pos, fd);
	ft_putstr_fd("</origin>\n", fd);
	ft_putstr_fd("</torre>\n", fd);
}

void		ft_parse_prim_2d(t_elem *elem, int fd)
{
	if (elem->type == CERCLE)
		ft_parse_cercle(elem, fd);
	if (elem->type == CARRE)
		ft_parse_carre(elem, fd);
	if (elem->type == TRIANGLE)
		ft_parse_triangle(elem, fd);
	if (elem->type == TORRE)
		ft_parse_torre(elem, fd);
}