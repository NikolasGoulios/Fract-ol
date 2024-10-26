/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoulios <ngoulios@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 14:11:53 by ngoulios          #+#    #+#             */
/*   Updated: 2024/10/26 18:58:32 by ngoulios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

//Generates a color based on the number of iterations using sine functions for smoother transitions 
/*uint32_t get_color(int iterations, int max_iterations, double k_red, double k_green, double k_blue)
{
    if (iterations == max_iterations)
        return ft_pixel(0, 0, 0, 255);

    uint32_t red = (uint32_t)(sin(k_red * iterations) * 127 + 128);
    uint32_t green = (uint32_t)(sin(k_green * iterations) * 127 + 128);
    uint32_t blue = (uint32_t)(sin(k_blue * iterations) * 127 + 128);

	 uint32_t color = ft_pixel(red, green, blue, 255);
	printf("Color Generated - R: %u, G: %u, B: %u\n", red, green, blue);

    return color;;
}

//This function combines four 8-bit color components (RGBA) into a single 32-bit color 
uint32_t ft_pixel(uint32_t red, uint32_t green, uint32_t blue, uint32_t a)
{
    return (red << 24 | green << 16 | blue << 8 | a);
}*/

uint32_t get_color(int iterations, int max_iterations, double k_red, double k_green, double k_blue)
{
	if (iterations < 0) 
		iterations = 0;
    else if (iterations >= max_iterations)
        return (0xFF000000);  // Black for points in set 
    double t = (double)iterations / max_iterations;
    
    uint8_t r = (uint8_t)(255 * (0.5 + 0.5 * cos(k_red * 6.28318 * t)));
    uint8_t g = (uint8_t)(255 * (0.5 + 0.5 * cos(k_green * 6.28318 * t + 2.09439)));
    uint8_t b = (uint8_t)(255 * (0.5 + 0.5 * cos(k_blue * 6.28318 * t + 4.18879)));
    
    return (r << 24) | (g << 16) | (b << 8) | 255;
}
