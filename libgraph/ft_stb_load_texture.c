/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stb_load_texture.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjalloul <kjalloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 14:07:07 by kjalloul          #+#    #+#             */
/*   Updated: 2018/05/11 16:11:41 by kjalloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# define STB_IMAGE_IMPLEMENTATION
# include "../stb/stb_image.h"
#include "libgraph.h"

void ft_stb_load_textur(t_texture *textur, char *file_path)
{
	if (file_path != NULL && textur != NULL)
		textur->data = stbi_load(file_path, &(textur->width),
											&(textur->height), &(textur->n), 0);
}
