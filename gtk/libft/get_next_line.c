/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjalloul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 17:43:52 by kjalloul          #+#    #+#             */
/*   Updated: 2017/12/04 12:04:32 by kjalloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_buff		*ft_add_list(t_buff *list, const int fd)
{
	t_buff *start;

	if (list == NULL)
	{
		if ((list = (t_buff*)malloc(sizeof(*list))) == NULL)
			return (NULL);
		start = list;
	}
	else
	{
		start = list;
		while (list->next != NULL)
			list = list->next;
		if (((list->next) = (t_buff*)malloc(sizeof(*(list->next)))) == NULL)
			return (NULL);
		list = list->next;
	}
	list->fullbuff = NULL;
	list->eof = 0;
	list->fd = fd;
	list->err = 1;
	list->next = NULL;
	return (start);
}

static int			ft_get_file(int fd, t_buff *list)
{
	char	buffer[BUFF_SIZE + 1];
	int		err;
	char	*tmp;

	err = 1;
	buffer[BUFF_SIZE] = '\0';
	while ((err) > 0)
	{
		err = read(fd, buffer, BUFF_SIZE);
		if (err < 0)
			return (-1);
		list->err = err;
		buffer[err] = '\0';
		if (ft_count_char(buffer, '\n') > 0)
			err = 0;
		tmp = ft_strjoin(list->fullbuff, (char*)buffer);
		if (list->fullbuff != NULL)
			free(list->fullbuff);
		list->fullbuff = ft_strdup(tmp);
		free(tmp);
	}
	return (1);
}

static int			ft_get_line(t_buff *list, char **line)
{
	size_t		len;
	char		*buff;
	size_t		max;

	max = ft_strlen(list->fullbuff);
	if (max == 0 && list->err == 0)
		return (0);
	buff = ft_strdup(list->fullbuff);
	if (ft_count_char(buff, '\n') > 0)
	{
		len = ft_strchr(buff, '\n') - buff;
		*line = ft_strsub(buff, 0, len);
		if (list->fullbuff != NULL)
			free(list->fullbuff);
		list->fullbuff = ft_strsub(buff, len + 1, ft_strlen(buff) - len - 1);
	}
	else
	{
		*line = ft_strdup(list->fullbuff);
		list->eof = 1;
	}
	free(buff);
	return (1);
}

static t_buff		*ft_get_elem(const int fd, t_buff *list)
{
	while (list != NULL)
	{
		if (list->fd == fd)
			return (list);
		list = list->next;
	}
	return (NULL);
}

int					get_next_line(const int fd, char **line)
{
	static t_buff	*list = NULL;
	t_buff			*tmp;
	ssize_t			err;

	if (line == NULL)
		return (-1);
	tmp = ft_get_elem(fd, list);
	if (tmp != NULL && tmp->eof == 1)
		return (0);
	if (tmp == NULL)
	{
		list = ft_add_list(list, fd);
		tmp = ft_get_elem(fd, list);
	}
	if ((err = ft_get_file(fd, tmp)) < 0)
		return (-1);
	return (ft_get_line(tmp, line));
}
