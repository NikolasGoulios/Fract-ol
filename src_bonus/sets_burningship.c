/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sets_burningship.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoulios <ngoulios@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 19:44:10 by ngoulios          #+#    #+#             */
/*   Updated: 2024/11/03 16:59:49 by ngoulios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int	burning_ship(t_fractal *f)
{
	t_complex	z;
	t_complex	c;
	uint32_t	iter;
	double		z_real2;
	double		z_imag2;
	double		temp_real;

	iter = 0;
	z.real = 0.0;
	z.imaginary = 0.0;
	c = pixel_to_complex(f->pixel_x, f->pixel_y, f);
	while (iter < f->max_iter)
	{
		z_real2 = z.real * z.real;
		z_imag2 = z.imaginary * z.imaginary;
		if (z_real2 + z_imag2 > 4.0)
			break;
		temp_real = z_real2 - z_imag2 + c.real;
		z.imaginary = 2.0 * fabs(z.real * z.imaginary) + c.imaginary;
		z.real = fabs(temp_real);
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
