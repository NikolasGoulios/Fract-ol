/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoulios <ngoulios@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 17:03:11 by ngoulios          #+#    #+#             */
/*   Updated: 2024/10/26 19:00:12 by ngoulios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


void draw_fractal(t_fractal *fractal) 
{
    int y = 0;
    int x;
    int iterations;

    // Bounds checking to prevent buffer overflow
    if (!fractal->img || !fractal->mlx)
    {
        ft_printf("Error: Invalid image or MLX context\n");
        return;
    }

    while (y < HEIGHT) 
    {
        x = 0;
        while (x < WIDTH) 
        {
            fractal->pixel_x = x;
            fractal->pixel_y = y;

            // Safety check for function pointer
            if (fractal->fractal_func)
            {
                iterations = fractal->fractal_func(fractal);
                
                // Ensure valid iterations
                if (iterations >= 0 && iterations <= MAX_ITERATIONS)
                {
                    fractal->color = get_color(iterations, MAX_ITERATIONS, K_RED, K_GREEN, K_BLUE);
                    
                    // Bounds checking before putting pixel
                    if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
                    {
                        mlx_put_pixel(fractal->img, x, y, fractal->color);
                    }
                }
            }
            x++;
        }
        y++;
    }

    ft_printf("Fractal drawing completed successfully\n");
}
