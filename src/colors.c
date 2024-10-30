/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoulios <ngoulios@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 14:11:53 by ngoulios          #+#    #+#             */
/*   Updated: 2024/10/30 19:01:49 by ngoulios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

uint32_t	get_color(uint32_t iterations,
						uint32_t max_iterations, t_fractal *f)
{
	double		t;
	uint8_t		r;
	uint8_t		g;
	uint8_t		b;

	if (iterations >= max_iterations)
		return (255);
	t = (double)iterations / max_iterations;
	r = (uint8_t)(255 * (0.5 + 0.5 * cos(f->red * 6.28318 * t + 0.5435)));
	g = (uint8_t)(255 * (0.5 + 0.5 * cos(f->green * 6.28318 * t + 2.09439)));
	b = (uint8_t)(255 * (0.5 + 0.5 * cos(f->blue * 6.28318 * t + 4.18879)));
	return ((r << 24) | (g << 16) | (b << 8) | 255);
}
