/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjalloul <kjalloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 12:04:54 by kjalloul          #+#    #+#             */
/*   Updated: 2018/05/10 19:44:57 by yvillepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H
# include <stdio.h>
# include <fcntl.h>
# include "libgraph.h"

# define WIN_WIDTH 1000
# define WIN_HEIGHT 1000

# define SPHERE 1
# define PLANE 2
# define CONE 3
# define CYLINDER 4
# define CERCLE 5
# define RECT 6
# define VALID 1
# define UNVALID 0

# define HARD 50

# define ERRUSAGE "Usage : ./rtv1 <filename>"
# define ERRFILE "File does not exist"
# define ERRCAM "Cam Usage: cam|origin:x,y,z|vd:x,y,z|vdr:x,y,z"
# define ERRSPOT "Spot Usage: spot|origin:x:y:z|intensity"
# define ERRCOLOR "Color Usage color:r:00:g:00:b:00"
# define ERR_COLOR_RANGE "Colors can only be between 0 and 255"
# define ERRDIV "Can not divide by 0"

typedef struct		s_2dpt
{
	int				x;
	int				y;
}					t_2dpt;

typedef struct		s_quater
{
	double			w;
	double			x;
	double			y;
	double			z;
}					t_quater;

typedef struct		s_line
{
	t_3dpt			*pos;
	t_3dpt			*dir;
}					t_line;

typedef struct		s_cercle
{
	t_3dpt			pos;
	t_3dpt			dir;
	double			r;	
	double			t;
	int				color;
}					t_cercle;

typedef struct		s_rect
{
	t_3dpt			pos;
	t_3dpt			dir;
	double			height;
	double			width;
	t_3dpt			pos_local;
	t_3dpt			dir_local;
	t_3dpt			l_to_g_move;
	t_3dpt			g_to_l_move;
	t_quater		l_to_g_rot;
	t_quater		g_to_l_rot;
}					t_rect;

typedef struct		s_plane
{
	t_3dpt			normal;
	t_3dpt			point;
	int				color;
	t_3dpt			path_to_light;
	double			d;
}					t_plane;

typedef struct		s_sphere
{
	double			radius;
	t_3dpt			origin;
	int				color;
	double			a;
	double			b;
	double			c;
	double			det;
	double			t1;
	double			t2;
	t_3dpt			path_to_light;
	t_3dpt			normal;
}					t_sphere;

typedef struct		s_cyl
{
	double			radius;
	t_3dpt			origin;
	t_3dpt			vec;
	t_3dpt			origin_local;
	t_3dpt			vec_local;
	int				color;
	double			a;
	double			b;
	double			c;
	double			det;
	double			t1;
	double			t2;
	t_3dpt			o;
	t_3dpt			path_to_light;
	t_3dpt			normal;
}					t_cyl;

typedef struct		s_cone
{
	double			radius;
	t_3dpt			origin;
	t_3dpt			vec;
	t_3dpt			origin_local;
	t_3dpt			vec_local;
	double			angle;
	int				color;
	double			a;
	double			b;
	double			c;
	double			det;
	double			t1;
	double			t2;
	t_3dpt			o;
	t_3dpt			path_to_light;
	t_3dpt			normal;
}					t_cone;

typedef struct		s_prim
{
	int				type;
	t_sphere		sphere;
	t_plane			plane;
	t_cone			cone;
	t_cyl			cyl;
	t_cercle		cercle;
	t_rect			rect;
	double			t;
	int				isvalid;
	int				color;
	t_color			color2;
	double			dot;
	t_3dpt			p;
	t_3dpt			normal;
	t_3dpt			rot_axis;
	double			rot_angle;
	t_3dpt			transl;
	t_3dpt			l_to_g_move;
	t_3dpt			g_to_l_move;
	t_quater		l_to_g_rot;
	t_quater		g_to_l_rot;
	int				reflective;
	struct s_prim	*next;
}					t_prim;

typedef struct		s_vp
{
	double			width;
	double			height;
	double			dist;
	t_3dpt			vplr;
	double			xindent;
	double			yindent;
	t_2dpt			*pos;
}					t_vp;

typedef struct		s_cam
{
	t_3dpt			origin;
	double			fov;
	t_vp			vp;
	t_3dpt			vd;
	t_3dpt			vdr;
	t_3dpt			vdu;
	t_3dpt			rot_axis;
	double			rot_angle;
	t_3dpt			transl;
}					t_cam;

typedef struct		s_ray
{
	t_3dpt			vpcurrent;
	t_3dpt			dir;
	t_3dpt			dir_re;
	double			distance;
	t_3dpt			p;
	int				color;
	t_color			color2;
	t_cam			*cam;
}					t_ray;

typedef struct		s_light
{
	int				type;
	t_prim			prim;
	double			t;
	t_3dpt			origin;
	double			intensity;
	double			dist;
	t_color			color;
	double			dotd;
	double			dotr;
	int				status;
	int				valid;
	struct s_light	*next;
}					t_light;

typedef struct		s_obj
{
	t_light			*light;
	t_prim			*prim;
}					t_obj;

void				ft_init_sphere(t_sphere *sphr, t_3dpt origin, double radius,
																	int color);
void				ft_init_cam_vectors(t_cam *cam);
void				ft_init_cam(t_cam *cam);
void				ft_get_topleft_indent(t_cam *cam);

t_color				ft_figure_color(t_obj *obj, t_3dpt *origin);

void				ft_calculate_vector(t_3dpt *vector, t_3dpt *start,
																t_3dpt *end);
double				ft_calculate_dot(t_3dpt *vec1, t_3dpt *vec2);
void				ft_calculate_vec_end(t_3dpt *end, t_3dpt *start,
														t_3dpt *vec, double t);

int					ft_keyhook(int keycode, void *param);
t_prim				*ft_add_lst_file(t_prim *list, int type);

void				ft_init_plane(t_plane *plane, t_3dpt point, t_3dpt normal,
																	int color);

double				ft_resolve_cyl(t_prim *prim, t_3dpt *dir, t_3dpt *origin);

void				ft_parsing_start(char *filename, t_cam *cam, t_light **spot,
																t_prim **list);

void				ft_check_camera(char *str, t_cam *cam);

int					ft_count_tab(char **tab);
void				ft_free_tab(char **tab);

void				ft_set_color(t_color *color, int r, int g, int b);

double				ft_resolve_sphere(t_prim *prim, t_3dpt *dir,
														t_3dpt *ray_origin);
double				ft_resolve_plane(t_prim *prim, t_3dpt *dir,
															t_3dpt *origin);

double				ft_calculate_dist(t_3dpt *p1, t_3dpt *p2);
void				ft_calculate_normal(t_prim *prim, t_3dpt *p);

double				ft_resolve_cone(t_prim *prim, t_3dpt *dir,
															t_3dpt *ray_origin);

double				ft_degree_to_rad(double degree);

void				ft_quater_rot(t_3dpt *result, t_3dpt *source, t_3dpt *axe,
																double theta);

void				ft_normalize_vector(t_3dpt *source);
void				ft_rotate_all(t_prim *prim);

void				ft_sum_vectors(t_3dpt *result, t_3dpt *vec1, t_3dpt *vec2);

t_light				*ft_add_lst_light(t_light *list, int type);

void				ft_cross_product(t_3dpt *result, t_3dpt *vec1,
																t_3dpt *vec2);
void				ft_vec_quater_rot(t_3dpt *result, t_3dpt *vec,
																t_quater *q1);
void				ft_quater_from_vec(t_quater *result, t_3dpt *source);
void				ft_find_quaters_between(t_quater *result, t_3dpt *start,
																t_3dpt *end);
void				ft_quater_mult(t_quater *first, t_quater *second,
															t_quater *result);
void				ft_normalize_quater(t_quater *source);

void				ft_create_local_vector_spaces(t_prim *prim);
void				ft_swap_g_to_l(t_3dpt *result, t_3dpt *source, t_3dpt *move,
															t_quater *rot);
void				ft_swap_l_to_g(t_3dpt *result, t_3dpt *source, t_3dpt *move,
																t_quater *rot);
void				ft_create_local_cyl(t_prim *prim);
void				ft_create_local_cone(t_prim *prim);

void				ft_plane_setup(char **tab, t_prim **prims);
void				ft_cylinder_setup(char **tab, t_prim **prims);
void				ft_cone_setup(char **tab, t_prim **prims);
void				ft_sphere_setup(char **tab, t_prim **prims);
t_prim				*ft_get_last(t_prim *last);
void				ft_parse_color(char *color, t_color *color2,
													void (*ft_err)(void));
void				ft_parsing_mov(char *rot, char *transl, t_prim *last,
														void (*ft_err)(void));
void				ft_spot_setup(char **tab, t_light **spots);

void				ft_translante_all(t_prim *prim);
void				ft_rotate_all(t_prim *prim);
void				ft_rotate_plan(t_prim *prim);
void				ft_rotate_cyl(t_prim *prim);
void				ft_rotate_cone(t_prim *prim);

void                ft_check_lit(t_obj *obj, t_prim *small, t_color *color,
						t_3dpt *origin);

void				ft_error_sphere(void);
void				ft_error_cone(void);
void				ft_error_plane(void);
void				ft_error_cyl(void);
void				ft_error_cam(void);

double				ft_return_prim_dist(t_prim *prim, t_3dpt *ray,
														t_3dpt *origin);
void				ft_resolve_prim(t_prim *prim, t_ray *ray, t_cam *cam);
int                 ft_check_obst(t_3dpt *o, t_3dpt *p_to_light, t_prim *obst, double dist);
void                ft_get_dotr(t_prim *small, t_light *light, t_3dpt *p, t_3dpt *origin);
void                ft_get_shade(t_prim *prim, t_color *color, t_light *light);
double				inter_plane(t_3dpt *normal, double d, t_3dpt *pos, t_3dpt *dir);
t_3dpt				*calc_point(t_3dpt *pos, t_3dpt *dir, double t);
void				read_vect(char *svect, t_3dpt *vect);
void				ft_cercle_setup(char **tab, t_prim **prims);
void				ft_cercle_normal(t_prim *prim, t_3dpt *p);
double				ft_resolve_cercle(t_prim *prim, t_3dpt *dir, t_3dpt *ray_origin);
double				dist(t_3dpt *v, t_3dpt *v2);
void				ft_rectangle_setup(char **tab, t_prim **prims);
void				ft_create_local_rect(t_prim *prim);
double				ft_resolve_rect(t_prim *prim, t_3dpt *dir, t_3dpt *origin);

#endif
