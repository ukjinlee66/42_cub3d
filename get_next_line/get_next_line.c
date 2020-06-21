/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlee <youlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 00:45:36 by youlee            #+#    #+#             */
/*   Updated: 2020/04/22 17:06:30 by youlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void			put_line(char **line, char **buf2, int fd, int idx)
{
	char			*temp;
	char			*temp2;

	temp = malloc(sizeof(char) * (idx + 1));
	ft_strncpy(temp, buf2[fd], (unsigned int)idx);
	if (buf2[fd][idx] != '\0')
	{
		temp2 = ft_strdup(buf2[fd] + (idx + 1), 1, 0, 0);
		ft_strdup(0, 0, &buf2[fd], temp2);
	}
	else if ((buf2[fd][idx]) == '\0')
		ft_strdup(0, 0, &buf2[fd], ft_strdup("\0", 1, 0, 0));
	*line = temp;
}

static int			val_ret(char ***buf2, int fd, int fdnum, char **line)
{
	int row;

	row = 0;
	while ((*buf2)[row] != NULL)
		row++;
	if ((*buf2)[fd][0] == 0 && fdnum < BUFFER_SIZE && fdnum >= 0)
	{
		*line = ft_strdup("\0", 1, 0, 0);
		return (ft_strlen(NULL, buf2, 1, row));
	}
	else if (fdnum == 0)
	{
		if ((ft_strchr((*buf2)[fd], '\n', 0, -1)) >= 0)
		{
			put_line(line, *buf2, fd, ft_strchr((*buf2)[fd], '\n', 0, -1));
			return (1);
		}
		else if ((ft_strchr((*buf2)[fd], '\0', 0, -1)) >= 0)
		{
			put_line(line, *buf2, fd, ft_strchr((*buf2)[fd], '\0', 0, -1));
			return (ft_strlen(NULL, buf2, 1, row));
		}
	}
	return ((fdnum < 0 ? -1 : 0));
}

static int			buf2_manage(char **buf2, char **line, char *buf, int fd)
{
	char			*temp;

	if (buf2[fd][0] == 0)
	{
		temp = ft_strdup(buf, 1, 0, 0);
		ft_strdup(0, 0, &buf2[fd], temp);
		free(buf);
	}
	else
	{
		temp = ft_strjoin(buf2[fd], buf);
		ft_strdup(0, 0, &buf2[fd], temp);
		free(buf);
	}
	if ((ft_strchr(buf2[fd], '\n', 0, -1)) >= 0)
	{
		put_line(line, buf2, fd, ft_strchr(buf2[fd], '\n', 0, -1));
		return (1);
	}
	return (0);
}

static void			row_calloc(char ***buf2, int fd, int row_size)
{
	char			**temp;
	char			**bb;

	bb = *buf2;
	while (bb[row_size] != NULL)
		row_size++;
	if (fd + 1 > row_size)
	{
		row_size = 0;
		temp = malloc(sizeof(char*) * (fd + 2));
		temp[fd + 1] = NULL;
		while (bb[row_size] != NULL)
		{
			temp[row_size] = ft_strdup(bb[row_size], 1, 0, 0);
			free(bb[row_size]);
			row_size++;
		}
		while (row_size < fd + 1)
		{
			temp[row_size] = ft_strdup("\0", 1, 0, 0);
			row_size++;
		}
		free(bb);
		*buf2 = temp;
	}
}

int					get_next_line(int fd, char **line)
{
	static char		**buf2;
	char			*buf;
	int				fdnum;

	if (fd < 0 || line == NULL || BUFFER_SIZE <= 0)
		return (-1);
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buf2 == NULL)
	{
		buf2 = (char**)malloc(sizeof(char*) * (fd + 2));
		buf2[fd + 1] = NULL;
		ft_strchr(0, 0, buf2, fd);
	}
	else
		row_calloc(&buf2, fd, 0);
	while ((fdnum = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[fdnum] = '\0';
		if (buf2_manage(buf2, line, buf, fd) == 1)
			return (1);
		buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	}
	if (buf)
		free(buf);
	return (val_ret(&buf2, fd, fdnum, line));
}
