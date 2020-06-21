/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlee <youlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/21 15:04:32 by youlee            #+#    #+#             */
/*   Updated: 2020/06/21 17:13:15 by youlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdlib.h>

int			error_check(t_game *game, char const *str)
{
	if (str)
		write(1, str, ft_strlen(str));
	exit_game(game, EXIT_FAILURE);
	return (EXIT_FAILURE);
}

int			main(int argc, char *argv)
{
	t_game				game;
	int					save;

	save = (argc >= 2 && !ft_strcmp(argv[1], "--save"));
	if (argc < (2 + save))
		return (error_check(&game, "Error:\nno map.\n"));
	init_game(&game, save);
	if (!parse_config(&game.config, argv[1 + save]))
		return (error_check(&game, "Error:\ninvalid map.\n"));
	if (!finish_init(&game))
		return (1);
	mlx_hook(game.window.win, X_EVENT_KEY_PRESS, 0, &key_press, &game);
	mlx_hook(game.window.win, X_EVENT_KEY_RELEASE, 0, &key_release, &game);
	mlx_hook(game.window.win, X_EVENT_EXIT, 0, &exit_hook, &game);
	mlx_loop(game.window.ptr);
	return (0);
}
