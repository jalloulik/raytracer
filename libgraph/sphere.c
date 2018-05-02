/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvillepo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 13:12:49 by yvillepo          #+#    #+#             */
/*   Updated: 2018/03/23 03:51:05 by yvillepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		read_object_sphere(t_object *object, int fd)
{
	object->type = SPHERE;
	object->form = ft_malloc(sizeof(t_sphere));
	read_sphere(object->form, fd);
}

void		read_sphere(t_sphere *sphere, int fd)
{
	char *line;

	sphere->pos = read_vect(fd);
	if (get_next_line(fd, &line) == 0)
		exit_error("fichier emtree");
	jump_coment(&line);
	sphere->r = ft_atof(line);
	free(line);
}

double		inter_sphere(t_sphere *sphere, t_line *line)
{
	t_vect	deg2;
	t_vect	*diff;
	double	t;

	diff = new_vect(line->pos->x - sphere->pos->x,
			line->pos->y - sphere->pos->y,
			line->pos->z - sphere->pos->z);
	deg2.x = v_scale(line->dir, line->dir); 
	deg2.y = 2 * v_scale(line->dir, diff);
	deg2.z = v_scale(diff, diff) - sphere->r * sphere->r;
	t = solv_2nd(deg2.x, deg2.y, deg2.z);
	free(diff);
	return (t);
}
