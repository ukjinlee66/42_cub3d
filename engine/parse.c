/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlee <youlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 18:20:37 by youlee            #+#    #+#             */
/*   Updated: 2020/08/03 17:52:45 by youlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	parse_content(char *line)
{
	if (line[0] == 'R')
		return (CONTENT_R);
	else if (line[0] == 'N' && line[1] == 'O')
		return (CONTENT_NO);
	else if (line[0] == 'S' && line[1] == 'O')
		return (CONTENT_SO);
	else if (line[0] == 'W' && line[1] == 'E')
		return (CONTENT_WE);
	else if (line[0] == 'E' && line[1] == 'A')
		return (CONTENT_EA);
	else if (line[0] == 'S' && line[1] == 'P')
		return (CONTENT_SP);
	else if (line[0] == 'S' && line[1] == 'C')
		return (CONTENT_SC);
	else if (line[0] == 'S' && line[1] == 'm')
		return (CONTENT_Sm);
	else if (line[0] == 'S' && line[1] == 'M')
		return (CONTENT_SM);
	else if (line[0] == 'S' && line[1] == 'S')
		return (CONTENT_SS);
	else
		return (-1);
}

static int parse_content2(char *line)
{
	if (line[0] == 'S' && line[1] == 'K')
		return (CONTENT_SK);
	else if (line[0] == 'S' && line[1] == 'Q')
		return (CONTENT_SQ);
	else if (line[0] == 'S' && line[1] == 'E')
		return (CONTENT_SE);
	else if (line[0] == 'F')
		return (CONTENT_F);
	else if (line[0] == 'C')
		return (CONTENT_C);
	else if (line[0] == 'S')
		return (CONTENT_S);
	else
		return (-1);
}

static void	line_parse(t_cub *cub, int ret,
		char *line, char **buf)
{
	int		size;
	int		content;

	size = ft_strlen(line);
	if (size == 0 && (ret == 1 || ret == 0))
		return ;
	content	= parse_content(line) == -1 ?
		parse_content2(line) : parse_content(line);
	printf("content : %d\n",content);
	if (content == 0)
		set_resolution(cub, line);
	else if (content >= 1 && content <= 4) // bearing
		set_bearing(cub, line);
	else if (content >= 5 && content <= 12) // sprite
		set_content(cub, line);
	else if (content == 16) //default sprite
		set_dsprite(cub, line);
	else if (content == 14 || content == 15) //floor ceiling
		set_ce_fl(cub, line);
	else
		set_map(cub, line);
}

int			parse_map(t_cub *cub, char *input)
{
	char	*line;
	int		fd;
	int		ret;
	int		idx;
	char	*buf;

	idx = ft_strchr(input, '.');
	if (input[idx + 1] != 'c' || input[idx + 2] != 'u' ||
			input[idx + 3] != 'b')
		return (0);
	if ((fd = open(input, O_RDONLY)) < 0)
		return (0);
	while ((ret = get_next_line(fd, &line)))
	{
		printf("ret : %d line : %s\n",ret,line);
		line_parse(cub, ret, line, &buf);
		free(line);
	}
	printf("ret : %d line : %s\n",ret,line);
	line_parse(cub, ret, line, &buf);
	free(line);
	return (0);
}
