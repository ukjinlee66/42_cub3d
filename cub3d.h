/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlee <youlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 21:55:11 by youlee            #+#    #+#             */
/*   Updated: 2020/07/08 21:17:46 by youlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef CUB3D_H
# define CUB3D_H

#include "mlx.h"
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

/*
 ** x_event_key **
*/

# define X_EVENT_KEY_PRESS			2
# define X_EVENT_KEY_RELEASE		3
# define X_EVENT_KEY_EXIT			17

/*
 ** key_info **
*/

# define KEY_ESC					53
# define KEY_Q						12
# define KEY_W						13
# define KEY_E						14
# define KEY_R						15
# define KEY_A						0
# define KEY_S						1
# define KEY_D						2
# define KEY_LEFT					123
# define KEY_RIGHT					124
# define KEY_UNDER					125
# define KEY_UP						126

/*
 ** direction and parse
*/

# define RESOLUTION					R
# define NORTH						NO
# define TEX_NORTH					0
# define SOUTH						SO
# define TEX_SOUTH					1
# define WEST						WE
# define TEX_WEST					2
# define EAST						EA
# define TEX_EAST					3
# define FLOOR						F
# define TEX_FLOOR					4
# define CEILLING					C
# define TEX_SKY					5
# define SPRITE						S

/*
 ** other options
*/
# define FOV						.66
# define MAX_HEIGHT					1080
# define MAX_WIDTH					1920
# define MH							600
# define MIN_HEIGHT					320
# define MIN_WIDTH					480
# define rotate_speed				.07
# define move_speed					.11

/*
 ** struct
*/

typedef struct						s_pos
{
	double			x;
	double			y;
}									t_pos;

typedef struct						s_image
{
	void			*ptr;
	void			*img;
	t_pos			pos;
	int				size_l;
	int				bpp;
	int				endian;
}									t_image;

typedef struct						s_object
{
	int				col;
	int				row;
	double			dist;
	int				side_;
	int				height;
	double			wall_x;
	int				direction;
	t_pos			side;
	t_pos			map_pos;
	t_pos			pos;
	t_pos			dir;
	t_pos			delta;
	t_pos			step;
	t_pos			floor_wall;
	t_pos			c_floor;
}									t_object;

typedef struct						s_camera
{
	t_pos			pos;
	t_pos			dir;
	t_pos			x_dir;
	t_pos			plane;
}									t_camera;

typedef struct						s_window
{
	void			*ptr;
	void			*win;
	t_image			screen;
	t_pos			size;
	t_pos			half;
}									t_window;

typedef struct						s_texture
{
	char			*path;
	void			*ptr;
	void			*tex;
	t_pos			start;
	t_pos			end;
	int				width;
	int				height;
	int				size_l;
	int				bpp;
	int				endian;	
}									t_texture;

typedef struct						s_cub
{
	t_window		window;
	t_camera		camera;
	t_texture		texture[10];
	t_object		object;
	t_pos			move;
	t_pos			x_move;
	t_pos			rotate;
	unsigned		c[9];
	double			cos[2];
	double			sin[2];
	double			depth[1080];
	double			cam_width[1920];
	double			cam_height[1080];
	int				map[10][10];
	int				option;
}									t_cub;

/*
 ** function
*/

void			init_camera(t_camera *camera);
int				up_down_camera(t_cub *cub, int direction);
int				side_camera(t_cub *cub, int direction);
int				rotate_camera(t_cub *cub, int dir);
void			draw_wall(t_cub *cub, t_object *obj);
int				draw_vertical(t_window *window, t_pos *start,
		int len, int color);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			init_img(t_window *window, t_image *img);
int				exit_game(void);
int				key_press(int key, t_cub *cub);
int				key_release(int key, t_cub *cub);
int				main_loop(t_cub *cub);
void			set_position(t_pos *pos, double x, double y);
void			copy_position(t_pos *pos1, t_pos *pos2);
int				ray_cast(t_cub *cub, t_object *obj, int col);
int				make_table(t_cub *cub);
void			coord(t_window *win, t_pos *pos, int color);
void			put_screen(t_cub *cub);
void			init_window(t_window *window);
void			put_img(t_cub *cub);
int				cal_color(int color, int divide);
int				cal_color2(t_texture *tex, t_pos *pos);
int				MAX(int a, int b);
void			draw_sky_floor(t_cub *cub, t_object *obj);
void			load_texture(t_cub *cub);

#endif
