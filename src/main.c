/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoulios <ngoulios@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 22:22:55 by ngoulios          #+#    #+#             */
/*   Updated: 2024/12/04 21:15:52 by ngoulios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

static bool		initialize_graphics(t_fractal *fractal);
static bool		initialize_drawing_surface(t_fractal *fractal);

/*
 * Entry point for the fractal program.
 * - Parses command-line arguments to decide fractal type and Julia constants.
 * - Sets up the MLX environment and drawing surface.
 * - Draws the fractal and starts the event loop.
 */
int	main(int argc, char **argv)
{
	t_fractal	fractal;
	t_complex	julia_c;

	fractal.fractal_type = parsing_validity(argc, argv, &julia_c);
	if (fractal.fractal_type == -1)
		return (EXIT_FAILURE);
	if (!initialize_graphics(&fractal))
		return (EXIT_FAILURE);
	if (!initialize_drawing_surface(&fractal))
	{
		mlx_terminate(fractal.mlx);
		return (EXIT_FAILURE);
	}
	init_fractal(&fractal, &julia_c);
	draw_fractal(&fractal);
	if (mlx_image_to_window(fractal.mlx, fractal.img, 0, 0) < 0)
	{
		mlx_terminate(fractal.mlx);
		return (EXIT_FAILURE);
	}
	setup_mlx_hooks(&fractal);
	mlx_loop(fractal.mlx);
	cleanup_fractal(&fractal);
	return (EXIT_SUCCESS);
}

/*
 * Initializes the MLX graphics environment.
 * - Creates an MLX instance and window.
 * - Returns false if initialization fails.
 */
static bool	initialize_graphics(t_fractal *fractal)
{
	fractal->mlx = mlx_init(WIDTH, HEIGHT, WINDOW_TITLE, false);
	if (!fractal->mlx)
		return (false);
	return (true);
}

/*
 * Creates the image buffer for rendering fractals.
 * - The buffer will hold pixel data for the fractal to be drawn.
 * - Returns false if image creation fails.
 */
static bool	initialize_drawing_surface(t_fractal *fractal)
{
	fractal->img = mlx_new_image(fractal->mlx, WIDTH, HEIGHT);
	if (!fractal->img)
		return (false);
	return (true);
}
