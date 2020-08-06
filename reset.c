/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlee <youlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 15:33:52 by youlee            #+#    #+#             */
/*   Updated: 2020/08/06 18:23:05 by youlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			init_cub2(t_cub *cub, int i)
{
	cub->c[TEX_NORTH] = 0xFFFFFF;
	cub->c[TEX_SOUTH] = 0xCCCCCC;
	cub->c[TEX_WEST] = 0xFF44FF;
	cub->c[TEX_EAST] = 0x44FF44;
	cub->c[TEX_SKY] = 0x33C6E3;
	cub->c[TEX_FLOOR] = 0xA0764C;
	set_position(&cub->move, 0., 0.);
	set_position(&cub->x_move, 0., 0.);
	set_position(&cub->rotate, 0., 0.);
	cub->coin = (char*)malloc(sizeof(char) * 10);
	cub->coin[0] = 'X';
	cub->coin[1] = '0';
	cub->coin[2] = '\0';
	cub->mouse.x = 0.;
	cub->mouse.y = 0.;
	cub->cos[0] = cos(-ROTATE_SPEED);
	cub->cos[1] = cos(ROTATE_SPEED);
	cub->sin[0] = sin(-ROTATE_SPEED);
	cub->sin[1] = sin(ROTATE_SPEED);
	while (i < 7)
		cub->special[i++] = NULL;
	cub->jump_val = 0;
	cub->secret = false;
	cub->open = false;
	return ;
}

void			init_cub3(t_cub *cub, int i)
{
	cub->mv_speed = MOVE_SPEED;
	while (i < 17)
		cub->texture[i++].tex = NULL;
	cub->life = 3;
	cub->bgm = NULL;
	cub->max_map_row = 0;
	cub->max_map_col = 0;
	cub->texture[13].path = "textures/exclamation_block.xpm";
	cub->texture[14].path = "textures/sprite1.xpm";
	cub->texture[15].path = "textures/castle.xpm";
	cub->texture[16].path = "textures/barrel.xpm";
	return ;
}
