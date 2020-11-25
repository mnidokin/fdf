#ifndef FDF_H
# define FDF_H

#	include <errno.h>
#	include <fcntl.h>
#	include <stdlib.h>
#	include "libft.h"
#	include "get_next_line.h"
#	include "mlx.h"

typedef	struct	s_fdf
{
	double		alpha;
	double		beta;
	double		gamma;
	t_coords	*coords;
	int			offset_x;
	int			offset_y;
	int			max_x;
	int			max_y;
	int			scale;
	void		*mlx_ptr;
	void		*window;
}				t_fdf;

typedef	struct	s_coords
{
	float	x;
	float	y;
	float	x1;
	float	y1;
}				t_coords;

/*
** ft_read.c
*/

void	ft_touch_map(int ac, char *file_name);

/*
** ft_error.c
*/

void	ft_error_mes(void);
int		ft_error_open(int fd, char *str);

/*
** ft_scaling.c
*/

int	ft_scaling(t_fdf *fdf, int size);

#endif
