/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlee <youlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/21 15:07:10 by youlee            #+#    #+#             */
/*   Updated: 2020/06/25 17:14:31 by youlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			exit_game(t_game *game, int code)
{
	clear_config(&game->config);
	clear_window(&game->window);
	clear_textures(game);
	clear_sprites(&game->sprites);
	exit(code);
	return (code);
}

int			init_game(t_game *game, int save)
{
	if (init_window(&game->window, &game->config))
	{
		return (exit_error(game,
					"Error:\nmlx failed to create window or img.\n"));
	}
	find_start_pos(&game->config, &game->camera);
	find_start_angle(&game->config, &game->camera);
	make_tables(game);
	return (1);
}

