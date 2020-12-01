/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_height_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnidokin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 18:29:21 by mnidokin          #+#    #+#             */
/*   Updated: 2020/12/01 18:34:53 by mnidokin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_height_map(t_fdf *fdf)
{
	int x;
	int y;
	int j;

	j = 0;
	if (!(fdf->height_map = malloc(sizeof(int*) * fdf->max_y)))
		exit(EXIT_FAILURE);
	y = 0;
	while (y < fdf->max_y)
	{
		if (!(fdf->height_map[y] = malloc(sizeof(int) * fdf->max_x)))
			exit(EXIT_FAILURE);
		x = 0;
		while (x < fdf->max_x)
		{
			fdf->height_map[y][x] = fdf->height_map_src[j];
			x++;
			j++;
		}
		y++;
	}
	return (0);
}

int	ft_height_get(t_fdf *fdf, float *next_height)
{
	fdf->cur_height = fdf->height_map[(int)fdf->coords->y][(int)fdf->coords->x];
	*next_height = fdf->height_map[(int)fdf->coords->next_y]\
	[(int)fdf->coords->next_x];
	return (0);
}
