#include "fdf.h"

int	ft_rotation_point(t_fdf *fdf)
{
	ft_rotation_x_axis(&(fdf->coords->y), &(fdf->cur_height), fdf->alpha);
	ft_rotation_y_axis(&(fdf->coords->x), &(fdf->cur_height), fdf->beta);
	ft_rotation_z_axis(&(fdf->coords->x), &(fdf->coords->y), fdf->gamma);
	return (0);
}

int	ft_rotation_next_point(t_fdf *fdf, int *next_height)
{
	ft_rotation_x_axis(&(fdf->coords->next_y), next_height, fdf->alpha);
	ft_rotation_y_axis(&(fdf->coords->next_x), next_height, fdf->beta);
	ft_rotation_z_axis(&(fdf->coords->next_x), \
	&(fdf->coords->next_y), fdf->gamma);
	return (0);
}

int	ft_rotation_x_axis(int *y, int *z, double angl)
{
	int y_val;

	y_val = *y;
	*y = y_val * cos(angl) + *z * sin(angl);
	*z = -y_val * sin(angl) + *z * cos(angl);
	return (0);
}

int	ft_rotation_y_axis(int *x, int *z, double angl)
{
	int x_val;

	x_val = *x;
	*x = x_val * cos(angl) + *z * sin(angl);
	*z = -x_val * sin(angl) + *z * cos(angl);
	return (0);
}

int	ft_rotation_z_axis(int *x, int *y, double angl)
{
	int x_val;
	int y_val;

	x_val = *x;
	y_val = *y;
	*x = x_val * cos(angl) - *y * sin(angl);
	*y = x_val * sin(angl) + *y * cos(angl);
	return (0);
}
