/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoulios <ngoulios@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 22:22:55 by ngoulios          #+#    #+#             */
/*   Updated: 2024/10/23 16:35:19 by ngoulios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

mlx_t *init_mlx(void);
mlx_image_t *init_image(mlx_t *mlx);

int main(int argc, char **argv)
{
	t_fractal fractal;
	t_complex julia_c;
	mlx_t *mlx;
	mlx_image_t *img;
	int fractal_type;
	int precision;
	
	fractal_type = setup_fractal_type(argc, argv, &julia_c);
	if (fractal_type == -1)
		return(print_usage());
	mlx = init_mlx();
	if (!mlx)
		return EXIT_FAILURE;
	img = init_image(mlx);
	if(!img)
		return EXIT_FAILURE;
	init_fractal(&fractal, img, mlx, fractal_type, &julia_c);
	precision = MAX_ITERATIONS;
	draw_fractal(&fractal);
	mlx_image_to_window(mlx, fractal.img,  0, 0);
	setup_mlx_hooks(mlx, &fractal);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return EXIT_SUCCESS;
	 
}

mlx_t *init_mlx(void)
{
	mlx_t *mlx;
	
	mlx = mlx_init(WIDTH, HEIGHT, "SLAYYY", false);
	if (!mlx)
	{
		ft_printf("Failed to initialize MLX42\n");
		return (0);
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
    return img;
}
