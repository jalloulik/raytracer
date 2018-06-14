/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjalloul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 12:56:32 by kjalloul          #+#    #+#             */
/*   Updated: 2017/12/01 14:56:44 by kjalloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*buff;
	size_t	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	buff = (char *)malloc(sizeof(*buff) * (len + 1));
	if (buff == NULL)
		return (NULL);
	while (i < len)
	{
		buff[i] = s[start];
		i++;
		start++;
	}
	buff[i] = '\0';
	return (buff);
}
