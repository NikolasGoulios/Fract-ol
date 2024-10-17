/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoulios <ngoulios@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 17:03:11 by ngoulios          #+#    #+#             */
/*   Updated: 2024/10/17 18:06:32 by ngoulios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void draw_fractal(t_fractal *fractal, int fractal_type, t_complex julia_c) {
    int y;
	int iterations;
	
	y = 0;
    while (y < HEIGHT) 
	{
        int x = 0;
        while (x < WIDTH) 
		{
            t_complex z = pixel_to_complex(x, y, fractal);
            if (fractal_type == 0) 
                iterations = mandelbrot(z);
			else 
                iterations = julia(z, julia_c);
            uint32_t color = get_color(iterations);

            mlx_put_pixel(fractal->img, x, y, color);
            x++;
        }
        y++;
    }
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
/*int julia(t_complex z, t_complex c) {
    int iterations = 0;

    while (iterations < MAX_ITERATIONS) {
        // Calculate z^2 + c
        double real_temp = z.real * z.real - z.imaginary * z.imaginary + c.real;
        z.imaginary = 2.0 * z.real * z.imaginary + c.imaginary;
        z.real = real_temp;

        // Check if modulus exceeds 2 (escape condition)
        if ((z.real * z.real + z.imaginary * z.imaginary) > 4.0) {
            return iterations; // Point escapes
        }
        iterations++;
    }

    return MAX_ITERATIONS; // Point is in the Julia set
}*/

int julia(t_fractal *f)
{
    t_complex z = {f->x0, f->y0};
    t_complex c = f->julia_real; // Julia set constant
    return fractal_iteration(z, c, f->precision);
}
int mandelbrot(t_fractal *f)
{
    t_complex z = {0, 0};
    t_complex c = {f->x0, f->y0};
    return fractal_iteration(z, c, f->precision);
}

void mandelbrot_param(t_fractal *f)
{
        f ->x_min = -2.0;
		f ->x_max = 1.0;
        f ->y_min = -1.5;
		f ->y_max = 1.5;
        f ->func = &mandelbrot;
}
void set_julia_params(t_fractal *f)
{
    
    f->x_min = -2.0;
    f->x_max = 2.0;
    f->y_min = -2.0;
    f->y_max = 2.0;
    f->func = &julia; 
}
