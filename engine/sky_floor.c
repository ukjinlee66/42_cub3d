/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sky_floor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 20:51:58 by youlee            #+#    #+#             */
/*   Updated: 2020/07/08 15:27:16 by youlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void			init_sky_floor(t_object *obj)
{
	if (obj->side_ == 0 && obj->dir.x > 0)
		set_position(&obj->floor_wall,
				obj->map_pos.x, obj->map_pos.y + obj->wall_x);
	else if (obj->side_ == 0 && obj->dir.x < 0)
		set_position(&obj->floor_wall,
				obj->map_pos.x + 1., obj->map_pos.y + obj->wall_x);
	else if (obj->side_ && obj->dir.y > 0)
		set_position(&obj->floor_wall,
				obj->map_pos.x + obj->wall_x, obj->map_pos.y);
	else if (obj->side_ && obj->dir.y < 0)
		set_position(&obj->floor_wall,
				obj->map_pos.x + obj->wall_x, obj->map_pos.y + 1.);
}

static void			draw_floor(t_cub *cub, t_object *obj, t_pos *pixel, t_pos *tex_pos)
{
	t_texture	*tex;

	tex = &cub->texture[TEX_FLOOR];
	if (!tex -> tex)
	{
		coord(&cub->window, pixel, cal_color(cub->c[TEX_FLOOR], cub->cam_height[obj->row]));
	}
	else
	{
		set_position(tex_pos, (int)(obj->c_floor.x * tex->width) % tex->width,
				(int)(obj->c_floor.y * tex->height) % tex->height);
		coord(&cub->window, pixel, cal_color(cal_color2(tex, tex_pos), cub->cam_height[obj->row]));
	}
}

static void			draw_sky(t_cub *cub, t_object *obj, t_pos *pixel, t_pos *tex_pos)
{
	t_texture	*tex;

	tex = &cub->texture[TEX_SKY];
	if (!cub->texture[TEX_SKY].tex)
	{
		coord(&cub->window, pixel,
				cal_color(cub->c[TEX_SKY], cub->cam_height[obj->row]));
	}
	else
	{
		set_position(tex_pos, (int)(obj->c_floor.x * tex->width) % tex->width,
				(int)(obj->c_floor.y * tex->height) % tex->height);
		coord(&cub->window, pixel,
				cal_color(cal_color2(tex, tex_pos), cub->cam_height[obj->row]));
	}
}

void				draw_sky_floor(t_cub *cub, t_object *obj)
{
	int			i;
	double		w;
	t_pos		pixel;
	t_pos		tex_pos;

	init_sky_floor(obj);
	pixel.x = obj->col;
	i = cub->window.half.y + (obj->height / 2.);
	while (i < cub->window.size.y)
	{
		obj->row = (int)i;
		w = cub->cam_height[i] / obj->dist;
		set_position(&obj->c_floor,
				w * obj->floor_wall.x + (1. - w)
				* cub->camera.pos.x,
				w * obj->floor_wall.y + (1. - w)
				* cub->camera.pos.y);
		pixel.y = i;
		draw_floor(cub, obj, &pixel, &tex_pos);
		pixel.y = cub->window.size.y - i++;
		draw_sky(cub, obj, &pixel, &tex_pos);
	}
}
