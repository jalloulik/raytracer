/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elem.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfavart <tfavart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 14:34:45 by tfavart           #+#    #+#             */
/*   Updated: 2018/06/20 13:19:19 by tfavart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ELEM_H
# define ELEM_H

typedef struct		s_3d
{
	int				x;
	int				y;
	int				z;
}					t_3d;

typedef struct		s_2d
{
	int				x;
	int				y;
}					t_2d;

typedef struct		s_refract
{
	char			on_off;
	char			*material;
	int				pourcent;
}					t_refract;

typedef struct		s_reflect
{
	char			on_off;
	int				pourcent;
}					t_reflect;

typedef struct		s_texture
{
	char			on_off;
	char			*name;
	t_2d			move;
	t_2d			scale;
}					t_texture;

typedef struct		s_sinus
{
	char			on_off;
	t_2d			sin_x;
	t_2d			sin_y;
	t_2d			sin_z;
}					t_sinus;

typedef struct		s_checker
{
	char			on_off;
	t_2d			move;
	t_2d			scale;
}					t_checker;

typedef struct		s_tri
{
	t_3d			p1;
	t_3d			p2;
	t_3d			p3;
}					t_tri;

typedef struct		s_elem
{
	char			*name;
	GtkTreeIter		iter;
	char			type;
	t_3d			pos;
	t_3d			translation;
	t_3d			vec;
	t_3d			rot;
	int				angle_rot;
	t_3d			color;
	int				angle;
	int				rad;
	int				intensity;
	char			specular;
	t_reflect		reflect;
	t_refract		refract;
	t_texture		tex_c;
	t_texture		tex_n;
	t_sinus			sinus;
	t_checker		checker;
	t_tri			triang;
	char			sepia;
	t_2d			rayon_torre;
	t_2d			size;
	struct s_elem	*next;
}					t_elem;

#endif
