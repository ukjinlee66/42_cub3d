/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlee <youlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/21 16:34:38 by youlee            #+#    #+#             */
/*   Updated: 2020/06/24 18:51:41 by youlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENGINE_H
# define ENGINE_H

# include <math.h>
# include "mlx/mlx.h"
# include "config/config.h"
# include "cub3d.h"

# define X_EVENT_KEY_PRESS				2
# define X_EVENT_KEY_RELEASE			3
# define X_EVENT_MOUSE_PRESS			4
# define X_EVENT_MOUSE_RELEASE			5
# define X_EVENT_MONUS_MOVE				6
# define X_EVENT_EXIT					17

# define BEST_RATIO						1.7777777778

/*
 ** function
*/

void					update_window(t_game *game);

int						clear_window(t_window *window);

int						init_image(t_window *window, t_image *img);

int						init_window(t_window *window, t_config *config);

void					draw_pixel(t_window *w, t_pos *pos, int color);

int						draw_vertical_line(t_window *window, t_pos *start, \
		int len, int color);

int						draw_rectangle(t_window *window, t_pos *p1, t_pos *p2, \
		int color);
int						rotate_camera(t_game *game, int dir);

void					find_start_pos(t_config *config, t_camera *camera);

void					find_start_angle(t_config *config, t_camera *camera);

int						move_camera(t_game *game, int dir);

int						move_perp_camera(t_game *game, int dir);

#endif
