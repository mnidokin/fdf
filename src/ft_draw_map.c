#include "fdf.h"

int	ft_draw_map(t_fdf *fdf)
{
	float	x_step;
	float	y_step;
	float	max;
	float	z1;

	fdf->cur_height = fdf->height_map[(int)fdf->coords->y][(int)fdf->coords->x];
	z1 = fdf->height_map[(int)fdf->coords->next_y][(int)fdf->coords->next_x];
	fdf->cur_color = (fdf->cur_height || z1) ? 0xe80c0c : 0xffffff;
	ft_scale_coords(fdf);
	ft_rotation_map(fdf, &z1);
	ft_iso_check(fdf, z1);
	ft_offset(fdf);
	x_step = fdf->coords->next_x - fdf->coords->x;
	y_step = fdf->coords->next_y - fdf->coords->y;
	max = ft_isbigger(ft_abs(x_step), ft_abs(y_step));
	x_step /= max;
	y_step /= max;
	while ((int)(fdf->coords->x - fdf->coords->next_x) || (int)(fdf->coords->y - fdf->coords->next_y))
	{
		mlx_pixel_put(fdf->mlx_ptr, fdf->window, (int)fdf->coords->x, (int)fdf->coords->y, fdf->cur_color);
		fdf->coords->x += x_step;
		fdf->coords->y += y_step;
	}
	return (0);
}
