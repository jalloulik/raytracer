/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_function3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfavart <tfavart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 13:57:08 by tfavart           #+#    #+#             */
/*   Updated: 2018/06/20 21:45:22 by tfavart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ui.h"

void		ft_parse_angle(t_elem *elem, int fd)
{
	ft_putstr_fd("<angle>", fd);
	ft_putnbr_fd(elem->angle, fd);
	ft_putstr_fd("</angle>\n", fd);
}

void		ft_parse_rad(t_elem *elem, int fd)
{
	ft_putstr_fd("<radius>", fd);
	ft_putnbr_fd(elem->rad, fd);
	ft_putstr_fd("</radius>\n", fd);
}

void		ft_parse_intensity(t_elem *elem, int fd)
{
	ft_putstr_fd("<intensity>", fd);
	ft_putnbr_fd(elem->intensity, fd);
	ft_putstr_fd("</intensity>\n", fd);
}

void		ft_parse_rayon_torre(t_elem *elem, int fd)
{
	ft_putstr_fd("<r1>", fd);
	ft_putnbr_fd(elem->rayon_torre.x, fd);
	ft_putstr_fd("</r1>\n", fd);
	ft_putstr_fd("<r2>", fd);
	ft_putnbr_fd(elem->rayon_torre.y, fd);
	ft_putstr_fd("</r2>\n", fd);
}

void		ft_parse_size(t_elem *elem, int fd)
{
	ft_putstr_fd("<size>", fd);
	ft_put_2d(elem->size, fd);
	ft_putstr_fd("</size>\n", fd);
}
