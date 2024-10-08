/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoulios <ngoulios@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 15:56:09 by ngoulios          #+#    #+#             */
/*   Updated: 2024/10/08 17:57:29 by ngoulios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void keyboard_hooks(mlx_key_data_t keydata, void *param)
{
    t_fractol *f = (t_fractol *)param;

    if (keydata.key == MLX_KEY_ESCAPE)
        mlx_close_window(f->mlx);
    else if (keydata.key == MLX_KEY_Z)
        zoom_in(f); 
    else if (keydata.key == MLX_KEY_X)
        zoom_out(f); 
}

void scroll_hook(double ydelta, void *param)
{

    t_fractol *f = (t_fractol *)param;

    if (ydelta > 0) 
        f->zoom *= 1.1;
    else if (ydelta < 0)
        f->zoom /= 1.1;

    draw_fractals(f);
}


void close_hook(void *param)
{
    t_fractol *f = (t_fractol *)param;
    mlx_terminate(f->mlx);
}
