/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnidokin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 18:29:13 by mnidokin          #+#    #+#             */
/*   Updated: 2020/12/01 18:30:07 by mnidokin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_draw(t_fdf *fdf)
{
	int x;
	int y;

	y = 0;
	while (y < fdf->max_y)
	{
		x = 0;
		while (x < fdf->max_x)
		{
			if (x < fdf->max_x - 1)
			{
				ft_draw_x_step(fdf, x, y);
				ft_draw_map(fdf);
			}
			if (y < fdf->max_y - 1)
			{
				ft_draw_y_step(fdf, x, y);
				ft_draw_map(fdf);
			}
			x++;
		}
		y++;
	}
	return (0);
}

int	ft_draw_x_step(t_fdf *fdf, int x, int y)
{
	fdf->coords->x = x;
	fdf->coords->y = y;
	fdf->coords->next_x = x + 1;
	fdf->coords->next_y = y;
	return (0);
}

int	ft_draw_y_step(t_fdf *fdf, int x, int y)
{
	fdf->coords->x = x;
	fdf->coords->y = y;
	fdf->coords->next_x = x;
	fdf->coords->next_y = y + 1;
	return (0);
}
