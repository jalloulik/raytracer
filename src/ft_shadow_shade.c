/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shadow_shade.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjalloul <kjalloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 20:14:10 by kjalloul          #+#    #+#             */
/*   Updated: 2018/06/20 20:14:25 by kjalloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	ft_shadow_texture(t_color *base, t_color *texture)
{
	double		r;
	double		g;
	double		b;

	r = (base->red + texture->red) / 2;
	g = (base->green + texture->green) / 2;
	b = (base->blue + texture->blue) / 2;
	texture = 0;
	if (r > 255)
		r = 255;
	if (g > 255)
		g = 255;
	if (b > 255)
		b = 255;
	ft_set_color(base, (int)r, (int)g, (int)b);
}

void	ft_get_shadow(t_color *base, double percentage)
{
	double		r;
	double		g;
	double		b;

	r = (base->red * (1 - percentage) + base->red) / 2;
	g = (base->green * (1 - percentage) + base->green) / 2;
	b = (base->blue * (1 - percentage) + base->blue) / 2;
	if (r > 255)
		r = 255;
	if (g > 255)
		g = 255;
	if (b > 255)
		b = 255;
	ft_set_color(base, (int)r, (int)g, (int)b);
}
