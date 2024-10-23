/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoulios <ngoulios@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 22:22:55 by ngoulios          #+#    #+#             */
/*   Updated: 2024/10/23 19:32:53 by ngoulios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

mlx_t *init_mlx(void);
mlx_image_t *init_image(mlx_t *mlx);

#include "fractol.h"

#include "fractol.h"

int main(int argc, char **argv)
{
    t_fractal fractal;
    t_complex julia_c;
    mlx_t *mlx;
    mlx_image_t *img;
    int fractal_type;

    // Validate arguments
    fractal_type = parsing_validity(argc, argv, &julia_c);
    if (fractal_type == -1)
        return EXIT_FAILURE;  // Returning EXIT_FAILURE since this is an int-returning function

    // Initialize MLX (pointer-returning function, use NULL for failure)
    mlx = init_mlx();
    if (!mlx)
        return EXIT_FAILURE;  // Here, we return EXIT_FAILURE since main expects int, not a pointer

    // Create image (pointer-returning function, use NULL for failure)
    img = init_image(mlx);
    if (!img)
        return EXIT_FAILURE;  // Return EXIT_FAILURE because this is the main function

    // Initialize fractal
    init_fractal(&fractal, img, mlx, fractal_type, &julia_c);

    // Draw fractal and set up hooks
    draw_fractal(&fractal);
    mlx_image_to_window(mlx, fractal.img, 0, 0);
    setup_mlx_hooks(mlx, &fractal);

    // Start the MLX loop
    mlx_loop(mlx);
    mlx_terminate(mlx);

    return EXIT_SUCCESS;  // Return EXIT_SUCCESS for successful completion
}

mlx_t *init_mlx(void)
{
	mlx_t *mlx;
	
	mlx = mlx_init(WIDTH, HEIGHT, "SLAYYY", false);
	if (!mlx)
	{
		ft_printf("Failed to initialize MLX42\n");
		return NULL;
	}
	return (mlx);
}

mlx_image_t *init_image(mlx_t *mlx)
{
    mlx_image_t *img = mlx_new_image(mlx, WIDTH, HEIGHT);
    if (!img)
    {
        printf("Failed to create image\n");
        mlx_terminate(mlx);
        return NULL;
    }
    return (img);
}
