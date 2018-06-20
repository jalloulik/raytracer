/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_function5.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfavart <tfavart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 13:19:52 by tfavart           #+#    #+#             */
/*   Updated: 2018/06/20 14:04:22 by tfavart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ui.h"

static void	ft_sinx(t_elem *elem, int fd)
{
	ft_putstr_fd("<sinx>", fd);
	ft_putstr_fd("<a>", fd);
	ft_putnbr_fd(elem->sinus.sin_x.x, fd);
	ft_putstr_fd("</a>", fd);
	ft_putstr_fd("<b>", fd);
	ft_putnbr_fd(elem->sinus.sin_x.y, fd);
	ft_putstr_fd("</b>", fd);
	ft_putstr_fd("</sinx>", fd);
}

void		ft_parse_sinus(t_elem *elem, int fd)
{
	if (elem->sinus.on_off == 1)
	{
		ft_sinx(elem, fd);
		ft_putstr_fd("<siny>", fd);
		ft_putstr_fd("<a>", fd);
		ft_putnbr_fd(elem->sinus.sin_y.x, fd);
		ft_putstr_fd("</a>", fd);
		ft_putstr_fd("<b>", fd);
		ft_putnbr_fd(elem->sinus.sin_y.y, fd);
		ft_putstr_fd("</b>", fd);
		ft_putstr_fd("</siny>", fd);
		ft_putstr_fd("<sinz>", fd);
		ft_putstr_fd("<a>", fd);
		ft_putnbr_fd(elem->sinus.sin_z.x, fd);
		ft_putstr_fd("</a>", fd);
		ft_putstr_fd("<b>", fd);
		ft_putnbr_fd(elem->sinus.sin_z.y, fd);
		ft_putstr_fd("</b>", fd);
		ft_putstr_fd("</sinz>", fd);
	}
}
