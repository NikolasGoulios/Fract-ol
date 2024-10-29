/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoulios <ngoulios@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 14:11:53 by ngoulios          #+#    #+#             */
/*   Updated: 2024/10/29 15:42:33 by ngoulios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

uint32_t	get_color(int iterations, int max_iterations,
						double k_red, double k_green, double k_blue)
{
	double		t;
	uint8_t		r;
	uint8_t		g;
	uint8_t		b;

	if (iterations < 0)
		iterations = 0;
	else if (iterations >= max_iterations)
		return (0xFF000000);
	t = (double)iterations / max_iterations;
	r = (uint8_t)(255 * (0.5 + 0.5 * cos(k_red * 6.28318 * t + 0.5435)));
	g = (uint8_t)(255 * (0.5 + 0.5 * cos(k_green * 6.28318 * t + 2.09439)));
	b = (uint8_t)(255 * (0.5 + 0.5 * cos(k_blue * 6.28318 * t + 4.18879)));
	return ((r << 24) | (g << 16) | (b << 8) | 255);
}
