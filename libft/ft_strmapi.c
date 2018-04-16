/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjalloul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 11:53:08 by kjalloul          #+#    #+#             */
/*   Updated: 2017/11/13 11:54:28 by kjalloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*buff;
	unsigned int	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	buff = (char*)malloc(sizeof(*buff) * (ft_strlen(s) + 1));
	if (buff == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		buff[i] = f(i, s[i]);
		i++;
	}
	buff[i] = '\0';
	return (buff);
}
