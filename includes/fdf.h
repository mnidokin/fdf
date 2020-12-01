#ifndef FDF_H
# define FDF_H

#	include <errno.h>
#	include <fcntl.h>
#	include <stdlib.h>
#	include <math.h>
#	include "libft.h"
#	include "get_next_line.h"
#	include "mlx.h"

# define COLOR_DISCO		0x9A1F6A
# define COLOR_BRICK_RED	0xC2294E
# define COLOR_FLAMINGO		0xEC4B27
# define COLOR_JAFFA		0xEF8633
# define COLOR_SAFFRON		0xF3AF3D

# define AR_UP				126
# define AR_DOWN			125
# define AR_LEFT			123
# define AR_RIGHT			124

# define KEY_ESC	53
# define KEY_I		34
# define KEY_0		29

# define SCROLL_LEFT	6
# define SCROLL_RIGHT	7

typedef	struct	s_coords
{
	float	x;
	float	y;
	float	next_x;
	float	next_y;
}				t_coords;

typedef	struct	s_fdf
{
	double		alpha;
	double		beta;
	double		gamma;
	t_coords	*coords;
	int			*height_map_src;
	int			**height_map;
	float		cur_height;
	int			offset_x;
	int			offset_y;
	int			max_x;
	int			max_y;
	int			scale;
	int			cur_color;
	int			iso_flag;
	void		*mlx_ptr;
	void		*window;
}				t_fdf;

/*
** ft_error.c
*/

int		ft_error_touch_map(int ac, char *str);
int		ft_error_check_map(int fd, char *str);
void	ft_error_msg(void);

/*
** ft_height_map.c
*/

int	ft_height_map(t_fdf *fdf);

/*
** ft_key.c
*/

int		ft_key(int key, t_fdf *fdf);
int		ft_key_angle(int key, t_fdf *fdf);

/*
** ft_read.c
*/

int		ft_read(char *str, t_fdf *fdf);
int		ft_read_coords_map(char *str, t_fdf *fdf);
int		ft_read_coords_line(char *str);
int		ft_read_height(char *str, t_fdf *fdf);
int		ft_read_height_line(char *str, int *i);

/*
** ft_scale.c
*/

int		ft_scale(t_fdf *fdf, int size);
int		ft_scale_coords(t_fdf *fdf);

/*
** ft_draw.c
*/

int	ft_draw(t_fdf *fdf);
int	ft_draw_x_step(t_fdf *fdf, int x, int y);
int	ft_draw_y_step(t_fdf *fdf, int x, int y);

/*
** ft_draw_map.c
*/

int	ft_draw_map(t_fdf *fdf);

/*
** ft_rotation.c
*/

int	ft_rotation_map(t_fdf *fdf, float *next_height);
int	ft_rotation_x_axis(double angl, float *z, float *y);
int	ft_rotation_y_axis(double angl, float *z, float *x);
int	ft_rotation_z_axis(double angl, float *x, float *y);

/*
** ft_iso.c
*/

int	ft_iso_check(t_fdf *fdf, float next_height);
int	ft_iso_calc(float height, float *x, float *y);

/*
** ft_offset.c
*/

int	ft_offset(t_fdf *fdf);

/*
** ft_isbigger.c
*/

float	ft_isbigger(float x, float y);

/*
** ft_abs.c
*/

float ft_abs(float num);

#endif
