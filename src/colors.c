/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoulios <ngoulios@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 14:11:53 by ngoulios          #+#    #+#             */
/*   Updated: 2024/10/23 14:12:13 by ngoulios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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