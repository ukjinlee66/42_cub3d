/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlee <youlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 11:15:26 by youlee            #+#    #+#             */
/*   Updated: 2020/07/08 17:10:08 by youlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
 ** start player position : (3,3)
*/

void			init_camera(t_camera *camera)
{
	set_position(&camera->pos, 6.5, 5.5);
	set_position(&camera->dir, 0., -1.);
	set_position(&camera->x_dir, camera->dir.y, -camera->dir.x);
	set_position(&camera->plane, FOV, 0.);
	return ;
}

int				up_down_camera(t_cub *cub, int direction)
{
	t_pos			next;
	t_camera		*camera;

	camera = &cub->camera;
	copy_position(&next, &camera->pos);
	next.x += ((direction) ? -1 : 1) * (camera->dir.x * move_speed);
	if ((next.x > cub->object.row || cub->map[(int)next.x][(int)camera->pos.y] == 1)
			|| next.x < 0)
		next.x = camera->pos.x;
    if (cub->map[(int)camera->pos.x][(int)camera->pos.y] == 3||
            cub->map[(int)camera->pos.x][(int)camera->pos.y] == 4)
        cub->map[(int)camera->pos.x][(int)camera->pos.y] = 0;
	copy_position(&camera->pos, &next);
	copy_position(&next, &camera->pos);
	next.y += ((direction) ? -1 : 1) * (camera->dir.y * move_speed);
	if ((next.y > cub->object.col || cub->map[(int)camera->pos.x][(int)next.y] == 1)
			|| next.y < 0)
		next.y = camera->pos.y;
    if (cub->map[(int)camera->pos.x][(int)camera->pos.y] == 3||
            cub->map[(int)camera->pos.x][(int)camera->pos.y] == 4)
        cub->map[(int)camera->pos.x][(int)camera->pos.y] = 0;
	copy_position(&camera->pos, &next);
	return (1);
}

int				side_camera(t_cub *cub, int direction)
{
	t_pos			next;
	t_camera		*camera;

	camera = &cub->camera;
	copy_position(&next, &camera->pos);
	next.x += ((direction) ? -1 : 1) * (camera->x_dir.x * move_speed) + 0.00001;
	if ((next.x > cub->object.row || cub->map[(int)next.x][(int)camera->pos.y] == 1)
			|| (next.x < 0))
		next.x = camera->pos.x;
	copy_position(&camera->pos, &next);
	copy_position(&next, &camera->pos);
	next.y += ((direction) ? -1 : 1) * (camera->x_dir.y * move_speed) + 0.00001;
	if ((next.y > cub->object.col || cub->map[(int)camera->pos.x][(int)next.y] == 1)
			|| (next.y < 0))
		next.y = camera->pos.y;
	copy_position(&camera->pos, &next);
	return (1);
}

int				rotate_camera(t_cub *cub, int dir)
{
	t_pos			prev;
	t_camera		*camera;

	camera = &cub->camera;
	copy_position(&prev, &camera->dir);
	camera->dir.x = (camera->dir.x * cub->cos[dir]) - (camera->dir.y *
			cub->sin[dir]);
	camera->dir.y = (prev.x * cub->sin[dir]) + (camera->dir.y *
			cub->cos[dir]);
	copy_position(&prev, &camera->plane);
	camera->plane.x = (camera->plane.x * cub->cos[dir]) -
		(camera->plane.y * cub->sin[dir]);
	camera->plane.y = (prev.x * cub->sin[dir]) +
		(camera->plane.y * cub->cos[dir]);
	copy_position(&prev, &camera->x_dir);
	camera->x_dir.x = (camera->x_dir.x * cub->cos[dir]) -
		(camera->x_dir.y * cub->sin[dir]);
	camera->x_dir.y = (prev.x * cub->sin[dir]) +
		(camera->x_dir.y * cub->cos[dir]);
	return (1);
}
