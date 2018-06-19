/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keyhooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjalloul <kjalloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 10:50:12 by kjalloul          #+#    #+#             */
/*   Updated: 2018/06/04 14:30:46 by kjalloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		ft_keyhook(int keycode, void *param)
{
	if (keycode == ESC_KEY)
		ft_key_hook_exit(keycode);
	else if (keycode == S_KEY)
		ft_save_image(param);
	return (keycode);
}
