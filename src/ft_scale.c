/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scale.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnidokin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 18:30:19 by mnidokin          #+#    #+#             */
/*   Updated: 2020/12/01 18:30:20 by mnidokin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_scale(t_fdf *fdf, int size)
{
	fdf->scale = size / (fdf->max_x + fdf->max_y);
	return (0);
}

int	ft_scale_coords(t_fdf *fdf)
{
	fdf->coords->x *= (float)fdf->scale;
	fdf->coords->y *= (float)fdf->scale;
	fdf->coords->next_x *= (float)fdf->scale;
	fdf->coords->next_y *= (float)fdf->scale;
	return (0);
}
