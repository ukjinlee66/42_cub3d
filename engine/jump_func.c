/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jump_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlee <youlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 15:57:48 by youlee            #+#    #+#             */
/*   Updated: 2020/07/28 15:47:59 by youlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int				jumpup(t_cub *cub)
{
	if (cub->jump_val - 3 < 30)
	{
		cub->jump_val -= 3;
		cub->window.half.y += cub->jump_val;
		if (cub->jump_val == 0)
			cub->jump_val = -30;
	}
	return (1);
}

int				jumpdown(t_cub *cub)
{
	if (cub->jump_val + 3 > -30)
	{
		cub->jump_val += 3;
		cub->window.half.y -= abs(cub->jump_val);
		if (cub->jump_val == 0)
			cub->jump_val = 0;
	}
	return (1);
}
