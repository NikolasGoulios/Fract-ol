/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoulios <ngoulios@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 22:22:55 by ngoulios          #+#    #+#             */
/*   Updated: 2024/10/11 13:33:19 by ngoulios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "fractol.h"

int	main(int argc, char **argv)
{
	t_fractol	f;

	if (argc < 2 || !is_valid(&f, argc, argv))
		print_usage();
	if (initialize_fractol(&f))
		return (1);
	mlx_key_hook(f.mlx, &on_keyboard, &f);
	mlx_close_hook(f.mlx, &on_close, &f);
	mlx_scroll_hook(f.mlx, &on_scroll, &f);
	mlx_loop_hook(f.mlx, draw_fractals, &f);
	mlx_loop(f.mlx);
	mlx_terminate(f.mlx);
	return (0);
}
