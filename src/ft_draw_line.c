#include "fdf.h"

/*
** Bresenham's line algorithm
*/

int	ft_draw_line(t_fdf *fdf)
{
	int	next_height;
	int	x_displace;
	int	y_displace;
	int	max_step;

	x_displace = 0;
	y_displace = 0;
	max_step = 0;
	fdf->cur_height = fdf->height_map[fdf->coords->x][fdf->coords->x];
	next_height = fdf->height_map[fdf->coords->next_x][fdf->coords->next_y];
	return (0);
}
