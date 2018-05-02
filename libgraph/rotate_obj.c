/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_obj.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvillepo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 19:10:56 by yvillepo          #+#    #+#             */
/*   Updated: 2018/03/23 08:35:40 by yvillepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	rot_obj(t_object *obj, double angle, int axe)
{
	angle = deg_to_rad(angle);
	if (obj->type == PLANE)
		rotate_xyz(((t_plane*)obj->form)->n, angle, axe);
	if (obj->type == CYL)
		rotate_xyz(((t_cyl*)obj->form)->dir, angle, axe);
	if (obj->type == CONE)
		rotate_xyz(((t_cone*)obj->form)->dir, angle, axe);
}

void	read_rot(t_mlx *mlx, char *line, int i)
{
	char		**data;
	t_list		*elem;

	data = ft_strsplit(line, ' ');
	if (len_tabstr(data) < 4)
		exit_error("pb rotation");
	elem = ft_lst_nelem(mlx->object, i - ft_atoi(data[1]));
	rot_obj(elem->content, ft_atoi(data[3]), data[2][0]);
	free_tabstr(&data);
}
