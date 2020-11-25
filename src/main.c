#include "fdf.h"

int	main(int ac, char *av)
{
	t_fdf	*fdf;

	ft_touch_map(ac, av[1]);
	if (!(fdf = (t_fdf *)malloc(sizeof(t_fdf))))
		exit (2);
	if (!(fdf->coords = (t_coords *)malloc(sizeof(t_coords))))
		exit (2);
	fdf->max_x = 0;
	fdf->max_y = 0;
	fdf->mlx_ptr = mlx_init();
	fdf->window = mlx_new_window(fdf->mlx_ptr, 1000, 1000, "FDF");
	ft_scaling(fdf, 1000);
	fdf->offset_x = 200;
	fdf->offset_y = 200;
	fdf->alpha = 0;
	fdf->beta = 0;
	fdf->gamma = 0;
	
	return (0);
}
