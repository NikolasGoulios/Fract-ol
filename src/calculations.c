/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoulios <ngoulios@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 17:29:42 by ngoulios          #+#    #+#             */
/*   Updated: 2024/10/17 17:30:15 by ngoulios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex pixel_to_complex(int x, int y, t_fractal* fractal) 
{
    t_complex c;
    c.real = fractal->x_min + (x / (double)WIDTH) * (fractal->x_max - fractal->x_min);
    c.imaginary = fractal->y_min + (y / (double)HEIGHT) * (fractal->y_max - fractal->y_min);
    return c;
}