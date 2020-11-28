#include "fdf.h"

void	ft_t_xx(int x, int y, t_fdf *fdf_list)
{
	fdf_list->coords->x = x;
	fdf_list->coords->y = y;
	fdf_list->coords->next_x = x + 1;
	fdf_list->coords->next_y = y;
}

void	ft_t_yy(int x, int y, t_fdf *fdf_list)
{
	fdf_list->coords->x = x;
	fdf_list->coords->y = y;
	fdf_list->coords->next_x = x;
	fdf_list->coords->next_y = y + 1;
}

int	ft_draw_map(t_fdf *fdf)
{
	int	iter_x;
	int	iter_y;

	iter_x = 0;
	iter_y = 0;
	while (iter_y < fdf->max_y)
	{
		iter_x = 0;
		while (iter_x < fdf->max_x)
		{
			//ft_coord_step(fdf, iter_x, iter_y);
			if (iter_x < fdf->max_x - 1)
			{
				ft_t_xx(iter_x, iter_y, fdf);
				ft_draw_line(fdf);
			}
			if (iter_y < fdf->max_y - 1)
			{
				ft_t_yy(iter_x, iter_y, fdf);
				ft_draw_line(fdf);
			}
			iter_x++;
		}
		iter_y++;
	}
	return (0);
}

/*int	ft_coord_step(t_fdf *fdf, int pos_x, int pos_y)
{
	fdf->coords->x = pos_x;
	fdf->coords->y = pos_y;
	if (pos_x < fdf->max_x - 1)
	{
		fdf->coords->next_x = pos_x + 1;
		fdf->coords->next_y = pos_y;
	}
	if (pos_y < fdf->max_y - 1)
	{
		fdf->coords->next_x = pos_x;
		fdf->coords->next_y = pos_y + 1;
	}
	return (0);
}*/
