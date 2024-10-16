/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoulios <ngoulios@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 22:22:55 by ngoulios          #+#    #+#             */
/*   Updated: 2024/10/16 13:08:09 by ngoulios         ###   ########.fr       */
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

int main(void)
{
	mlx_t *mlx;
	int y = 0;
	int x = 0;
	
	mlx = mlx_init(WIDTH, HEIGHT, "Example Window", false);
	if (!mlx)
		return EXIT_FAILURE;

	mlx_image_t *img = mlx_new_image(mlx, WIDTH, HEIGHT);
	if (!img)
		return EXIT_FAILURE;
	
	
    while (y < HEIGHT) 
	{    
        while (x < WIDTH) 
		{
            if ((x / BLOCK_SIZE + y / BLOCK_SIZE) % 2 == 0)
                mlx_put_pixel(img, x, y, 0xFF0000FF); // Red
            else
                mlx_put_pixel(img, x, y, 0x0000FFFF); // Blue
            x++;
        }
        y++;
    }
		
	//mlx_put_pixel(img, WIDTH / 2, HEIGHT / 2, 0xFF0000FF);
	mlx_image_to_window(mlx, img, 0, 0);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return EXIT_SUCCESS;
}
