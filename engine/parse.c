/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlee <youlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 18:20:37 by youlee            #+#    #+#             */
/*   Updated: 2020/08/04 17:14:19 by youlee           ###   ########.fr       */
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

static int	line_parse(t_cub *cub, int ret,
		char *line, char **buf)
{
	static bool map_parse = false;
	int			size;
	int			content;

	size = ft_strlen(line);
	if (size == 0 && (ret == 1 || ret == 0))
		return (1);
	content	= parse_content(line) == -1 ?
		parse_content2(line) : parse_content(line);
	if (content == 0 && !(set_resolution(cub, line)))
		return (0);
	if (content >= 1 && content <= 12 && !(set_content(cub, line ,content)))
		return (0);
	if (content == 16 && !(set_dsprite(cub, line, content)))
		return (0);
	if (content == 14 || content == 15) //floor ceiling
	{
		map_parse = content == 15 ? true : false;
		set_ce_fl(cub, line, content);
	}
	if (map_parse && content == -1 )
		(set_map(cub, line));
	return (1);
}

static void	set_row_col(t_cub *cub)
{
	cub->max_map_row++;
	cub->req_row = cub->max_map_row;
	cub->req_col = cub->max_map_col;
	cub->object.row = cub->req_row;
	cub->object.col = cub->req_col;
}

int			parse_param(t_cub *cub, char *input)
{
	char		*line;
	int			fd;
	int			ret;
	int			idx;
	char		*buf;

	idx = ft_strchr(input, '.');
	if (input[idx + 1] != 'c' || input[idx + 2] != 'u' ||
			input[idx + 3] != 'b')
		return (0);
	if ((fd = open(input, O_RDONLY)) < 0)
		return (0);
	while ((ret = get_next_line(fd, &line)))
	{
		if (!line_parse(cub, ret, line, &buf))
			return (0);
		free(line);
	}
	if (!line_parse(cub, ret, line, &buf))
		return (0);
	free(line);
	set_row_col(cub);
	return (1);
}
