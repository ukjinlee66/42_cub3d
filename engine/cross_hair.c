/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cross_hair.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlee <youlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 16:20:23 by youlee            #+#    #+#             */
/*   Updated: 2020/07/27 16:30:20 by youlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			put_cross_hair(t_cub *cub)
{
	int			i;
	t_pos		pixel;

	i = -11;
	set_position(&pixel, cub->window.size.x / 2., cub->window.size.y / 2.);
	coord(&cub->window, &pixel, 0xFF0000);
	while (i++ < 11)
		if (i < -1 || i > 1)
		{
			set_position(&pixel, cub->window.size.x / 2. + 2,
					cub->window.size.y / 2. + i);
			coord(&cub->window, &pixel, 0xFF0000);
			pixel.x = cub->window.size.x / 2. - 2;
			coord(&cub->window, &pixel, 0xFF0000);
		}
	i = -11;
	while (i++ < 11)
		if (i < -1 || i > 1)
		{
			set_position(&pixel, cub->window.size.x / 2. + i,
					cub->window.size.y / 2. + 2);
			coord(&cub->window, &pixel, 0xFF0000);
			pixel.y = cub->window.size.x / 2. - 2;
			coord(&cub->window, &pixel, 0xFF0000);
		}
}
