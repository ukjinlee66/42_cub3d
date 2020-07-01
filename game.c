/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlee <youlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/21 15:07:10 by youlee            #+#    #+#             */
/*   Updated: 2020/07/02 04:40:57 by youlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>
int			exit_game(t_game *game, int code)
{
	clear_config(&game->config);
	clear_window(&game->window);
	clear_tex(game);
	//clear_sprites(&game->sprites);
	exit(code);
	return (code);
}

void		init_game(t_game *game, int point)
{
	int				i;

	point = 0;
	init_config(&game->config);
	set_pos(&game->move, 0, 0);
	set_pos(&game->x_move, 0, 0);
	set_pos(&game->rotate, 0, 0);
	game->options = 0x11111110;
	game->kill = 0;
	game->to_kill = 0;
	game->sprites = NULL;
	i = 0;
	while (i < TEXTURES)
		game->tex[i++].tex = NULL;
}

int			finish_init(t_game *game)
{
	if (!init_window(&game->window, &game->config))
	{
		return (error_check(game,
					"Error:\nmlx failed to create window or img.\n"));
	}
	find_start_pos(&game->config, &game->camera);
	find_start_angle(&game->config, &game->camera);
	load_textures(game);
	make_tables(game);
	return (1);
}
