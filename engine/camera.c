/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlee <youlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 19:53:06 by youlee            #+#    #+#             */
/*   Updated: 2020/07/02 04:03:12 by youlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"
#include <stdio.h>
void		find_start_pos(t_config *config, t_camera *camera)
{
	int				stop;

	stop = 0;
	camera->pos.y = 0;
	while (!stop && camera->pos.y < config->row)
	{
		camera->pos.x = 0;
		while (!stop && camera->pos.x < config->col)
		{
			if (ft_in_set(MAP(camera->pos, *config), DIRECTIONS))
			{
				stop = 1;
				break ;
			}
			(camera->pos.x)++;
		}
		if (!stop)
			(camera->pos.y)++;
	}
	camera->pos.x += .5;
	camera->pos.y += .5;
}

void		find_start_angle(t_config *config, t_camera *camera)
{
	if (MAP(camera->pos, *config) == 'N')
	{
		set_pos(&camera->dir, 0., -1.);
		set_pos(&camera->plane, config->fov, 0.);
	}
	else if (MAP(camera->pos, *config) == 'E')
	{
		set_pos(&camera->dir, 1., 0.);
		set_pos(&camera->plane, 0., config->fov);
	}
	else if (MAP(camera->pos, *config) == 'S')
	{
		set_pos(&camera->dir, 0., 1.);
		set_pos(&camera->plane, -config->fov, 0.);
	}
	else if (MAP(camera->pos, *config) == 'W')
	{
		set_pos(&camera->dir, -1., 0.);
		set_pos(&camera->plane, 0., -config->fov);
	}
	set_pos(&camera->x_dir, camera->dir.y, -camera->dir.x);
	//MAP(camera->pos, *config) = '0';
	config->map[(int)floor(camera->pos.y * config->col) + (int)floor(camera->pos.x)] = '0';
}

int			move_camera(t_game *game, int dir)
{
	t_camera		*c;
	t_pos			n_pos;

	c = &game->camera;
	copy_pos(&n_pos, &c->pos);
	n_pos.x += (((dir) ? -1 : 1) * (c->dir.x * .11));
	if (IN_MAP(n_pos, game->config)
			&& MAP(n_pos, game->config) != '1'
			&& MAP(n_pos, game->config) != '2')
		copy_pos(&c->pos, &n_pos);
	copy_pos(&n_pos, &c->pos);
	n_pos.y += (((dir) ? -1 : 1) * (c->dir.y * .11));
	if (IN_MAP(n_pos, game->config)
			&& MAP(n_pos, game->config) != '1'
			&& MAP(n_pos, game->config) != '2')
		copy_pos(&c->pos, &n_pos);
	return (1);
}

int			move_perp_camera(t_game *game, int dir)
{
	t_camera		*c;
	t_pos			n_pos;

	c = &game->camera;
	copy_pos(&n_pos, &c->pos);
	n_pos.x += (((dir) ? -1 : 1) * (c->x_dir.x * .11) + 0.00001);
	if (IN_MAP(n_pos, game->config)
			&& MAP(n_pos, game->config) != '1'
			&& MAP(n_pos, game->config) != '2')
		copy_pos(&c->pos, &n_pos);
	copy_pos(&n_pos, &c->pos);
	n_pos.y += (((dir) ? -1 : 1) * (c->x_dir.y * .11) + 0.00001);
	if (IN_MAP(n_pos, game->config)
			&& MAP(n_pos, game->config) != '1'
			&& MAP(n_pos, game->config) != '2')
		copy_pos(&c->pos, &n_pos);
	return (1);
}

int			rotate_camera(t_game *game, int dir)
{
	t_camera		*c;
	t_pos			old;

	c = &game->camera;
	copy_pos(&old, &c->dir);
	c->dir.x = (c->dir.x * game->cos[dir]) - (c->dir.y * game->sin[dir]);
	c->dir.y = (old.x * game->sin[dir]) + (c->dir.y * game->cos[dir]);
	copy_pos(&old, &c->plane);
	c->plane.x = (c->plane.x * game->cos[dir]) - (c->plane.y * game->sin[dir]);
	c->plane.y = (old.x * game->sin[dir]) + (c->plane.y * game->cos[dir]);
	copy_pos(&old, &c->x_dir);
	c->x_dir.x = (c->x_dir.x * game->cos[dir]) - (c->x_dir.y * game->sin[dir]);
	c->x_dir.y = (old.x * game->sin[dir]) + (c->x_dir.y * game->cos[dir]);
	return (1);
}
