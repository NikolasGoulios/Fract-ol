/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoulios <ngoulios@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 17:05:42 by ngoulios          #+#    #+#             */
/*   Updated: 2024/10/23 19:00:36 by ngoulios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/* General key hook function to handle closing the window and adjusting max iterations. */
void handle_key(mlx_key_data_t keydata, void* param) 
{
    t_fractal* fractal = (t_fractal*)param;

    // Handle closing the window with ESC key
    if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS) 
    {
        mlx_delete_image(fractal->mlx, fractal->img);
        mlx_close_window(fractal->mlx);
    }

    // Adjust the max number of iterations with +/- keys
    if (mlx_is_key_down(fractal->mlx, MLX_KEY_KP_SUBTRACT) && fractal->precision > 5) 
    {
        fractal->precision *= 0.9;  // Reduce iterations
    }
    if (mlx_is_key_down(fractal->mlx, MLX_KEY_KP_ADD) && fractal->precision < 500) 
    {
        fractal->precision *= 1.1;  // Increase iterations
    }
}

/* Key hook function to modify the Julia set's constant (julia_c). */
void handle_key_julia(void* param) 
{
    t_fractal* fractal = (t_fractal*)param;

    if (mlx_is_key_down(fractal->mlx, MLX_KEY_LEFT_CONTROL)) 
    {
        if (mlx_is_key_down(fractal->mlx, MLX_KEY_LEFT_SHIFT))
            fractal->julia_c.real *= 0.9;  // Adjust real part of Julia constant
        else
            fractal->julia_c.real *= 1.1;
    }
    if (mlx_is_key_down(fractal->mlx, MLX_KEY_RIGHT_CONTROL)) 
    {
        if (mlx_is_key_down(fractal->mlx, MLX_KEY_RIGHT_SHIFT))
            fractal->julia_c.imaginary *= 0.9;  // Adjust imaginary part of Julia constant
        else
            fractal->julia_c.imaginary *= 1.1;
    }
}

/* Key hook function to move the fractal view using arrow keys. */
void handle_key_arrow(void* param) 
{
    t_fractal* fractal = (t_fractal*)param;
    double real_delta = fractal->x_max - fractal->x_min;
    double imag_delta = fractal->y_max - fractal->y_min;
	double move_step = 0.1;  // The percentage of the current view range to move
	
    if (mlx_is_key_down(fractal->mlx, MLX_KEY_RIGHT)) 
    {
        fractal->x_min += real_delta * move_step;
        fractal->x_max += real_delta * move_step;
    }
    if (mlx_is_key_down(fractal->mlx, MLX_KEY_LEFT)) 
    {
        fractal->x_min -= real_delta * move_step;
        fractal->x_max -= real_delta * move_step;
    }
    if (mlx_is_key_down(fractal->mlx, MLX_KEY_DOWN)) 
    {
        fractal->y_min -= imag_delta * move_step;
        fractal->y_max -= imag_delta * move_step;
    }
    if (mlx_is_key_down(fractal->mlx, MLX_KEY_UP)) 
    {
        fractal->y_min += imag_delta * move_step;
        fractal->y_max += imag_delta * move_step;
    }
}

/* Scroll hook function to handle zooming in and out. */
void handle_scroll(double xdelta, double ydelta, void* param) 
{
    t_fractal* fractal = (t_fractal*)param;
    double mouse_r, mouse_i, zoom;

    (void) xdelta;  // Unused, we only care about vertical scrolling
    mlx_get_mouse_pos(fractal->mlx, &(fractal->pixel_x), &(fractal->pixel_y));
    pixel_to_complex(&mouse_r, &mouse_i, fractal);

    if (ydelta > 0)
        zoom = 0.9;  // Zoom in
    else if (ydelta < 0)
        zoom = 1.1;  // Zoom out
    else
        return;

    fractal->x_min = mouse_r + (fractal->x_min - mouse_r) * zoom;
    fractal->x_max = mouse_r + (fractal->x_max - mouse_r) * zoom;
    fractal->y_min = mouse_i + (fractal->y_min - mouse_i) * zoom;
    fractal->y_max = mouse_i + (fractal->y_max - mouse_i) * zoom;
}
