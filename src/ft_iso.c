#include "fdf.h"

int	ft_iso_check(t_fdf *fdf, int next_height)
{
	if (fdf->iso_flag)
	{
		ft_iso_proection(fdf);
		ft_iso_proection_next_point(fdf, next_height);
	}
	return (0);
}

int	ft_iso_proection(t_fdf *fdf)
{
	fdf->coords->x = (fdf->coords->x - fdf->coords->y) * cos(0.8);
	fdf->coords->y = (fdf->coords->x + fdf->coords->y) * sin(0.8) - fdf->cur_height;
	return (0);
}

int	ft_iso_proection_next_point(t_fdf *fdf, int height)
{
	fdf->coords->next_x = (fdf->coords->next_x - fdf->coords->next_y) * cos(0.8);
	fdf->coords->next_y = (fdf->coords->next_x + fdf->coords->next_y) * sin(0.8) - height;
	return (0);
}
