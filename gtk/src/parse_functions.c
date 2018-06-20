/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfavart <tfavart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 14:51:49 by tfavart           #+#    #+#             */
/*   Updated: 2018/06/20 21:44:30 by tfavart          ###   ########.fr       */
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
	ft_putstr_fd("</x>\n", fd);
	ft_putstr_fd("<y>", fd);
	ft_putnbr_fd(elem.y, fd);
	ft_putstr_fd("</y>\n", fd);
}

void		ft_parse_checker(t_elem *elem, int fd)
{
	if (elem->checker.on_off == 1)
	{
		ft_putstr_fd("<checkers>\n", fd);
		ft_putstr_fd("<status>true</status>\n", fd);
		ft_putstr_fd("<scale>", fd);
		ft_put_2d(elem->checker.scale, fd);
		ft_putstr_fd("</scale>\n", fd);
		ft_putstr_fd("<mov>", fd);
		ft_put_2d(elem->checker.move, fd);
		ft_putstr_fd("</mov>\n", fd);
		ft_putstr_fd("</checkers>\n", fd);
	}
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
	ft_putstr_fd("</p3>\n", fd);
}
