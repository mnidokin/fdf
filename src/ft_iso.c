/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iso.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnidokin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 18:29:36 by mnidokin          #+#    #+#             */
/*   Updated: 2020/12/01 18:30:00 by mnidokin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_iso_check(t_fdf *fdf, float next_height)
{
	if (fdf->iso_flag == 1)
	{
		ft_iso_calc(fdf->cur_height, &fdf->coords->x, &fdf->coords->y);
		ft_iso_calc(next_height, &fdf->coords->next_x, &fdf->coords->next_y);
	}
	return (0);
}

int	ft_iso_calc(float height, float *x, float *y)
{
	*x = (*x - *y) * cos(0.8);
	*y = (*x + *y) * sin(0.8) - height;
	return (0);
}
