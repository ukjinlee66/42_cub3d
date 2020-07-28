/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   icon.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlee <youlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 20:19:10 by youlee            #+#    #+#             */
/*   Updated: 2020/07/28 15:46:36 by youlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			draw_heart_icon(t_cub *cub, int dist)
{
	t_texture	tex;
	t_pos		pos[2];

	pos[0].y = cub->window.size.y - 50;
	tex.ptr = mlx_xpm_file_to_image(cub->window.ptr, "textures/heart.xpm",
			&tex.width, &tex.height);
	tex.data = (int *)mlx_get_data_addr(tex.ptr, &tex.bpp,
			&tex.size_l, &tex.endian);
	pos[1].x = 0;
	while (pos[1].x < tex.height)
	{
		pos[0].x = cub->window.half.x + dist;
		pos[1].y = 0;
		while (pos[1].y < tex.width)
		{
			if ((int)tex.data[(int)(pos[1].x * tex.width + pos[1].y)] != 0x0)
				coord(&cub->window, &pos[0], tex.data[(int)(pos[1].x *
							tex.width + pos[1].y)]);
			pos[1].y++;
			pos[0].x++;
		}
		pos[1].x++;
		pos[0].y++;
	}
}

void			draw_coin_icon(t_cub *cub)
{
	t_texture	tex;
	t_pos		pos[2];

	pos[0].y = cub->window.size.y - 70;
	tex.ptr = mlx_xpm_file_to_image(cub->window.ptr, "textures/Coin.xpm",
			&tex.width, &tex.height);
	tex.data = (int *)mlx_get_data_addr(tex.ptr, &tex.bpp,
			&tex.size_l, &tex.endian);
	pos[1].x = 0;
	while (pos[1].x < tex.height)
	{
		pos[0].x = cub->window.half.x - 100;
		pos[1].y = 0;
		while (pos[1].y < tex.width)
		{
			if ((int)tex.data[(int)(pos[1].x * tex.width + pos[1].y)] != 0x0)
				coord(&cub->window, &pos[0], tex.data[(int)(pos[1].x *
							tex.width + pos[1].y)]);
			pos[1].y++;
			pos[0].x++;
		}
		pos[1].x++;
		pos[0].y++;
	}
}

void			draw_key_icon(t_cub *cub)
{
	t_texture	tex;
	t_pos		pos[2];

	pos[0].y = 20;
	tex.ptr = mlx_xpm_file_to_image(cub->window.ptr, "textures/key.xpm",
			&tex.width, &tex.height);
	tex.data = (int *)mlx_get_data_addr(tex.ptr, &tex.bpp,
			&tex.size_l, &tex.endian);
	pos[1].x = 0;
	while (pos[1].x < tex.height)
	{
		pos[0].x = cub->window.size.x - 100;
		pos[1].y = 0;
		while (pos[1].y < tex.width)
		{
			if ((int)tex.data[(int)(pos[1].x * tex.width + pos[1].y)] != 0x0)
				coord(&cub->window, &pos[0], tex.data[(int)(pos[1].x *
							tex.width + pos[1].y)]);
			pos[1].y++;
			pos[0].x++;
		}
		pos[1].x++;
		pos[0].y++;
	}
}

void			draw_mario_icon(t_cub *cub)
{
	t_texture	tex;
	t_pos		pos[2];

	pos[0].y = cub->window.size.y - 70;
	tex.ptr = mlx_xpm_file_to_image(cub->window.ptr, "textures/mario.xpm",
			&tex.width, &tex.height);
	tex.data = (int *)mlx_get_data_addr(tex.ptr, &tex.bpp,
			&tex.size_l, &tex.endian);
	pos[1].x = 0;
	while (pos[1].x < tex.height)
	{
		pos[0].x = cub->window.half.x - 80;
		pos[1].y = 0;
		while (pos[1].y < tex.width)
		{
			if ((int)tex.data[(int)(pos[1].x * tex.width + pos[1].y)] != 0x0)
				coord(&cub->window, &pos[0], tex.data[(int)(pos[1].x *
							tex.width + pos[1].y)]);
			pos[1].y++;
			pos[0].x++;
		}
		pos[1].x++;
		pos[0].y++;
	}
}
