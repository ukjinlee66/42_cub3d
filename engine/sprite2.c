/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlee <youlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 14:29:55 by youlee            #+#    #+#             */
/*   Updated: 2020/08/06 22:40:20 by youlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			clear_sprite(t_sprite **spr)
{
	t_sprite *temp;

	while (*spr)
	{
		temp = (*spr)->next;
		free(*spr);
		*spr = temp;
	}
	*spr = NULL;
}

static int		sp_coord(t_cub *cub, t_sprite2 *spr2,
		t_texture *tex, t_pos *tex_pos)
{
	tex_pos->x = (int)(256 * (((int)(spr2->draw_x.x) -
					(-spr2->spr_s.x / 2. + spr2->screen)))
			* tex->width / spr2->spr_s.x) / 256;
	if (tex_pos->x < tex->start.x || tex_pos->x > tex->end.x)
		return (0);
	spr2->factor = ((int)(spr2->draw_y.x) * 256.) -
		((cub->window.half.y * 2.) * 128.) +
		(spr2->spr_s.y * 128.);
	tex_pos->y = ((spr2->factor * tex->height) / spr2->spr_s.y) / 256.;
	return (tex_pos->y > tex->start.y && tex_pos->y < tex->end.y);
}

void			draw_sprite2(t_cub *cub, t_sprite *sprite,
		t_sprite2 *spr2, t_texture *tex)
{
	t_pos		tex_pos;
	t_pos		pixel;
	int			color;

	set_position(&pixel, spr2->draw_x.x, spr2->draw_y.x);
	if (sp_coord(cub, spr2, tex, &tex_pos))
	{
		color = cal_color(cal_color2(tex, &tex_pos),
				sprite->dist / 3.5);
		if (color != 0x0)
			coord(&cub->window, &pixel, color);
	}
}
