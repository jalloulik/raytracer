/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfavart <tfavart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 15:58:32 by tfavart           #+#    #+#             */
/*   Updated: 2018/06/23 09:52:03 by tfavart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERFACE_H
# define INTERFACE_H

typedef struct		s_3d_button
{
	GtkWidget		*box_h;
	GtkWidget		*label_x;
	GtkWidget		*x;
	GtkWidget		*label_y;
	GtkWidget		*y;
	GtkWidget		*label_z;
	GtkWidget		*z;
}					t_3d_button;

typedef struct		s_2d_button
{
	GtkWidget		*box_v;
	GtkWidget		*box_h;
	GtkWidget		*label_x;
	GtkWidget		*x;
	GtkWidget		*label_y;
	GtkWidget		*y;
}					t_2d_button;

typedef struct		s_1d_button
{
	GtkWidget		*box_h;
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
	GtkWidget		*colonne6;
	GtkWidget		*colonne7;
	GtkWidget		*colonne8;
	GtkWidget		*colonne9;
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
	GtkWidget		*triangle;
	GtkWidget		*cercle;
	GtkWidget		*carre;
	GtkWidget		*torre;
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

typedef struct		s_cut_ui
{
	t_1d_button		on_off;
	t_3d_button		origin_1;
	t_3d_button		axe_1;
	t_3d_button		origin_2;
	t_3d_button		axe_2;
	t_3d_button		origin_3;
	t_3d_button		axe_3;
	t_3d_button		origin_4;
	t_3d_button		axe_4;
	t_3d_button		origin_5;
	t_3d_button		axe_5;
	t_3d_button		origin_6;
	t_3d_button		axe_6;
}					t_cut_ui;

typedef struct		s_light_ui
{
	GtkWidget		*spot;
	GtkWidget		*sun;
	GtkWidget		*ambiant;
	t_1d_button		intensity;
}					t_light_ui;

typedef struct		s_rayon_ui
{
	t_1d_button		r1;
	t_1d_button		r2;
}					t_rayon_ui;

typedef struct		s_list_ui
{
	GtkListStore	*store;
	GtkWidget		*button;
}					t_list_ui;

typedef struct		s_triangle
{
	t_3d_button		p1;
	t_3d_button		p2;
	t_3d_button		p3;
}					t_triangle;

typedef struct		s_interface
{
	t_container		cont;
	t_inter_fixe	fix;
	t_primitive		prim;
	t_triangle		triang;
	t_1d_button		angle;
	t_1d_button		rad;
	t_1d_button		specular;
	t_2d_button		size;
	t_light_ui		light;
	t_reflect_ui	reflect;
	t_refract_ui	refract;
	t_texture_ui	tex_c;
	t_texture_ui	tex_n;
	t_sinus_ui		sinus;
	t_list_ui		list;
	t_checker_ui	checker;
	t_1d_button		sepia;
	t_rayon_ui		rayon_torre;
	t_elem			*list_e;
	t_cut_ui		cut;
	GtkWidget		*render;
}					t_interface;

#endif
