/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfavart <tfavart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 14:34:42 by tfavart           #+#    #+#             */
/*   Updated: 2018/06/19 16:02:52 by tfavart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ui.h"

void		ft_parse_camera(t_elem *elem, int fd)
{
	if (elem->type == CAM)
	{
		ft_putstr_fd("<cam>\n", fd);
		ft_putstr_fd("<origin>", fd);
		ft_put_3d(elem->pos, fd);
		ft_putstr_fd("</origin>\n", fd);
		ft_putstr_fd("<rotation>", fd);
		ft_put_3d(elem->rot, fd);
		ft_putstr_fd("<angle>", fd);
		ft_putnbr_fd(elem->angle_rot, fd);
		ft_putstr_fd("</angle>", fd);
		ft_putstr_fd("</rotation>\n", fd);
		ft_putstr_fd("<translation>", fd);
		ft_put_3d(elem->translation, fd);
		ft_putstr_fd("</translation>\n", fd);
		if (elem->sepia == 1)
			ft_putstr_fd("<sepia>true</sepia>\n", fd);
		else
			ft_putstr_fd("<sepia>false</sepia>\n", fd);
		ft_putstr_fd("</cam>\n", fd);
	}
}