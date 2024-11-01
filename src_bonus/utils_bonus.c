/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoulios <ngoulios@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 16:02:35 by ngoulios          #+#    #+#             */
/*   Updated: 2024/11/01 18:22:57 by ngoulios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	print_usage(void)
{
	ft_putstr(
		"============================================================\n"
		"                      FRACTOL PROGRAM                        \n"
		"============================================================\n"
		"                   Choose Your Fractal!                     \n"
		"------------------------------------------------------------\n"
		" Usage: ./fractol [fractal_name] [Complex Plane]\n\n"
		" Fractals:\n"
		"  - mandelbrot : Default Mandelbrot set\n"
		"  - julia      : Julia set with custom parameters\n\n"
		" Examples:\n"
		"  - ./fractol mandelbrot\n"
		"  - ./fractol julia -0.5 0.4\n\n"
		" Controls:\n"
		"  - ESC   : Exit program\n"
		"  - R     : Reset to default view\n"
		"------------------------------------------------------------\n"
		"                      Have Fun Exploring!                    \n"
		"============================================================\n");
}

void	cleanup_fractal(t_fractal *fractal)
{
	if (fractal->img)
	{
		mlx_delete_image(fractal->mlx, fractal->img);
		fractal->img = NULL;
	}
	if (fractal->mlx)
	{
		mlx_terminate(fractal->mlx);
		fractal->mlx = NULL;
	}
	else if (fractal)
	{
		free(fractal);
		fractal = NULL;
	}
	ft_printf(CLEAN_COMPLETE);
}
