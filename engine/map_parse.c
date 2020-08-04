/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlee <youlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 13:03:49 by youlee            #+#    #+#             */
/*   Updated: 2020/08/04 16:14:35 by youlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	set_player_position(t_cub *cub, char *line, int row, int col)
{
	set_position(&cub->camera.pos, row + .5, col + .5);
	cub->map[row][col] = 0;
	if (line[col] == 'N')
	{
		set_position(&cub->camera.dir, 0., -1.);
		set_position(&cub->camera.plane, FOV, 0.);
	}
	else if (line[col] == 'E')
	{
		set_position(&cub->camera.dir, 1., 0.);
		set_position(&cub->camera.plane, 0., FOV);	
	}
	else if (line[col] == 'S')
	{
		set_position(&cub->camera.dir, 0., 1.);
		set_position(&cub->camera.plane, -FOV, 0.);	
	}	
	else if (line[col] == 'W')
	{
		set_position(&cub->camera.dir, -1., 0.);
		set_position(&cub->camera.plane, 0., -FOV);	
	}
	set_position(&cub->camera.x_dir,
			cub->camera.dir.y, -cub->camera.dir.x);
}

int			set_map(t_cub *cub, char *line)
{
	static int	row = 0;
	int			i;

	i = 0;
	while (line[i] || (row != 0 && i < cub->max_map_col))
	{
		if (line[i] == ' ' || (line[i] >= '0' && line[i] <= '9') ||
				line[i] == 'a' || line[i] == 'N' || line[i] == 'S' ||
				line[i] == 'E' || line[i] == 'W')
		{
			if (line[i] == 'a')
				cub->map[row][i] = 10;
			else if (line[i] >= 'E' && line[i] <= 'W')
				set_player_position(cub, line, row, i);
			else
				cub->map[row][i] = (line[i] == ' ') ? -1 : line[i] - '0';
		}
		else if (i < cub->max_map_col)
			cub->map[row][i] = -1;
		else
			return (0);
		i++;
	}
	cub->max_map_col = i;
	cub->max_map_row = row++;
	return (1);
}
