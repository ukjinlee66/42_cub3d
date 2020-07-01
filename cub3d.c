/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlee <youlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/21 15:04:39 by youlee            #+#    #+#             */
/*   Updated: 2020/07/01 23:18:13 by youlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		exit_hook(t_game *game)
{
	return (exit_game(game, EXIT_SUCCESS));
}

int		key_press(int keycode, t_game *game)
{
	if (keycode == KEY_W || keycode == KEY_FORWARD)
		game->move.x = 1;
	else if (keycode == KEY_S || keycode == KEY_BACKWARD)
		game->move.y = 1;
	if (keycode == KEY_A)
		game->x_move.x = 1;
	else if (keycode == KEY_D)
		game->x_move.y = 1;
	if (keycode == KEY_E || keycode == KEY_RIGHT)
		game->rotate.y = 1;
	else if (keycode == KEY_Q || keycode == KEY_LEFT)
		game->rotate.x = 1;
	return (0);
}

int		key_release(int keycode, t_game *game)
{
	if (keycode == KEY_W || keycode == KEY_FORWARD)
		game->move.x = 0;
	else if (keycode == KEY_S || keycode == KEY_BACKWARD)
		game->move.y = 0;
	else if (keycode == KEY_A)
		game->x_move.x = 0;
	else if (keycode == KEY_D)
		game->x_move.y = 0;
	else if (keycode == KEY_E || keycode == KEY_RIGHT)
		game->rotate.y = 0;
	else if (keycode == KEY_Q || keycode == KEY_LEFT)
		game->rotate.x = 0;
	else if (keycode == KEY_ESC)
		return (exit_game(game, EXIT_SUCCESS));
	return (0);
}

int		main_loop(t_game *game)
{
	static int update = 1;

	if (game->move.x || game->move.y)
		update = move_camera(game, (game->move.x) ? 0 : 1);
	if (game->x_move.x || game->x_move.y)
		update = move_perp_camera(game, (game->x_move.x) ? 0 : 1);
	if (game->rotate.x || game->rotate.y)
		update = rotate_camera(game, (game->rotate.x) ? 0 : 1);
	if (update)
	{
		//MAP(game->camera.pos, game->config) = 'A';
		game->config.map[(int)(floor(game->camera.pos.y) * game->config.col) +
			(int)floor(game->camera.pos.x)] = 'A';
		update_screen(game);
		update_window(game);
	}
	//update = 0;
	return (0);
}
