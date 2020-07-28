/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlee <youlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 14:29:30 by youlee            #+#    #+#             */
/*   Updated: 2020/07/28 16:49:20 by youlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		comp_tex(t_cub *cub, t_texture **tex, int val)
{
	if (val == 2)
		*tex = &cub->texture[TEX_SPRITE];
	else if (val == 3)
		*tex = &cub->texture[7];
	else if (val == 4)
		*tex = &cub->texture[8];
	else if (val == 5)
		*tex = &cub->texture[9];
	else if (val == 6)
		*tex = &cub->texture[10];
	else if (val == 7)
		*tex = &cub->texture[11];
}

t_sprite		*add_front_spr(t_sprite **sprite,
		double dist, t_pos *pos, t_texture *tex)
{
	t_sprite		*new;

	if (!(new = (t_sprite*)malloc(sizeof(*new))))
		return (NULL);
	copy_position(&new->spr_pos, pos);
	new->dist = dist;
	new->next = *sprite;
	new->tex = tex;
	*sprite = new;
	return (new);
}

int				check_sprite(t_cub *cub)
{
	int				i;
	int				j;
	int				val;
	t_pos			pos;
	t_texture		*tex;

	i = 0;
	while (i < cub->req_row)
	{
		j = 0;
		while (j < cub->req_col)
		{
			set_position(&pos, i + .5, j + .5);
			val = cub->map[(int)pos.x][(int)pos.y];
			comp_tex(cub, &tex, val);
			if (val >= 2 && val <= 7 && tex->tex &&
					!add_front_spr(&cub->sprite, 0.,
						&pos, tex))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

double			sprite_dist_cal(t_pos pos1, t_pos pos2)
{
	return (fabs((pos1.x - pos2.x) * (pos1.x - pos2.x) +
				(pos1.y - pos2.y) * (pos1.y - pos2.y)));
}

void			handle_sprite(t_cub *cub)
{
	int				i;
	t_sprite		*sort;
	double			invdet;
	t_camera		*c;
	t_sprite2		spr2;

	c = &cub->camera;
	invdet = 1. / vector_cross(c->plane, c->dir);
	sort = sort_sprite(cub, cub->sprite);
	while (sort)
	{
		if (sort->dist > .1)
		{
			init_sprite(cub, sort, invdet, &spr2);
			draw_sprite(cub, sort, &spr2, sort->tex);
		}
		sort = sort->sort;
	}
}
