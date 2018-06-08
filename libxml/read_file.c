/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrisby <mfrisby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 17:48:18 by mfrisby           #+#    #+#             */
/*   Updated: 2018/06/08 16:28:11 by mfrisby          ###   ########.fr       */
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
	buf = ft_strnew(len + 1);
	while (read(fd, buf, len))
	{
	}
	xmlp->content = buf;
	xmlp->len = len;
}
