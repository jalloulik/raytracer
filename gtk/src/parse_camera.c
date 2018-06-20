/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfavart <tfavart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 14:34:42 by tfavart           #+#    #+#             */
/*   Updated: 2018/06/20 21:44:13 by tfavart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ui.h"

void		ft_parse_camera(t_elem *elem, int fd)
{
	if (elem->type == CAM)
	{
		ft_putstr_fd("<cam>\n", fd);
		ft_parse_origin(elem, fd);
		ft_parse_rotation(elem, fd);
		ft_parse_translation(elem, fd);
		if (elem->sepia == 1)
			ft_putstr_fd("<sepia>true</sepia>\n", fd);
		else
			ft_putstr_fd("<sepia>false</sepia>\n", fd);
		ft_putstr_fd("</cam>\n", fd);
	}
}
