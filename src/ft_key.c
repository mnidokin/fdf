#include "fdf.h"

int		ft_key(int key, t_fdf *fdf)
{
	if (key == 53)
		exit(0);
	if (key == 34)
		fdf->iso_flag = 1;
	if (key == 35)
		fdf->iso_flag = 0;
	if (key == 126)
		fdf->offset_y -= 10;
	if (key == 125)
		fdf->offset_y += 10;
	if (key == 124)
		fdf->offset_x += 10;
	if (key == 123)
		fdf->offset_x -= 10;
	if (key == 6)
		fdf->scale -= 1;
	if (key == 7)
		fdf->scale += 1;
	ft_key_angle(key, fdf);
	mlx_clear_window(fdf->mlx_ptr, fdf->window);
	ft_draw(fdf);
	return (0);
}

int	ft_key_angle(int key, t_fdf *fdf)
{
	if (key == 12)
		fdf->alpha += 100 * 0.002;
	if (key == 13)
		fdf->beta += 100 * 0.002;
	if (key == 14)
		fdf->gamma += 100 * 0.002;
	if (key == 0)
		fdf->alpha -= 100 * 0.002;
	if (key == 1)
		fdf->beta -= 100 * 0.002;
	if (key == 2)
		fdf->gamma -= 100 * 0.002;
	if (key == 15)
		fdf->alpha = 0;
	if (key == 17)
		fdf->beta = 0;
	if (key == 16)
		fdf->gamma = 0;
	return (0);
}