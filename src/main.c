/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoulios <ngoulios@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 22:22:55 by ngoulios          #+#    #+#             */
/*   Updated: 2024/10/19 14:06:05 by ngoulios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
Idealy I want to achive this kind of main. small scalable and readable
I ll do my best
 
int	main(int argc, char **argv)
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
    mlx_t *mlx = mlx_init(WIDTH, HEIGHT, "Fractal Explorer", false);
    if (!mlx) 
	{
        printf("Failed to initialize MLX42\n");
        return EXIT_FAILURE;
    }
    mlx_image_t *img = mlx_new_image(mlx, WIDTH, HEIGHT);
    if (!img) 
	{
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
		return EXIT_FAILURE;
    fractal.fractal_type = fractal_type;
	if (fractal.fractal_type == 0) 
		fractal.fractal_func = &mandelbrot;
	else if (fractal.fractal_type == 1) 
	{
        fractal.fractal_func = &julia;
        fractal.julia_real = julia_c.real;
        fractal.julia_imaginary = julia_c.imaginary;
    } 
	else 
	{
		ft_putstr(
		"------------------------------------------------------------"
		"--------------------\n"
		"#######                                          \n"
		"#       #####    ##    ####  #####  ####  #      \n"
		"#       #    #  #  #  #    #   #   #    # #      \n"
		"#####   #    # #    # #        #   #    # #      \n"
		"#       #####  ###### #        #   #    # #      \n"
		"#       #   #  #    # #    #   #   #    # #      \n"
		"#       #    # #    #  ####    #    ####  ######\n"
		"------------------------------------------------------------"
		"--------------------\n");
		ft_putstr("usage:\n ./fractol [fractal_name] [-colors=[r,g,b\\|r,g,b\\|+]"
		"\n\nfractals:\n all (opens all)\n mandelbrot (Default)\n julia"
		"\n burning_ship\n mandelbrot_n\n julia_n\n bird_of_prey"
		"\n julia_mod\n phoenix_mod\n burning_julia\n\n"
		"example:\n ./fractol mandelbrot julia "
		"-colors=255,0,0\\|0,255,0\\|0,0,255\n\n"
		"more options:\n"
		" ESC to exit\n"
		" G for guide & further actions on screen.\n"
		"------------------------------------------------------------"
		"--------------------\n");
		return EXIT_FAILURE;

	}
    fractal.precision = MAX_ITERATIONS;
    draw_fractal(&fractal); 
    mlx_image_to_window(mlx, fractal.img, 0, 0);
	mlx_key_hook(mlx, handle_key, &fractal); 
	mlx_scroll_hook(mlx, handle_scroll, &fractal);
	mlx_close_hook(mlx, window_close_hook, mlx);
    mlx_loop(mlx);
    mlx_terminate(mlx);
    return EXIT_SUCCESS;
}
