/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoulios <ngoulios@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 15:55:31 by ngoulios          #+#    #+#             */
/*   Updated: 2024/10/10 15:54:11 by ngoulios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int initialize_fractal(t_fractol *f)
{
    f->mlx = mlx_init(WIDTH, HEIGHT, "Fractol", true);
    if (!f->mlx)
        return (ft_printf("ERROR_INIT"));

    f->image = mlx_new_image(f->mlx, WIDTH, HEIGHT);
    if (!f->image)
        return (cleanup(f));
    if (strcmp(f->type, "Mandelbrot") == 0)
        set_mandelbrot_params(f);
    else if (strcmp(f->type, "Julia") == 0)
        set_julia_params(f);

    return (0);
}

void draw_pixel(t_fractol *f, int x, int y)
{
    f->y0 = (HEIGHT - y) * (f->y_max - f->y_min) / HEIGHT + f->y_min;
    f->x0 = x * (f->x_max - f->x_min) / WIDTH + f->x_min;
    f->color = color_generator(f->func(f), f);
    mlx_put_pixel(f->image, x, y, f->color);
}

void draw_fractals(void *param)
{
    t_fractol *f = (t_fractol *)param;
    if (f->disco_mode > 0)
        get_random_colors(f);
    for (int y = 0; y < HEIGHT; y++)
    {
        for (int x = 0; x < WIDTH; x++)
        {
            draw_pixel(f, x, y);
        }
    }
    mlx_image_to_window(f->mlx, f->image, 0, 0);
}

int cleanup(t_fractol *f)
{
    if (f->image)
        mlx_delete_image(f->mlx, f->image);
    if (f->mlx)
    {
        mlx_close_window(f->mlx);
        mlx_terminate(f->mlx);
    }
    return (1);
}