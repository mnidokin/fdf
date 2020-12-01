#include "fdf.h"

int	ft_height_map(t_fdf *fdf)
{
	int x;
	int y;
	int j;

	j = 0;
	if (!(fdf->height_map = malloc(sizeof(int*) * fdf->max_y)))
		exit(EXIT_FAILURE);
	y = 0;
	while (y < fdf->max_y)
	{
		if (!(fdf->height_map[y] = malloc(sizeof(int) * fdf->max_x)))
			exit(EXIT_FAILURE);
		x = 0;
		while (x < fdf->max_x)
		{
			fdf->height_map[y][x] = fdf->height_map_src[j];
			x++;
			j++;
		}
		y++;
	}
	return (0);
}
