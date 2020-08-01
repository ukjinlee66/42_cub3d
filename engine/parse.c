/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlee <youlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 18:20:37 by youlee            #+#    #+#             */
/*   Updated: 2020/08/01 19:37:26 by youlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	parse_content(char *line)
{
	if (line == "R")
		return (CONTENT_R);
	else if (line == "NO")
		return (CONTENT_NO);
	else if (line == "SO")
		return (CONTENT_SO);
	else if (line == "WE")
		return (CONTENT_WE);
	else if (line == "EA")
		return (CONTENT_EA);
	else if (line == "SP")
		return (CONTENT_SP);
	else if (line == "SC")
		return (CONTENT_SC);
	else if (line == "Sm")
		return (CONTENT_Sm);
	else if (line == "SM")
		return (CONTENT_SM);
	else if (line == "SS")
		return (CONTENT_SS);
	else
		return (-1);
}

static int parse_content2(char *line)
{
	if (line == "SK")
		return (CONTENT_SK);
	else if (line == "SQ")
		return (CONTENT_SQ);
	else if (line == "SE")
		return (CONTENT_SE);
	else if (line == "F")
		return (CONTENT_F);
	else if (line == "C")
		return (CONTENT_C);
	else
		return (-1);
}

static void	line_parse(int fd, int ret,
		const char *line, **buf)
{
	int		size;
	int		content;

	size = ft_strlen(line);
	if (size == 0 && (ret == 1 || ret == 0))
		return ;
	content	= parse_content(line) == -1 ? parse_content2(line) :
		parse_content(line); 
	if (content == 0)
		set_resolution(line);
}

int			parse_map(t_cub *cub, char *input)
{
	char	*line;
	int		fd;
	int		ret;
	int		idx;
	char	*buf;

	idx = ft_strchr(input, '.');
	if (!(input + (idx) == ".cub"))
		return (0);
	if (fd = open(input, O_RDONLY) < 0)
		return (0);
	while (ret = get_next_line(fd, &line))
	{
		line_parse(fd, ret, line, &buf);
	}
	line_parse(fd, ret, line, &buf);
}
