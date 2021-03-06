/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_handle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlee <youlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 11:19:45 by youlee            #+#    #+#             */
/*   Updated: 2020/08/09 18:50:35 by youlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int				exit_game(t_cub *cub)
{
	int			i;

	i = 0;
	Mix_FreeMusic(cub->bgm);
	cub->bgm = NULL;
	clear_sprite(&cub->sprite);
	while (i < 5)
	{
		Mix_FreeChunk(cub->special[i]);
		cub->special[i++] = NULL;
	}
	i = 0;
	while (i < 17)
		if (cub->texture[i].path != NULL)
			free(cub->texture[i++].path);
	Mix_Quit();
	SDL_Quit();
	exit(0);
}

int				mouse_move(int x, int y, t_cub *cub)
{
	if (cub->mouse.x == 0 && cub->mouse.y == 0)
		set_position(&cub->mouse, x, y);
	else
	{
		if ((int)cub->mouse.x < x)
			rotate_camera(cub, 1);
		else if ((int)cub->mouse.x > x)
			rotate_camera(cub, 0);
		if ((int)cub->mouse.y < y)
			cub->window.half.y -= 10;
		else if ((int)cub->mouse.y > y)
			cub->window.half.y += 10;
		set_position(&cub->mouse, x, y);
	}
	return (0);
}

int				key_press(int key, t_cub *cub)
{
	if (key == KEY_W)
		cub->move.x = 1;
	else if (key == KEY_S)
		cub->move.y = 1;
	if (key == KEY_A)
		cub->x_move.x = 1;
	else if (key == KEY_D)
		cub->x_move.y = 1;
	if (key == KEY_UP)
		if (cub->window.half.y < cub->window.size.y * 2. / 3.)
			cub->window.half.y += 7;
	if (key == KEY_UNDER)
		if (cub->window.half.y > cub->window.size.y / 3.)
			cub->window.half.y -= 7;
	if (key == KEY_Q || key == KEY_LEFT)
		cub->rotate.x = 1;
	if (key == KEY_E || key == KEY_RIGHT)
		cub->rotate.y = 1;
	if (key == KEY_SPACE && !cub->jump_val)
		cub->jump_val = 30;
	if (key == KEY_F)
		cub->open = true;
	return (0);
}

int				key_release(int key, t_cub *cub)
{
	if (key == KEY_W || key == KEY_UP)
		cub->move.x = 0;
	if (key == KEY_S || key == KEY_UNDER)
		cub->move.y = 0;
	if (key == KEY_A)
		cub->x_move.x = 0;
	if (key == KEY_D)
		cub->x_move.y = 0;
	if (key == KEY_Q || key == KEY_LEFT)
		cub->rotate.x = 0;
	if (key == KEY_E || key == KEY_RIGHT)
		cub->rotate.y = 0;
	if (key == KEY_ESC)
		exit_game(cub);
	return (0);
}

int				main_loop(t_cub *cub)
{
	static int		update = 1;
	t_camera		*c;

	c = &cub->camera;
	if (cub->move.x || cub->move.y)
		update = up_down_camera(cub, (cub->move.x) ? 0 : 1);
	if (cub->x_move.x || cub->x_move.y)
		update = side_camera(cub, (cub->x_move.x) ? 0 : 1);
	if (cub->rotate.x || cub->rotate.y)
		update = rotate_camera(cub, (cub->rotate.x) ? 0 : 1);
	assist_loop3(cub, c, &update);
	assist_loop(cub, c);
	assist_loop2(cub, c);
	if (update)
	{
		put_screen(cub);
		put_img(cub);
		mlx_string_put(cub->window.ptr, cub->window.win,
				cub->window.half.x - 50,
				cub->window.size.y - 50, 0xFF0000, cub->coin);
	}
	update = 0;
	return (0);
}
