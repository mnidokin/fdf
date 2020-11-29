#include "fdf.h"

int	ft_init(t_fdf *fdf)
{
	if (!(fdf->coords = (t_coords *)malloc(sizeof(t_coords))))
		exit(EXIT_FAILURE);
	fdf->max_x = 0;
	fdf->max_y = 0;
	fdf->offset_x = 200;
	fdf->offset_y = 200;
	fdf->alpha = 0;
	fdf->beta = 0;
	fdf->gamma = 0;
	fdf->mlx_ptr = mlx_init();
	fdf->window = mlx_new_window(fdf->mlx_ptr, 1000, 1000, "FDF");
	return (0);
}
