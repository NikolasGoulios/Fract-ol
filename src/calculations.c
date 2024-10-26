/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoulios <ngoulios@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 17:29:42 by ngoulios          #+#    #+#             */
/*   Updated: 2024/10/26 19:10:39 by ngoulios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex pixel_to_complex(int x, int y, t_fractal *f)
{
    t_complex c;
	x = (x < 0) ? 0 : (x >= WIDTH ? WIDTH - 1 : x); // Change it
    y = (y < 0) ? 0 : (y >= HEIGHT ? HEIGHT - 1 : y); // Change it
	
    double range_x = f->x_max - f->x_min;
    double range_y = f->y_max - f->y_min;
    
    c.real = f->x_min + (x * range_x / WIDTH) / f->zoom;
    if (f->fractal_type == 1)
		c.imaginary = f->y_min + (y * range_y / HEIGHT) / f->zoom;
	else 
		c.imaginary = f->y_max - (y * range_y / HEIGHT) / f->zoom;
    
    return c;
}