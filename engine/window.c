/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlee <youlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 18:16:37 by youlee            #+#    #+#             */
/*   Updated: 2020/07/02 02:41:15 by youlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"
#include <stdio.h>

int			clear_window(t_window *window)
{
	if (window->screen.img)
		mlx_destroy_image(window->ptr, window->screen.img);
	if (window->ptr && window->win)
		mlx_destroy_window(window->ptr, window->win);
	return (0);
}

int			init_image(t_window *window, t_image *img)
{
	if (!(img->img =
				mlx_new_image(window->ptr, window->size.x, window->size.y)))
		return (0);
	img->ptr = mlx_get_data_addr(
			img->img, &img->bpp, &img->size_l, &img->endian);
	return (1);
}

int			init_window(t_window *window, t_config *config)
{
	set_pos(&window->size, config->req_width, config->req_height);
	window->size.x = window->size.x > 1920 ? 1920 : window->size.x;
	window->size.y = window->size.y > 1080 ? 1080 : window->size.y;
	window->size.x = window->size.x < 848 ? 848 : window->size.x;
	window->size.y = window->size.y < 480 ? 480 : window->size.y;
	window->ptr = NULL;
	window->win = NULL;
	window->ratio = window->size.x / window->size.y;
	window->screen.img = NULL;
	if (window->ratio < BEST_RATIO)
		config->fov = config->fov / ((BEST_RATIO / config->fov) / 2.5);
	else if (window->ratio > BEST_RATIO)
		config->fov = config->fov * ((config->fov / BEST_RATIO) * 2.5);
	if (!(window->ptr = mlx_init())
			|| !(window->win = mlx_new_window(
					window->ptr, window->size.x, window->size.y, "cub3d")))
		return (0);
	set_pos(&window->half, window->size.x / 2, window->size.y / 2);
	if (!init_image(window, &window->screen))
		return (0);
	return (1);
}

void		update_window(t_game *game)
{
	t_window			*w;

	w = &game->window;
	mlx_put_image_to_window(w->ptr, w->win, w->screen.img, 0, 0);
	//if (game->options & FLAG_UI)
	//	write_ui_text(game);
}
