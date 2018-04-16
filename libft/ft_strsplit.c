/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjalloul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 15:04:15 by kjalloul          #+#    #+#             */
/*   Updated: 2017/11/15 19:51:09 by kjalloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		skip_symb(char const *s, char c, int i)
{
	while (s[i] != '\0' && s[i] == c)
		i++;
	return (i);
}

static int		count_words(char const *s, char c)
{
	int i;
	int count;

	i = 0;
	count = 0;
	i = skip_symb(s, c, i);
	while (s[i] != '\0')
	{
		count++;
		while (s[i] != '\0' && s[i] != c)
			i++;
		i = skip_symb(s, c, i);
	}
	return (count);
}

static int		word_len(char const *s, char c, int i[2], char **table)
{
	int len;
	int j;

	len = 0;
	j = 0;
	while (s[i[0]] != '\0' && s[i[0]] != c)
	{
		(i[0])++;
		len++;
	}
	i[0] = i[0] - len;
	if ((table[i[1]] = (char*)malloc(sizeof(char) * (len + 1))) == NULL)
		return (-1);
	while (len > 0)
	{
		table[i[1]][j] = s[i[0]];
		(i[0])++;
		j++;
		len--;
	}
	table[i[1]][j] = '\0';
	return (i[0]);
}

char			**ft_strsplit(char const *s, char c)
{
	int		word_count;
	char	**table;
	int		i[2];

	i[0] = 0;
	i[1] = 0;
	if (s == NULL)
		return (NULL);
	word_count = count_words(s, c);
	if ((table = (char**)malloc(sizeof(*table) * (word_count + 1))) == NULL)
		return (NULL);
	i[0] = skip_symb(s, c, i[0]);
	while (s[i[0]] != '\0')
	{
		i[0] = skip_symb(s, c, i[0]);
		if ((i[0] = word_len(s, c, i, table)) < 0)
			return (NULL);
		(i[1])++;
		i[0] = skip_symb(s, c, i[0]);
	}
	table[i[1]] = 0;
	return (table);
}
