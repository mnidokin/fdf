#include "fdf.h"

int	ft_rotation_map(t_fdf *fdf, float *next_height)
{
	ft_rotation_x_axis(fdf->alpha, &fdf->cur_height, &fdf->coords->y);
	ft_rotation_x_axis(fdf->alpha, next_height, &fdf->coords->next_y);
	ft_rotation_y_axis(fdf->beta, &fdf->cur_height, &fdf->coords->x);
	ft_rotation_y_axis(fdf->beta, next_height, &fdf->coords->next_x);
	ft_rotation_z_axis(fdf->gamma, &fdf->coords->x, &fdf->coords->y);
	ft_rotation_z_axis(fdf->gamma, &fdf->coords->next_x, &fdf->coords->next_y);
	return (0);
}

int	ft_rotation_x_axis(double angl, float *z, float *y)
{
	float y_val;

	y_val = *y;
	*y = y_val * cos(angl) + *z * sin(angl);
	*z = -y_val * sin(angl) + *z * cos(angl);
	return (0);
}

int	ft_rotation_y_axis(double angl, float *z, float *x)
{
	float x_val;

	x_val = *x;
	*x = x_val * cos(angl) + *z * sin(angl);
	*z = -x_val * sin(angl) + *z * cos(angl);
	return (0);
}

int	ft_rotation_z_axis(double angl, float *x, float *y)
{
	float	x_val;
	float	y_val;

	x_val = *x;
	y_val = *y;
	*x = x_val * cos(angl) - y_val * sin(angl);
	*y = x_val * sin(angl) + y_val * cos(angl);
	return (0);
}
