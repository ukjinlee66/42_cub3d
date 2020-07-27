/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlee <youlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 21:55:11 by youlee            #+#    #+#             */
/*   Updated: 2020/07/27 20:32:19 by youlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef CUB3D_H
# define CUB3D_H

#include "mlx.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <math.h>
#include <stdio.h>
#include "SDL.h"
#include "SDL_mixer.h"

/*
 ** x_event_key **
*/

# define X_EVENT_KEY_PRESS			2
# define X_EVENT_KEY_RELEASE		3
# define X_EVENT_MOUSE_PRESS        4
# define X_EVENT_MOUSE_RELEASE      5
# define X_EVENT_MOUSE_MOVE         6
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
# define KEY_SPACE                  49
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
# define TEX_SPRITE                 6
/*
 ** other options
*/

# define FOV						.66
# define MAX_HEIGHT					1080
# define MAX_WIDTH					1920
# define MH							800
# define MIN_HEIGHT					320
# define MIN_WIDTH					480
# define rotate_speed				.07
# define move_speed					.07
# define number_sprite				5

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
    int             *data;
	t_pos			start;
	t_pos			end;
	int				width;
	int				height;
	int				size_l;
	int				bpp;
	int				endian;	
}									t_texture;

typedef struct                      s_sprite2
{
    int             screen;
    int             factor;
    int             y_org;
    t_pos           tex_pos;
    t_pos           spr_s;
    t_pos           pos;
    t_pos           draw_x;
    t_pos           draw_y;
	t_pos			transform;
}                                   t_sprite2;

typedef struct						s_sprite
{
	t_texture		*tex;
	t_pos			spr_pos;
	double			dist;
	struct s_sprite	*next;
	struct s_sprite	*sort;
}									t_sprite;

typedef struct						s_cub
{
	t_window		window;
	t_camera		camera;
	t_sprite		*sprite;
	t_texture		texture[13];
	t_object		object;
	t_pos			move;
	t_pos			x_move;
	t_pos			rotate;
    t_pos           mouse;
	unsigned		c[9];
	double			cos[2];
	double			sin[2];
	double			depth[1080];
	double			cam_width[1920];
	double			cam_height[1080];
	int				map[10][10];
	int				req_col;
	int				req_row;
	int				life;
    char            *coin;
	Mix_Chunk		*special[7];
	Mix_Music		*bgm;
    double          mv_speed;
    int             jump_val;
	bool			secret;
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
int				exit_game(t_cub *cub);
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
int				cal_color(int color, double divide);
int				cal_color2(t_texture *tex, t_pos *pos);
int		        MAX(int a, int b);
void			draw_sky_floor(t_cub *cub, t_object *obj);
void			load_texture(t_cub *cub);
t_sprite		*add_front_spr(t_sprite **sprite, double dist,
	t_pos *pos, t_texture *tex);
int				check_sprite(t_cub *cub);
void			handle_sprite(t_cub *cub);
void			init_sprite(t_cub *cub, t_sprite *spr, double invdet, t_sprite2 *spr2);
t_sprite		*add_sroted(t_sprite **sort, t_sprite *spr);
t_sprite		*sort_sprite(t_cub *cub, t_sprite *spr);
double          vector_cross(t_pos pos1, t_pos pos2);
double	        sprite_dist_cal(t_pos pos1, t_pos pos2);
void            draw_sprite2(t_cub *cub, t_sprite *sprite,
        t_sprite2 *spr2, t_texture *tex);
void            draw_sprite(t_cub *cub, t_sprite *spr,
        t_sprite2 *spr2, t_texture *tex);
void            put_cross_hair(t_cub *cub);
void            draw_heart_icon(t_cub *cub, int dist);
void			delete_spr(t_sprite **spr, t_pos *pos);
int				check_coin_map(t_cub *cub);
void			print_str(const char *str);
void			startbgm(t_cub *cub);
int             mouse_move(int x, int y, t_cub *cub);
void            redmush_music(t_cub *cub);
void            gremush_music(t_cub *cub);
void            star_music(t_cub *cub);
void            coin_music(t_cub *cub);
void            jump_music(t_cub *cub);
void            wall_music(t_cub *cub);
int             jumpup(t_cub *cub);
int             jumpdown(t_cub *cub);
void			draw_coin_icon(t_cub *cub);
void			draw_key_icon(t_cub *cub);

#endif
