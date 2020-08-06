/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlee <youlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 14:25:30 by youlee            #+#    #+#             */
/*   Updated: 2020/08/06 19:03:43 by youlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		else_draw(t_cub *cub)
{
	if (cub->sprite)
		handle_sprite(cub);
	if (cub->secret == true)
		draw_key_icon(cub);
	put_cross_hair(cub);
	draw_coin_icon(cub);
	draw_mario_icon(cub);
}

void			coord(t_window *win, t_pos *pos, int color)
{
	if (pos->x >= 0 && pos->x < win->size.x &&
			pos->y >= 0 && pos->y < win->size.y)
		*(int*)(win->screen.ptr + (4 * (int)win->size.x * (int)pos->y) +
				((int)pos->x * 4)) = color;
}

void			put_screen(t_cub *cub)
{
	int					i;
	t_object			obj;
	t_pos				start;

	set_position(&start, 0, 0);
	i = 0;
	while (i < cub->window.size.x)
	{
		ray_cast(cub, &obj, i);
		cub->depth[i] = obj.dist;
		obj.height = fabs(cub->window.size.y / obj.dist);
		draw_wall(cub, &obj);
		if (obj.height < cub->window.size.y)
			draw_sky_floor(cub, &obj);
		i++;
	}
	else_draw(cub);
	i = 1;
	if (cub->life > 0)
		while (i <= cub->life)
		{
			draw_heart_icon(cub, i * 40);
			i++;
		}
}

void			init_window(t_window *window)
{
	window->size.x = window->size.x < MIN_HEIGHT ? MIN_HEIGHT : window->size.x;
	window->size.y = window->size.y < MIN_WIDTH ? MIN_WIDTH : window->size.y;
	window->size.x = window->size.x > MAX_HEIGHT ? MAX_HEIGHT : window->size.x;
	window->size.y = window->size.y > MAX_WIDTH ? MAX_WIDTH : window->size.y;
	set_position(&window->half, window->size.x / 2., window->size.y / 2.);
	window->ptr = mlx_init();
	window->win = mlx_new_window(window->ptr, window->size.x,
			window->size.y, "cub3d");
	window->screen.img = NULL;
	init_img(window, &window->screen);
}

void			put_img(t_cub *cub)
{
	t_window			*win;

	win = &cub->window;
	mlx_put_image_to_window(win->ptr, win->win, win->screen.img, 0, 0);
}
