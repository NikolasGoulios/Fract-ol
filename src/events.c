/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoulios <ngoulios@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 17:05:42 by ngoulios          #+#    #+#             */
/*   Updated: 2024/10/30 19:14:58 by ngoulios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	handle_key_arrow(void *param);
void	handle_key(mlx_key_data_t keydata, void *param);
void	handle_scroll(double xdelta, double ydelta, void *param);

void	setup_mlx_hooks(t_fractal *fractal)
{
	mlx_key_hook(fractal->mlx, handle_key, fractal);
	mlx_loop_hook(fractal->mlx, handle_key_arrow, fractal);
	mlx_scroll_hook(fractal->mlx, handle_scroll, fractal);
}

void	handle_key(mlx_key_data_t keydata, void *param)
{
	t_fractal	*fractal;

	fractal = (t_fractal *) param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		mlx_delete_image(fractal->mlx, fractal->img);
		mlx_close_window(fractal->mlx);
	}
	if (mlx_is_key_down(fractal->mlx, MLX_KEY_KP_SUBTRACT)
		&& fractal->max_iter > 5)
	{
		fractal->max_iter *= 0.9;
		draw_fractal(fractal);
		mlx_image_to_window(fractal->mlx, fractal->img, 0, 0);
	}
	else if (mlx_is_key_down(fractal->mlx, MLX_KEY_KP_ADD)
		&& fractal->max_iter < 100)
	{
		fractal->max_iter *= 1.1;
		draw_fractal(fractal);
		mlx_image_to_window(fractal->mlx, fractal->img, 0, 0);
	}
}

/* Arrow keys to move fractal view, with refresh */
void	handle_key_arrow(void *param)
{
	t_fractal	*fractal;
	double		real_delta;
	double		imag_delta;

	fractal = (t_fractal *) param;
	real_delta = fractal->x_max - fractal->x_min;
	imag_delta = fractal->y_max - fractal->y_min;
    if (mlx_is_key_down(fractal->mlx, MLX_KEY_RIGHT))
	{
		fractal->x_min += real_delta * fractal->move_step;
		fractal->x_max += real_delta * fractal->move_step;
	}
	if (mlx_is_key_down(fractal->mlx, MLX_KEY_LEFT))
	{
		fractal->x_min -= real_delta * fractal->move_step;
		fractal->x_max -= real_delta * fractal->move_step;
	}
	if (mlx_is_key_down(fractal->mlx, MLX_KEY_DOWN))
	{
		fractal->y_min -= imag_delta * fractal->move_step;
		fractal->y_max -= imag_delta * fractal->move_step;
	}
	if (mlx_is_key_down(fractal->mlx, MLX_KEY_UP))
	{
		fractal->y_min += imag_delta * fractal->move_step;
		fractal->y_max += imag_delta * fractal->move_step;
	}
	draw_fractal(fractal);
	mlx_image_to_window(fractal->mlx, fractal->img, 0, 0);
}

void	handle_scroll(double xdelta, double ydelta, void *param)
{
	t_fractal	*fractal;
	t_complex	mouse_pos;
	double		mouse_r;
	double		mouse_i;
	double		zoom;
	(void)xdelta;
	
	fractal = (t_fractal*)param;
    mlx_get_mouse_pos(fractal->mlx, &(fractal->pixel_x), &(fractal->pixel_y));
    mouse_pos = pixel_to_complex(fractal->pixel_x, fractal->pixel_y, fractal);
    mouse_r = mouse_pos.real;
    mouse_i = mouse_pos.imaginary;
	if (ydelta > 0)
		zoom = 0.9;
	else if (ydelta < 0)
		zoom = 1.1;
    else 
		return ;
    fractal->x_min = mouse_r + (fractal->x_min - mouse_r) * zoom;
	fractal->x_max = mouse_r + (fractal->x_max - mouse_r) * zoom;
	fractal->y_min = mouse_i + (fractal->y_min - mouse_i) * zoom;
	fractal->y_max = mouse_i + (fractal->y_max - mouse_i) * zoom;
	draw_fractal(fractal);
	mlx_image_to_window(fractal->mlx, fractal->img, 0, 0);
}

