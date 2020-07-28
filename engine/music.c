/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   music.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlee <youlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 20:50:30 by youlee            #+#    #+#             */
/*   Updated: 2020/07/28 15:49:32 by youlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		startbgm(t_cub *cub)
{
	if (SDL_Init(SDL_INIT_AUDIO) < 0)
		print_str(SDL_GetError());
	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024);
	cub->bgm = Mix_LoadMUS("Music/superbgm.mp3");
	Mix_PlayMusic(cub->bgm, -1);
}

void		redmush_music(t_cub *cub)
{
	cub->special[0] = Mix_LoadWAV("Music/redmush.wav");
	Mix_PlayChannel(-1, cub->special[0], 0);
}

void		gremush_music(t_cub *cub)
{
	cub->special[1] = Mix_LoadWAV("Music/greenmush.wav");
	Mix_PlayChannel(-1, cub->special[1], 0);
}

void		star_music(t_cub *cub)
{
	cub->special[2] = Mix_LoadWAV("Music/Star.wav");
	Mix_PlayChannel(-1, cub->special[2], 0);
}

void		coin_music(t_cub *cub)
{
	cub->special[3] = Mix_LoadWAV("Music/Coin.wav");
	Mix_PlayChannel(-1, cub->special[3], 0);
}
