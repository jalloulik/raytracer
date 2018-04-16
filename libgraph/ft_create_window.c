/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_window.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjalloul <kjalloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 17:42:36 by kjalloul          #+#    #+#             */
/*   Updated: 2018/01/03 08:01:34 by kjalloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgraph.h"

void	ft_create_window(t_winenv *mlxenv, int length, int height, char *title)
{
	mlxenv->length = length;
	mlxenv->height = height;
	mlxenv->win = mlx_new_window(mlxenv->mlxptr, mlxenv->length,
											mlxenv->height, title);
	if (mlxenv->win == NULL)
		ft_error(ERROR);
}
