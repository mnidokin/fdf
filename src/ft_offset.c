#include "fdf.h"

int	ft_offset(t_fdf *fdf)
{
	fdf->coords->x += fdf->offset_x;
	fdf->coords->next_x += fdf->offset_x;
	fdf->coords->y += fdf->offset_y;
	fdf->coords->next_y += fdf->offset_y;
	return (0);
}
