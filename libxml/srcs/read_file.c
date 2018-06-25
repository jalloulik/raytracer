/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfavart <tfavart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 17:48:18 by mfrisby           #+#    #+#             */
/*   Updated: 2018/06/24 16:55:16 by tfavart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include "libxml.h"

static off_t	file_size(int fd)
{
	struct stat	st;

	if (fstat(fd, &st) == 0)
		return (st.st_size);
	return (-1);
}

void			read_file(int fd, t_xmlp *xmlp)
{
	char		*buf;
	int			len;

	len = file_size(fd);
	if (!(buf = (char*)malloc(sizeof(char) * (len + 1))))
		ft_error_2("probleme allocation memoire\n");
	while (read(fd, buf, len))
	{
	}
	xmlp->content = buf;
	xmlp->len = len;
}
