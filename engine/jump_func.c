#include "cub3d.h"

int            jumpup(t_cub *cub)
{
    if (cub->jump_val - 3 < 30)
    {
        printf("cub->jump_valup : %d\n",
                cub->jump_val);
        cub->jump_val-=3;
        cub->window.half.y += cub->jump_val;
        if (cub->jump_val == 0)
            cub->jump_val = -30;
    }
    return (1);
}

int             jumpdown(t_cub *cub)
{
    printf("cub->jump_down: %d\n",
            cub->jump_val);
    if (cub->jump_val + 3 > -30)
    {
        cub->jump_val+=3;
        cub->window.half.y -= abs(cub->jump_val);
        if (cub->jump_val == 0)
            cub->jump_val = 0;
    }
    return (1);
}
