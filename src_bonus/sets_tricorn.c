/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sets_tricorn.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoulios <ngoulios@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 20:01:16 by ngoulios          #+#    #+#             */
/*   Updated: 2024/11/01 20:04:40 by ngoulios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int tricorn(t_fractal *f)
{
    t_complex z, c;
    uint32_t iter = 0;
    double z_real2, z_imag2, temp_real;

    z.real = 0.0;
    z.imaginary = 0.0;
    c = pixel_to_complex(f->pixel_x, f->pixel_y, f);
    while (iter < f->max_iter)
    {
        z_real2 = z.real * z.real;
        z_imag2 = z.imaginary * z.imaginary;
        if (z_real2 + z_imag2 > 4.0)
            break;
        temp_real = z_real2 - z_imag2 + c.real;
        z.imaginary = -2.0 * z.real * z.imaginary + c.imaginary;
        z.real = temp_real;
        iter++;
    }
    return (iter);
}

void tricorn_param(t_fractal *f)
{
    f->x_min = -2.0;
    f->x_max = 2.0;
    f->y_min = -2.0;
    f->y_max = 2.0;
    f->zoom = 1.0;
    f->fractal_func = &tricorn;
}
