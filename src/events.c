/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoulios <ngoulios@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 17:05:42 by ngoulios          #+#    #+#             */
/*   Updated: 2024/10/19 14:06:28 by ngoulios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void handle_key(mlx_key_data_t keydata, void* param) 
{
    t_fractal* fractal = (t_fractal*)param;
    double move_factor = 0.1 * (fractal->x_max - fractal->x_min);
    int moved = 0;

    if ((keydata.key == MLX_KEY_LEFT || keydata.key == MLX_KEY_RIGHT || 
         keydata.key == MLX_KEY_UP || keydata.key == MLX_KEY_DOWN) && 
         (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT)) 
	{

        if (keydata.key == MLX_KEY_LEFT) 
		{
            fractal->x_min -= move_factor;
            fractal->x_max -= move_factor;
            moved = 1;
        } 
        else if (keydata.key == MLX_KEY_RIGHT) 
		{
            fractal->x_min += move_factor;
            fractal->x_max += move_factor;
            moved = 1;
        } 
        else if (keydata.key == MLX_KEY_UP) 
		{
            fractal->y_min -= move_factor;
            fractal->y_max -= move_factor;
            moved = 1;
        } 
        else if (keydata.key == MLX_KEY_DOWN) 
		{
            fractal->y_min += move_factor;
            fractal->y_max += move_factor;
            moved = 1;
        }

        if (moved) 
		{
            draw_fractal(fractal);
            mlx_image_to_window(fractal->mlx, fractal->img, 0, 0);
        }
    }
	
    if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS) 
	{
        mlx_close_window(fractal->mlx);
    }
}


void handle_scroll(double x_offset, double y_offset, void* param) 
{
	(void) x_offset;
    t_fractal* fractal = (t_fractal*)param;

    double zoom_factor = (y_offset > 0) ? 0.9 : 1.1;
    double real_center = (fractal->x_min + fractal->x_max) / 2;
    double imaginary_center = (fractal->y_min + fractal->y_max) / 2;
    double real_range = (fractal->x_max - fractal->x_min) * zoom_factor;
    double imaginary_range = (fractal->y_max - fractal->y_min) * zoom_factor;

    fractal->x_min = real_center - real_range / 2;
    fractal->x_max = real_center + real_range / 2;
    fractal->y_min = imaginary_center - imaginary_range / 2;
    fractal->y_max = imaginary_center + imaginary_range / 2;
    mlx_delete_image(fractal->mlx, fractal->img);

    // Create a new image for the updated fractal
    fractal->img = mlx_new_image(fractal->mlx, WIDTH, HEIGHT);

    // Redraw the fractal with new zoom settings
    draw_fractal(fractal);

    // Push the new image to the window
    mlx_image_to_window(fractal->mlx, fractal->img, 0, 0);

    // Debug print
    printf("Zoom updated bounds: x_min = %f, x_max = %f, y_min = %f, y_max = %f\n", fractal->x_min, fractal->x_max, fractal->y_min, fractal->y_max);
}

void handle_close(mlx_key_data_t keydata, void *param) 
{
    if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS) 
		mlx_close_window((mlx_t*)param);
}

void window_close_hook(void *param) 
{
    mlx_terminate((mlx_t*)param);
}
