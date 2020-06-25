/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tables.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlee <youlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 17:19:19 by youlee            #+#    #+#             */
/*   Updated: 2020/06/25 18:17:15 by youlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

/*
 ** calculate ray position and direction
 ** x-coordinate in camera space.
*/

static void			calculate_camera_x(double width, double *r)
{
	int			i;

	i = 0;
	while (i < width)
		r[i++] = ((2. * (double)i) / width) - 1.;
}

static void			calculate_cos_sin(double rotate_speed, double *cos_r, \
		dobule *sin_r)
{
	cos_r[0] = cos(-rotate_speed);
	cos_r[1] = cos(rotate_speed);
	sin_r[0] = sin(-rotate_speed);
	sin_r[1] = sin(rotate_speed);
}

static void			calculate_sf_dist(double hegiht, double *r)
{
	int			i;

	i = 0;
	while (i < height)
		r[i++] = (height / (2. * (double)i - height));
}

void				make_tables(t_game *game)
{
	calculate_camera_x(game->window.size.x, game->camera_x);
	calculate_cos_sin(game->config.rotate_speed, game->cos, game->sin);
	calculate_sf_dist(game->window.size.y, game->sf_dist);
}
