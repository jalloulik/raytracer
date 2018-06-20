/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjalloul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 13:10:06 by kjalloul          #+#    #+#             */
/*   Updated: 2017/11/10 18:31:36 by kjalloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_secondstr(char *buff, char const *s2, int i)
{
	int j;

	j = 0;
	if (s2 != NULL)
	{
		while (s2[j] != '\0')
		{
			buff[i] = s2[j];
			j++;
			i++;
		}
	}
	buff[i] = '\0';
	return (buff);
}

static int		ft_firststr(char *buff, char const *s1, int i)
{
	int j;

	j = 0;
	if (s1 != NULL)
	{
		while (s1[j] != '\0')
		{
			buff[i] = s1[j];
			i++;
			j++;
		}
	}
	return (i);
}

char			*ft_strjoin(char const *s1, char const *s2)
{
	char	*buff;
	int		i;
	int		s1size;
	int		s2size;

	i = 0;
	if (s1 != NULL)
		s1size = ft_strlen(s1);
	else
		s1size = 0;
	if (s2 != NULL)
		s2size = ft_strlen(s2);
	else
		s2size = 0;
	buff = (char *)malloc(sizeof(*buff) * (s1size + s2size + 1));
	if (buff == NULL)
		return (NULL);
	i = ft_firststr(buff, s1, i);
	buff = ft_secondstr(buff, s2, i);
	return (buff);
}
