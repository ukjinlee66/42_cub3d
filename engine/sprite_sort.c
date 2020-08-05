/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlee <youlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 14:30:04 by youlee            #+#    #+#             */
/*   Updated: 2020/08/05 18:26:52 by youlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			draw_sprite(t_cub *cub, t_sprite *spr,
		t_sprite2 *spr2, t_texture *tex)
{
	while (spr2->draw_x.x < cub->window.size.x &&
			spr2->draw_x.x < spr2->draw_x.y)
	{
		if (spr2->transform.y > 0.
				&& spr2->transform.y < cub->depth[(int)spr2->draw_x.x])
		{
			spr2->draw_y.x = spr2->y_org;
			while (spr2->draw_y.x < (cub->window.size.y)
					&& spr2->draw_y.x < spr2->draw_y.y)
			{
				draw_sprite2(cub, spr, spr2, tex);
				spr2->draw_y.x++;
			}
		}
		spr2->draw_x.x++;
	}
}

void			init_sprite(t_cub *cub, t_sprite *spr,
		double invdet, t_sprite2 *spr2)
{
	t_camera	*c;

	c = &cub->camera;
	set_position(&spr2->pos, (spr->spr_pos.x - c->pos.x),
			(spr->spr_pos.y - c->pos.y));
	set_position(&spr2->transform,
			invdet * (c->dir.y * spr2->pos.x
				- c->dir.x * spr2->pos.y),
			invdet * (-c->plane.y * spr2->pos.x
				+ c->plane.x * spr2->pos.y));
	spr2->screen = (int)((cub->window.size.x / 2.) *
			(1. + spr2->transform.x / spr2->transform.y));
	spr2->spr_s.x = fabs(cub->window.size.y / spr2->transform.y);
	spr2->spr_s.y = fabs(cub->window.size.y / spr2->transform.y);
	set_position(&spr2->draw_x,
			(int)maxn(0, -spr2->spr_s.x / 2.
				+ spr2->screen),
			(int)maxn(0, spr2->spr_s.x / 2.
				+ spr2->screen));
	set_position(&spr2->draw_y,
			(int)maxn(0, -spr2->spr_s.y / 2. + (cub->window.half.y * 2.) / 2.),
			(int)maxn(0, spr2->spr_s.y / 2. + (cub->window.half.y * 2.) / 2.));
	spr2->y_org = spr2->draw_y.x;
}

void			delete_spr(t_sprite **spr, t_pos *pos)
{
	t_sprite	*curr;
	t_sprite	*prev;
	t_sprite	*temp;

	curr = *spr;
	prev = NULL;
	while (*spr)
	{
		if ((int)(*spr)->spr_pos.x == (int)pos->x &&
				(int)(*spr)->spr_pos.y == (int)pos->y)
		{
			temp = *spr;
			if (!prev)
				*spr = temp->next;
			else
				prev->next = temp->next;
			free(temp);
			if (prev)
				*spr = curr;
			return ;
		}
		prev = *spr;
		*spr = (*spr)->next;
	}
	*spr = curr;
}

t_sprite		*add_sorted(t_sprite **sort, t_sprite *spr)
{
	t_sprite	*curr;
	t_sprite	*prev;

	if (!*sort)
		return ((*sort) = spr);
	curr = *sort;
	prev = NULL;
	while (*sort && (*sort)->dist > spr->dist)
	{
		prev = *sort;
		*sort = (*sort)->sort;
	}
	if (!prev)
	{
		spr->sort = *sort;
		*sort = spr;
	}
	else
	{
		spr->sort = prev->sort;
		prev->sort = spr;
		*sort = curr;
	}
	return (spr);
}

t_sprite		*sort_sprite(t_cub *cub, t_sprite *spr)
{
	t_sprite	*sort;
	t_pos		c;

	copy_position(&c, &cub->camera.pos);
	sort = NULL;
	while (spr)
	{
		spr->dist = sprite_dist_cal(c, spr->spr_pos);
		spr->sort = NULL;
		add_sorted(&sort, spr);
		spr = spr->next;
	}
	return (sort);
}
