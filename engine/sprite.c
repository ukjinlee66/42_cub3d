#include "cub3d.h"

t_sprite		*add_front_spr(t_sprite **sprite,
		double dist, t_pos *pos, t_texture *tex)
{
	t_sprite		*new;

	if (!(new = (t_sprite*)malloc(sizeof(*new))))
		return (NULL);
	copy_position(&new->pos, pos);
	new->dist = dist;
	new->tex = tex;
	new->next = *sprite;
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

int				handle_sprite(t_cub *cub)
{
	int				i;

	i = 0;
	while (i < number_sprite && cub->sprite[i])
		
}
