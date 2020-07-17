#include "cub3d.h"

void        put_cross_hair(t_cub *cub)
{
    int         i;
    int         j;
    t_pos       pixel;
    
    i = -10;
    pixel.x = cub->window.size.x / 2.;
    pixel.y = cub->window.size.y / 2.;
    coord(&cub->window, &pixel, 0xFF0000);
    while (i < 11)
    {
        if (i < -1 || i > 1)
        {
            pixel.y = cub->window.size.y / 2. + i;
            pixel.x = cub->window.size.x / 2. + 2;
            coord(&cub->window, &pixel, 0xFF0000);
            pixel.x = cub->window.size.x / 2. - 2;
            coord(&cub->window, &pixel, 0xFF0000);

        }
        i++;
    }
    i = -10;
    while (i < 11)
    {
        if (i < -1 || i > 1)
        {
            pixel.x = cub->window.size.x / 2. + i;
            pixel.y = cub->window.size.y / 2. + 2;
            coord(&cub->window, &pixel, 0xFF0000);
            pixel.y = cub->window.size.x / 2. - 2;
            coord(&cub->window, &pixel, 0xFF0000);
        }
        i++;
    }
}
