/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvillepo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 03:29:15 by yvillepo          #+#    #+#             */
/*   Updated: 2018/03/23 07:25:27 by yvillepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void			read_color(t_color *color, int fd)
{
	char	*line;

	if (get_next_line(fd, &line) == 0)
		exit_error("fichier emtree");
	jump_coment(&line);
	color->color = (unsigned int)ft_atoi_base(line, 16);
	free(line);
}

t_color			mult_color(t_color color, double mult)
{
	if (mult < 0)
		mult = 0;
	if (mult > 1)
		mult = 1;
	color.rgb[0] *= mult;
	color.rgb[1] *= mult;
	color.rgb[2] *= mult;
	return (color);
}
