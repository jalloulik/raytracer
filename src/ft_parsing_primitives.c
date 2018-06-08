/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_primitives.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjalloul <kjalloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 16:22:12 by kjalloul          #+#    #+#             */
/*   Updated: 2018/06/08 17:04:01 by yvillepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	ft_parse_vector(char *str, t_3dpt *vec)
{
	char **tmp;

	tmp = ft_strsplit(str, ':');
	if (ft_count_tab(tmp) != 4 || ft_strequ(tmp[0], "vec") == 0)
		ft_error_cyl();
	ft_set_3dpt(vec, (double)ft_atoi(tmp[1]),
		(double)ft_atoi(tmp[2]), (double)ft_atoi(tmp[3]));
	ft_normalize_vector(vec);
	ft_free_tab(tmp);
}

void	ft_check_refraction(t_prim *last, char *str)
{
	char **tmp;

	tmp = ft_strsplit(str, ':');
	if (tmp != NULL)
	{
		if (ft_count_tab(tmp) >= 2 && ft_strequ(tmp[0], "refract") == 1)
		{
			if (ft_strequ(tmp[1], "DIAMOND") == 1)
				last->refraction_index = DIAMOND;
			else if (ft_strequ(tmp[1], "VACUUM") == 1)
				last->refraction_index = VACUUM;
			else if (ft_strequ(tmp[1], "AIR") == 1)
				last->refraction_index = AIR;
			else if (ft_strequ(tmp[1], "ICE") == 1)
				last->refraction_index = ICE;
			else if (ft_strequ(tmp[1], "WATER") == 1)
				last->refraction_index = WATER;
			else if (ft_strequ(tmp[1], "PLEXIGLAS") == 1)
				last->refraction_index = PLEXIGLAS;
			else if (ft_strequ(tmp[1], "DENSEFLINTGLASS") == 1)
				last->refraction_index = DENSEFLINTGLASS;
			else
				ft_error("Material not supported");
			last->refractive = 1;
			last->refract_ratio = 1;
			if (ft_count_tab(tmp) >= 3)
			{
				if (ft_atoi(tmp[2]) <= 100 && ft_atoi(tmp[2]) > 0)
					last->refract_ratio = (double)ft_atoi(tmp[2]) / 100.0;
				else
					ft_error("Refraction percentage needs to be 1-100 range");
			}
		}
		ft_free_tab(tmp);
	}
}

void	ft_check_reflection(t_prim *last, char *str)
{
	char **tmp;

	tmp = ft_strsplit(str, ':');
	if (tmp != NULL)
	{
		if (ft_count_tab(tmp) >= 1 && ft_strequ(tmp[0], "reflect") == 1)
		{
			last->reflective = 1;
			last->reflec_ratio = 1;
			if (ft_count_tab(tmp) >= 2)
			{
				if (ft_atoi(tmp[1]) <= 100 && ft_atoi(tmp[1]) > 0)
					last->reflec_ratio = (double)ft_atoi(tmp[1]) / 100.0;
				else
					ft_error("Reflection percentage needs to be 1-100 range");
			}
		}
		ft_free_tab(tmp);
	}
}

void	ft_check_sin(t_prim *last, char *str)
{
	char **tmp;

	tmp = ft_strsplit(str, ':');
	if (tmp != NULL)
	{
		if (ft_count_tab(tmp) == 3 && ft_strequ(tmp[0], "sinx"))
		{
			last->sin.status = TRUE;
			last->sin.xstatus = TRUE;
			if (ft_atoi(tmp[1]) <= 0)
				ft_error("Value cannot be smaller or equal to zero");
			last->sin.x = ft_atoi(tmp[1]);
			if (ft_atoi(tmp[2]) <= 0)
				ft_error("Sin div cannot be smaller or equal to zero");
			last->sin.x_div = ft_atoi(tmp[2]);
		}
		if (ft_count_tab(tmp) == 3 && ft_strequ(tmp[0], "siny"))
		{
			last->sin.status = TRUE;
			last->sin.ystatus = TRUE;
			if (ft_atoi(tmp[1]) <= 0)
				ft_error("Value cannot be smaller or equal to zero");
			last->sin.y = ft_atoi(tmp[1]);
			if (ft_atoi(tmp[2]) <= 0)
				ft_error("Sin div cannot be smaller or equal to zero");
			last->sin.y_div = ft_atoi(tmp[2]);
		}
		if (ft_count_tab(tmp) == 3 && ft_strequ(tmp[0], "sinz"))
		{
			last->sin.status = TRUE;
			last->sin.zstatus = TRUE;
			if (ft_atoi(tmp[1]) <= 0)
				ft_error("Value cannot be smaller or equal to zero");
			last->sin.z = ft_atoi(tmp[1]);
			if (ft_atoi(tmp[2]) <= 0)
				ft_error("Sin div cannot be smaller or equal to zero");
			last->sin.z_div = ft_atoi(tmp[2]);
		}
		ft_free_tab(tmp);
	}
}

void	ft_check_texture(t_prim *last, char *str, char *type)
{
	char **tmp;
	char	*filename;
	t_texture *texture;

	tmp = ft_strsplit(str, ':');
	if (tmp != NULL)
	{
		if (ft_count_tab(tmp) >= 2 && (ft_strequ(tmp[0], "texture") == 1 || ft_strequ(tmp[0], "normal") == 1))
		{
			if (ft_strequ(tmp[0], "texture") == 1)
				texture = &(last->textur);
			else
				texture = &(last->textur_n);
		}
		if (ft_count_tab(tmp) >= 2 && ft_strequ(tmp[0], type) == 1)
		{
			filename = ft_strjoin("assets/", tmp[1]);
			texture->xscale = 1;
			texture->yscale = 1;
			texture->xmove = 0;
			texture->ymove = 0;
			texture->valid = TRUE;
			ft_stb_load_textur(texture, filename);
			free(filename);
			if (ft_count_tab(tmp) >= 4 && ft_strequ(tmp[2], "scale") == 1)
			{
				texture->xscale = (double)ft_atoi(tmp[3]);
				if (ft_count_tab(tmp) >= 5 && ft_strequ(tmp[4], "mov") == 0)
					texture->yscale = (double)ft_atoi(tmp[3]);
				else
				{
					texture->yscale = texture->xscale;
					if (ft_count_tab(tmp) >= 6 && ft_strequ(tmp[4], "mov") == 1)
					{
						if (ft_atoi(tmp[5]) < 0 || ft_atoi(tmp[5]) > 100)
							ft_error("Scale needs to be between 0 and 100");
						texture->xmove = (double)ft_atoi(tmp[5]) / 100 ;
						if (ft_count_tab(tmp) >= 7)
						{
							if (ft_atoi(tmp[6]) < 0 || ft_atoi(tmp[6]) > 100)
								ft_error("Scale needs to be between 0 and 100");
							texture->ymove = (double)ft_atoi(tmp[6]) / 100;
						}
						else
							texture->ymove = texture->xmove;
					}
				}
			}
		}
		ft_free_tab(tmp);
	}
}

void	ft_count_options(t_prim *last, char **tab, int start)
{
	last->sin.status = FALSE;
	last->sin.xstatus = FALSE;
	last->sin.ystatus = FALSE;
	last->sin.zstatus = FALSE;
	last->reflective = FALSE;
	last->refractive = FALSE;
	last->textur.valid = FALSE;
	last->textur_n.valid = FALSE;
	if (ft_count_tab(tab) >= start)
	{
		ft_check_reflection(last, tab[start]);
		ft_check_refraction(last, tab[start]);
		ft_check_texture(last, tab[start], "texture");
		ft_check_texture(last, tab[start], "normal");
		ft_check_sin(last, tab[start]);
	}
	if (ft_count_tab(tab) >= start + 1)
	{
		ft_check_reflection(last, tab[start + 1]);
		ft_check_refraction(last, tab[start + 1]);
		ft_check_texture(last, tab[start + 1], "texture");
		ft_check_texture(last, tab[start + 1], "normal");
		ft_check_sin(last, tab[start + 1]);
	}
	if (ft_count_tab(tab) >= start + 2)
	{
		ft_check_reflection(last, tab[start + 2]);
		ft_check_refraction(last, tab[start + 2]);
		ft_check_texture(last, tab[start + 2], "texture");
		ft_check_texture(last, tab[start + 2], "normal");
		ft_check_sin(last, tab[start + 2]);
	}
	if (ft_count_tab(tab) >= start + 3)
	{
		ft_check_reflection(last, tab[start + 3]);
		ft_check_refraction(last, tab[start + 3]);
		ft_check_texture(last, tab[start + 3], "texture");
		ft_check_texture(last, tab[start + 3], "normal");
		ft_check_sin(last, tab[start + 3]);
	}
	if (ft_count_tab(tab) >= start + 4)
	{
		ft_check_reflection(last, tab[start + 4]);
		ft_check_refraction(last, tab[start + 4]);
		ft_check_texture(last, tab[start + 4], "texture");
		ft_check_texture(last, tab[start + 4], "normal");
		ft_check_sin(last, tab[start + 4]);
	}
}

void	ft_plane_setup(char **tab, t_prim **prims)
{
	t_prim	*last;
	t_prim	*list;
	char	**tmp;

	list = *prims;
	list = ft_add_lst_file(list, PLANE);
	*prims = list;
	last = ft_get_last(list);
	if (ft_count_tab(tab) < 6)
		ft_error_plane();
	tmp = ft_strsplit(tab[1], ':');
	if (ft_count_tab(tmp) != 4 || ft_strequ(tmp[0], "origin") == 0)
		ft_error_plane();
	ft_set_3dpt(&(last->plane.point), (double)ft_atoi(tmp[1]),
		(double)ft_atoi(tmp[2]), (double)ft_atoi(tmp[3]));
	ft_free_tab(tmp);
	tmp = ft_strsplit(tab[2], ':');
	if (ft_count_tab(tmp) != 4 || ft_strequ(tmp[0], "normal") == 0)
		ft_error_plane();
	ft_set_3dpt(&(last->plane.normal), (double)ft_atoi(tmp[1]),
		(double)ft_atoi(tmp[2]), (double)ft_atoi(tmp[3]));
	ft_free_tab(tmp);
	ft_parse_color(tab[3], &(last->color2), &ft_error_plane);
	ft_parsing_mov(tab[4], tab[5], last, &ft_error_plane);
	ft_count_options(last, tab, 6);
}

void	ft_cylinder_setup(char **tab, t_prim **prims)
{
	t_prim	*last;
	t_prim	*list;
	char	**tmp;

	list = *prims;
	list = ft_add_lst_file(list, CYLINDER);
	*prims = list;
	last = ft_get_last(list);
	if (ft_count_tab(tab) < 7)
		ft_error_plane();
	tmp = ft_strsplit(tab[1], ':');
	if (ft_count_tab(tmp) != 4 || ft_strequ(tmp[0], "origin") == 0)
		ft_error_cyl();
	ft_set_3dpt(&(last->cyl.origin), (double)ft_atoi(tmp[1]),
		(double)ft_atoi(tmp[2]), (double)ft_atoi(tmp[3]));
	ft_free_tab(tmp);
	ft_parse_vector(tab[2], &(last->cyl.vec));
	tmp = ft_strsplit(tab[3], ':');
	if (ft_count_tab(tmp) != 2 || ft_strequ(tmp[0], "radius") == 0)
		ft_error_cyl();
	if ((last->cyl.radius = ft_atoi(tmp[1])) <= 0)
		ft_error("Radius can not be Null or negative");
	ft_free_tab(tmp);
	ft_parse_color(tab[4], &(last->color2), &ft_error_cyl);
	ft_parsing_mov(tab[5], tab[6], last, &ft_error_cyl);
	ft_count_options(last, tab, 7);
}

void	ft_cone_setup(char **tab, t_prim **prims)
{
	t_prim	*last;
	t_prim	*list;
	char	**tmp;

	list = *prims;
	list = ft_add_lst_file(list, CONE);
	*prims = list;
	last = ft_get_last(list);
	if (ft_count_tab(tab) < 7)
		ft_error_plane();
	tmp = ft_strsplit(tab[1], ':');
	if (ft_count_tab(tmp) != 4 || ft_strequ(tmp[0], "origin") == 0)
		ft_error_cone();
	ft_set_3dpt(&(last->cone.origin), (double)ft_atoi(tmp[1]),
		(double)ft_atoi(tmp[2]), (double)ft_atoi(tmp[3]));
	ft_free_tab(tmp);
	ft_parse_vector(tab[2], &(last->cone.vec));
	tmp = ft_strsplit(tab[3], ':');
	if (ft_count_tab(tmp) != 2 || ft_strequ(tmp[0], "angle") == 0)
		ft_error_cone();
	last->cone.angle = ft_degree_to_rad(ft_atoi(tmp[1]));
	ft_free_tab(tmp);
	ft_parse_color(tab[4], &(last->color2), &ft_error_cone);
	ft_parsing_mov(tab[5], tab[6], last, &ft_error_cone);
	ft_count_options(last, tab, 7);
}

void	ft_sphere_setup(char **tab, t_prim **prims)
{
	t_prim	*last;
	t_prim	*list;
	char	**tmp;

	list = *prims;
	list = ft_add_lst_file(list, SPHERE);
	*prims = list;
	last = ft_get_last(list);
	if (ft_count_tab(tab) < 6)
		ft_error_plane();
	tmp = ft_strsplit(tab[1], ':');
	if (ft_count_tab(tmp) != 4 || ft_strequ(tmp[0], "origin") == 0)
		ft_error_sphere();
	ft_set_3dpt(&(last->sphere.origin), (double)ft_atoi(tmp[1]),
		(double)ft_atoi(tmp[2]), (double)ft_atoi(tmp[3]));
	ft_free_tab(tmp);
	tmp = ft_strsplit(tab[2], ':');
	if (ft_count_tab(tmp) != 2 || ft_strequ(tmp[0], "radius") == 0)
		ft_error_sphere();
	last->sphere.radius = ft_atoi(tmp[1]);
	ft_free_tab(tmp);
	ft_parse_color(tab[3], &(last->color2), &ft_error_sphere);
	ft_parsing_mov(tab[4], tab[5], last, &ft_error_sphere);
	if(read_cut(tab + 5, prims))
		ft_count_options(last, tab, 6 + 3);
	else
		ft_count_options(last, tab, 6);
}

void	ft_cercle_setup(char **tab, t_prim **prims)
{
	t_prim	*last;
	t_prim	*list;

	list = *prims;
	list = ft_add_lst_file(list, CERCLE);
	*prims = list;
	last = ft_get_last(list);
	if (ft_count_tab(tab) < 7)
		ft_error("parsing cercle");
	read_vect(tab[1], &(last->cercle.pos));
	read_vect(tab[2], &(last->cercle.dir));
	ft_normalize_vector(&(last->cercle.dir));
	last->cercle.r =  ft_atoi(tab[3]);
	ft_parse_color(tab[4], &(last->color2), &ft_error_sphere);
	ft_parsing_mov(tab[5], tab[6], last, &ft_error_sphere);
}

void	ft_rectangle_setup(char **tab, t_prim **prims)
{
	t_prim	*last;
	t_prim	*list;

	list = *prims;
	list = ft_add_lst_file(list, RECT);
	*prims = list;
	last = ft_get_last(list);
	if (ft_count_tab(tab) < 8)
		ft_error("parsing rect");
	read_vect(tab[1], &(last->rect.pos));
	read_vect(tab[2], &(last->rect.dir));
	ft_normalize_vector(&(last->rect.dir));
	last->rect.width =  ft_atoi(tab[3]);
	last->rect.height =  ft_atoi(tab[4]);
	ft_parse_color(tab[5], &(last->color2), &ft_error_sphere);
	ft_parsing_mov(tab[6], tab[7], last, &ft_error_sphere);
}

void	ft_tore_setup(char **tab, t_prim **prims)
{
	t_prim	*last;
	t_prim	*list;

	list = *prims;
	list = ft_add_lst_file(list, TORE);
	*prims = list;
	last = ft_get_last(list);
	if (ft_count_tab(tab) < 8)
		ft_error("parsing tore");
	read_vect(tab[1], &(last->tore.pos));
	read_vect(tab[2], &(last->tore.dir));
	ft_normalize_vector(&(last->tore.dir));
	last->tore.r1 =  ft_atoi(tab[3]);
	last->tore.r2 =  ft_atoi(tab[4]);
	ft_parse_color(tab[5], &(last->color2), &ft_error_sphere);
	ft_parsing_mov(tab[6], tab[7], last, &ft_error_sphere);
}

void	ft_triangle_setup(char **tab, t_prim **prims)
{
	t_prim	*last;
	t_prim	*list;

	list = *prims;
	list = ft_add_lst_file(list, TRIANGLE);
	*prims = list;
	last = ft_get_last(list);
	if (ft_count_tab(tab) < 7)
		ft_error("parsing triangle");
	read_vect(tab[1], &(last->triangle.p1));
	read_vect(tab[2], &(last->triangle.p2));
	read_vect(tab[3], &(last->triangle.p3));
	ft_parse_color(tab[4], &(last->color2), &ft_error_sphere);
	ft_parsing_mov(tab[5], tab[6], last, &ft_error_sphere);

}
