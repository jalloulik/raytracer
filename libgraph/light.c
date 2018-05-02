/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvillepo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 11:38:52 by yvillepo          #+#    #+#             */
/*   Updated: 2018/03/23 07:29:41 by yvillepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static double	shadow(t_list *o, t_line *light)
{
	double		t;
	int			cmp;
	double		res;

	cmp = 0;
	res = 0.30;
	while (o)
	{
		t = intersec_unit(o->content, light);
		if (t < 0.9999999 && t > 0)
			cmp++;
		o = o->next;
	}
	if (cmp == 0)
		return (10);
	return (res / cmp);
}

double			is_shadow(t_mlx *mlx, t_line *cam, double d)
{
	t_line	light;
	t_vect	*tmp;
	double	res;

	tmp = calc_point(cam, d);
	light.pos = mlx->light;
	light.dir = v_sub(tmp, light.pos);
	free(tmp);
	res = shadow(mlx->object, &light);
	free(light.dir);
	return (res);
}

static t_vect	*calc_cc(t_object *obj, t_vect *pos, t_line *cam, double t)
{
	t_plane *plane;
	t_vect	*center;

	plane->n = ((t_cyl)obj->form)->dir;
	plane->pos = ((t_cyl)obj->form)->pos;
	center = intersec_plane2(plane, pos);
	return (v_sub(pos, center));
	free(tmp);
	return (norm);
}

static t_vect	*calc_norm(double t, t_line *cam, t_object *obj, t_vect *pos)
{
	t_vect	*norm;

	norm = 0;
	if (obj->type == SPHERE)
		norm = v_sub(pos, ((t_sphere*)obj->form)->pos);
	if (obj->type == PLANE)
		norm = ((t_plane*)obj->form)->n;
	if (obj->type == CYL || obj->type == CONE)
		norm = calc_cc(obj, pos, cam, t);
	if (norm)
		return (norm);
	else
		exit_error("calc norm");
	return (NULL);
}

double			calc_light(t_mlx *mlx, t_line *cam, t_object *obj, double t)
{
	t_vect		*norm;
	t_vect		*dir_light;
	t_vect		*pos;
	double		percent;
	double		res;

	norm = 0;
	pos = calc_point(cam, t);
	norm = calc_norm(t, cam, obj, pos);
	v_unit(norm);
	dir_light = v_sub(pos, mlx->light);
	v_unit(dir_light);
	percent = is_shadow(mlx, cam, t);
	free(pos);
	res = - v_scale(norm, dir_light);
	res = res < 0 ? 0 : res;
	if (percent < 10 && mlx->ombre)
		//res = percent * res;
		res = 0;
	if (norm && (norm != ((t_plane*)obj->form)->n))
		free(norm);
	free(dir_light);
	return (res);
}
