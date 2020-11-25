#include "fdf.h"

int	ft_scaling(t_fdf *fdf, int size)
{
	fdf->scale = size / (fdf->max_x + fdf->max_y);
	return (0);
}