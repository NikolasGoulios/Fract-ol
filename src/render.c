/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoulios <ngoulios@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 17:03:11 by ngoulios          #+#    #+#             */
/*   Updated: 2024/10/23 18:43:01 by ngoulios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/* This function maps the pixel coordinates to complex number */
t_complex pixel_to_complex(int x, int y, t_fractal *fractal)
{
    t_complex c;

    c.real = fractal->x_min + (x * (fractal->x_max - fractal->x_min) / WIDTH);
    c.imaginary = fractal->y_min + (y * (fractal->y_max - fractal->y_min) / HEIGHT);
    
    return c;
}

/* Render the fractal by iterating over each pixel and applying the fractal function */
void	draw_fractal(t_fractal *fractal) 
{
    int y = 0;
    int x;
    int iterations;
    uint32_t color;
    t_complex c;

    while (y < HEIGHT) 
	{
        x = 0;
        while (x < WIDTH) 
		{
            // Map the pixel (x, y) to the complex plane based on current bounds
            c = pixel_to_complex(x, y, fractal);
            fractal->x_min = c.real;
            fractal->y_min = c.imaginary;

            // Call the appropriate fractal function (Mandelbrot or Julia)
            iterations = fractal->fractal_func(fractal);

            // Set the pixel color based on iterations
            color = get_color(iterations);
            mlx_put_pixel(fractal->img, x, y, color);

            x++;
        }
        y++;
    }

    ft_printf("Fractal drawing complete!\n");
}
