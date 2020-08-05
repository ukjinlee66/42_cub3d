/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_assistant.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlee <youlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 17:23:55 by youlee            #+#    #+#             */
/*   Updated: 2020/08/05 17:55:08 by youlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			assist_loop(t_cub *cub, t_camera *c)
{
	if (cub->map[(int)c->pos.x][(int)c->pos.y] == 4 ||
			cub->map[(int)c->pos.x][(int)c->pos.y] == 5)
	{
		if (cub->map[(int)c->pos.x][(int)c->pos.y] == 4)
		{
			gremush_music(cub);
			cub->life--;
		}
		else
		{
			redmush_music(cub);
			cub->life++;
		}
		cub->map[(int)c->pos.x][(int)c->pos.y] = 0;
		delete_spr(&cub->sprite, &c->pos);
		if (cub->life == 0)
			exit_game(cub);
	}
}

void			assist_loop2(t_cub *cub, t_camera *c)
{
	if (cub->map[(int)c->pos.x][(int)c->pos.y] == 6)
	{
		star_music(cub);
		cub->map[(int)c->pos.x][(int)c->pos.y] = 0;
		delete_spr(&cub->sprite, &c->pos);
		cub->mv_speed += .03;
	}
	if (cub->map[(int)c->pos.x][(int)c->pos.y] == 7)
	{
		star_music(cub);
		cub->secret = true;
		cub->map[(int)c->pos.x][(int)c->pos.y] = 0;
		delete_spr(&cub->sprite, &c->pos);
	}
	if (cub->secret)
		secret_open(cub);
}

void			assist_loop3(t_cub *cub, t_camera *c,
		int *update)
{
	if (cub->open)
		*update = open_door(cub);
	if (cub->jump_val > 0)
	{
		if (cub->jump_val == 30)
			jump_music(cub);
		*update = jumpup(cub);
	}
	if (cub->jump_val < 0)
		*update = jumpdown(cub);
	if (cub->window.size.y / 2. != cub->window.half.y)
		*update = 1;
	if (cub->mouse.x || cub->mouse.y)
		*update = 1;
	if (check_coin_map(cub) > 0)
	{
		if (cub->map[(int)c->pos.x][(int)c->pos.y] == 3)
		{
			coin_music(cub);
			cub->map[(int)c->pos.x][(int)c->pos.y] = 0;
			cub->coin[1] = ((cub->coin[1] - 32) + 1) + 32;
			delete_spr(&cub->sprite, &c->pos);
		}
	}
}
