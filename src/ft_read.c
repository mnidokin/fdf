/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnidokin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 18:29:56 by mnidokin          #+#    #+#             */
/*   Updated: 2020/12/01 18:32:46 by mnidokin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_read(char *str, t_fdf *fdf)
{
	ft_read_coords_map(str, fdf);
	if (!(fdf->height_map_src = \
	(int *)malloc(sizeof(int) * (fdf->max_x * fdf->max_y))))
		exit(EXIT_FAILURE);
	ft_read_height(str, fdf);
	ft_height_map(fdf);
	return (0);
}

int	ft_read_coords_map(char *str, t_fdf *fdf)
{
	char	*line;
	int		fd;

	fd = open(str, O_RDONLY);
	fdf->max_y = 0;
	while (get_next_line(fd, &line) == 1)
	{
		if (fdf->max_y == 0)
			fdf->max_x = ft_read_coords_line(line);
		else if (fdf->max_x != ft_read_coords_line(line))
			exit(EXIT_SUCCESS);
		fdf->max_y++;
		free(line);
	}
	close(fd);
	return (0);
}

int	ft_read_coords_line(char *str)
{
	int	i;
	int	x;

	i = 0;
	x = 0;
	while (str[i] != '\0')
	{
		if (str[i] != ' ' && (ft_isalnum(str[i]) != 1) && str[i] != '-')
			ft_error_msg();
		if ((str[i] == ' ' && 1 == ft_isalnum(str[i - 1])) || \
		(ft_isalnum(str[i]) == 1 && str[i + 1] == '\0'))
		{
			x++;
			i++;
		}
		else
			i++;
	}
	return (x);
}

int	ft_read_height(char *str, t_fdf *fdf)
{
	char	*l;
	int		fd;
	int		i;
	int		j;

	fd = open(str, O_RDONLY);
	j = 0;
	while (get_next_line(fd, &l) == 1)
	{
		i = 0;
		while (l[i])
		{
			if (ft_isalnum(l[i]) == 1)
			{
				fdf->height_map_src[j] = ft_read_height_line(l, &i);
				j++;
			}
			i++;
		}
		free(l);
	}
	close(fd);
	return (0);
}

int	ft_read_height_line(char *str, int *i)
{
	char	*n;
	int		a;
	int		f;

	a = *i;
	f = 1;
	while (ft_isalnum(str[a]))
		a++;
	n = malloc(sizeof(char) * a + 1);
	a = 0;
	while (ft_isalnum(str[*i]))
	{
		if (str[*i - 1] == '-')
			f = -1;
		n[a] = str[*i];
		a++;
		*i += 1;
	}
	n[a] = '\0';
	a = ft_atoi(n);
	a *= f;
	*i -= 1;
	free(n);
	return (a);
}
