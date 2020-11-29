#include "fdf.h"

int	ft_read_height(t_fdf *fdf, char *str)
{
	char	*tmp_str;
	int		fd;
	int		iter_i;
	int		iter_z;

	iter_z = 0;
	fd = 0;
	if (!(fdf->height_map_src = (int *)malloc(sizeof(int) * (fdf->max_x * fdf->max_y))))
		exit(EXIT_FAILURE);
	fd = open(str, O_RDONLY);
	while (get_next_line(fd, &tmp_str) == 1)
	{
		iter_i = 0;
		while (tmp_str[iter_i])
		{
			if (ft_isalnum(tmp_str[iter_i]) == 1)
			{
				fdf->height_map_src[iter_z] = ft_height_raw_map(tmp_str, &iter_i);
				iter_z++;
			}
			iter_i++;
		}
		free(tmp_str);
	}
	close(fd);
	return (0);
}

int	ft_height_raw_map(char *str, int *pos)
{
	char	*num_str;
	int		num_len;
	int		iter;
	int		res;
	int		flag;

	flag = -1;
	res = 0;
	iter = 0;
	num_len = *pos;
	while (ft_isalnum(str[num_len]))
	{
		num_len++;
	}
	if (!(num_str = (char *)malloc(sizeof(char) * num_len + 1)))
		exit(EXIT_FAILURE);
	num_len = 0;
	while (ft_isalnum(str[*pos]))
	{
		if (str[*pos - 1] == '-')
			flag = 1;
		num_str[iter] = str[*pos];
		iter++;
		(*pos)++;
	}
	num_str[iter] = '\0';
	res = ft_atoi(num_str);
	if (flag == 1)
		res *= -1;
	(*pos) -= 1;
	free(num_str);
	return (res);
}

int	ft_height_map_gen(t_fdf *fdf, char *str)
{
	int	iter_height;
	int	iter_max_x;
	int	iter_max_y;

	iter_height = 0;
	iter_max_x = 0;
	iter_max_y = 0;
	ft_read_height(fdf, str);
	if (!(fdf->height_map = (int **)malloc(sizeof(int *) * fdf->max_y)))
		exit(EXIT_FAILURE);
	while (iter_max_y < fdf->max_y)
	{
		iter_max_x = 0;
		if (!(fdf->height_map[iter_max_y] = (int *)malloc(sizeof(int) * fdf->max_x)))
			exit(EXIT_FAILURE);
		while (iter_max_x < fdf->max_x)
		{
			fdf->height_map[iter_max_y][iter_max_x] = fdf->height_map_src[iter_height];
			iter_height++;
			iter_max_x++;
		}
		iter_max_y++;
	}
	return (0);
}
