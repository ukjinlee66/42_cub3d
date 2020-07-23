#include "mlx.h"
#include <stdio.h>
#include <stdlib.h>

# define ESC 53
# define KEY_PRESS 2
# define KEY_RELEASE 3
# define MOUSE_PRESS 4
# define MOUSE_RELEASE 5
# define MOUSE_MOVE 6
# define KEY_EXIT 17


typedef struct  s_param
{
    double x;
    double y;
    int mx;
    int my;
    char *num;
}               t_param;

void init_param(t_param *param)
{
    param->num = (char*)malloc(sizeof(char) * 5);
    param->num[0] = '1';
    param->num[1] = '2';
    param->num[2] = '\0';
}

int key_press(int key)
{
    if (key == 0)
        printf("A\n");
    else if (key == 1)
        printf("S\n");
    else if (key == 2)
        printf("D\n");
    return (0);
}

int mouse_press(int button, int x, int y)
{
    printf("press button %d x : %d y : %d\n", button, x, y);
    return (0);
}

int mouse_release(int button, int x,int y)
{
    printf("release button %d x : %d y : %d\n",button, x, y);
    return (0);
}

int mouse_move(int x, int y)
{
    printf("mouse move x : %d y : %d\n", x, y);
    return (0);
}

int exit_game()
{
    printf("exit game\n");
    exit(0);
    return (0);
}

int main(void)
{
    void *ptr;
    void *win;
    t_param p;

    init_param(&p);
    ptr = mlx_init();
    win = mlx_new_window(ptr, 500, 500, "mouse_string_test");
    mlx_hook(win, KEY_PRESS, 0, &key_press, NULL);
    mlx_hook(win, MOUSE_PRESS, 0, &mouse_press, NULL);
    mlx_hook(win, MOUSE_RELEASE, 0, &mouse_release, NULL);
    mlx_hook(win, MOUSE_MOVE, 0, &mouse_move, NULL);
    mlx_string_put(ptr, win, 10, 10, 0xFF0000, p.num);
    mlx_hook(win, KEY_EXIT, 0, &exit_game, NULL);
    mlx_loop(ptr);
}
