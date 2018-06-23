/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cut.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfavart <tfavart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 12:37:11 by tfavart           #+#    #+#             */
/*   Updated: 2018/06/23 14:04:38 by tfavart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ui.h"

void		ft_parse_cut_3(t_elem *elem, int fd)
{
	if (elem->cut.axe_5.x != 0 || elem->cut.axe_5.y != 0
		|| elem->cut.axe_5.z != 0)
	{
		ft_putstr_fd("<pos5>", fd);
		ft_put_3d(elem->cut.origin_5, fd);
		ft_putstr_fd("</pos5>", fd);
		ft_putstr_fd("<axis5>", fd);
		ft_put_3d(elem->cut.axe_5, fd);
		ft_putstr_fd("</axis5>\n", fd);
	}
	if (elem->cut.axe_6.x != 0 || elem->cut.axe_6.y != 0
		|| elem->cut.axe_6.z != 0)
	{
		ft_putstr_fd("<pos6>", fd);
		ft_put_3d(elem->cut.origin_6, fd);
		ft_putstr_fd("</pos6>", fd);
		ft_putstr_fd("<axis6>", fd);
		ft_put_3d(elem->cut.axe_6, fd);
		ft_putstr_fd("</axis6>\n", fd);
	}
}

void		ft_parse_cut_2(t_elem *elem, int fd)
{
	if (elem->cut.axe_3.x != 0 || elem->cut.axe_3.y != 0
		|| elem->cut.axe_3.z != 0)
	{
		ft_putstr_fd("<pos3>", fd);
		ft_put_3d(elem->cut.origin_3, fd);
		ft_putstr_fd("</pos3>", fd);
		ft_putstr_fd("<axis3>", fd);
		ft_put_3d(elem->cut.axe_3, fd);
		ft_putstr_fd("</axis3>\n", fd);
	}
	if (elem->cut.axe_4.x != 0 || elem->cut.axe_4.y != 0
		|| elem->cut.axe_4.z != 0)
	{
		ft_putstr_fd("<pos4>", fd);
		ft_put_3d(elem->cut.origin_4, fd);
		ft_putstr_fd("</pos4>", fd);
		ft_putstr_fd("<axis4>", fd);
		ft_put_3d(elem->cut.axe_4, fd);
		ft_putstr_fd("</axis4>\n", fd);
	}
}

void		ft_parse_cut_1(t_elem *elem, int fd)
{
	if (elem->cut.axe_1.x != 0 || elem->cut.axe_1.y != 0
		|| elem->cut.axe_1.z != 0)
	{
		ft_putstr_fd("<pos1>", fd);
		ft_put_3d(elem->cut.origin_1, fd);
		ft_putstr_fd("</pos1>", fd);
		ft_putstr_fd("<axis1>", fd);
		ft_put_3d(elem->cut.axe_1, fd);
		ft_putstr_fd("</axis1>\n", fd);
	}
	if (elem->cut.axe_2.x != 0 || elem->cut.axe_2.y != 0
		|| elem->cut.axe_2.z != 0)
	{
		ft_putstr_fd("<pos2>", fd);
		ft_put_3d(elem->cut.origin_2, fd);
		ft_putstr_fd("</pos2>", fd);
		ft_putstr_fd("<axis2>", fd);
		ft_put_3d(elem->cut.axe_2, fd);
		ft_putstr_fd("</axis2>\n", fd);
	}
}

void		ft_parse_cut(t_elem *elem, int fd)
{
	if (elem->cut.on_off == 1)
	{
		ft_putstr_fd("<cut>\n", fd);
		ft_parse_cut_1(elem, fd);
		ft_parse_cut_2(elem, fd);
		ft_parse_cut_3(elem, fd);
		ft_putstr_fd("</cut>\n", fd);
	}
}