/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoulios <ngoulios@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 17:26:22 by ngoulios          #+#    #+#             */
/*   Updated: 2024/10/10 15:11:13 by ngoulios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void keyboard_hooks(mlx_key_data_t keydata, void *param)
{
    t_fractol *f = (t_fractol *)param;

    if (keydata.key == MLX_KEY_ESCAPE) // Close window
        mlx_close_window(f->mlx);
    else if (keydata.key == MLX_KEY_R) // Reset fractal
    {
        if (strcmp(f->type, "MANDELBROT") == 0 || strcmp(f->type, "Mandelbrot") == 0 || strcmp(f->type, "mandelbrot") == 0)
            set_mandelbrot_params(f);
        else if (strcmp(f->type, "JULIA") == 0 || strcmp(f->type, "Julia") == 0 || strcmp(f->type, "julia") == 0)
            set_julia_params(f);
        draw_fractals(f);
    }
}
void scroll_hook(double xdelta, double ydelta, void *param)
{
    t_fractol *f = (t_fractol *)param;

	(void) xdelta;
    if (ydelta > 0) // Zoom in
        f->zoom *= 1.1;
    else if (ydelta < 0) // Zoom out
        f->zoom /= 1.1;

    draw_fractals(f); // Redraw the fractal after zooming
}
void close_hook(void *param)
{
    t_fractol *f = (t_fractol *)param;
    mlx_terminate(f->mlx);
}
