#include "fdf.h"

int	ft_isbelowzero(int num)
{
	if (num < 0)
		return (-num);
	else
		return (num);
}

int	ft_isbigger(int first, int second)
{
	if (first > second)
		return (first);
	else
		return (second);
}

int	ft_point_check(t_fdf *fdf)
{
	if ((fdf->coords->x - fdf->coords->next_x) || \
	(fdf->coords->y - fdf->coords->next_y))
		return (0);
	return (1);
}

int	ft_point_step(t_fdf *fdf, int x_displace, int y_displace)
{
	fdf->coords->x += x_displace;
	fdf->coords->y += y_displace;
	return (0);
}
