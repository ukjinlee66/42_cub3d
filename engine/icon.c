/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   icon.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlee <youlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 20:19:10 by youlee            #+#    #+#             */
/*   Updated: 2020/07/27 20:19:18 by youlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void            draw_heart_icon(t_cub *cub, int dist)
{
    t_window    *win;
    t_texture   tex;
    t_pos       pos;
    int         i;
    int         j;

    win = &cub->window;
    pos.x = win->half.x + dist;
    pos.y = win->size.y - 50;
    tex.ptr = mlx_xpm_file_to_image(win->ptr, "textures/heart.xpm", &tex.width, &tex.height);
    tex.data = (int *)mlx_get_data_addr(tex.ptr, &tex.bpp,
            &tex.size_l, &tex.endian);
    i = 0;
    while (i < tex.height)
    {
        pos.x = win->half.x + dist;
        j = 0;
        while (j < tex.width)
        {
            if ((int)tex.data[i * tex.width + j] != 0x0)
            *(int*)(win->screen.ptr + (4 * (int)win->size.x * (int)pos.y) + ((int)pos.x * 4)) = (int)tex.data[i * tex.width + j];
            j++;
            pos.x++;
        }
        i++;
        pos.y++;
    }
}

void			draw_coin_icon(t_cub *cub)
{
	t_window	*win;
	t_texture	tex;
	t_pos		pos;
	int			i;
	int			j;

	win = &cub->window;
	pos.y = win->size.y - 70;
	tex.ptr = mlx_xpm_file_to_image(win->ptr, "textures/Coin.xpm", &tex.width,
			&tex.height);
	tex.data = (int *)mlx_get_data_addr(tex.ptr, &tex.bpp,
			&tex.size_l, &tex.endian);
	i = 0;
	while (i < tex.height)
	{
		pos.x = win->half.x - 100;
		j = 0;
		while (j < tex.width)
		{
			if ((int)tex.data[i * tex.width + j] != 0x0)
				*(int*)(win->screen.ptr + (4 * (int)win->size.x * (int)pos.y) +
						((int)pos.x * 4)) = (int)tex.data[i * tex.width + j];
			j++;
			pos.x++;
		}
		i++;
		pos.y++;
	}
}

void			draw_key_icon(t_cub *cub)
{
	t_window	*win;
	t_texture	tex;
	t_pos		pos;
	int			i;
	int			j;

	win = &cub->window;
	pos.y = 20;
	tex.ptr = mlx_xpm_file_to_image(win->ptr, "textures/key.xpm", &tex.width,
			&tex.height);
	tex.data = (int *)mlx_get_data_addr(tex.ptr, &tex.bpp,
			&tex.size_l, &tex.endian);
	i = 0;
	while (i < tex.height)
	{
		pos.x = win->size.x - 100;
		j = 0;
		while (j < tex.width)
		{
			if ((int)tex.data[i * tex.width + j] != 0x0)
				*(int*)(win->screen.ptr + (4 * (int)win->size.x * (int)pos.y) +
						((int)pos.x * 4)) = (int)tex.data[i * tex.width + j];
			j++;
			pos.x++;
		}
		i++;
		pos.y++;
	}
}
