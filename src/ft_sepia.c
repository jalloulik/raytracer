/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sepia.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjalloul <kjalloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 17:03:12 by kjalloul          #+#    #+#             */
/*   Updated: 2018/06/06 17:03:30 by kjalloul         ###   ########.fr       */
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
