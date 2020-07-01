/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlee <youlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/21 15:04:32 by youlee            #+#    #+#             */
/*   Updated: 2020/07/02 05:05:58 by youlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int			error_check(t_game *game, char const *str)
{
	if (str)
		write(1, str, ft_strlen(str));
	exit_game(game, EXIT_FAILURE);
	return (EXIT_FAILURE);
}

int			main(int argc, char **argv)
{
	t_game				game;
	int					save;

	//save = (argc >= 2 && !ft_strcmp(argv[1], "--save"));
	//if (argc < (2 + save))
	//	return (error_check(&game, "Error:\nno map.\n"));
	init_game(&game, save);
	game.config.map = (int*)malloc(sizeof(int) * 400);
	game.config.row = 20;
	game.config.col = 20;
	for(int i=0;i<20;i++)
	{	for(int j=0;j<20;j++)
		{
			if (i == 0 || j == 0 || i == 19 || j == 19)
				game.config.map[(i*20)  + j] = '1';
			else if (i == 1 && j == 1)
				game.config.map[(i*20)+j] = 'S';
			else
				game.config.map[(i*20) + j] = '0';
		}
	}
	//printf("game->pos %d %d\n game->cameradir %d %d\n",game.camera.pos.x,
		//	game.camera.pos.y,game.camera.x_dir.x,game.camera.x_dir.y);
	game.config.tex_path[0] = "./textures/wall1.xpm";
	game.config.tex_path[1] = "./textures/wall2.xpm";
	game.config.tex_path[2] = "./textures/wall3.xpm";
	game.config.tex_path[3] = "./textures/wall4.xpm";
	game.config.tex_path[4] = "./textures/sky1.xpm";
	game.config.tex_path[5] = "./textures/floor1.xpm";
	finish_init(&game);
	//game.config.tex_path[0] = "textures/wall1.xpm";
	//load_textures(&game);
	//if (!parse_config(&game.config, argv[1 + save]))
	//	return (error_check(&game, "Error:\ninvalid map.\n"));
	//if (!finish_init(&game))
	//	return (1);
	mlx_hook(game.window.win, X_EVENT_KEY_PRESS, 0, &key_press, &game);
	mlx_hook(game.window.win, X_EVENT_KEY_RELEASE, 0, &key_release, &game);
	mlx_hook(game.window.win, X_EVENT_EXIT, 0, &exit_hook, &game);
	mlx_loop_hook(game.window.ptr, &main_loop, &game);
	mlx_loop(game.window.ptr);
	return (0);
}
