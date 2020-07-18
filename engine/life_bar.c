#include "cub3d.h"

void            draw_life_bar(t_cub *cub)
{
    t_window    *win;
    void        *img;
    int         width;
    int         height;

    win = &cub->window;
    img = mlx_xpm_file_to_image(win->ptr, "textures/life_bar.xpm", &width, &height);
    mlx_put_image_to_window(win->ptr, win->win, img, 50, 50);
}
