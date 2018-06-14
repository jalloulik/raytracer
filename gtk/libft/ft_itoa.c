/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjalloul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 16:49:18 by kjalloul          #+#    #+#             */
/*   Updated: 2017/11/15 19:46:13 by kjalloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			ft_get_size(int n)
{
	int i;

	i = 0;
	if (n == 0)
		return (1);
	if (n == -2147483648)
	{
		i++;
		n = n / 10;
	}
	if (n < 0)
		n = -n;
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static int			power_ten(int len)
{
	int power;

	power = 1;
	while (len > 1)
	{
		power = power * 10;
		len--;
	}
	return (power);
}

static char			*here_goes_the_math(int len, char *buff, int i, int n)
{
	int		power;

	power = power_ten(len);
	while (len > 0)
	{
		buff[i] = (n / power) + '0';
		n = n % power;
		power = power / 10;
		i++;
		len--;
	}
	return (buff);
}

char				*ft_itoa(int n)
{
	int		len;
	int		lenmax;
	char	*buff;
	int		i;

	i = 0;
	len = ft_get_size(n);
	lenmax = (n < 0) ? (len + 1) : (len);
	if ((buff = (char*)malloc(sizeof(*buff) * (lenmax + 1))) == NULL)
		return (NULL);
	buff[lenmax] = '\0';
	if (n < 0)
	{
		buff[i++] = '-';
		if (n == -2147483648)
		{
			buff[lenmax - 1] = '8';
			n = n / 10;
			len--;
		}
		n = n * -1;
	}
	return (here_goes_the_math(len, buff, i, n));
}
