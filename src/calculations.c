/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoulios <ngoulios@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 17:29:42 by ngoulios          #+#    #+#             */
/*   Updated: 2024/11/01 17:47:59 by ngoulios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

t_complex	pixel_to_complex(int x, int y, t_fractal *f)
{
	t_complex	c;
	double		range_y;
	double		range_x;

	if (x < 0)
		x = 0;
	else if (x >= WIDTH)
		x = WIDTH - 1;
	if (y < 0)
		y = 0;
	else if (y >= HEIGHT)
		y = HEIGHT - 1;
	range_x = f->x_max - f->x_min;
	range_y = f->y_max - f->y_min;
	c.real = f->x_min + (x * range_x / WIDTH) / f->zoom;
	if (f->fractal_type == 1)
		c.imaginary = f->y_min + (y * range_y / HEIGHT) / f->zoom;
	else
		c.imaginary = f->y_max - (y * range_y / HEIGHT) / f->zoom;
	return (c);
}
