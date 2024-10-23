/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoulios <ngoulios@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 17:06:36 by ngoulios          #+#    #+#             */
/*   Updated: 2024/10/23 17:34:06 by ngoulios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void init_fractal(t_fractal *fractal, mlx_image_t *img, mlx_t *mlx, int fractal_type, t_complex *julia_c)
{
    fractal->x_min = -2.0;
    fractal->x_max = 1.0;
    fractal->y_min = -1.5;
    fractal->y_max = 1.5;
    fractal->img = img;
    fractal->mlx = mlx;
    fractal->fractal_type = fractal_type;

    if (fractal_type == 0)
        fractal->fractal_func = &mandelbrot;
    else if (fractal_type == 1)
    {
        fractal->fractal_func = &julia;
        fractal->julia_real = julia_c->real;
        fractal->julia_imaginary = julia_c->imaginary;
    }
}
