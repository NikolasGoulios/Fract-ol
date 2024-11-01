/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sets_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoulios <ngoulios@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 18:40:48 by ngoulios          #+#    #+#             */
/*   Updated: 2024/11/01 19:45:36 by ngoulios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int	fractal_iteration(t_complex z, t_complex c, uint32_t max_iter)
{
	uint32_t	iter;
	double		z_real2;
	double		z_imag2;
	double		temp_real;

	iter = 0;
	if (iter > max_iter)
		iter = max_iter;
	while (iter < max_iter)
	{
		z_real2 = z.real * z.real;
		z_imag2 = z.imaginary * z.imaginary;
		if (z_real2 + z_imag2 > 4.0)
			break ;
		temp_real = z_real2 - z_imag2 + c.real;
		z.imaginary = 2.0 * z.real * z.imaginary + c.imaginary;
		z.real = temp_real;
		iter++;
	}
	return (iter);
}

int	mandelbrot(t_fractal *f)
{
	t_complex	z;
	t_complex	c;

	z.real = 0.0;
	z.imaginary = 0.0;
	c = pixel_to_complex(f->pixel_x, f->pixel_y, f);
	return (fractal_iteration(z, c, f->max_iter));
}

int	julia(t_fractal *f)
{
	t_complex	z;
	t_complex	c;

	z = pixel_to_complex(f->pixel_x, f->pixel_y, f);
	c.real = f->julia_real;
	c.imaginary = f->julia_imaginary;
	return (fractal_iteration(z, c, f->max_iter));
}

void	mandelbrot_param(t_fractal *f)
{
	f->x_min = -2.0;
	f->x_max = 2.0;
	f->y_min = -2.0;
	f->y_max = 2.0;
	f->zoom = 1.0;
	f->fractal_func = &mandelbrot;
}

void	set_julia_params(t_fractal *f)
{
	f->x_min = -2.0;
	f->x_max = 2.0;
	f->y_min = -2.0;
	f->y_max = 2.0;
	f->zoom = 1.0;
	f->fractal_func = &julia;
}
