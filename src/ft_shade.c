/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shade.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjalloul <kjalloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 08:59:35 by kjalloul          #+#    #+#             */
/*   Updated: 2018/05/31 16:25:01 by kjalloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	ft_sepia_filter(t_color *base)
{
	double		r;
	double		g;
	double		b;

	r = base->red * 0.393 + base->green * 0.769 + base->blue * 0.189;
	g = base->red * 0.349 + base->green * 0.686 + base->blue * 0.168;
	b = base->red * 0.272 + base->green * 0.534 + base->blue * 0.131;
	if (r > 255)
		r = 255;
	if (g > 255)
		g = 255;
	if (b > 255)
		b = 255;
	ft_set_color(base, (int)r, (int)g, (int)b);
}

void	ft_percentage_color(t_color *base, double percentage)
{
	double		r;
	double		g;
	double		b;

	r = base->red * percentage;
	g = base->green * percentage;
	b = base->blue * percentage;
	if (r > 255)
		r = 255;
	if (g > 255)
		g = 255;
	if (b > 255)
		b = 255;
	ft_set_color(base, (int)r, (int)g, (int)b);
}

void	ft_shadow_texture(t_color *base, t_color *texture)
{
	double		r;
	double		g;
	double		b;

	// r = base->red;
	// g = base->green;
	// b = base->blue;
	r = (base->red + texture->red) / 2;
	g = (base->green + texture->green) / 2;
	b = (base->blue + texture->blue) / 2;
	// r = base->red * 0+ texture->red;
	// g = base->green * 0+ texture->green;
	// b = base->blue * 0+ texture->blue;
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

t_color	ft_combine_colors(t_color *base, t_color *reflect, t_color *refract)
{
	int		r;
	int		g;
	int		b;
	t_color result;

	r = base->red + reflect->red + refract->red;
	g = base->green + reflect->green + refract->green;
	b = base->blue + reflect->blue + refract->blue;
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

	if (prim->textur.valid == TRUE)
		prim->color2 = ft_get_sphere_texture(prim);
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
