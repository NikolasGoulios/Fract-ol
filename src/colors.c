/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoulios <ngoulios@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 14:11:53 by ngoulios          #+#    #+#             */
/*   Updated: 2024/10/23 19:12:40 by ngoulios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/* Generates a color based on the number of iterations using sine functions for smoother transitions 
uint32_t get_color(int iterations, int max_iterations, double k_red, double k_green, double k_blue)
{
    if (iterations == max_iterations)
        return ft_pixel(0, 0, 0, 255);  // Set color to black if max iterations reached

    // Calculate smooth color transitions using sine functions
    uint32_t red = (uint32_t)(sin(k_red * iterations) * 127 + 128);   // Scaled to range [0, 255]
    uint32_t green = (uint32_t)(sin(k_green * iterations) * 127 + 128);
    uint32_t blue = (uint32_t)(sin(k_blue * iterations) * 127 + 128);

    // Combine RGBA values into a single 32-bit color
    return ft_pixel(red, green, blue, 255);  // 255 is the alpha channel for full opacity
}

	This function combines four 8-bit color components (RGBA) into a single 32-bit color 
	uint32_t ft_pixel(uint32_t red, uint32_t green, uint32_t blue, uint32_t a)
{
    return (red << 24 | green << 16 | blue << 8 | a);
}*/



/* Linear interpolation between two values */
static uint32_t interpolate(uint32_t start, uint32_t end, double factor) 
{
    return (uint32_t)((1 - factor) * start + factor * end);
}

/* Generates a color based on the number of iterations, transitioning between blue, orange, and light blue */
uint32_t get_color(int iterations, int max_iterations)
{
    if (iterations == max_iterations)
        return ft_pixel(255, 255, 255, 255);  // White for max iterations (like the light background in the image)

    // Map iterations to a gradient from deep blue to orange to light blue
    double t = (double)iterations / max_iterations;

    uint32_t red, green, blue;

    if (t < 0.5) {
        // First half of iterations: Deep blue to orange
        red = interpolate(0, 255, t * 2);      // Interpolating from blue to orange
        green = interpolate(0, 69, t * 2);
        blue = interpolate(255, 0, t * 2);
    } else {
        // Second half of iterations: Orange to light blue
        red = interpolate(255, 173, (t - 0.5) * 2);  // Interpolating from orange to light blue
        green = interpolate(69, 216, (t - 0.5) * 2);
        blue = interpolate(0, 230, (t - 0.5) * 2);
    }

    return ft_pixel(red, green, blue, 255);  // 255 is the alpha channel for full opacity
}

/* This function combines four 8-bit color components (RGBA) into a single 32-bit color */
uint32_t ft_pixel(uint32_t red, uint32_t green, uint32_t blue, uint32_t a)
{
    return (red << 24 | green << 16 | blue << 8 | a);
}
