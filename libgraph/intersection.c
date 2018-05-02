/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvillepo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 11:32:33 by yvillepo          #+#    #+#             */
/*   Updated: 2018/03/23 07:37:33 by yvillepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double			intersec_unit(t_object *obj, t_line *line)
{
	double	t;

	t = 0;
	if (obj->type == SPHERE)
		t = inter_sphere(obj->form, line);
	if (obj->type == PLANE)
		t = inter_plane(obj->form, line);
	if (obj->type == CYL)
		t = inter_cyl(obj->form, line);
	if (obj->type == CONE)
		t = inter_cone(obj->form, line);
	return (t);
}

static t_color	calc(t_mlx *mlx, t_vect *dir, t_list *object)
{
	double			min;
	double			t;
	t_line			line;
	t_object		*obj;

	obj = 0;
	min = 100000000000000000;
	line.pos = mlx->camera_pos;
	line.dir = dir;
	while (object)
	{
		t = intersec_unit(object->content, &line);
		if (t < min && t >= 0)
		{
			obj = (t_object*)object->content;
			min = t;
		}
		object = object->next;
	}
	if (obj)
	{
		return (mult_color(obj->color, 0.00
					+ calc_light(mlx, &line, obj, min)));
	}
	return ((t_color)(unsigned int)0);
}

t_color			intersec(t_mlx *mlx, int i, int j, t_list *object)
{
	t_vect		dir;
	double		min;

	min = 0;
	calc_ray(mlx, &dir, i, j);
	return (calc(mlx, &dir, object));
}
