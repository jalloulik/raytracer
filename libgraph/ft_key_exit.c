/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_exit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjalloul <kjalloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 13:06:44 by kjalloul          #+#    #+#             */
/*   Updated: 2018/02/08 13:06:56 by kjalloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgraph.h"

int			ft_key_hook_exit(int keycode)
{
	if (keycode == ESC_KEY)
		exit(0);
	return (keycode);
}
