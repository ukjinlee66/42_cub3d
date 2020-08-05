/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlee <youlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 15:02:33 by youlee            #+#    #+#             */
/*   Updated: 2020/08/05 18:34:15 by youlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int			cal_dir(t_object *obj)
{
	if (obj->side_)
		return ((obj->dir.y < 0) ? TEX_NORTH : TEX_SOUTH);
	return ((obj->dir.x < 0) ? TEX_WEST : TEX_EAST);
}

static double		cal_perp(t_cub *cub, t_object *obj)
{
	double perp_dist;

	if (obj->side_)
	{
		perp_dist = (obj->map_pos.y - cub->camera.pos.y +
				(1. - obj->step.y) / 2.);
		return (fabs(perp_dist / obj->dir.y));
	}
	perp_dist = (obj->map_pos.x - cub->camera.pos.x +
			(1. - obj->step.x) / 2.);
	return (fabs(perp_dist / obj->dir.x));
}

static void			cal_xaxis(t_object *obj, t_camera *camera, int col, \
		double camera_x)
{
	obj->col = col;
	set_position(&obj->map_pos, (int)camera->pos.x, (int)camera->pos.y);
	set_position(&obj->dir, camera->dir.x + camera->plane.x * camera_x,
			camera->dir.y + camera->plane.y * camera_x);
	set_position(&obj->delta, fabs(1. / obj->dir.x), fabs(1. / obj->dir.y));
	if (obj->dir.x < 0.)
	{
		set_position(&obj->step, -1., (obj->dir.y < 0.) ? -1. : 1.);
		obj->side.x = (obj->pos.x - obj->map_pos.x) * obj->delta.x;
	}
	else
	{
		set_position(&obj->step, 1., (obj->dir.y < 0.) ? -1. : 1.);
		obj->side.x = (obj->map_pos.x + 1. - obj->pos.x) * obj->delta.x;
	}
	if (obj->dir.y < 0.)
		obj->side.y = (obj->pos.y - obj->map_pos.y) * obj->delta.y;
	else
		obj->side.y = (obj->map_pos.y + 1. - obj->pos.y) * obj->delta.y;
}

static void			set_dir(t_cub *cub, t_object *obj)
{
	if (cub->map[(int)obj->map_pos.x][(int)obj->map_pos.y] == 8)
		obj->direction = 12;
	else if (cub->map[(int)obj->map_pos.x][(int)obj->map_pos.y] == 9)
		obj->direction = 14;
	else if (cub->map[(int)obj->map_pos.x][(int)obj->map_pos.y] == 10)
		obj->direction = 13;
	else if (cub->map[(int)obj->map_pos.x][(int)obj->map_pos.y] == 11)
		obj->direction = 15;
	else
		obj->direction = cal_dir(obj);
}

int					ray_cast(t_cub *cub, t_object *obj, int col)
{
	int			hit;

	copy_position(&obj->pos, &cub->camera.pos);
	cal_xaxis(obj, &cub->camera, col, cub->cam_width[col]);
	hit = 0;
	while (!hit)
	{
		if (obj->side.x < obj->side.y)
		{
			obj->side.x += obj->delta.x;
			obj->map_pos.x += obj->step.x;
			obj->side_ = 0;
		}
		else
		{
			obj->side.y += obj->delta.y;
			obj->map_pos.y += obj->step.y;
			obj->side_ = 1;
		}
		assist_raycast(cub, obj, &hit);
	}
	obj->dist = cal_perp(cub, obj);
	set_dir(cub, obj);
	return (0);
}
