/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlee <youlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/21 16:34:38 by youlee            #+#    #+#             */
/*   Updated: 2020/06/25 20:51:22 by youlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENGINE_H
# define ENGINE_H

# include <math.h>
# include "mlx.h"
# include "../config/config.h"
# include "../cub3d.h"

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

typedef struct				s_pos
{
	double					x;
	double					y;
}							t_pos;

typedef struct				s_raysult
{
	int						col;
	int						row;
	double					dist;
	int						dir;
	int						side;
	int						height;
	t_pos					ray_pos;
	t_pos					ray_dir;
	t_pos					map_pos;
	t_pos					side_dist;
	t_pos					delta_dist;
	t_pos					step;
	double					wall_x;
	t_pos					floor_wall;
	t_pos					c_floor;
}							t_raysult;

typedef	struct				s_image
{
	void					*img;
	void					*ptr;
	int						bpp;
	int						endian;
	int						size_l;
}							t_image;

typedef struct				s_tex
{
	char					*path;
	void					*tex;
	void					*ptr;
	t_pos					start;
	t_pos					end;
	int						width;
	int						height;
	int						bpp;
	int						size_l;
	int						endian;
}							t_tex;

typedef struct				s_sprite_draw
{
	int						sprite_screen;
	t_pos					pos;
	t_pos					transform;
	t_pos					spr_s;
	t_pos					draw_x;
	t_pos					draw_y;
	t_pos					tex_pos;
	int						fact;
	int						draw_y_org;
}							t_sprite_draw;

typedef struct				s_sprite
{

}							t_sprite;

typedef struct				s_window
{

}							t_window;

typedef struct				s_camera
{

}							t_camera;

typedef struct				s_game
{

}							t_game;

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

int						wall_dir(t_raysult *ray);

double					ray_dir(t_game *game, t_raysult *ray);

void					init_ray(t_raysult *ray, t_camera *c, int col, \
		double camera_x);

void					ray_cast(t_game *game, t_raysult *ray, int col);

void					update_screen(t_game *game);

void					draw_wall(t_game *game, t_raysult *ray);

int						shade_color(int color, double divide);

int						dist_shade(int options, int color, double dist);

int						get_tex_color(t_tex *tex, t_pos *pos);

#endif
