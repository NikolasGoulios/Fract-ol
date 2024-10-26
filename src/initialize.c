/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoulios <ngoulios@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 17:06:36 by ngoulios          #+#    #+#             */
/*   Updated: 2024/10/26 18:57:09 by ngoulios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void init_fractal(t_fractal *fractal, t_complex *julia_c)
{
    // Initialize common parameters
    fractal->max_iter = MAX_ITERATIONS;
    fractal->zoom = 1.0;
    fractal->color = 0;
    fractal->red = K_RED;
    fractal->grn = K_GREEN;
    fractal->blu = K_BLUE;
    fractal->a = 255;
    fractal->mono_color = 0;
    fractal->disco_mode = 0;

    if (fractal->fractal_type == 1)
    {
        mandelbrot_param(fractal);
    }
    else if (fractal->fractal_type == 2)
    {
        set_julia_params(fractal);
        fractal->julia_real = julia_c->real;
        fractal->julia_imaginary = julia_c->imaginary;
    }
}