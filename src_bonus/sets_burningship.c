/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sets_burningship.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoulios <ngoulios@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 19:44:10 by ngoulios          #+#    #+#             */
/*   Updated: 2024/11/05 18:39:28 by ngoulios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

static t_complex	init_complex(double real, double imaginary);
static t_complex	update_burning_ship(t_complex z, t_complex c);
static int			has_escaped(t_complex z);

int	burning_ship(t_fractal *f)
{
	t_complex	z;
	t_complex	c;
	uint32_t	iter;

	z = init_complex(0.0, 0.0);
	c = pixel_to_complex(f->pixel_x, f->pixel_y, f);
	iter = 0;
	while (iter < f->max_iter && !has_escaped(z))
	{
		z = update_burning_ship(z, c);
		iter++;
	}
	return (iter);
}

void	burning_ship_param(t_fractal *f)
{
	f->x_min = -2.0;
	f->x_max = 2.0;
	f->y_min = 2.0;
	f->y_max = -2.0;
	f->zoom = 1.0;
	f->fractal_func = &burning_ship;
}

static t_complex	init_complex(double real, double imaginary)
{
	t_complex	complex;

	complex.real = real;
	complex.imaginary = imaginary;
	return (complex);
}

static int	has_escaped(t_complex z)
{
	double	z_real2;
	double	z_imag2;

	z_real2 = z.real * z.real;
	z_imag2 = z.imaginary * z.imaginary;
	return (z_real2 + z_imag2 > 4.0);
}

static t_complex	update_burning_ship(t_complex z, t_complex c)
{
	double	z_real2;
	double	z_imag2;
	double	temp_real;

	z_real2 = z.real * z.real;
	z_imag2 = z.imaginary * z.imaginary;
	temp_real = z_real2 - z_imag2 + c.real;
	z.imaginary = 2.0 * fabs(z.real * z.imaginary) + c.imaginary;
	z.real = fabs(temp_real);
	return (z);
}
