/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfavart <tfavart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 14:51:49 by tfavart           #+#    #+#             */
/*   Updated: 2018/06/20 13:55:20 by tfavart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ui.h"

void		ft_put_3d(t_3d elem, int fd)
{
	ft_putnbr_fd(elem.x, fd);
	ft_putstr_fd(":", fd);
	ft_putnbr_fd(elem.y, fd);
	ft_putstr_fd(":", fd);
	ft_putnbr_fd(elem.z, fd);
}

void		ft_put_2d(t_2d elem, int fd)
{
	ft_putstr_fd("<x>", fd);
	ft_putnbr_fd(elem.x, fd);
	ft_putstr_fd("</x>", fd);
	ft_putstr_fd("<y>", fd);
	ft_putnbr_fd(elem.y, fd);
	ft_putstr_fd("</y>", fd);
}

void		ft_parse_checker(t_elem *elem, int fd)
{
	ft_putstr_fd("<checker>", fd);
	if (elem->checker.on_off == 1)
	{
		ft_putstr_fd("<status>true</status>", fd);
		ft_putstr_fd("<scale>", fd);
		ft_put_2d(elem->checker.scale, fd);
		ft_putstr_fd("</scale>", fd);
		ft_putstr_fd("<move>", fd);
		ft_put_2d(elem->checker.move, fd);
		ft_putstr_fd("</move>", fd);
	}
	else
		ft_putstr_fd("<status>false</status>", fd);
	ft_putstr_fd("</checker>", fd);
}

void		ft_parse_triang_p(t_elem *elem, int fd)
{
	ft_putstr_fd("<p1>", fd);
	ft_put_3d(elem->triang.p1, fd);
	ft_putstr_fd("</p1>", fd);
	ft_putstr_fd("<p2>", fd);
	ft_put_3d(elem->triang.p2, fd);
	ft_putstr_fd("</p2>", fd);
	ft_putstr_fd("<p3>", fd);
	ft_put_3d(elem->triang.p3, fd);
	ft_putstr_fd("</p3>", fd);
}