/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoulios <ngoulios@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 15:56:09 by ngoulios          #+#    #+#             */
/*   Updated: 2024/10/10 15:16:42 by ngoulios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void zoom_in(t_fractol *f)
{
    f->zoom *= 1.1; // Adjust the zoom factor as needed
}

void zoom_out(t_fractol *f)
{
    f->zoom /= 1.1; // Adjust the zoom factor as needed
}

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

void close_hook(void *param)
{
    t_fractol *f = (t_fractol *)param;
    mlx_terminate(f->mlx);
}

