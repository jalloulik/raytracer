/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfavart <tfavart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 14:51:49 by tfavart           #+#    #+#             */
/*   Updated: 2018/06/19 15:09:07 by tfavart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ui.h"

void		ft_put_3d(t_3d elem, int fd)
{
	ft_putstr_fd("<x>", fd);
	ft_putnbr_fd(elem.x, fd);
	ft_putstr_fd("</x>", fd);
	ft_putstr_fd("<y>", fd);
	ft_putnbr_fd(elem.y, fd);
	ft_putstr_fd("</y>", fd);
	ft_putstr_fd("<z>", fd);
	ft_putnbr_fd(elem.z, fd);
	ft_putstr_fd("</z>", fd);
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
