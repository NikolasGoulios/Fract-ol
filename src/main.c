/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoulios <ngoulios@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 22:22:55 by ngoulios          #+#    #+#             */
/*   Updated: 2024/10/17 17:45:48 by ngoulios         ###   ########.fr       */
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


int main(int argc, char **argv) 
{
    mlx_t *mlx = mlx_init(WIDTH, HEIGHT, "Fractal Explorer", false);
    if (!mlx) {
        printf("Failed to initialize MLX42\n");
        return EXIT_FAILURE;
    }
    mlx_image_t *img = mlx_new_image(mlx, WIDTH, HEIGHT);
    if (!img) {
        printf("Failed to create image\n");
        mlx_terminate(mlx);
        return EXIT_FAILURE;
    }
    t_fractal fractal = 
	{
        .x_min = -2.0, .x_max = 1.0,
        .y_min = -1.5, .y_max = 1.5,
        .img = img,
        .mlx = mlx
    };

    t_complex julia_c;
    int fractal_type = parse_arguments(argc, argv, &julia_c);
    if (fractal_type == -1) 
	{
        return EXIT_FAILURE; 
    }
    draw_fractal(&fractal, fractal_type, julia_c);  
    mlx_image_to_window(mlx, fractal.img, 0, 0);
    mlx_key_hook(mlx, handle_key, &fractal);
    mlx_scroll_hook(mlx, handle_scroll, &fractal);
    mlx_key_hook(mlx, handle_close, mlx);
    mlx_close_hook(mlx, window_close_hook, mlx);
    mlx_loop(mlx);
    mlx_terminate(mlx);
    return EXIT_SUCCESS;
}

