#include "fdf.h"

int	main(int ac, char **av)
{
	t_fdf	*fdf;

	ft_touch_map(ac, av[1]);
	if (!(fdf = (t_fdf *)malloc(sizeof(t_fdf))))
		exit (2);
	ft_init(fdf);
	fdf->max_y = 0;
	ft_putnbr(fdf->max_y);
	ft_putendl("");
	ft_putendl("2");
	ft_read(fdf, av[1]);
	ft_scaling(fdf, 1000);
	ft_draw_map(fdf);
	mlx_key_hook(fdf->window, ft_key_scan, fdf);
	mlx_loop(fdf->mlx_ptr);
	return (0);
}
