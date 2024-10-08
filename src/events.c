/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoulios <ngoulios@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 17:26:22 by ngoulios          #+#    #+#             */
/*   Updated: 2024/10/08 17:32:50 by ngoulios         ###   ########.fr       */
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
        if (f->type == "MANDELBROT" || f->type == "Mandelbrot" || f->type == "mandelbrot")
            set_mandelbrot_params(f);
        else if (f->type == "JULIA" || f->type == "Julia" || f->type == "julia")
            set_julia_params(f);
        draw_fractals(f);
    }
}
void scroll_hook(double xdelta, double ydelta, void *param)
{
    t_fractol *f = (t_fractol *)param;

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
