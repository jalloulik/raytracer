/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjalloul <kjalloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 18:26:38 by kjalloul          #+#    #+#             */
/*   Updated: 2018/03/22 14:23:41 by kjalloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	ft_error_cam(void)
{
	ft_putendl("cam|origin:x:y:z|rotation:x:y:z:angle:n|translation:x:y:z");
	exit(0);
}

void	ft_error_sphere(void)
{
	ft_putstr("Sphere Usage: sphere|origin:x:y:z|radius:n|");
	ft_putendl("color:r:ff:g:00:b:00|rotation:x:y:z:angle:n|translation:x:y:z");
	exit(0);
}

void	ft_error_cone(void)
{
	ft_putstr("Cone Usage: cone|origin:x:y:z|vec:x:y:z|angle:n|");
	ft_putendl("color:r:ff:g:00:b:00|rotation:x:y:z:angle:n|translation:x:y:z");
	exit(0);
}

void	ft_error_plane(void)
{
	ft_putstr("Plane Usage : plane|origin:x:y:z|normal:x:y:z|");
	ft_putendl("color:r:ff:g:00:b:00|rotation:x:y:z:angle:n|translation:x:y:z");
	exit(0);
}

void	ft_error_cyl(void)
{
	ft_putstr("Cyl Usage: cylinder|origin:x:y:z|vec:x:y:z|radius:n|");
	ft_putendl("color:r:ff:g:00:b:00|rotation:x:y:z:angle:n|translation:x:y:z");
	exit(0);
}
