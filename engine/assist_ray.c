/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assist_ray.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlee <youlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 18:32:48 by youlee            #+#    #+#             */
/*   Updated: 2020/08/05 18:37:10 by youlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		assist_raycast(t_cub *cub, t_object *obj,
		int *hit)
{
	if ((int)obj->map_pos.x >= cub->req_row ||
			(int)obj->map_pos.y >= cub->req_col)
	{
		obj->map_pos.x -= ((!obj->side_) ? obj->step.x : 0.);
		obj->map_pos.y -= ((obj->side_) ? obj->step.y : 0.);
		*hit = 1;
	}
	else if (cub->map[(int)obj->map_pos.x][(int)obj->map_pos.y] == 1 ||
			cub->map[(int)obj->map_pos.x][(int)obj->map_pos.y] == 8 ||
			cub->map[(int)obj->map_pos.x][(int)obj->map_pos.y] == 10 ||
			cub->map[(int)obj->map_pos.x][(int)obj->map_pos.y] == 11)
		*hit = 1;
}
