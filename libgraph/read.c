/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvillepo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 11:59:52 by yvillepo          #+#    #+#             */
/*   Updated: 2018/03/23 07:32:03 by yvillepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include <fcntl.h>

void			jump_coment(char **line)
{
	char	*l;
	char	*tmp;

	l = *line;
	while (*l)
	{
		if (*l == ':')
		{
			l++;
			while (*l && *l == ' ')
				l++;
			tmp = ft_strdup(l);
			free(*line);
			*line = tmp;
			return ;
		}
		l++;
	}
}

t_vect			*read_vect(int fd)
{
	char	*line;
	char	**point;
	t_vect	*v;

	v = ft_malloc(sizeof(*v));
	if (get_next_line(fd, &line) == 0)
		exit_error("fichier emtree");
	jump_coment(&line);
	point = ft_strsplit(line, ' ');
	if (len_tabstr(point) < 3)
		exit_error("fichier entree");
	v->x = ft_atof(*point);
	v->y = ft_atof(point[1]);
	v->z = ft_atof(point[2]);
	free_tabstr(&point);
	free(line);
	return (v);
}

static void		read_object(t_mlx *mlx, char *obj, int fd)
{
	t_object	*object;

	if (*obj == '\n')
		return ;
	object = malloc(sizeof(*object));
	if (*obj == 's')
		read_object_sphere(object, fd);
	else if (*obj == 'p')
		read_object_plane(object, fd);
	else if (*obj == 'c' && obj[1] == 'y')
		read_object_cyl(object, fd);
	else if (*obj == 'c' && obj[1] == 'o')
		read_object_cone(object, fd);
	else
		exit_error("object unknown");
	read_color(&(object->color), fd);
	if (mlx->object == 0)
		mlx->object = ft_lstnew(object, sizeof(*object));
	else
		ft_lstadd(&(mlx->object), ft_lstnew(object, sizeof(*object)));
	free(object);
}

void			parse_block(t_mlx *mlx, char *line, int fd, int *i)
{
	if (*line == 'r' || *line == 'R')
	{
		read_rot(mlx, line, *i);
		return ;
	}
	if (*line == 't' || *line == 'T')
	{
		read_translation(mlx, line, fd, *i);
		return ;
	}
	read_object(mlx, line, fd);
	line = 0;
	(*i)++;
}

void			parse(t_mlx *mlx, char *file)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	fd = open(file, O_RDONLY);
	read_camera(mlx, fd);
	read_light(mlx, fd);
	while (get_next_line(fd, &line))
	{
		jump_coment(&line);
		if (!(*line))
		{
			free(line);
			continue ;
		}
		parse_block(mlx, line, fd, &i);
		if (line)
			free(line);
		line = 0;
	}
}
