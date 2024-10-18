/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoulios <ngoulios@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 22:22:55 by ngoulios          #+#    #+#             */
/*   Updated: 2024/10/18 18:32:02 by ngoulios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*int	main(int argc, char **argv)
{
	t_fractol	f;

	if (argc < 2 || !is_valid(&f, argc, argv))
		print_usage();
	if (initialize_fractol(&f))
		return (1);
	mlx_key_hook(f.mlx, &on_keyboard, &f);
	mlx_close_hook(f.mlx, &on_close, &f);
	mlx_scroll_hook(f.mlx, &on_scroll, &f);
	mlx_loop_hook(f.mlx, draw_fractals, &f);
	mlx_loop(f.mlx);
	mlx_terminate(f.mlx);
	return (0);
}*/


#include "fractol.h"

int main(int argc, char **argv) 
{
    // Initialize MLX
    mlx_t *mlx = mlx_init(WIDTH, HEIGHT, "Fractal Explorer", false);
    if (!mlx) 
	{
        printf("Failed to initialize MLX42\n");
        return EXIT_FAILURE;
    }

    // Create the image buffer
    mlx_image_t *img = mlx_new_image(mlx, WIDTH, HEIGHT);
    if (!img) 
	{
        printf("Failed to create image\n");
        mlx_terminate(mlx);
        return EXIT_FAILURE;
    }

    // Initialize fractal struct
    t_fractal fractal = {
        .x_min = -2.0, .x_max = 1.0,
        .y_min = -1.5, .y_max = 1.5,
        .img = img,
        .mlx = mlx
    };

    // Parse command-line arguments (Mandelbrot or Julia, plus any parameters)
    t_complex julia_c;
    int fractal_type = parse_arguments(argc, argv, &julia_c);
    if (fractal_type == -1) {
        return EXIT_FAILURE;  // Invalid argument case
    }

    // Set the fractal type and function pointer
    fractal.fractal_type = fractal_type;  // Set the fractal type in the struct

    if (fractal.fractal_type == 0) {
        fractal.fractal_func = &mandelbrot;  // Set Mandelbrot function
    } else if (fractal.fractal_type == 1) {
        fractal.fractal_func = &julia;  // Set Julia function
        fractal.julia_real = julia_c.real;
        fractal.julia_imaginary = julia_c.imaginary;
    } else {
        printf("Invalid fractal type\n");
        return EXIT_FAILURE;
    }

    // Set precision for fractal iterations
    fractal.precision = MAX_ITERATIONS;

    // Render the fractal
    draw_fractal(&fractal);  // Pass fractal by reference
    mlx_image_to_window(mlx, fractal.img, 0, 0);

    // Register event hooks for movement, zoom, and exit
    // Register event hooks for movement, zoom, and exit
	mlx_key_hook(mlx, handle_key, &fractal);  // Single key hook for movement and closing
	mlx_scroll_hook(mlx, handle_scroll, &fractal);
	mlx_close_hook(mlx, window_close_hook, mlx);


    // Start the event loop to keep the window responsive
    mlx_loop(mlx);

    // Clean up and exit
    mlx_terminate(mlx);
    return EXIT_SUCCESS;
}
