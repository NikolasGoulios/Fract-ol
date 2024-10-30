/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoulios <ngoulios@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 17:05:42 by ngoulios          #+#    #+#             */
/*   Updated: 2024/10/30 13:20:04 by ngoulios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void setup_mlx_hooks(mlx_t *mlx, t_fractal *fractal)
{
    mlx_key_hook(mlx, handle_key, fractal);
    mlx_scroll_hook(mlx, handle_scroll, fractal);
}

/* General key hook function for precision adjustments and window close. */
void handle_key(mlx_key_data_t keydata, void* param) 
{
    t_fractal* fractal = (t_fractal*)param;
    if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS) 
    {
        mlx_delete_image(fractal->mlx, fractal->img);
        mlx_close_window(fractal->mlx);
    }
    else if (mlx_is_key_down(fractal->mlx, MLX_KEY_KP_SUBTRACT) && fractal->precision > 5) 
    {
        fractal->precision -= 5;
        draw_fractal(fractal);
        mlx_image_to_window(fractal->mlx, fractal->img, 0, 0);
    }
    else if (mlx_is_key_down(fractal->mlx, MLX_KEY_KP_ADD) && fractal->precision < 500) 
    {
        fractal->precision += 5;
        draw_fractal(fractal);
        mlx_image_to_window(fractal->mlx, fractal->img, 0, 0);
    }
}

/* Arrow keys to move fractal view, with refresh */
void handle_key_arrow(void* param) 
{
    t_fractal* fractal = (t_fractal*)param;
    double real_delta = fractal->x_max - fractal->x_min;
    double imag_delta = fractal->y_max - fractal->y_min;
    double move_step = 0.1;

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
    draw_fractal(fractal);
    mlx_image_to_window(fractal->mlx, fractal->img, 0, 0);
}

/* Zoom in/out with redraw */
void handle_scroll(double xdelta, double ydelta, void* param)
{
    t_fractal* fractal = (t_fractal*)param;
    double mouse_r, mouse_i, zoom;

    (void)xdelta;
    mlx_get_mouse_pos(fractal->mlx, &(fractal->pixel_x), &(fractal->pixel_y));
    t_complex mouse_pos = pixel_to_complex(fractal->pixel_x, fractal->pixel_y, fractal);
    mouse_r = mouse_pos.real;
    mouse_i = mouse_pos.imaginary;

    zoom = (ydelta > 0) ? 0.9 : (ydelta < 0) ? 1.1 : 1.0;
    if (zoom != 1.0)
    {
        fractal->x_min = mouse_r + (fractal->x_min - mouse_r) * zoom;
        fractal->x_max = mouse_r + (fractal->x_max - mouse_r) * zoom;
        fractal->y_min = mouse_i + (fractal->y_min - mouse_i) * zoom;
        fractal->y_max = mouse_i + (fractal->y_max - mouse_i) * zoom;
        draw_fractal(fractal);
        mlx_image_to_window(fractal->mlx, fractal->img, 0, 0);
    }
}
