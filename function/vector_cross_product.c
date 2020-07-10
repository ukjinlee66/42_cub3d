#include "cub3d.h"

double          vector_cross(t_pos pos1, t_pos pos2)
{
    return((pos1.y * pos2.x) - (pos1.x * pos2.y));
}
