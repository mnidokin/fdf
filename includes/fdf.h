#ifndef FDF_H
# define FDF_H

#	include <errno.h>
#	include <fcntl.h>
#	include <stdlib.h>
#	include "libft.h"
#	include "get_next_line.h"
#	include "mlx.h"

# define COLOR_DISCO		0x9A1F6A
# define COLOR_BRICK_RED	0xC2294E
# define COLOR_FLAMINGO		0xEC4B27
# define COLOR_JAFFA		0xEF8633
# define COLOR_SAFFRON		0xF3AF3D

typedef	struct	s_fdf
{
	double		alpha;
	double		beta;
	double		gamma;
	t_coords	*coords;
	int			*height_map_src;
	int			**height_map;
	int			cur_height;
	int			offset_x;
	int			offset_y;
	int			max_x;
	int			max_y;
	int			scale;
	int			cur_color;
	void		*mlx_ptr;
	void		*window;
}				t_fdf;

typedef	struct	s_coords
{
	int	x;
	int	y;
	int	next_x;
	int	next_y;
}				t_coords;

/*
** ft_read.c
*/

void	ft_touch_map(int ac, char *file_name);
int		ft_read(t_fdf *fdf, char *str);
int		ft_read_width_n_length(t_fdf *fdf, char *str);
int		ft_read_max_width(char	*line);
int		ft_read_valid_char(char *line, int pos);

/*
** ft_error.c
*/

void	ft_error_mes(void);
int		ft_error_open(int fd, char *str);
int		ft_error_invalid_char(char *line, int pos);

/*
** ft_scaling.c
*/

int		ft_scaling(t_fdf *fdf, int size);
int		ft_coord_scale(t_fdf *fdf);

/*
** ft_height.c
*/

int		ft_read_height(t_fdf *fdf, char *str);
int		ft_height_raw_map(char *str, int *pos);
int		ft_height_map_gen(t_fdf *fdf, char *str);

/*
** ft_init.h
*/

int		ft_init(t_fdf *fdf);

/*
** ft_draw_map.c
*/

int		ft_draw_map(t_fdf *fdf);
int		ft_coord_step(t_fdf *fdf, int pos_x, int pos_y);

/*
** ft_draw_line.c
*/

int		ft_draw_line(t_fdf *fdf);

/*
** ft_aux.c
*/

int		ft_isbelowzero(int num);
int		ft_isbigger(int first, int second);

#endif
