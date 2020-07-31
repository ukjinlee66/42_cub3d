/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlee <youlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 17:13:14 by youlee            #+#    #+#             */
/*   Updated: 2020/08/01 03:33:01 by youlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "cub3d.h"

static void		put_line(char **line, char ***buf2, int idx)
{
	char			*temp;
	char			*temp2;

	temp = malloc(sizeof(char) * (idx + 1));
	ft_strncpy(temp, (**buf2), idx);
	if ((**buf2)[idx] != '\0')
	{
		temp2 = ft_strdup((**buf2) + (idx + 1));
		free(**buf2);
		**buf2 = temp2;
	}
	else if ((**buf2)[idx] == '\0')
	{
		free(**buf2);
		**buf2 = ft_strdup("\0");
	}
	*line = temp;
}

static int		val_ret(char **buf2, int fdnum, char **line)
{
	if ((*buf2)[0] == 0 && fdnum < BUFFER_SIZE && fdnum >= 0)
	{
		*line = ft_strdup("\0");
		free(*buf2);
		*buf2 = 0;
	}
	else if (fdnum == 0)
	{
		if ((ft_strchr((*buf2), '\n') >= 0))
		{
			put_line(line, &buf2, ft_strchr((*buf2), '\n'));
			return (1);
		}
		else if ((ft_strchr((*buf2), '\0')) >= 0)
		{
			put_line(line, &buf2, ft_strchr((*buf2), '\0'));
			free(*buf2);
			*buf2 = 0;
			return (0);
		}
	}
	return ((fdnum < 0 ? -1 : 0));
}

static int		buf2_manage(char **buf2, char **line, char *buf)
{
	char			*temp;

	if ((*buf2)[0] == 0)
	{
		temp = ft_strdup(buf);
		free(*buf2);
		*buf2 = temp;
		free(buf);
	}
	else
	{
		temp = ft_strjoin(*buf2, buf);
		free(*buf2);
		*buf2 = temp;
		free(buf);
	}
	if ((ft_strchr(*buf2, '\n')) >= 0)
	{
		put_line(line, &buf2, ft_strchr(*buf2, '\n'));
		return (1);
	}
	return (0);
}

int				get_next_line(int fd, char **line)
{
	static char		*buf2;
	char			*buf;
	int				fdnum;

	if (fd < 0 || line == NULL || BUFFER_SIZE <= 0)
		return (-1);
	buf = (char*)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (buf2 == NULL)
		buf2 = (char*)malloc(sizeof(char) * 1000000);
	while ((fdnum = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[fdnum] = '\0';
		if (buf2_manage(&buf2, line, buf) == 1)
			return (1);
		buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	}
	if (buf)
		free(buf);
	return (val_ret(&buf2, fdnum, line));
}
