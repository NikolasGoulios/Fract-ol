/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoulios <ngoulios@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 17:03:11 by ngoulios          #+#    #+#             */
/*   Updated: 2024/10/31 18:15:34 by ngoulios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


void draw_fractal(t_fractal *fractal)
{
    int y = 0;
    int x;
    uint32_t iterations;

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
            if (fractal->fractal_func)
            {
                iterations = fractal->fractal_func(fractal);
                if (iterations <= fractal->max_iter)
                {
                    fractal->color = get_color(iterations, fractal->max_iter, fractal);
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
}
