/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoulios <ngoulios@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 16:55:51 by ngoulios          #+#    #+#             */
/*   Updated: 2024/10/08 17:39:42 by ngoulios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void set_mandelbrot_params(t_fractol *f)
{
   
    f->x_min = -2.0;
    f->x_max = 1.0;
    f->y_min = -1.5;
    f->y_max = 1.5;
    f->func = &mandelbrot; 
}

void set_julia_params(t_fractol *f)
{
    
    f->x_min = -2.0;
    f->x_max = 2.0;
    f->y_min = -2.0;
    f->y_max = 2.0;
    f->func = &julia; 
}

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

int mandelbrot(t_fractol *f)
{
    t_complex z = {0, 0};
    t_complex c = {f->x0, f->y0};
    return fractal_iteration(z, c, f->precision);
}

int julia(t_fractol *f)
{
    t_complex z = {f->x0, f->y0};
    t_complex c = f->real; // Julia set constant
    return fractal_iteration(z, c, f->precision);
}

