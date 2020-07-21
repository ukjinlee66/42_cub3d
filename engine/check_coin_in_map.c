/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_coin_in_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlee <youlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 15:37:45 by youlee            #+#    #+#             */
/*   Updated: 2020/07/21 15:42:39 by youlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			check_coin_map(t_cub *cub)
{
	int			i;
	int			j;
	int			ret;

	i = 0;
	while (i < cub->req_row)
	{
		j = 0;
		while (j < cub->req_col)
		{
			if (cub->map[i][j] == 3)
				ret++;
			j++;
		}
		i++;
	}
	return (ret);
}
