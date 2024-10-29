/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoulios <ngoulios@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 14:11:53 by ngoulios          #+#    #+#             */
/*   Updated: 2024/10/29 12:56:12 by ngoulios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

uint32_t get_color(int iterations, int max_iterations, double k_red, double k_green, double k_blue)
{
	if (iterations < 0) 
		iterations = 0;
    else if (iterations >= max_iterations)
        return (0xFF000000);  // Black for points in set 
    double t = (double)iterations / max_iterations;
    
    uint8_t r = (uint8_t)(255 * (0.5 + 0.5 * cos(k_red * 6.28318 * t + 0.5435)));
    uint8_t g = (uint8_t)(255 * (0.5 + 0.5 * cos(k_green * 6.28318 * t + 2.09439)));
    uint8_t b = (uint8_t)(255 * (0.5 + 0.5 * cos(k_blue * 6.28318 * t + 4.18879)));
    
    return (r << 24) | (g << 16) | (b << 8) | 255;
}

/*uint32_t get_color(int iterations, int max_iterations, double k_red, double k_green, double k_blue)
{
    if (iterations == max_iterations)
        return (0x000000FF);  // Black color for maximum iterations with full opacity

    // Smooth color transition using sine functions
    double t = (double)iterations / max_iterations;
    uint8_t r = (uint8_t)(255 * (0.5 + 0.5 * sin(k_red * t * 3.14159 * 2)));
    uint8_t g = (uint8_t)(255 * (0.5 + 0.5 * sin(k_green * t * 3.14159 * 2 + 2.09439)));
    uint8_t b = (uint8_t)(255 * (0.5 + 0.5 * sin(k_blue * t * 3.14159 * 2 + 4.18879)));
    
    // Combine RGBA components into a single 32-bit color
    return (r << 24) | (g << 16) | (b << 8) | 0xFF;
}*/



