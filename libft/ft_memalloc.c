/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvillepo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 17:25:09 by yvillepo          #+#    #+#             */
/*   Updated: 2018/01/09 21:06:01 by yvillepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*mem;

	if (!(mem = malloc(size)))
		exit (0);
	ft_bzero(mem, size);
	return (mem);
}

void	*ft_malloc(size_t size)
{
	void	*mem;

	if (!(mem = malloc(size)))
		exit (0);
	return (mem);
}
