/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_handle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlee <youlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 11:19:45 by youlee            #+#    #+#             */
/*   Updated: 2020/07/21 21:18:18 by youlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int				exit_game(t_cub *cub)
{
	Mix_FreeMusic(cub->bgm);
	cub->bgm = NULL;
	Mix_Quit();
	exit(0);
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
    {
        if (cub->window.half.y < cub->window.size.y * 2. / 3.)
		    cub->window.half.y+=7;
    }
	else if (key == KEY_UNDER)
    {
        if (cub->window.half.y > cub->window.size.y / 3.)
		    cub->window.half.y-=7;
    }
	if (key == KEY_Q || key == KEY_LEFT)
		cub->rotate.x = 1;
	else if (key == KEY_E || key == KEY_RIGHT)
		cub->rotate.y = 1;
	return (0);
}

int				key_release(int key, t_cub *cub)
{
	if (key == KEY_W || key == KEY_UP)
		cub->move.x = 0;
	else if (key == KEY_S || key == KEY_UNDER)
		cub->move.y = 0;
	if (key == KEY_A)
		cub->x_move.x = 0;
	else if (key == KEY_D)
		cub->x_move.y = 0;
	if (key == KEY_Q || key == KEY_LEFT)
		cub->rotate.x = 0;
	else if (key == KEY_E || key == KEY_RIGHT)
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
    if (cub->window.size.y / 2. != cub->window.half.y)
        update = 1;
	if (update)
	{
		if (check_coin_map(cub) > 0)
		{
			if (cub->map[(int)c->pos.x][(int)c->pos.y] == 3)
			{
				cub->map[(int)c->pos.x][(int)c->pos.y] = 0;
				cub->coin++;
				delete_spr(&cub->sprite, &c->pos);
			}
		}
		else if (cub->map[(int)c->pos.x][(int)c->pos.y] == 4)
		{
			cub->map[(int)c->pos.x][(int)c->pos.y] = 0;
			cub->life--;
			delete_spr(&cub->sprite, &c->pos);
			if (cub->life == 0)
				exit_game(cub);
		}
		put_screen(cub);
		put_img(cub);
        mlx_string_put(cub->window.ptr, cub->window.win, 30, 30, 0xFF0000, cub->coin);
	}
	update = 0;
	return (0);
}
