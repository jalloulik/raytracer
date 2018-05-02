/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cyl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvillepo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 11:31:11 by yvillepo          #+#    #+#             */
/*   Updated: 2018/03/23 08:23:22 by yvillepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void			read_cyl(t_cyl *cyl, int fd)
{
	char	*line;

	cyl->dir = read_vect(fd);
	v_unit(cyl->dir);
	if (is_nul(cyl->dir))
		exit_error("vecteur directeur null");
	cyl->pos = read_vect(fd);
	if (!get_next_line(fd, &line))
		exit_error("format input");
	jump_coment(&line);
	cyl->r = ft_atof(line);
	free(line);
}

void			read_object_cyl(t_object *object, int fd)
{
	object->type = CYL;
	object->form = ft_malloc(sizeof(t_cyl));
	read_cyl(object->form, fd);
}

double			inter_cyl(t_cyl *cyl, t_line *l)
{
	t_vect	*diff;
	t_vect	deg2;

	diff = new_vect(l->pos->x - cyl->pos->x, l->pos->y - cyl->pos->y,
			l->pos->z - cyl->pos->z);
	deg2.x = v_scale(l->dir, l->dir) -
		pow(v_scale(l->dir, cyl->dir), 2);
	deg2.y = 2 * (v_scale(l->dir, diff) -
			v_scale(l->dir, cyl->dir) * v_scale(diff, cyl->dir));
	deg2.z = v_scale(diff, diff) - 2 * pow(v_scale(diff, cyl->dir), 2) -
		cyl->r * cyl->r;
	free(diff);
	return (solv_2nd(deg2.x, deg2.y, deg2.z));
}
