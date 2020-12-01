/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnidokin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 18:29:46 by mnidokin          #+#    #+#             */
/*   Updated: 2020/12/01 20:35:40 by mnidokin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_key(int key, t_fdf *fdf)
{
	if (key == KEY_ESC)
		exit(0);
	if (key == KEY_I)
		fdf->iso_flag = 1;
	if (key == KEY_O)
		fdf->iso_flag = 0;
	if (key == AR_UP)
		fdf->offset_y -= 10;
	if (key == AR_DOWN)
		fdf->offset_y += 10;
	if (key == AR_RIGHT)
		fdf->offset_x += 10;
	if (key == AR_LEFT)
		fdf->offset_x -= 10;
	if (key == MAIN_PAD_MINUS)
		fdf->scale -= 10;
	if (key == MAIN_PAD_PLUS)
		fdf->scale += 10;
	ft_key_angle(key, fdf);
	mlx_clear_window(fdf->mlx_ptr, fdf->window);
	ft_draw(fdf);
	return (0);
}

int		ft_key_angle(int key, t_fdf *fdf)
{
	if (key == KEY_Q)
		fdf->alpha += 100 * 0.002;
	if (key == KEY_W)
		fdf->beta += 100 * 0.002;
	if (key == KEY_E)
		fdf->gamma += 100 * 0.002;
	if (key == KEY_A)
		fdf->alpha -= 100 * 0.002;
	if (key == KEY_S)
		fdf->beta -= 100 * 0.002;
	if (key == KEY_D)
		fdf->gamma -= 100 * 0.002;
	if (key == KEY_R)
		fdf->alpha = 0;
	if (key == KEY_T)
		fdf->beta = 0;
	if (key == KEY_Y)
		fdf->gamma = 0;
	return (0);
}
