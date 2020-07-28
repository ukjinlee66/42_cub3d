/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlee <youlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 12:07:36 by youlee            #+#    #+#             */
/*   Updated: 2020/07/28 16:31:27 by youlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool		map_val(t_cub *cub, int x, int y, int val)
{
	if (cub->map[x][y + 1] == val)
		return (true);
	else if (cub->map[x][y - 1] == val)
		return (true);
	else if (cub->map[x + 1][y] == val)
		return (true);
	else if (cub->map[x - 1][y] == val)
		return (true);
	else
		return (false);
}

static void		change_val(t_cub *cub, int x, int y, int val)
{
	int			ret;

	ret = (val == 8) ? 9 : 8;
	if (cub->map[x][y + 1] == val)
		cub->map[x][y + 1] = ret;
	else if (cub->map[x][y - 1] == val)
		cub->map[x][y - 1] = ret;
	else if (cub->map[x + 1][y] == val)
		cub->map[x + 1][y] = ret;
	else if (cub->map[x - 1][y] == val)
		cub->map[x - 1][y] = ret;
}

int				open_door(t_cub *cub)
{
	t_camera	*c;
	int			dx;
	int			dy;

	c = &cub->camera;
	if (map_val(cub, (int)c->pos.x, (int)c->pos.y, 8))
	{
		door_music(cub);
		change_val(cub, (int)c->pos.x, (int)c->pos.y, 8);
		cub->open = false;
		return (1);
	}
	else if (map_val(cub, (int)c->pos.x, (int)c->pos.y, 9))
	{
		door_music(cub);
		change_val(cub, (int)c->pos.x, (int)c->pos.y, 9);
		cub->open = false;
		return (1);
	}
	cub->open = false;
	return (0);
}

void			secret_open(t_cub *cub)
{
	t_camera	*c;
	int			i;
	int			j;

	i = 0;
	while (i < cub->req_row)
	{
		j = 0;
		while (j < cub->req_col)
		{
			if (cub->map[i][j] == 10)
				cub->map[i][j] = 11;
			j++;
		}
		i++;
	}
	c = &cub->camera;
	if (cub->map[(int)c->pos.x][(int)c->pos.y] == 11)
		exit_game(cub);
}
