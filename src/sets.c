/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sets.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoulios <ngoulios@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 18:40:48 by ngoulios          #+#    #+#             */
/*   Updated: 2024/10/29 18:15:24 by ngoulios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int fractal_iteration(t_complex z, t_complex c, int max_iter)
{
    int iter = 0;
    double z_real = z.real;
    double z_imag = z.imaginary;
    
	if (max_iter <= 0 || max_iter > MAX_ITERATIONS)
        max_iter = MAX_ITERATIONS;
		
    while (iter < max_iter)
    {
        double z_real2 = z_real * z_real;
        double z_imag2 = z_imag * z_imag;
        
        if (z_real2 + z_imag2 > 4.0)
            break;
            
        double temp_real = z_real2 - z_imag2 + c.real;
        z_imag = 2.0 * z_real * z_imag + c.imaginary;
        z_real = temp_real;
        
        iter++;
    }
    return iter;
}

int mandelbrot(t_fractal *f) 
{
    t_complex z = {0.0, 0.0};
    t_complex c = pixel_to_complex(f->pixel_x, f->pixel_y, f);
    return fractal_iteration(z, c, f->max_iter);
}

int julia(t_fractal *f) 
{
    t_complex z = pixel_to_complex(f->pixel_x, f->pixel_y, f);
    t_complex c = {f->julia_real, f->julia_imaginary};
    return fractal_iteration(z, c, f->max_iter);
}

void mandelbrot_param(t_fractal *f) 
{
    f->x_min = -2.0;
    f->x_max = 2.0;
    f->y_min = -2.0;
    f->y_max = 2.0;
    f->zoom = 1.0;
    f->max_iter = MAX_ITERATIONS;
    f->precision = MAX_ITERATIONS;
    f->fractal_func = &mandelbrot;
    f->mono_color = 0;
    //f->disco_mode = 0;
}

void set_julia_params(t_fractal *f) 
{
    f->x_min = -2.0;
    f->x_max = 2.0;
    f->y_min = -2.0;
    f->y_max = 2.0;
    f->zoom = 1.0;
    f->max_iter = MAX_ITERATIONS;
    f->precision = MAX_ITERATIONS;
    f->fractal_func = &julia;
    f->mono_color = 0;
    //f->disco_mode = 0;
}

