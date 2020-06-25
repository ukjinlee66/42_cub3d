/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlee <youlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 20:09:49 by youlee            #+#    #+#             */
/*   Updated: 2020/06/25 20:14:06 by youlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static void			init_draw_wall(t_tex *tex, t_raysult *ray, t_pos *p_tex)
{
	if (ray->side)
		ray->wall_x = ray->ray_pos.x +
			((ray->map_pos.y - ray->ray_pos.y +
				(1. - ray->step.y) / 2.) / ray->ray->dir.y) * ray->ray_dir.x;
	else
		ray->wall_x = ray->ray_pos.y +
			((ray->map_pos.x - ray->ray_pos.x +
						(1. - ray->step.x) / 2.) / ray->ray->dir.x) *
							ray->ray_dir.y;
	ray->wall_x -= floor(ray->wall_x);
	p_tex->x = (int)(ray->wall_x * tex->width);
	if (ray->side == 0 && ray->ray_dir.x > 0.)
		p_tex->x = tex->width - p_tex->x - 1.;
	else if (ray->side == 1 && ray->ray_dir.y < 0.)
		p_tex->x = tex->width - p_tex->x - 1.;
}

void				draw_wall(t_game *game, t_raysult *ray)
{
	int			num[2];
	t_pos		p_tex;
	t_tex		*tex;
	t_pos		pixel;

	tex = &g->tex[ray->dir];
	set_pos(&pixel, ray->col, MAX(0, game->window.half.y - (ray->height / 2.)));
	if (!tex->tex)
	{
		draw_vertical_line(&g->window, &pixel, ray->height, \
				distance_shade(game->options, \
					game->config.c[ray->dir], ray->dist));
		return ;
	}
	init_draw_wall(tex, ray, &p_tex);
	num[1] = MAX(0, game->window.half.y - (ray->height / 2.));
	num[0] = 0;
	while (num[0] < ray->height && (pixel.y = num[1]++) < \
			game->window.size.y)
	{
		p_tex.y = (int)((pixel.y * 2 - game->window.size.y + ray->height));
		draw_pixel(&game->window, &pixel, distance_shade(game->options,
					get_tex_color(tex, &p_tex), ray->dist));
		num[0]++;
	}
}
