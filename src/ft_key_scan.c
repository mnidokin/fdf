#include "fdf.h"
#include <stdio.h>

int	ft_key_scan(t_fdf *fdf, int key)
{
	if (key == KEY_ESC)
		exit(0);
	ft_key_offset_axis(fdf, key);
	ft_key_zoom(fdf, key);
	//mlx_clear_window(fdf->mlx_ptr, fdf->window); //!
	ft_draw_map(fdf); //!
	return (0);
}

int	ft_key_offset_axis(t_fdf *fdf, int key)
{
	if (key == AR_UP)
		fdf->offset_y -= 10;
	if (key == AR_DOWN)
		fdf->offset_y += 10;
	if (key == AR_LEFT)
		fdf->offset_x -= 10;
	if (key == AR_RIGHT)
		fdf->offset_x += 10;
	return (0);
}

int	ft_key_zoom(t_fdf *fdf, int key)
{
	if (key == SCROLL_LEFT)
		fdf->scale -= 1;
	if (key == SCROLL_RIGHT)
		fdf->scale += 1;
	return (0);
}
