/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfavart <tfavart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 14:35:54 by tfavart           #+#    #+#             */
/*   Updated: 2018/06/19 15:15:08 by tfavart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ui.h"

static void	ft_spot(t_elem *elem, int fd)
{
	ft_putstr_fd("<spot>\n", fd);
	ft_putstr_fd("<origin>", fd);
	ft_put_3d(elem->pos, fd);
	ft_putstr_fd("</origin>\n", fd);
	ft_putstr_fd("<intensity>", fd);
	ft_putnbr_fd(elem->intensity, fd);
	ft_putstr_fd("</intensity>\n", fd);
	ft_putstr_fd("</spot>\n", fd);
}

static void	ft_sun(t_elem *elem, int fd)
{
	ft_putstr_fd("<sun>\n", fd);
	ft_putstr_fd("<origin>", fd);
	ft_put_3d(elem->pos, fd);
	ft_putstr_fd("</origin>\n", fd);
	ft_putstr_fd("<intensity>", fd);
	ft_putnbr_fd(elem->intensity, fd);
	ft_putstr_fd("</intensity>\n", fd);
	ft_putstr_fd("</sun>\n", fd);
}

static void	ft_ambiant(t_elem *elem, int fd)
{
	ft_putstr_fd("<ambiant>\n", fd);
	ft_putstr_fd("<intensity>", fd);
	ft_putnbr_fd(elem->intensity, fd);
	ft_putstr_fd("</intensity>\n", fd);
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