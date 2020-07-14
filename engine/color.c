/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlee <youlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 17:37:05 by youlee            #+#    #+#             */
/*   Updated: 2020/07/08 21:22:16 by youlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int				cal_color(int color, int divide)
{
	if (divide <= 1.)
		return (color);
	return (((int)(((0xFF0000 & color) >> 16)/divide ) << 16)
		+ ((int)(((0x00FF00 & color) >> 8) )/divide << 8)
		+ ((int)((0x0000FF & color)/divide )));
}

int				cal_color2(t_texture *tex, t_pos *pos)
{
	if (pos->x >= 0 && (int)pos->x < tex->width
            && pos->y >= 0 && (int)pos->y < tex->height)
    {
		return (*(int*)(tex->ptr +
				(4 * tex->width * (int)pos->y) +
				(4 * (int)pos->x)));
    }
	return (0x0);
}
