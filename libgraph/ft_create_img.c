/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_img.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjalloul <kjalloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 17:15:01 by kjalloul          #+#    #+#             */
/*   Updated: 2018/01/03 09:34:40 by kjalloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgraph.h"

void	ft_create_img(t_winenv *mlxenv, int length, int height)
{
	mlxenv->img.length = length;
	mlxenv->img.height = height;
	mlxenv->img.ptr = mlx_new_image(mlxenv->mlxptr, (mlxenv->img.length),
							(mlxenv->img.height));
	if (mlxenv->img.ptr == NULL)
		ft_error(ERROR);
	mlxenv->img.str = mlx_get_data_addr(mlxenv->img.ptr, &(mlxenv->img.bpp),
								&(mlxenv->img.s_l), &(mlxenv->img.endian));
	if (mlxenv->img.str == NULL)
		ft_error(ERROR);
}
