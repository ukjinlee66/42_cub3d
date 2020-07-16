/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_handle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlee <youlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 11:19:45 by youlee            #+#    #+#             */
/*   Updated: 2020/07/14 21:26:27 by youlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int				exit_game(void)
{
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
		    cub->window.half.y+=5;
    }
	else if (key == KEY_UNDER)
    {
        if (cub->window.half.y > cub->window.size.y / 3.)
		    cub->window.half.y-=5;
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
		exit_game();
	return (0);
}

int				main_loop(t_cub *cub)
{
	static int update = 1;

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
		put_screen(cub);
		put_img(cub);
	}
	update = 0;
	return (0);
}
