/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoulios <ngoulios@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 22:22:55 by ngoulios          #+#    #+#             */
/*   Updated: 2024/10/26 19:36:17 by ngoulios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static mlx_t *init_mlx(t_fractal *fractal);
static mlx_image_t *init_image(t_fractal *fractal);

int main(int argc, char **argv)
{
    t_fractal fractal;
    t_complex julia_c;

    int fractal_type = parsing_validity(argc, argv, &julia_c);
    if (fractal_type == 1) 
		fractal.fractal_type = 1;
	else if (fractal_type == 2) 
        fractal.fractal_type = 2;
	else 
        return EXIT_FAILURE;
    fractal.mlx = init_mlx(&fractal);
    if (!fractal.mlx)
        return EXIT_FAILURE;
    fractal.img = init_image(&fractal);
    if (!fractal.img)
        return EXIT_FAILURE;
    init_fractal(&fractal, &julia_c);
    draw_fractal(&fractal);
    if (mlx_image_to_window(fractal.mlx, fractal.img, 0, 0) < 0) 
	{
        perror("Failed to display image in window");
        mlx_terminate(fractal.mlx);
        return EXIT_FAILURE;
    }
    setup_mlx_hooks(fractal.mlx, &fractal);
    mlx_loop(fractal.mlx);
	mlx_delete_image(fractal.mlx, fractal.img);
    mlx_terminate(fractal.mlx);
    return EXIT_SUCCESS;
}

static mlx_t *init_mlx(t_fractal *fractal)
{	
	fractal->mlx = mlx_init(WIDTH, HEIGHT, "SLAYYY", false);
	if (!fractal->mlx)
	{
		ft_printf("Failed to initialize MLX42\n");
		return NULL;
	}
	return (fractal->mlx);
}

static mlx_image_t *init_image(t_fractal *fractal)
{
    fractal->img = mlx_new_image(fractal->mlx, WIDTH, HEIGHT);
    if (!fractal->img)
    {
        perror("Failed to create image\n");
        mlx_terminate(fractal->mlx);
        return NULL;
    }
    return (fractal->img);
}
