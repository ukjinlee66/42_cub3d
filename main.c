/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlee <youlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 21:55:05 by youlee            #+#    #+#             */
/*   Updated: 2020/07/08 21:19:55 by youlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

static void		init_cub(t_cub *cub)
{
	int			i;
	int			j;
	
	i = 0;
	init_window(&cub->window);
	init_camera(&cub->camera);
	while (i < 10)
		cub->texture[i++].tex = NULL;
	cub->texture[0].path = "textures/wall1.xpm";
	cub->texture[1].path = "textures/wall2.xpm";
	cub->texture[2].path = "textures/wall3.xpm";
	cub->texture[3].path = "textures/wall4.xpm";
	cub->texture[4].path = "textures/floor1.xpm";
	cub->texture[5].path = "textures/sky1.xpm";
	cub->texture[6].path = "textures/sprite1.xpm";
	cub->texture[7].path = "textures/wood.xpm";
	i = 0;
	int map2[10][10] = {
	{ 1,1,1,1,1,1,1,1,1,1 },
	{ 1,0,0,0,0,0,0,0,0,1 },
	{ 1,0,0,0,0,0,0,0,0,1 },
	{ 1,0,0,0,0,0,0,0,0,1 },
	{ 1,0,0,0,0,0,0,0,0,1 },
	{ 1,0,0,0,0,0,0,0,0,1 },
	{ 1,0,0,0,0,0,0,2,0,1 },
	{ 1,0,0,0,0,0,2,0,0,1 },
	{ 1,0,0,0,0,0,0,0,0,1 },
	{ 1,1,1,1,1,1,1,1,1,1 }
	};
	copy_map(cub, 10, 10, map2);
	cub->c[TEX_NORTH] = 0xFFFFFF;
	cub->c[TEX_SOUTH] = 0xCCCCCC;
	cub->c[TEX_WEST] = 0xFF44FF;
	cub->c[TEX_EAST] = 0x44FF44;
	cub->c[TEX_SKY] = 0x33C6E3;
	cub->c[TEX_FLOOR] = 0xA0764C;
	cub->object.row = 10;
	cub->object.col = 10;
	set_position(&cub->move, 0., 0.);
	set_position(&cub->x_move, 0., 0.);
	set_position(&cub->rotate, 0., 0.);
	cub->option = 0;
	cub->cos[0] = cos(-rotate_speed);
	cub->cos[1] = cos(rotate_speed);
	cub->sin[0] = sin(-rotate_speed);
	cub->sin[1] = sin(rotate_speed);
}

int				main(int argc, char **argv)
{
	t_cub			cub;

	init_cub(&cub);
	make_table(&cub);
	load_texture(&cub);
	mlx_hook(cub.window.win, X_EVENT_KEY_PRESS, 0, &key_press, &cub);
	mlx_hook(cub.window.win, X_EVENT_KEY_RELEASE, 0, &key_release, &cub);
	mlx_hook(cub.window.win, X_EVENT_KEY_EXIT, 0, &exit_game, &cub);
	mlx_loop_hook(cub.window.ptr, &main_loop, &cub);
	mlx_loop(cub.window.ptr);
	return (0);
}
