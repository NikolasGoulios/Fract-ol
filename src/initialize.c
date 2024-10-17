/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoulios <ngoulios@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 17:06:36 by ngoulios          #+#    #+#             */
/*   Updated: 2024/10/17 17:07:07 by ngoulios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void draw_fractal(t_fractal* fractal, int fractal_type, t_complex julia_c) {
    int y = 0;
    while (y < HEIGHT) {
        int x = 0;
        while (x < WIDTH) {
            // Map pixel (x, y) to a complex number z
            t_complex z = pixel_to_complex(x, y, fractal);

            int iterations;
            if (fractal_type == 0) {
                // Mandelbrot set
                iterations = mandelbrot(z);
            } else {
                // Julia set
                iterations = julia(z, julia_c);  // Pass z and the fixed constant c
            }

            // Color based on iterations (you can change this for a cool effect later)
            uint32_t color = (iterations == MAX_ITERATIONS) ? 0x000000FF : (iterations * 0x010101FF);
            mlx_put_pixel(fractal->img, x, y, color);

            x++;
        }
        y++;
    }
}