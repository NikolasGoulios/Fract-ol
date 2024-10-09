/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoulios <ngoulios@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 15:54:04 by ngoulios          #+#    #+#             */
/*   Updated: 2024/10/09 13:50:10 by ngoulios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int	main(int argc, char **argv)
{
	t_fractol	f;

	if (argc < 2 || !is_valid(&f, argc, argv))
		return (print_usage());
	if (!initialize_fractal(&f))
		return (ft_printf(ERROR_INIT));
	mlx_key_hook(f.mlx, &keyboard_hooks, &f);
	mlx_close_hook(f.mlx, &close_hook, &f);
	mlx_scroll_hook(f.mlx, &scroll_hook, &f);
	mlx_loop_hook(f.mlx, draw_fractals, &f);
	mlx_loop(f.mlx);
	mlx_terminate(f.mlx);
	return (0);
}