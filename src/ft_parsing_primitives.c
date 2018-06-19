/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_primitives.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjalloul <kjalloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 16:22:12 by kjalloul          #+#    #+#             */
/*   Updated: 2018/06/19 03:28:40 by kjalloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	ft_check_refraction(t_prim *last, t_node *node, char *type)
{
	char *content;
	char *tmp;

	tmp = ft_strjoin(type, "/refract/status");
	content = xmlp_get_child_node_content(node, tmp);
	free(tmp);
	if (ft_strequ(content, "true") != 1)
		return ;

	tmp = ft_strjoin(type, "/refract/material");
	content = xmlp_get_child_node_content(node, tmp);
	free(tmp);
	if (ft_strequ(content, "DIAMOND") == 1)
		last->refraction_index = DIAMOND;
	else if (ft_strequ(content, "VACUUM") == 1)
		last->refraction_index = VACUUM;
	else if (ft_strequ(content, "AIR") == 1)
		last->refraction_index = AIR;
	else if (ft_strequ(content, "ICE") == 1)
		last->refraction_index = ICE;
	else if (ft_strequ(content, "WATER") == 1)
		last->refraction_index = WATER;
	else if (ft_strequ(content, "PLEXIGLAS") == 1)
		last->refraction_index = PLEXIGLAS;
	else if (ft_strequ(content, "DENSEFLINTGLASS") == 1)
		last->refraction_index = DENSEFLINTGLASS;
	else
		ft_error("Material not supported");
	last->refractive = 1;
	last->refract_ratio = 1;
	tmp = ft_strjoin(type, "/refract/ratio");
	content = xmlp_get_child_node_content(node, tmp);
	free(tmp);
	if (ft_atoi(content) <= 100 && ft_atoi(content) > 0)
		last->refract_ratio = (double)ft_atoi(content) / 100.0;
	else
		ft_error("Refraction percentage needs to be 1-100 range");
}

void	ft_check_reflection(t_prim *last, t_node *node, char *type)
{
	char *tmp;
	char *content;

	tmp = ft_strjoin(type, "/reflect/status");
	content = xmlp_get_child_node_content(node, tmp);
	free(tmp);
	if (ft_strequ(content, "true") != 1)
		return ;

	tmp = ft_strjoin(type, "/reflect/ratio");
	content = xmlp_get_child_node_content(node, tmp);
	free(tmp);

	last->reflective = 1;
	last->reflec_ratio = 1;
	if (ft_atoi(content) <= 100 && ft_atoi(content) > 0)
		last->reflec_ratio = (double)ft_atoi(content) / 100.0;
	else
		ft_error("Reflection percentage needs to be 1-100 range");
}

void	ft_check_sin(t_prim *last, t_node *node, char *type)
{
	char *tmp;
	char *content;

	content = NULL;
	tmp = ft_strjoin(type, "/sinx/a");
	content = xmlp_get_child_node_content(node, tmp);
	free(tmp);
	if (content)
	{
		if (ft_atoi(content) <= 0)
			ft_error("Value cannot be smaller or equal to zero");
		last->sin.x = ft_atoi(content);
		tmp = ft_strjoin(type, "/sinx/b");
		content = xmlp_get_child_node_content(node, tmp);
		free(tmp);
		if (ft_atoi(content) <= 0)
			ft_error("Sin div cannot be smaller or equal to zero");
		last->sin.x_div = ft_atoi(content);
		last->sin.status = TRUE;
		last->sin.xstatus = TRUE;
	}
	tmp = ft_strjoin(type, "/siny/a");
	content = xmlp_get_child_node_content(node, tmp);
	free(tmp);
	if (content)
	{
		if (ft_atoi(content) <= 0)
			ft_error("Value cannot be smaller or equal to zero");
		last->sin.y = ft_atoi(content);
		tmp = ft_strjoin(type, "/siny/b");
		content = xmlp_get_child_node_content(node, tmp);
		free(tmp);
		if (ft_atoi(content) <= 0)
			ft_error("Sin div cannot be smaller or equal to zero");
		last->sin.y_div = ft_atoi(content);
		last->sin.status = TRUE;
		last->sin.ystatus = TRUE;
	}

	tmp = ft_strjoin(type, "/sinz/a");
	content = xmlp_get_child_node_content(node, tmp);
	free(tmp);
	if (content)
	{
		if (ft_atoi(content) <= 0)
			ft_error("Value cannot be smaller or equal to zero");
		last->sin.z = ft_atoi(content);
		tmp = ft_strjoin(type, "/sinz/b");
		content = xmlp_get_child_node_content(node, tmp);
		free(tmp);
		if (ft_atoi(content) <= 0)
			ft_error("Sin div cannot be smaller or equal to zero");
		last->sin.z_div = ft_atoi(content);
		last->sin.status = TRUE;
		last->sin.zstatus = TRUE;
	}
}

void	ft_check_ntexture(t_prim *last, t_node *node, char *type)
{
	char	*tmp;
	char	*filename;
	t_texture *texture;
	char *content;

	content = NULL;
	if (ft_strequ(type, "normal") == 1)
	{
		tmp = ft_strjoin(type, "/normal/file");
		content = xmlp_get_child_node_content(node, tmp);
		free(tmp);
		texture = &(last->textur_n);
	}
	if (content)
	{
		filename = ft_strjoin("assets/", content);
		texture->xscale = 1;
		texture->yscale = 1;
		texture->xmove = 0;
		texture->ymove = 0;
		texture->valid = TRUE;
		ft_stb_load_textur(texture, filename);
		free(filename);
	}
	tmp = ft_strjoin(type, "/normal/scale/x");
	content = xmlp_get_child_node_content(node, tmp);
	free(tmp);
	if (content)
		texture->xscale = (double)ft_atoi(content);
	tmp = ft_strjoin(type, "/normal/scale/y");
	content = xmlp_get_child_node_content(node, tmp);
	free(tmp);
	if (content)
		texture->yscale = (double)ft_atoi(content);
	tmp = ft_strjoin(type, "/normal/mov/x");
	content = xmlp_get_child_node_content(node, tmp);
	free(tmp);
	if (content)
		if (ft_atoi(content) < 0 || ft_atoi(content) > 100)
			texture->xmove = (double)ft_atoi(content) / 100 ;
	tmp = ft_strjoin(type, "/normal/mov/y");
	content = xmlp_get_child_node_content(node, tmp);
	free(tmp);
	if (content)
		if (ft_atoi(content) < 0 || ft_atoi(content) > 100)
			texture->ymove = (double)ft_atoi(content) / 100 ;
}


void	ft_check_texture(t_prim *last, t_node *node, char *type)
{
	char *tmp;
	char	*filename;
	t_texture *texture;
	char *content;

	tmp = ft_strjoin(type, "/texture/file");
	content = xmlp_get_child_node_content(node, tmp);
	free(tmp);
	texture = &(last->textur);
	if (content)
	{
		filename = ft_strjoin("assets/", content);
		texture->xscale = 1;
		texture->yscale = 1;
		texture->xmove = 0;
		texture->ymove = 0;
		texture->valid = TRUE;
		ft_stb_load_textur(texture, filename);
		free(filename);
	}
	tmp = ft_strjoin(type, "/texture/scale/x");
	content = xmlp_get_child_node_content(node, tmp);
	free(tmp);
	if (content)
		texture->xscale = (double)ft_atoi(content);
	tmp = ft_strjoin(type, "/texture/scale/y");
	content = xmlp_get_child_node_content(node, tmp);
	free(tmp);
	if (content)
		texture->yscale = (double)ft_atoi(content);
	tmp = ft_strjoin(type, "/texture/mov/x");
	content = xmlp_get_child_node_content(node, tmp);
	free(tmp);
	if (content)
		if (ft_atoi(content) < 0 || ft_atoi(content) > 100)
			texture->xmove = (double)ft_atoi(content) / 100 ;
	tmp = ft_strjoin(type, "/texture/mov/y");
	content = xmlp_get_child_node_content(node, tmp);
	free(tmp);
	if (content)
		if (ft_atoi(content) < 0 || ft_atoi(content) > 100)
			texture->ymove = (double)ft_atoi(content) / 100 ;
}

void	ft_check_checkers(t_prim *last, t_node *node, char *type)
{
	char *tmp;
	char *content;

	tmp = ft_strjoin(type, "/checkers/status");
	content = xmlp_get_child_node_content(node, tmp);
	free(tmp);
	if (ft_strequ(content, "true") == 1)
	{
		last->checkers.valid = TRUE;
		last->checkers.xscale = 1;
		last->checkers.yscale = 1;
		last->checkers.xmove = 0;
		last->checkers.ymove = 0;
		last->checkers.width = PROCED_WIDTH;
		last->checkers.height = PROCED_HEIGHT;

		tmp = ft_strjoin(type, "/checkers/scale/x");
		content = xmlp_get_child_node_content(node, tmp);
		free(tmp);
		if (content)
			last->checkers.xscale = (double)ft_atoi(content);
		tmp = ft_strjoin(type, "/checkers/scale/y");
		content = xmlp_get_child_node_content(node, tmp);
		free(tmp);
		if (content)
			last->checkers.yscale = (double)ft_atoi(content);
		tmp = ft_strjoin(type, "/checkers/mov/x");
		content = xmlp_get_child_node_content(node, tmp);
		free(tmp);
		if (content)
			if (ft_atoi(content) < 0 || ft_atoi(content) > 100)
				last->checkers.xmove = (double)ft_atoi(content) / 100 ;
		tmp = ft_strjoin(type, "/checkers/mov/y");
		content = xmlp_get_child_node_content(node, tmp);
		free(tmp);
		if (content)
			if (ft_atoi(content) < 0 || ft_atoi(content) > 100)
				last->checkers.ymove = (double)ft_atoi(content) / 100 ;
	}
}

void	ft_count_options(t_prim *last, t_node *node, char *type)
{
	ft_check_reflection(last, node, type);
	ft_check_refraction(last, node, type);
	ft_check_texture(last, node, type);
	ft_check_ntexture(last, node, type);
	ft_check_sin(last, node, type);
	ft_check_checkers(last, node, type);
	if (last->textur.valid == TRUE && last->checkers.valid == TRUE)
		ft_error("Can't have both checkers and color texture on");
}

void	ft_set_3dpt_from_string(t_3dpt *point, char *str)
{
	char	**tmp;

	if (str == NULL)
		ft_error("No coordinates");
	tmp = ft_strsplit(str, ':');
	if (ft_count_tab(tmp) != 3)
		ft_error("Point or vector coordinates should be formated x:y:z");
	ft_set_3dpt(point, (double)ft_atoi(tmp[0]), (double)ft_atoi(tmp[1]), (double)ft_atoi(tmp[2]));
	ft_free_tab(tmp);
}

void	ft_intialise_primitives(t_prim *last)
{
	ft_set_3dpt(&(last->rot_axis), 0, 1, 0);
	last->rot_angle = ft_degree_to_rad(0.0);
	ft_set_3dpt(&(last->transl), 0, 0, 0);
	last->sin.status = FALSE;
	last->sin.xstatus = FALSE;
	last->sin.ystatus = FALSE;
	last->sin.zstatus = FALSE;
	last->reflective = FALSE;
	last->refractive = FALSE;
	last->textur.valid = FALSE;
	last->textur_n.valid = FALSE;
	last->checkers.valid = FALSE;
}

void	ft_plane_setup(t_node *node, t_prim **prims)
{
	t_prim	*last;
	t_prim	*list;
	char *content;

	list = *prims;
	list = ft_add_lst_file(list, PLANE);
	*prims = list;
	last = ft_get_last(list);

	content = xmlp_get_child_node_content(node, "plane/origin");
	ft_set_3dpt_from_string(&(last->plane.point), content);

	content = xmlp_get_child_node_content(node, "plane/vec");
	ft_set_3dpt_from_string(&(last->plane.normal), content);

	content = xmlp_get_child_node_content(node, "plane/color");
	if (content == NULL)
		ft_error("Need color for plane");
	ft_parse_color(content, &(last->color2), &ft_error_plane);
	ft_parsing_mov(node, last, "plane");
	ft_count_options(last, node, "plane");
}

void	ft_cylinder_setup(t_node *node, t_prim **prims)
{
	t_prim	*last;
	t_prim	*list;
	char *content;
	// int		i;

	list = *prims;
	list = ft_add_lst_file(list, CYLINDER);
	*prims = list;
	last = ft_get_last(list);

	content = xmlp_get_child_node_content(node, "cylinder/origin");
	ft_set_3dpt_from_string(&(last->cyl.origin), content);

	content = xmlp_get_child_node_content(node, "cylinder/vec");
	ft_set_3dpt_from_string(&(last->cyl.vec), content);

	content = xmlp_get_child_node_content(node, "cylinder/radius");
	if (content == NULL)
		ft_error("Need Radius for Cylinder");
	last->cyl.radius = ft_atoi(content);
	if (last->cyl.radius <= 0)
		ft_error("Radius can not be Null or negative");

	content = xmlp_get_child_node_content(node, "cylinder/color");
	if (content == NULL)
		ft_error("Need color for Cylinder");
	ft_parse_color(content, &(last->color2), &ft_error_cyl);
	ft_parsing_mov(node, last, "cylinder");
	ft_count_options(last, node, "cylinder");

	// i = read_cut(tab + 7, last);

}

void	ft_cone_setup(t_node *node, t_prim **prims)
{
	t_prim	*last;
	t_prim	*list;
	char *content;
	// int		i;

	list = *prims;
	list = ft_add_lst_file(list, CONE);
	*prims = list;
	last = ft_get_last(list);

	content = xmlp_get_child_node_content(node, "cone/origin");
	ft_set_3dpt_from_string(&(last->cone.origin), content);

	content = xmlp_get_child_node_content(node, "cone/vec");
	ft_set_3dpt_from_string(&(last->cone.vec), content);

	content = xmlp_get_child_node_content(node, "cone/angle");
	if (content == NULL)
		ft_error("Need angle for Cone");
	last->cone.angle = ft_degree_to_rad(ft_atoi(content));
	if (last->cone.angle <= 0)
		ft_error("Angle can not be Null or negative");
	content = xmlp_get_child_node_content(node, "cone/color");
	if (content == NULL)
		ft_error("Need color for cone");
	ft_parse_color(content, &(last->color2), &ft_error_cone);
	ft_parsing_mov(node, last, "cone");
	ft_count_options(last, node, "cone");

	// i = read_cut(tab + 7, last);
}

void	ft_sphere_setup(t_node *node, t_prim **prims)
{
	t_prim	*last;
	t_prim	*list;
	char *content;
	// int		i;

	content = NULL;
	list = *prims;
	list = ft_add_lst_file(list, SPHERE);
	*prims = list;
	last = ft_get_last(list);

	content = xmlp_get_child_node_content(node, "sphere/origin");
	ft_set_3dpt_from_string(&(last->sphere.origin), content);

	content = xmlp_get_child_node_content(node, "sphere/radius");
	if (content == NULL)
		ft_error("Need Radius for sphere");
	last->sphere.radius = ft_atoi(content);

	content = xmlp_get_child_node_content(node, "sphere/color");
	if (content == NULL)
		ft_error("Need color for sphere");
	ft_parse_color(content, &(last->color2), &ft_error_sphere);

	ft_parsing_mov(node, last, "sphere");

	// i = read_cut(tab + 6, last);

	ft_count_options(last, node, "sphere");
}

void	ft_cercle_setup(t_node *node, t_prim **prims)
{
	t_prim	*last;
	t_prim	*list;
	char *content;

	list = *prims;
	list = ft_add_lst_file(list, CERCLE);
	*prims = list;
	last = ft_get_last(list);

	content = xmlp_get_child_node_content(node, "cercle/origin");
	ft_set_3dpt_from_string(&(last->cercle.pos), content);

	content = xmlp_get_child_node_content(node, "cercle/vec");
	ft_set_3dpt_from_string(&(last->cercle.dir), content);
	ft_normalize_vector(&(last->cercle.dir));

	content = xmlp_get_child_node_content(node, "cercle/radius");
	if (content == NULL)
		ft_error("Need Radius for sphere");
	last->cercle.r = ft_atoi(content);
	content = xmlp_get_child_node_content(node, "cercle/color");
	if (content == NULL)
		ft_error("Need color for cercle");
	ft_parse_color(content, &(last->color2), &ft_error_sphere);
	ft_parsing_mov(node, last, "cercle");
}

void	ft_rectangle_setup(t_node *node, t_prim **prims)
{
	t_prim	*last;
	t_prim	*list;
	char *content;

	list = *prims;
	list = ft_add_lst_file(list, RECT);
	*prims = list;
	last = ft_get_last(list);

	content = xmlp_get_child_node_content(node, "rect/origin");
	ft_set_3dpt_from_string(&(last->rect.pos), content);

	content = xmlp_get_child_node_content(node, "rect/vec");
	ft_set_3dpt_from_string(&(last->rect.dir), content);
	ft_normalize_vector(&(last->rect.dir));

	content = xmlp_get_child_node_content(node, "rect/size/x");
	if (content == NULL)
		ft_error("Rectangle size needs a width");
	last->rect.width =  ft_atoi(content);
	content = xmlp_get_child_node_content(node, "rect/size/y");
	if (content == NULL)
		ft_error("Rectangle size needs a height");
	last->rect.height =  ft_atoi(content);
	content = xmlp_get_child_node_content(node, "rect/color");
	if (content == NULL)
		ft_error("Need color for rectangle");
	ft_parse_color(content, &(last->color2), &ft_error_sphere);
	ft_parsing_mov(node, last, "rect");
}

void	ft_tore_setup(t_node *node, t_prim **prims)
{
	t_prim	*last;
	t_prim	*list;
	char *content;

	list = *prims;
	list = ft_add_lst_file(list, TORE);
	*prims = list;
	last = ft_get_last(list);

	content = xmlp_get_child_node_content(node, "tore/origin");
	ft_set_3dpt_from_string(&(last->tore.pos), content);

	content = xmlp_get_child_node_content(node, "tore/vec");
	ft_set_3dpt_from_string(&(last->tore.dir), content);
	ft_normalize_vector(&(last->tore.dir));

	content = xmlp_get_child_node_content(node, "tore/r1");
	last->tore.r1 =  ft_atoi(content);
	content = xmlp_get_child_node_content(node, "tore/r2");
	last->tore.r2 =  ft_atoi(content);
	content = xmlp_get_child_node_content(node, "tore/color");
	if (content == NULL)
		ft_error("Need color for tore");
	ft_parse_color(content, &(last->color2), &ft_error_sphere);
	ft_parsing_mov(node, last, "tore");

}

void	ft_triangle_setup(t_node *node, t_prim **prims)
{
	t_prim	*last;
	t_prim	*list;
	char *content;

	list = *prims;
	list = ft_add_lst_file(list, TRIANGLE);
	*prims = list;
	last = ft_get_last(list);

	content = xmlp_get_child_node_content(node, "triangle/p1");
	ft_set_3dpt_from_string(&(last->triangle.p1), content);
	content = xmlp_get_child_node_content(node, "triangle/p2");
	ft_set_3dpt_from_string(&(last->triangle.p2), content);
	content = xmlp_get_child_node_content(node, "triangle/p3");
	ft_set_3dpt_from_string(&(last->triangle.p3), content);
	content = xmlp_get_child_node_content(node, "triangle/color");
	if (content == NULL)
		ft_error("Need color for triangle");
	ft_parse_color(content, &(last->color2), &ft_error_sphere);
	ft_parsing_mov(node, last, "triangle");
}
