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

	ft_get_high(fdf, &next_height);
	fdf->cur_color = (fdf->cur_height || next_height) ? 0xF3AF3D : 0xEC4B27;
	ft_coord_scale(fdf);
	ft_rotation_point(fdf);
	ft_rotation_next_point(fdf, &next_height);
	ft_iso_check(fdf, next_height);
	ft_offset_point(fdf);
	x_displace = fdf->coords->next_x - fdf->coords->x;
	y_displace = fdf->coords->next_y - fdf->coords->y;
	max_step = ft_isbigger(ft_isbelowzero(x_displace), \
	ft_isbelowzero(y_displace));
	x_displace /= max_step;
	y_displace /= max_step;
	while (ft_point_check(fdf) == 0)
	{
		mlx_pixel_put(fdf->mlx_ptr, fdf->window, fdf->coords->x, \
		fdf->coords->y, fdf->cur_color);
		ft_point_step(fdf, x_displace, y_displace);
	}
	return (0);
}

int	ft_get_high(t_fdf *fdf, int *next_height)
{
	fdf->cur_height = fdf->height_map[fdf->coords->y][fdf->coords->x];
	*next_height = fdf->height_map[fdf->coords->next_y][fdf->coords->next_x];
	return (0);
}
