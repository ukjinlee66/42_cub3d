/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlee <youlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 18:59:48 by youlee            #+#    #+#             */
/*   Updated: 2020/08/05 19:26:16 by youlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool correct(t_cub *cub, int i, int j, int val)
{
	return (cub->map[i][j] == val ? true : false);
}

static void	DFS(t_cub *cub, int i, int j, bool *wrong)
{
	cub->visit[i][j] = true;
	if (i == cub->max_map_row ||
			j == cub->max_map_col)
		*wrong = true;
	if (cub->map[i + 1][j] != 1)
}

int			map_check(t_cub *cub)
{
	int			i;
	int			j;
	static bool	wrong = false;

	i = 0;
	while (i < cub->max_map_row)
	{
		j = 0;
		while (j < cub->max_map_col)
		{
			if (!cub->visit[i][j] && cub->map[i][j] != 1 &&
					cub->map[i][j] != -1)
				DFS(cub, i, j, &wrong);
			if (wrong)
				return (0);
			j++;
		}
		i++;
	}
}
