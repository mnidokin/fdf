#include "fdf.h"

void	ft_touch_map(int ac, char *file_name)
{
	int		fd;
	char	*buf[1024];

	if (ac != 2)
		ft_error_msg();
	fd = open(file_name, O_RDONLY);
	if (ft_error_open(fd, file_name) == -1)
		ft_error_mes();
	if (read(fd, buf, 1) <= 0)
		ft_error_mes();
	while (read(fd, buf, 1))
	{
		continue ;
	}
	close(fd);
}

int	ft_read(t_fdf *fdf, char *str)
{
	
	return (0);
}

int	ft_read_width_n_height(t_fdf *fdf, char *str)
{
	char	*tmp_str;
	int		fd;

	fd = open(str, O_RDONLY);
}
