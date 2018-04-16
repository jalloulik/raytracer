/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_3dpt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjalloul <kjalloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 14:43:10 by kjalloul          #+#    #+#             */
/*   Updated: 2018/02/14 14:43:43 by kjalloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgraph.h"

void	ft_set_3dpt(t_3dpt *point, double x, double y, double z)
{
	point->x = x;
	point->y = y;
	point->z = z;
}
