/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlee <youlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 21:43:45 by youlee            #+#    #+#             */
/*   Updated: 2020/07/02 04:11:55 by youlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"
#include <stdio.h>
int				wall_dir(t_raysult *ray)
{
	if (ray->side)
		return ((ray->ray_dir.y < 0) ? (TEX_NORTH) : (TEX_SOUTH));
	return ((ray->ray_dir.x < 0) ? (TEX_WEST) : (TEX_EAST));
}

double			ray_dir(t_game *game, t_raysult *ray)
{
	double		pos;

	if (ray->side)
	{
		pos = (ray->map_pos.y - game->camera.pos.y + (1. - ray->step.y) / 2.);
		return (fabs(pos / ray->ray_dir.y));
	}
	pos = (ray->map_pos.x - game->camera.pos.x + (1. - ray->step.x) / 2.);
	return (fabs(pos / ray->ray_dir.x));
}

void			init_ray(t_raysult *ray, t_camera *c, int col, \
	double camera_x)
{
	ray->col = col;
	set_pos(&ray->map_pos, (int)c->pos.x, (int)c->pos.y);
	set_pos(&ray->ray_dir, c->dir.x + c->plane.x * camera_x,
			c->dir.y + c->plane.y * camera_x);
	set_pos(&ray->delta_dist, fabs(1. / ray->ray_dir.x), fabs(1. / ray->ray_dir.y));
	if (ray->ray_dir.x < 0.)
	{
		set_pos(&ray->step, -1., (ray->ray_dir.y < 0.) ? -1. : 1.);
		ray->side_dist.x = (ray->ray_pos.x - ray->map_pos.x) * ray->delta_dist.x;
	}
	else
	{
		set_pos(&ray->step, 1., (ray->ray_dir.y < 0.) ? -1. : 1.);
		ray->side_dist.x = (ray->map_pos.x + 1. - ray->ray_pos.x) *
			ray->delta_dist.x;
	}
	if (ray->ray_dir.y < 0.)
		ray->side_dist.y = (ray->ray_pos.y - ray->map_pos.y) * \
						   ray->delta_dist.y;
	else
		ray->side_dist.y = (ray->map_pos.y + 1. - ray->ray_pos.y) * \
						   ray->delta_dist.y;
}

void			ray_cast(t_game *game, t_raysult *ray, int col)
{
	int			hit;
	int			next;

	copy_pos(&ray->ray_pos, &game->camera.pos);
	init_ray(ray, &game->camera, col, game->camera_x[col]);
	hit = 0;
	while (!hit)
	{
		next = (ray->side_dist.x < ray->side_dist.y);
		ray->side_dist.x += ((next) ? ray->delta_dist.x : 0.);
		ray->map_pos.x += ((next) ? ray->step.x : 0.);
		ray->side_dist.y += ((!next) ? ray->delta_dist.y : 0.);
		ray->map_pos.y += ((!next) ? ray->step.y : 0.);
		ray->side = !next;
		if (!IN_MAP(ray->map_pos, game->config))
		{
			ray->map_pos.x -= ((!ray->side) ? ray->step.x : 0.);
			ray->map_pos.y -= ((ray->side) ? ray->step.y : 0.);
			hit = 1;
		}
		else if (MAP(ray->map_pos, game->config) == '1')
			hit = 1;
	}
	ray->dist = ray_dir(game, ray);
	ray->dir = wall_dir(ray);
}
