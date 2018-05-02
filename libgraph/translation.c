/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvillepo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 02:35:09 by yvillepo          #+#    #+#             */
/*   Updated: 2018/03/23 07:31:29 by yvillepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void		trans_vect(t_vect *v, double x, double y, double z)
{
	v->x += x;
	v->y += y;
	v->z += z;
}

static void		trans_obj(t_object *obj, char **vect)
{
	if (len_tabstr(vect) != 3)
		exit_error("pb translation vect");
	if (obj->type == SPHERE)
		trans_vect(((t_sphere*)obj->form)->pos,
				ft_atof(*vect), ft_atof(vect[1]), ft_atof(vect[2]));
	if (obj->type == PLANE)
		trans_vect(((t_plane*)obj->form)->pos,
				ft_atof(*vect), ft_atof(vect[1]), ft_atof(vect[2]));
	if (obj->type == CYL)
		trans_vect(((t_cyl*)obj->form)->pos,
				ft_atof(*vect), ft_atof(vect[1]), ft_atof(vect[2]));
	if (obj->type == CONE)
		trans_vect(((t_cone*)obj->form)->pos,
				ft_atof(*vect), ft_atof(vect[1]), ft_atof(vect[2]));
}

void			read_translation(t_mlx *mlx, char *line, int fd, int i)
{
	char		**data;
	char		*l;
	t_list		*elem;

	data = ft_strsplit(line, ' ');
	if (len_tabstr(data) != 2)
		exit_error("pb translation");
	elem = ft_lst_nelem(mlx->object, i - ft_atoi(data[1]));
	free_tabstr(&data);
	if (get_next_line(fd, &l) == 0)
		exit_error("fichier emtree");
	data = ft_strsplit(l, ' ');
	trans_obj(elem->content, data);
	free_tabstr(&data);
}
