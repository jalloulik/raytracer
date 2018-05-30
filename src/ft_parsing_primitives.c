/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_primitives.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjalloul <kjalloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 16:22:12 by kjalloul          #+#    #+#             */
/*   Updated: 2018/05/30 14:58:32 by kjalloul         ###   ########.fr       */
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
			//harcoded normal
			// ft_stb_load_textur(&(last->textur_n), "assets/Stone_02_NRM.tga");
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
	last->reflective = 0;
	last->refractive = 0;
	if (ft_count_tab(tab) >= 6)
	{
		ft_check_reflection(last, tab[6]);
		ft_check_refraction(last, tab[6]);
		ft_check_texture(last, tab[6], "texture");
		ft_check_texture(last, tab[6], "normal");
	}
	if (ft_count_tab(tab) >= 7)
	{
		ft_check_reflection(last, tab[7]);
		ft_check_refraction(last, tab[7]);
		ft_check_texture(last, tab[7], "texture");
		ft_check_texture(last, tab[7], "normal");
	}
	if (ft_count_tab(tab) >= 8)
	{
		ft_check_reflection(last, tab[8]);
		ft_check_refraction(last, tab[8]);
		ft_check_texture(last, tab[8], "texture");
		ft_check_texture(last, tab[8], "normal");
	}
	if (ft_count_tab(tab) >= 9)
	{
		ft_check_reflection(last, tab[9]);
		ft_check_refraction(last, tab[9]);
		ft_check_texture(last, tab[9], "texture");
		ft_check_texture(last, tab[9], "normal");
	}
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
	last->reflective = 0;
	last->refractive = 0;
	if (ft_count_tab(tab) >= 7)
	{
		ft_check_reflection(last, tab[7]);
		ft_check_refraction(last, tab[7]);
		ft_check_texture(last, tab[7], "texture");
		ft_check_texture(last, tab[7], "normal");
	}
	if (ft_count_tab(tab) >= 8)
	{
		ft_check_reflection(last, tab[8]);
		ft_check_refraction(last, tab[8]);
		ft_check_texture(last, tab[8], "texture");
		ft_check_texture(last, tab[8], "normal");
	}
	if (ft_count_tab(tab) >= 9)
	{
		ft_check_reflection(last, tab[9]);
		ft_check_refraction(last, tab[9]);
		ft_check_texture(last, tab[9], "texture");
		ft_check_texture(last, tab[9], "normal");
	}
	if (ft_count_tab(tab) >= 10)
	{
		ft_check_reflection(last, tab[10]);
		ft_check_refraction(last, tab[10]);
		ft_check_texture(last, tab[10], "texture");
		ft_check_texture(last, tab[10], "normal");
	}
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
	last->reflective = 0;
	last->refractive = 0;
	if (ft_count_tab(tab) >= 7)
	{
		ft_check_reflection(last, tab[7]);
		ft_check_refraction(last, tab[7]);
		ft_check_texture(last, tab[7], "texture");
		ft_check_texture(last, tab[7], "normal");
	}
	if (ft_count_tab(tab) >= 8)
	{
		ft_check_reflection(last, tab[8]);
		ft_check_refraction(last, tab[8]);
		ft_check_texture(last, tab[8], "texture");
		ft_check_texture(last, tab[8], "normal");
	}
	if (ft_count_tab(tab) >= 9)
	{
		ft_check_reflection(last, tab[9]);
		ft_check_refraction(last, tab[9]);
		ft_check_texture(last, tab[9], "texture");
		ft_check_texture(last, tab[9], "normal");
	}
	if (ft_count_tab(tab) >= 10)
	{
		ft_check_reflection(last, tab[10]);
		ft_check_refraction(last, tab[10]);
		ft_check_texture(last, tab[10], "texture");
		ft_check_texture(last, tab[10], "normal");
	}
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
	last->reflective = 0;
	last->refractive = 0;
	last->textur.valid = FALSE;
	last->textur_n.valid = FALSE;
	if (ft_count_tab(tab) >= 6)
	{
		ft_check_reflection(last, tab[6]);
		ft_check_refraction(last, tab[6]);
		ft_check_texture(last, tab[6], "texture");
		ft_check_texture(last, tab[6], "normal");
	}
	if (ft_count_tab(tab) >= 7)
	{
		ft_check_reflection(last, tab[7]);
		ft_check_refraction(last, tab[7]);
		ft_check_texture(last, tab[7], "texture");
		ft_check_texture(last, tab[7], "normal");
	}
	if (ft_count_tab(tab) >= 8)
	{
		ft_check_reflection(last, tab[8]);
		ft_check_refraction(last, tab[8]);
		ft_check_texture(last, tab[8], "texture");
		ft_check_texture(last, tab[8], "normal");
	}
	if (ft_count_tab(tab) >= 9)
	{
		ft_check_reflection(last, tab[9]);
		ft_check_refraction(last, tab[9]);
		ft_check_texture(last, tab[9], "texture");
		ft_check_texture(last, tab[9], "normal");
	}
}
