/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfavart <tfavart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 14:35:54 by tfavart           #+#    #+#             */
/*   Updated: 2018/06/20 13:29:10 by tfavart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ui.h"

static void	ft_spot(t_elem *elem, int fd)
{
	ft_putstr_fd("<spot>\n", fd);
	ft_parse_origin(elem, fd);
	ft_parse_intensity(elem, fd);
	ft_putstr_fd("</spot>\n", fd);
}

static void	ft_sun(t_elem *elem, int fd)
{
	ft_putstr_fd("<sun>\n", fd);
	ft_parse_origin(elem, fd);
	ft_parse_intensity(elem, fd);
	ft_putstr_fd("</sun>\n", fd);
}

static void	ft_ambiant(t_elem *elem, int fd)
{
	ft_putstr_fd("<ambiant>\n", fd);
	ft_parse_intensity(elem, fd);
	ft_putstr_fd("</ambiant>\n", fd);
}

void		ft_parse_light(t_elem *elem, int fd)
{
	if (elem->type == SPOT)
		ft_spot(elem, fd);
	if (elem->type == SUN)
		ft_sun(elem, fd);
	if (elem->type == AMBIANT)
		ft_ambiant(elem, fd);
}