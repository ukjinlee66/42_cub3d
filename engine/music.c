/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   music.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlee <youlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 20:50:30 by youlee            #+#    #+#             */
/*   Updated: 2020/07/21 21:36:23 by youlee           ###   ########.fr       */
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
