#include "cub3d.h"



t_sprite		*add_front_spr(t_sprite **sprite,
		double dist, t_pos *pos, t_texture *tex)
{
	t_sprite		*new;

	if (!(new = (t_sprite*)malloc(sizeof(*new))))
		return (NULL);
	copy_position(&new->spr_pos, pos);
	new->dist = dist;
	new->tex = tex;
	new->next = *sprite;
	*sprite = new;
	return (new);
}

/*
 * sprite number 2~6
*/

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
			val = cub->map[pos.x][pos.y];
			tex = &cub->texture[TEX_SPRITE - 4];
			if (val >= 2 && val <= 6 && tex->tex &&
					!add_front_spr(&cub->sprite, 0.,
						&pos, tex))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static double	sprite_dist_cal(t_pos pos1, t_pos pos2)
{
	return ((pos1.x - pos2.x) * (pos1.x - pos2.x) +
				(pos1.y - pos2.y) * (pos1.y - pos2.y));
}

void			handle_sprite(t_cub *cub)
{
	int				i;
	t_sprite		*sort;
	double			invdet;
	t_camera		*c;

	c = &cub->camera;
	invdet = 1. / vector_cross(c->plane, c->dir);
	sort = sort_sprite(cub, cub->sprite);
	while (sort)
	{
		if (sort->dist > .1)
		{
			init_sprite(cub, sort, invdet, &cub->sprite);
			draw_sprite(cub, sort, &cub->sprite, sort->tex);
		}
		sort = sort->sort;
	}
}
