/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlee <youlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 15:33:52 by youlee            #+#    #+#             */
/*   Updated: 2020/07/30 16:02:31 by youlee           ###   ########.fr       */
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
	cub->cos[0] = cos(-rotate_speed);
	cub->cos[1] = cos(rotate_speed);
	cub->sin[0] = sin(-rotate_speed);
	cub->sin[1] = sin(rotate_speed);
	while (i < 7)
		cub->special[i++] = NULL;
	cub->jump_val = 0;
	cub->secret = false;
	cub->open = false;
	return ;
}

void			init_cub3(t_cub *cub, int i)
{
	cub->mv_speed = move_speed;
	while (i < 15)
		cub->texture[i++].tex = NULL;
	cub->life = 3;
	cub->bgm = NULL;
	return ;
}
