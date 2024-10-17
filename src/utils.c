/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoulios <ngoulios@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 16:54:54 by ngoulios          #+#    #+#             */
/*   Updated: 2024/10/17 17:52:22 by ngoulios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int parse_arguments(int argc, char **argv, t_complex *julia_c) 
{
    if (argc == 2 && ft_strcmp(argv[1], "mandelbrot") == 0) 
		return (0);
	else if (argc == 4 && ft_strcmp(argv[1], "julia") == 0) 
	{
        julia_c->real = ft_atoi(argv[2]);
        julia_c->imaginary = ft_atoi(argv[3]);
        return (1);
    } 
	else 
	{
        ft_printf("Usage: ./fractol [mandelbrot | julia <real> <imaginary>]\n");
        return (-1);
    }
}

uint32_t get_color(int iterations) 
{
    if (iterations == MAX_ITERATIONS) 
        return 0x000000FF;
		
    // Create a color gradient based on the iterations
    // This gives a gradient from blue to red to yellow
    int red = (iterations * 9) % 255;
    int green = (iterations * 2) % 255;
    int blue = (iterations * 5) % 255;

    return (red << 24) | (green << 16) | (blue << 8) | 0xFF;
}