/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlee <youlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 21:55:05 by youlee            #+#    #+#             */
/*   Updated: 2020/08/04 16:54:55 by youlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
/*
void			copy_map(t_cub *cub, int x, int y, int map[10][10])
{
	int			i;
	int			j;

	i = 0;
	while (i < x)
	{
		j = 0;
		while (j < y)
		{
			cub->map[i][j] = map[i][j];
			j++;
		}
		i++;
	}
}
*/
static void		init_cub(t_cub *cub)
{
	init_window(&cub->window);
	//init_camera(&cub->camera);
	init_cub3(cub, 0);
	/*cub->texture[0].path = "textures/bush.xpm";
	cub->texture[1].path = "textures/bush.xpm";
	cub->texture[2].path = "textures/bush.xpm";
	cub->texture[3].path = "textures/bush.xpm";
	cub->texture[4].path = "textures/floor1.xpm";
	cub->texture[5].path = "textures/clouds.xpm";
	cub->texture[6].path = "textures/pipe.xpm";
	cub->texture[7].path = "textures/Coin.xpm";
    cub->texture[8].path = "textures/mush1.xpm";
    cub->texture[9].path = "textures/mush2.xpm";
	cub->texture[10].path = "textures/star2.xpm";
    cub->texture[11].path = "textures/key.xpm";
	cub->texture[12].path = "textures/question.xpm";
	//1 wall 2 pipe 3 coin 4 green mushroom 5 red mushroom 6 star 7 key 8 door
	int map2[10][10] = {
	{ 1,1,1,1,1,1,1,1,1,1 },
	{ 1,3,5,1,0,0,7,1,0,1 },
	{ 1,4,0,8,0,0,0,1,10,1 },
	{ 1,1,1,1,0,0,0,0,0,1 },
	{ 1,0,0,0,0,0,0,0,0,1 },
	{ 1,0,0,0,0,0,0,0,0,1 },
	{ 1,0,0,0,0,0,0,2,0,1 },
	{ 1,6,3,4,5,0,2,0,0,1 },
	{ 1,0,0,0,0,0,0,0,0,1 },
	{ 1,1,1,1,1,1,1,1,1,1 }
	};*/
	//copy_map(cub, 10, 10, map2);
	init_cub2(cub, 0);
	//cub->object.row = cub->req_row = 10;
	//cub->object.col = cub->req_col = 10;
}

int				main(int argc, char **argv)
{
	t_cub			cub;

	if (argc == 3 && !ft_strcmp("--save", argv[2]))
	{
		screenshot(&cub);
		return (1);
	}
	else if (argc == 2 && argv[1])
	{
		if (!parse_param(&cub, argv[1]))
			return(print_str("Error\n wrong .cub file!\n"));
	}
	else
		return (print_str("Error\n wrong input file!\n"));
	init_cub(&cub);
	make_table(&cub);
	load_texture(&cub);
    check_sprite(&cub);
	startbgm(&cub);
	mlx_hook(cub.window.win, X_EVENT_KEY_PRESS, 0, &key_press, &cub);
	mlx_hook(cub.window.win, X_EVENT_KEY_RELEASE, 0, &key_release, &cub);
	mlx_hook(cub.window.win, X_EVENT_KEY_EXIT, 0, &exit_game, &cub);
    mlx_loop_hook(cub.window.ptr, &main_loop, &cub);
	mlx_hook(cub.window.win, X_EVENT_MOUSE_MOVE, 0, &mouse_move, &cub);
    mlx_mouse_hide();
	mlx_loop(cub.window.ptr);
	return (0);
}
