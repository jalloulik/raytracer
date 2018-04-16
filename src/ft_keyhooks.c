/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keyhooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjalloul <kjalloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 10:50:12 by kjalloul          #+#    #+#             */
/*   Updated: 2018/02/22 10:52:02 by kjalloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		ft_keyhook(int keycode, void *param)
{
	param = NULL;
	if (keycode == ESC_KEY)
		ft_key_hook_exit(keycode);
	return (keycode);
}
