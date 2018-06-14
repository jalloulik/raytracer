/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfavart <tfavart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 15:58:32 by tfavart           #+#    #+#             */
/*   Updated: 2018/06/14 11:47:19 by tfavart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTER_H
# define INTER_H

typedef struct		s_3d_button
{
	GtkWidget		*label_x;
	GtkWidget		*x;
	GtkWidget		*label_y;
	GtkWidget		*y;
	GtkWidget		*label_z;
	GtkWidget		*z;
}					t_3d_button;

typedef struct		s_2d_button
{
	GtkWidget		*label_x;
	GtkWidget		*x;
	GtkWidget		*label_y;
	GtkWidget		*y;
}					t_2d_button;

typedef struct		s_1d_button
{
	GtkWidget		*label_x;
	GtkWidget		*x;
}					t_1d_button;

typedef struct		s_container
{
	GtkWidget		*principal;
	GtkWidget		*colonne0;
	GtkWidget		*colonne1;
	GtkWidget		*colonne2;
	GtkWidget		*colonne3;
	GtkWidget		*colonne4;
	GtkWidget		*colonne5;
}					t_container;

typedef struct		s_inter_fixe
{
	t_3d_button		pos;
	t_3d_button		rot;
	t_1d_button		angle_rot;
	t_3d_button		translation;
	t_3d_button		vec;
	t_3d_button		color;
}					t_inter_fixe;

typedef struct		s_primitive
{
	GtkWidget		*sphere;
	GtkWidget		*plan;
	GtkWidget		*cylindre;
	GtkWidget		*cone;
}					t_primitive;

typedef struct		s_reflect_ui
{
	t_1d_button		on_off;
	t_1d_button		pourcent;
}					t_reflect_ui;

typedef struct		s_refract_ui
{
	t_1d_button		on_off;
	t_1d_button		pourcent;
	t_1d_button		material;
}					t_refract_ui;

typedef struct		s_texture_ui
{
	t_1d_button		on_off;
	t_1d_button		name;
	t_2d_button		move;
	t_2d_button		scale;
}					t_texture_ui;

typedef struct		s_sinus_ui
{
	t_1d_button		on_off;
	t_2d_button		sin_x;
	t_2d_button		sin_y;
	t_2d_button		sin_z;
}					t_sinus_ui;

typedef struct		s_checker_ui
{
	t_1d_button		on_off;
	t_2d_button		move;
	t_2d_button		scale;
}					t_checker_ui;

typedef struct		s_list_ui
{
	GtkListStore	*store;
	GtkWidget		*button;
}					t_list_ui;

typedef struct		s_interface
{
	t_container		cont;
	t_inter_fixe	fix;
	t_primitive		prim;
	t_1d_button		angle;
	t_1d_button		rad;
	t_1d_button		specular;
	t_reflect_ui	reflect;
	t_refract_ui	refract;
	t_texture_ui	tex_c;
	t_texture_ui	tex_n;
	t_sinus_ui		sinus;
	t_list_ui		list;
	t_checker_ui	checker;

	t_elem			*list_e;
}					t_interface;

#endif