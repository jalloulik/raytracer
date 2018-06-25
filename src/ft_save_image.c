/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjalloul <kjalloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 11:52:39 by kjalloul          #+#    #+#             */
/*   Updated: 2018/06/25 16:14:46 by kjalloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void	ft_put_color_fd(t_color *color, int fd)
{
	ft_putnbr_fd((int)color->red, fd);
	ft_putchar_fd(' ', fd);
	ft_putnbr_fd((int)color->green, fd);
	ft_putchar_fd(' ', fd);
	ft_putnbr_fd((int)color->blue, fd);
	ft_putchar_fd(' ', fd);
}

static void	ft_ppm_header(int fd)
{
	ft_putstr_fd("P3\n", fd);
	ft_putstr_fd("1000 1000\n255\n", fd);
}

static int	ft_create_image(void)
{
	int fd;

	if ((fd = open("screenshots/saved_img.ppm", O_CREAT | O_TRUNC |
														O_WRONLY, 0755)) < 0)
		ft_error("Creation failed");
	ft_ppm_header(fd);
	return (fd);
}

void		ft_save_image(t_winenv *mlxenv)
{
	int		x;
	int		y;
	int		fd;
	t_color	color;

	y = 0;
	fd = ft_create_image();
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			color = ft_read_img_rgb(&(mlxenv->img), x, y);
			ft_put_color_fd(&color, fd);
			x++;
		}
		ft_putchar_fd('\n', fd);
		y++;
	}
	close(fd);
}
