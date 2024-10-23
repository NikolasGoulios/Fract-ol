/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sets.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoulios <ngoulios@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 18:40:48 by ngoulios          #+#    #+#             */
/*   Updated: 2024/10/23 18:41:02 by ngoulios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// Fractal iteration logic, used by both Mandelbrot and Julia sets
int fractal_iteration(t_complex z, t_complex c, int max_iter)
{
    int iter = 0;
    
    while (z.real * z.real + z.imaginary * z.imaginary <= 4 && iter < max_iter)
    {
        double temp_real = z.real * z.real - z.imaginary * z.imaginary + c.real;
        z.imaginary = 2 * z.real * z.imaginary + c.imaginary;
        z.real = temp_real;
        iter++;
    }
    
    return iter;
}

// Mandelbrot fractal set function
int mandelbrot(t_fractal *f) 
{
    t_complex z = {0, 0};
    t_complex c = {f->x_min, f->y_min};
    
    return fractal_iteration(z, c, f->precision);
}

// Julia fractal set function
int julia(t_fractal *f) 
{
    t_complex z = {f->x_min, f->y_min};
    t_complex c = {f->julia_real, f->julia_imaginary};

    return fractal_iteration(z, c, f->precision);
}

// Initialize Mandelbrot parameters
void mandelbrot_param(t_fractal *f) 
{
    f->x_min = -2.0;
    f->x_max = 1.0;
    f->y_min = -1.5;
    f->y_max = 1.5;
    f->fractal_func = &mandelbrot;
}

// Initialize Julia parameters
void set_julia_params(t_fractal *f) 
{
    f->x_min = -2.0;
    f->x_max = 2.0;
    f->y_min = -2.0;
    f->y_max = 2.0;
    f->fractal_func = &julia; 
}
