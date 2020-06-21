/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlee <youlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/21 15:04:47 by youlee            #+#    #+#             */
/*   Updated: 2020/06/21 16:34:25 by youlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <math.h>
# include <unistd.h>
# include "engine/engine.h"
# include "config/config.h"
# include "utils/utils.h"

# define LEFT_CLICK			1
# define RIGHT_CLICK		2
# define MIDDLE_CLICK		3
# define SCROLL_UP			4
# define SCROLL_DOWN		5

# define KEY_1				18
# define KEY_2				19
# define KEY_3				20
# define KEY_4				21
# define KEY_Q				12
# define KEY_W				13
# define KEY_E				14
# define KEY_R				15
# define KEY_A				0
# define KEY_S				1
# define KEY_D				2
# define KEY_I				34
# define KEY_O				31
# define KEY_P				35
# define KEY_J				38
# define KEY_K				40
# define KEY_L				37
# define KEY_LEFT			123
# define KEY_RIGHT			124
# define KEY_FORWARD		126
# define KEY_BACKWARD		125

# define KEY_TAB			48
# define KEY_MAJ			257
# define KEY_ESC			53
# define KEY_TAB			48

/*
** struct
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
	t_pos					pos;
	double					dist;
	t_tex					*tex;
	struct s_sprite			*next;
	struct s_sprite			*sorted;
}							t_sprite;

typedef struct				s_window
{
	void					*ptr;
	void					*win;
	t_image					screen;
	t_pos					size;
	t_pos					half;
	double					ratio;
}							t_window;

typedef struct				s_camera
{
	t_pos					pos;
	t_pos					dir;
	t_pos					x_dir;
	t_pos					plane;
}							t_camera;

typedef struct				s_game
{
	t_config				config;
	t_window				window;
	t_camera				camera;
	t_sprite				*sprite;
	t_tex					tex[TEXTURES];
	t_pos					move;
	t_pos					x_move;
	t_pos					rotate;
	int						option;
	int						kill;
	int						to_kill;
	double					camera_x[1920];
	double					depth[1920];
	double					sf_dist[1080];
	double					cos[2];
	double					sin[2];
}							t_game;

#endif
