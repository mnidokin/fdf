#include "fdf.h"

void	ft_touch_map(int ac, char *file_name)
{
	int		fd;
	char	*buf[1024];

	if (ac != 2)
		ft_error_mes();
	fd = open(file_name, O_RDONLY);
	if (ft_error_open(fd, file_name) == -1)
		ft_error_mes();
	if (read(fd, buf, 1) <= 0)
		ft_error_mes();
	while (read(fd, buf, 1))
		continue ;
	close(fd);
}

int		ft_read(t_fdf *fdf, char *str)
{
	ft_read_width_n_length(fdf, str);
	ft_height_map_gen(fdf, str);
	return (0);
}

int		ft_read_width_n_length(t_fdf *fdf, char *str)
{
	char	*tmp_str;
	int		max_width;
	int		max_length;
	int		fd;

	max_length = 0;
	fd = open(str, O_RDONLY);
	while(get_next_line(fd, &tmp_str) == 1)
	{
		max_width = ft_read_max_width(tmp_str);
		if (fdf->max_x != 0)
			if (fdf->max_x != max_width)
				exit(2);
		fdf->max_x = max_width;
		max_length++;
		//free(tmp_str);
	}
	fdf->max_y = max_length;
	//free(tmp_str);
	close(fd);
	return (0);
}

int		ft_read_max_width(char	*line)
{
	int	max_width;
	int	iter;

	max_width = 0;
	iter = 0;
	while (line[iter])
	{
		if (ft_error_invalid_char(line, iter))
			ft_error_mes();
		if (ft_read_valid_char(line, iter))
			max_width++;
		iter++;
	}
	return (max_width);
}

int		ft_read_valid_char(char *line, int pos)
{
	if ((line[pos] == ' ' && ft_isalnum(line[pos - 1]) == 1) || (ft_isalnum(line[pos]) == 1 && line[pos + 1] == '\0'))
		return (1);
	return (0);
}
