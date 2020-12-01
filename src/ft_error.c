#include "fdf.h"

int		ft_error_touch_map(int ac, char *str)
{
	char	buf[1];
	int		i;
	int		fd;

	if (ac != 2)
		ft_error_msg();
	fd = open(str, O_RDONLY);
	ft_error_check_map(fd, str);
	if (read(fd, buf, 1) <= 0)
		ft_error_msg();
	while (read(fd, buf, 1))
	{
		i = 1;
	}
	close(fd);
	return (0);
}

int		ft_error_check_map(int fd, char *str)
{
	int		i;
	char	*s;

	if (fd < 0)
		ft_error_msg();
	s = ".fdf";
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '.')
		{
			if (ft_strequ(str + i, s) == 0)
				ft_error_msg();
			else
				return (0);
		}
		i++;
	}
	ft_error_msg();
	return (0);
}

void	ft_error_msg(void)
{
	ft_putendl("...the thread of prophecy is severed");
	exit(EXIT_FAILURE);
}
