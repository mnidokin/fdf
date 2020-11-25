#include "fdf.h"

void	ft_error_mes(void)
{
	ft_putendl("...the thread of prophecy is severed");
	exit(0);
}

int		ft_error_open(int fd, char *str)
{
	char	*exten;
	int		index;

	exten = ".fdf";
	index = 0;
	if (fd < 0)
		return (-1);
	while (str[index] != '\0')
	{
		if (str[index] == '.')
		{
			if (ft_strequ(str + index, exten) == 0)
				return (-1);
			else
				return (0);
		}
		index++;
	}
	return (-1);
}
