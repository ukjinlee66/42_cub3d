#include "cub3d.h"

void            draw_sprite(t_cub *cub, t_sprite *spr,
        t_sprite2 *spr2, t_texture *tex)
{
    while (spr2->draw_x.x < cub->window.size.x &&
            spr2->draw_x.x < spr2->draw_x.y)
    {
        if (spr2->transform.y > 0.
                && spr2->transform.y < cub->depth[(int)spr2->draw_x.x])
        {
            spr2->draw_y.x = spr2->y_org;
            while (spr2->draw_y.x < cub->window.size.y
                    && spr2->draw_y.x < spr2->draw_y.y)
            {
                draw_sprite(cub, spr, spr2, tex);
                spr2->draw_y.x++;
            }
        }
        spr2->draw_x.x++;
    }
}

void            init_sprite(t_cub *cub, t_sprite *spr,
        double invdet, t_sprite2 *spr2)
{
    t_camera    *c;
    double      height_width;

    c = &cub->camera;
    set_position(&spr2->pos, (spr->spr_pos.x - c->pos.x),
            (spr->spr_pos.y - c->pos.y));
    set_position(&spr2->transform, invdet *
            vector_cross(c->dir, spr->spr_pos),
            invdet * (-c->plane.y * spr->spr_pos.x +
                c->plane.x * spr->spr_pos.y));
    spr2->screen = (int)((cub->window.size.x / 2.) *
        (1. + spr2->transform.x / spr2->transform.y));
    height_width = fabs(cub->window.size.y / spr2->transform.y);
    spr2->spr_s.x = height_width;
    spr2->spr_s.y = height_width;
    set_position(&spr2->draw_x, 
            (int)MAX(0,-spr2->spr_s.x / 2. + spr2->screen),
            (int)MAX(0,spr2->spr_s.x / 2. + spr2->screen));
    set_position(&spr2->draw_y,
            (int)MAX(0,-spr2->spr_s.y / 2. + cub->window.size.y / 2.),
            (int)MAX(0,spr2->spr_s.y / 2. + cub->window.size.y / 2.));
    spr2->y_org = spr2->draw_y.x;
}

t_sprite		*add_sorted(t_sprite **sort, t_sprite *spr)
{
	t_sprite	*curr;
	t_sprite	*prev;

	if (!*sort)
		return ((*sort) = spr);
	curr = *sort;
	prev = NULL;
	while (*sort && (*sort)->dist > spr->dist)
	{
		prev = *sort;
		*sort = (*sort)->sort;
	}
	if (!prev)
	{
		spr->sort = *sort;
		*sort = sprite;
	}
	else
	{
		spr->sort = prev->sort;
		prev->sort = spr;
		*sort = curr;
	}
	return (spr);
}

t_sprite		*sort_sprite(t_cub *cub, t_sprite *spr)
{
	t_sprite	*sort;
	t_pos		c;

	copy_position(&c, &cub->camera.pos);
	sort = NULL;
	while (spr)
	{
		spr->dist = sprite_dist_cal(c.pos, spr->spr_pos);
		spr->sort = NULL;
		add_sorted(&sort, spr);
		spr = spr->next;
	}
	return (sort);
}