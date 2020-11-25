#include "fdf.h"

int	ft_scaling(t_fdf *fdf, int size)
{
	fdf->scale = size / (fdf->max_x + fdf->max_y);
	return (0);
}

int	ft_coord_scale(t_fdf *fdf)
{
	fdf->coords->x *= fdf->scale;
	fdf->coords->y *= fdf->scale;
	fdf->coords->next_x *= fdf->scale;
	fdf->coords->next_y *= fdf->scale;
	return (0);
}
