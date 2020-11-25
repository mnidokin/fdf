#include "fdf.h"

int	main(int ac, char *av)
{
	t_fdf	*fdf;

	ft_touch_map(ac, av[1]);
	if (!(fdf = (t_fdf *)malloc(sizeof(t_fdf))))
		exit (2);
	ft_init(fdf);
	ft_read(fdf, av[1]);
	ft_scaling(fdf, 1000);
	return (0);
}
