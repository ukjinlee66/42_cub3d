/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlee <youlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 18:59:48 by youlee            #+#    #+#             */
/*   Updated: 2020/08/06 18:20:27 by youlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	correct(t_cub *cub, int i, int j, int val)
{
	return (cub->map[i][j] == val ? true : false);
}

static void	dfs(t_cub *cub, int i, int j, bool *wrong)
{
	if (i < 0 || j < 0 || i >= cub->max_map_row || j >= cub->max_map_col)
		return ;
	cub->visit[i][j] = true;
	if (i == 0 || j == 0 || i == cub->max_map_row - 1 ||
			j == cub->max_map_col - 1)
		*wrong = true;
	else if (cub->map[i][j] == -1)
		*wrong = true;
	if (*wrong)
		return ;
	if (correct(cub, i + 1, j, 1) == false &&
			!cub->visit[i + 1][j])
		dfs(cub, i + 1, j, wrong);
	if (correct(cub, i - 1, j, 1) == false &&
			!cub->visit[i - 1][j])
		dfs(cub, i - 1, j, wrong);
	if (correct(cub, i, j + 1, 1) == false &&
			!cub->visit[i][j + 1])
		dfs(cub, i, j + 1, wrong);
	if (correct(cub, i, j - 1, 1) == false &&
			!cub->visit[i][j - 1])
		dfs(cub, i, j - 1, wrong);
	return ;
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
			if (!cub->visit[i][j] && cub->map[i][j] == 0)
				dfs(cub, i, j, &wrong);
			if (wrong)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
