/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   music2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlee <youlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 15:49:59 by youlee            #+#    #+#             */
/*   Updated: 2020/07/28 15:51:51 by youlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		jump_music(t_cub *cub)
{
	cub->special[4] = Mix_LoadWAV("Music/Jump.wav");
	Mix_PlayChannel(-1, cub->special[4], 0);
}

void		door_music(t_cub *cub)
{
	cub->special[5] = Mix_LoadWAV("Music/Door.wav");
	Mix_PlayChannel(-1, cub->special[5], 0);
}
