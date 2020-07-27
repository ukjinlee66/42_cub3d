/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlee <youlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 18:14:29 by youlee            #+#    #+#             */
/*   Updated: 2020/07/27 20:33:57 by youlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		init_draw(t_texture *tex, t_object *obj, t_pos *tex_pos)
{
	if (obj->side_)
		obj->wall_x = obj->pos.x + ((obj->map_pos.y - obj->pos.y +
					(1. - obj->step.y) / 2.) / obj->dir.y) * obj->dir.x;
	else
		obj->wall_x = obj->pos.y + ((obj->map_pos.x - obj->pos.x +
					(1. - obj->step.x) / 2.) / obj->dir.x) * obj->dir.y;
	obj->wall_x -= floor(obj->wall_x);
	tex_pos->x = (int)(obj->wall_x * tex->width);
	if (obj->side_ == 0 && obj->dir.x > 0.)
		tex_pos->x = tex->width - tex_pos->x - 1.;
	else if (obj->side_ == 1 && obj->dir.y < 0.)
		tex_pos->x = tex->width - tex_pos->x - 1.;
}

void			draw_wall(t_cub *cub, t_object *obj)
{
	t_texture	*tex;
	t_pos		tex_pos;
	t_pos		pixel;
	int			start;
	int			end;

	if (obj->direction == 12)
		printf("wall\n");
	tex = &cub->texture[obj->direction];
	set_position(&pixel, obj->col, MAX(0,
				cub->window.half.y - (obj->height / 2.)));
	if (!tex->tex)
	{
		draw_vertical(&cub->window, &pixel, obj->height,
			cal_color(cub->c[obj->direction],
					obj->dist / 3.5));
		return ;
	}
	init_draw(tex, obj, &tex_pos);
	end = MAX(0, (cub->window.half.y - (obj->height / 2.)));
	start = 0;
	while (start < obj->height && (pixel.y = end++) <
			cub->window.size.y)
	{
		tex_pos.y = (int)((pixel.y * 2 -
					(cub->window.half.y * 2.) + obj->height)
				* ((tex->height / 2.) / obj->height));
		coord(&cub->window, &pixel, cal_color(cal_color2(tex, &tex_pos),
				obj->dist / 3.5));
		start++;
	}
}

int				draw_vertical(t_window *window, t_pos *start,
		int len, int color)
{
	int			i;
	int			j;
	t_pos		pos;
	int			end_y;

	if (start->x < 0 || start->x > window->size.x)
		return (1);
	pos.x = start->x;
	end_y = (int)(window->size.y);
	i = 0;
	while (i < len && (j = start->y + i) < end_y)
	{
		pos.y = j;
		coord(window, &pos, color);
		i++;
	}
	return (1);
}
