/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoulios <ngoulios@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 17:03:11 by ngoulios          #+#    #+#             */
/*   Updated: 2024/10/19 14:07:46 by ngoulios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void draw_fractal(t_fractal *fractal) 
{
    // Debug output can be left commented for performance
    // printf("Drawing fractal...\n");  

    int y, x, iterations;
    y = 0;
    while (y < HEIGHT) 
	{
        x = 0;
        while (x < WIDTH) 
		{
			// Map the pixel (x, y) to the complex plane based on the current bounds
			t_complex c = pixel_to_complex(x, y, fractal);
            fractal->x0 = c.real;
            fractal->y0 = c.imaginary;

            // Call the appropriate fractal function (Mandelbrot or Julia)
            iterations = fractal->fractal_func(fractal);

            // Set the pixel color based on iterations
            uint32_t color = get_color(iterations);
            mlx_put_pixel(fractal->img, x, y, color);

            x++;
        }
        y++;
    }

    // Optional debugging output
    printf("Fractal drawing complete!\n");
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

int mandelbrot(t_fractal *f) 
{
    //printf("Mandelbrot function called for x0: %f, y0: %f\n", f->x0, f->y0);
    t_complex z = {0, 0};
    t_complex c = {f->x0, f->y0};
    
    int result = fractal_iteration(z, c, f->precision);
    //printf("Mandelbrot iterations: %d\n", result);
    return result;
}


int julia(t_fractal *f) 
{
    //printf("Julia function called for x0: %f, y0: %f, julia_real: %f, julia_imaginary: %f\n", f->x0, f->y0, f->julia_real, f->julia_imaginary);
    t_complex z = {f->x0, f->y0};
    t_complex c = {f->julia_real, f->julia_imaginary};

    int result = fractal_iteration(z, c, f->precision);
    //printf("Julia iterations: %d\n", result);
    return result;
}


void mandelbrot_param(t_fractal *f) 
{
    f->x_min = -2.0;
    f->x_max = 1.0;
    f->y_min = -1.5;
    f->y_max = 1.5;
    f->fractal_func = &mandelbrot;
}

void set_julia_params(t_fractal *f) 
{
    f->x_min = -2.0;
    f->x_max = 2.0;
    f->y_min = -2.0;
    f->y_max = 2.0;
    f->fractal_func = &julia; 
}
