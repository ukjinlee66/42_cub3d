#include "cub3d.h"

void        jump_music(t_cub *cub)
{
    cub->special[4] = Mix_LoadWAV("Music/Jump.wav");
    Mix_PlayChannel(-1, cub->special[4], 0);
}

void        wall_music(t_cub *cub)
{
    cub->special[5] = Mix_LoadWAV("Music/Door.wav");
    Mix_PlayChannel(-1, cub->special[5], 0);
}
