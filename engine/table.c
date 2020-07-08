/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlee <youlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 14:44:48 by youlee            #+#    #+#             */
/*   Updated: 2020/07/08 15:26:02 by youlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void			cal_up_down(double height, double *img)
{
	int			i;

	i = 0;
	while (i < height)
	{
		img[i] = height / ((2. * (double)i) - height);
		i++;
	}
}

static void			cal_left_right(double width, double *img)
{
	int			i;

	i = 0;
	while (i < width)
	{
		img[i] = ((2. * (double)i) / width) - 1.;
		i++;
	}
}

int					make_table(t_cub *cub)
{
	cal_left_right(cub->window.size.x, cub->cam_width);
	cal_up_down(cub->window.size.y, cub->cam_height);
	return (0);
}
