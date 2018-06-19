/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_prim_3d.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfavart <tfavart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 14:35:20 by tfavart           #+#    #+#             */
/*   Updated: 2018/06/19 16:10:04 by tfavart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ui.h"

static void	ft_parse_sphere(t_elem *elem, int fd)
{
	ft_putstr_fd("<sphere>\n", fd);
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
	ft_putstr_fd("</sphere>\n", fd);
}

static void	ft_parse_cone(t_elem *elem, int fd)
{
	ft_putstr_fd("<cone>\n", fd);
	ft_putstr_fd("<origin>", fd);
	ft_put_3d(elem->pos, fd);
	ft_putstr_fd("</origin>\n", fd);
	ft_putstr_fd("<normal>", fd);
	ft_put_3d(elem->vec, fd);
	ft_putstr_fd("</normal>\n", fd);
	ft_putstr_fd("<rotation>", fd);
	ft_put_3d(elem->rot, fd);
	ft_putstr_fd("<angle>", fd);
	ft_putnbr_fd(elem->angle_rot, fd);
	ft_putstr_fd("</angle>", fd);
	ft_putstr_fd("</rotation>\n", fd);
	ft_putstr_fd("<translation>", fd);
	ft_put_3d(elem->translation, fd);
	ft_putstr_fd("</translation>\n", fd);
	ft_putstr_fd("</cone>\n", fd);
}

static void	ft_parse_cylindre(t_elem *elem, int fd)
{
	ft_putstr_fd("<cylindre>\n", fd);
	ft_putstr_fd("<origin>", fd);
	ft_put_3d(elem->pos, fd);
	ft_putstr_fd("</origin>\n", fd);
	ft_putstr_fd("<normal>", fd);
	ft_put_3d(elem->vec, fd);
	ft_putstr_fd("</normal>\n", fd);
	ft_putstr_fd("<rotation>", fd);
	ft_put_3d(elem->rot, fd);
	ft_putstr_fd("<angle>", fd);
	ft_putnbr_fd(elem->angle_rot, fd);
	ft_putstr_fd("</angle>", fd);
	ft_putstr_fd("</rotation>\n", fd);
	ft_putstr_fd("<translation>", fd);
	ft_put_3d(elem->translation, fd);
	ft_putstr_fd("</translation>\n", fd);
	ft_putstr_fd("</cylindre>\n", fd);
}

static void	ft_parse_plan(t_elem *elem, int fd)
{
	ft_putstr_fd("<plan>\n", fd);
	ft_putstr_fd("<origin>", fd);
	ft_put_3d(elem->pos, fd);
	ft_putstr_fd("</origin>\n", fd);
	ft_putstr_fd("<normal>", fd);
	ft_put_3d(elem->vec, fd);
	ft_putstr_fd("</normal>\n", fd);
	
	ft_putstr_fd("</plan>\n", fd);
}

void		ft_parse_prim_3d(t_elem *elem, int fd)
{
	if (elem->type == SPHERE)
		ft_parse_sphere(elem, fd);
	if (elem->type == CONE)
		ft_parse_cone(elem, fd);
	if (elem->type == CYLINDRE)
		ft_parse_cylindre(elem, fd);
	if (elem->type == PLAN)
		ft_parse_plan(elem, fd);
}