/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_offset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnidokin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 18:29:50 by mnidokin          #+#    #+#             */
/*   Updated: 2020/12/01 18:29:59 by mnidokin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_offset(t_fdf *fdf)
{
	fdf->coords->x += fdf->offset_x;
	fdf->coords->next_x += fdf->offset_x;
	fdf->coords->y += fdf->offset_y;
	fdf->coords->next_y += fdf->offset_y;
	return (0);
}
