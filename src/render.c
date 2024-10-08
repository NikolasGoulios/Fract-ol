/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoulios <ngoulios@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 16:55:51 by ngoulios          #+#    #+#             */
/*   Updated: 2024/10/08 17:15:06 by ngoulios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void set_mandelbrot_params(t_fractol *f)
{
   
    f->x_min = -2.0;
    f->x_max = 1.0;
    f->y_min = -1.5;
    f->y_max = 1.5;
    f->func = &mandelbrot; 
}

void set_julia_params(t_fractol *f)
{
    
    f->x_min = -2.0;
    f->x_max = 2.0;
    f->y_min = -2.0;
    f->y_max = 2.0;
    f->func = &julia; 
}

