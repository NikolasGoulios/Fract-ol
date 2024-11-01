/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoulios <ngoulios@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 17:03:11 by ngoulios          #+#    #+#             */
/*   Updated: 2024/11/01 18:22:47 by ngoulios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

static void	draw_pixel(t_fractal *fractal, int x, int y);

void	draw_fractal(t_fractal *fractal)
{
	int	y;
	int	x;

	if (!fractal->img || !fractal->mlx)
		cleanup_fractal(fractal);
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			draw_pixel(fractal, x, y);
			x++;
		}
		y++;
	}
}

static void	draw_pixel(t_fractal *fractal, int x, int y)
{
	uint32_t	iterations;

	fractal->pixel_x = x;
	fractal->pixel_y = y;
	if (fractal->fractal_func)
	{
		iterations = fractal->fractal_func(fractal);
		if (iterations <= fractal->max_iter)
		{
			fractal->color = get_color(iterations, fractal->max_iter, fractal);
			if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
				mlx_put_pixel(fractal->img, x, y, fractal->color);
		}
	}
}
