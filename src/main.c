/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnidokin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 18:30:25 by mnidokin          #+#    #+#             */
/*   Updated: 2020/12/01 18:31:49 by mnidokin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int ac, char **av)
{
	t_fdf	*fdf;

	ft_error_touch_map(ac, av[1]);
	if (!(fdf = malloc(sizeof(t_fdf) * 1)))
		exit(EXIT_FAILURE);
	ft_read(av[1], fdf);
	fdf->mlx_ptr = mlx_init();
	fdf->window = mlx_new_window(fdf->mlx_ptr, 1000, 1000, "FDF");
	ft_scale(fdf, 1000);
	fdf->offset_x = 200;
	fdf->offset_y = 200;
	if (!(fdf->coords = malloc(sizeof(t_coords) * 1)))
		exit(EXIT_FAILURE);
	fdf->alpha = 0;
	fdf->beta = 0;
	fdf->gamma = 0;
	ft_draw(fdf);
	mlx_key_hook(fdf->window, ft_key, fdf);
	mlx_loop(fdf->mlx_ptr);
}
