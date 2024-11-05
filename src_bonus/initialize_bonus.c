/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoulios <ngoulios@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 17:06:36 by ngoulios          #+#    #+#             */
/*   Updated: 2024/11/05 15:09:31 by ngoulios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	init_fractal(t_fractal *fractal, t_complex *julia_c)
{
	fractal->zoom = 1.0;
	fractal->color = 0;
	fractal->red = K_RED;
	fractal->green = K_GREEN;
	fractal->blue = K_BLUE;
	fractal->a = 255;
	if (fractal->fractal_type == 1)
		mandelbrot_param(fractal);
	else if (fractal->fractal_type == 2)
	{
		set_julia_params(fractal);
		fractal->julia_real = julia_c->real;
		fractal->julia_imaginary = julia_c->imaginary;
	}
	else if (fractal->fractal_type == 3)
		burning_ship_param(fractal);
	fractal->move_step = 0.025;
	fractal->max_iter = 99;
}
