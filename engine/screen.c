/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlee <youlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 18:17:49 by youlee            #+#    #+#             */
/*   Updated: 2020/06/28 19:28:35 by youlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

void		update_screen(t_game *game)
{
	t_window		*w;
	int				i;
	t_raysult		ray;
	t_pos			start;

	w = &game->window;
	set_pos(&start, 0, 0);
	draw_rectangle(w, &start, &w->size, 0x0);
	i = 0;
	while (i < w->size.x)
	{
		ray_cast(game, &ray, i);
		game->depth[i] = ray.dist;
		ray.height = fabs(w->size.y / ray.dist);
		draw_wall(game, &ray);
		//if (ray.height < game->window.size.y)
		//	draw_sky_floor(game, &ray);
		i++;
	}
}
