/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shade.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjalloul <kjalloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 08:59:35 by kjalloul          #+#    #+#             */
/*   Updated: 2018/04/30 15:08:29 by kjalloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_color	ft_combine_colors(t_color *base, t_color *reflect)
{
	int		r;
	int		g;
	int		b;
	t_color result;


	r = base->red + reflect->red;
	g = base->green + reflect->green;
	b = base->blue + reflect->blue;
	if (r > 255)
		r = 255;
	if (g > 255)
		g = 255;
	if (b > 255)
		b = 255;
	ft_set_color(&result, r, g, b);
	return (result);
}

void	ft_get_shade(t_prim *prim, t_color *color, t_light *light)
{
	int		r;
	int		g;
	int		b;

	r = prim->color2.red * light->dotd * light->intensity + color->red;
	g = prim->color2.green * light->dotd * light->intensity + color->green;
	b = prim->color2.blue * light->dotd * light->intensity + color->blue;
	if (light->dotr >= 0 && light->dotr <= 1)
	{
		r = r + light->color.red * light->intensity * pow(light->dotr, HARD);
		g = g + light->color.green * light->intensity * pow(light->dotr, HARD);
		b = b + light->color.blue * light->intensity * pow(light->dotr, HARD);
	}
	if (r > 255)
		r = 255;
	if (g > 255)
		g = 255;
	if (b > 255)
		b = 255;
	color->red = (unsigned char)r;
	color->green = (unsigned char)g;
	color->blue = (unsigned char)b;
	color->alpha = 0;
}
