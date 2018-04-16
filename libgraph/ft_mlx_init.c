/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjalloul <kjalloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 08:04:35 by kjalloul          #+#    #+#             */
/*   Updated: 2018/01/03 08:07:54 by kjalloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgraph.h"

void	ft_mlx_init(t_winenv *mlxenv)
{
	mlxenv->mlxptr = mlx_init();
	if (mlxenv->mlxptr == NULL)
		ft_error(ERROR);
}
