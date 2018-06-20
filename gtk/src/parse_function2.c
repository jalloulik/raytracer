/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_function2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfavart <tfavart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 11:40:39 by tfavart           #+#    #+#             */
/*   Updated: 2018/06/20 14:04:49 by tfavart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ui.h"

void		ft_parse_origin(t_elem *elem, int fd)
{
	ft_putstr_fd("<origin>", fd);
	ft_put_3d(elem->pos, fd);
	ft_putstr_fd("</origin>", fd);
}

void		ft_parse_translation(t_elem *elem, int fd)
{
	ft_putstr_fd("<translation>", fd);
	ft_put_3d(elem->translation, fd);
	ft_putstr_fd("</translation>", fd);
}

void		ft_parse_vec(t_elem *elem, int fd)
{
	ft_putstr_fd("<vec>", fd);
	ft_put_3d(elem->vec, fd);
	ft_putstr_fd("</vec>", fd);
}

void		ft_parse_rotation(t_elem *elem, int fd)
{
	ft_putstr_fd("<rotation>", fd);
	ft_putstr_fd("<axis>", fd);
	ft_put_3d(elem->rot, fd);
	ft_putstr_fd("</axis>", fd);
	ft_putstr_fd("<angle>", fd);
	ft_putnbr_fd(elem->angle_rot, fd);
	ft_putstr_fd("</angle>", fd);
	ft_putstr_fd("</rotation>", fd);
}

void		ft_parse_color(t_elem *elem, int fd)
{
	ft_putstr_fd("<color>", fd);
	ft_put_3d(elem->color, fd);
	ft_putstr_fd("</color>", fd);
}
