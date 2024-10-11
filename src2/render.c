/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoulios <ngoulios@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 22:23:11 by ngoulios          #+#    #+#             */
/*   Updated: 2024/10/11 13:52:46 by ngoulios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int calculate_fractal(t_fractol *f, t_complex z, t_complex c)
{
	int     i;
	double  magnitude_squared;

	i = 0;
	while (i < f->precision)
	{
		z = ft_complex_sum(ft_complex_square(z), c);
		magnitude_squared = z.real * z.real + z.imaginary * z.imaginary;
		if (magnitude_squared > 4.0)
		{
			return i * f->mono_color;
		}
		i++;
	}
	return i;
}

int is_in_julia(t_fractol *f)
{
	t_complex z = {f->x0, f->y0};
	t_complex c = {f->julia_real, f->julia_imaginary};
	return calculate_fractal(f, z, c);
}

int is_in_mandelbrot(t_fractol *f)
{
	t_complex z = {0, 0};
	t_complex c = {f->x0, f->y0};
	return calculate_fractal(f, z, c);
}
