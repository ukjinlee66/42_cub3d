/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlee <youlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 17:13:14 by youlee            #+#    #+#             */
/*   Updated: 2020/07/30 18:58:04 by youlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "he.h"

void		put_line(char **line, char *buf2, int fd,
		int idx)
{
	printf("put_line\n");
	char			*temp;
	char			*temp2;

	temp = malloc(sizeof(char) * (idx + 1));
	ft_strncpy(temp, buf2, idx);
	printf("temp : %s\n",temp);
	if (buf2[idx] != '\0')
	{
		temp2 = ft_strdup(buf2 + (idx + 1));
		free(buf2);
		buf2 = temp2;
	}
	else if (buf2[idx] == '\0')
	{
		free(buf2);
		buf2 = "\0";
	}
	*line = temp;
}

int		val_ret(char *buf2, int fd, int fdnum,
		char **line)
{
	printf("val_ret\n");
	if (buf2[0] == 0 && fdnum < 100 && fdnum >= 0)
	{
		*line = ft_strdup("\0");
		free(buf2);
		buf2 = 0;
	}
	else if (fdnum == 0)
	{
		if ((ft_strchr(buf2, '\n') >= 0))
		{
			put_line(line, buf2, fd, ft_strchr(buf2, '\n'));
			return (1);
		}
		else if ((ft_strchr(buf2, '\0')) >= 0)
		{
			put_line(line, buf2, fd, ft_strchr(buf2, '\0'));
			free(buf2);
			buf2 = 0;
			return (0);
		}
	}
	return ((fdnum < 0 ? -1 : 0));
}


static int		buf2_manage(char *buf2, char **line,
		char *buf, int fd)
{
	printf("buf2_manage\n");
	char			*temp;

	if (buf2[0] == 0)
	{
		printf("buf2[0] == 0\n");
		temp = ft_strdup(buf);
		free(buf2);
		buf2 = temp;
		free(buf);
	}
	else
	{
		printf("else\n");
		temp = ft_strjoin(buf2, buf);
		free(buf2);
		buf2 = temp;
		free(buf);
	}
	if ((ft_strchr(buf2, '\n')) >= 0)
	{
		printf("a\n");
		put_line(line, buf2, fd, ft_strchr(buf2, '\n'));
		return (1);
	}
	return (0);
}

int				get_next_line(int fd, char **line)
{
	static char		*buf2;
	char			*buf;
	int				fdnum;

	if (fd < 0 || line == NULL)
		return (-1);
	buf = (char*)malloc(sizeof(char) * 4096);
	if (buf2 == NULL)
		buf2 = (char*)malloc(sizeof(char) * 4096);
	while ((fdnum = read(fd, buf, 100)) > 0)
	{
		printf("fdnum : %d\n",fdnum);
		buf[fdnum] = '\0';
		printf("buf : %s\n",buf);
		if (buf2_manage(buf2, line, buf, fd) == 1)
			return (1);
		buf = malloc(sizeof(char) * 101);
	}
	if (buf)
		free(buf);
	return (val_ret(buf2, fd, fdnum, line));
}
