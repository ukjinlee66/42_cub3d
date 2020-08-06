/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlee <youlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 21:55:05 by youlee            #+#    #+#             */
/*   Updated: 2020/08/06 19:32:00 by youlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		init_cub(t_cub *cub)
{
	init_window(&cub->window);
	init_cub3(cub, 0);
	init_cub2(cub, 0);
}

static void		background_execution(t_cub *cub)
{
	init_cub(cub);
	make_table(cub);
	load_texture(cub);
	check_sprite(cub);
	startbgm(cub);
}

int				main(int argc, char **argv)
{
	t_cub			cub;

	if (argc >= 2 && argv[1])
	{
		if (!parse_param(&cub, argv[1]))
			return (print_str("Error\n wrong .cub file!\n"));
		if (!map_check(&cub))
			return (print_str("Error\n wrong map format!\n"));
	}
	else
		return (print_str("Error\n wrong input file!\n"));
	background_execution(&cub);
	if (argc == 3 && !ft_strcmp("--save", argv[2]))
	{
		screenshot(&cub);
		return (1);
	}
	mlx_hook(cub.window.win, X_EVENT_KEY_PRESS, 0, &key_press, &cub);
	mlx_hook(cub.window.win, X_EVENT_KEY_RELEASE, 0, &key_release, &cub);
	mlx_hook(cub.window.win, X_EVENT_KEY_EXIT, 0, &exit_game, &cub);
	mlx_loop_hook(cub.window.ptr, &main_loop, &cub);
	mlx_hook(cub.window.win, X_EVENT_MOUSE_MOVE, 0, &mouse_move, &cub);
	mlx_loop(cub.window.ptr);
	return (0);
}
