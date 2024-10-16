/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoulios <ngoulios@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 22:22:55 by ngoulios          #+#    #+#             */
/*   Updated: 2024/10/16 18:10:35 by ngoulios         ###   ########.fr       */
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

/*int main(void)
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
}*/




// Map pixel (x, y) to the complex plane
t_complex pixel_to_complex(int x, int y, t_fractal* fractal) {
    t_complex c;
    c.real = fractal->x_min + (x / (double)WIDTH) * (fractal->x_max - fractal->x_min);
    c.imaginary = fractal->y_min + (y / (double)HEIGHT) * (fractal->y_max - fractal->y_min);
    return c;
}

// Mandelbrot function: checks if a point is in the Mandelbrot set
int mandelbrot(t_complex c) {
    t_complex z = {0, 0};
    int iterations = 0;

    while (iterations < MAX_ITERATIONS) {
        double real_temp = z.real * z.real - z.imaginary * z.imaginary + c.real;
        z.imaginary = 2.0 * z.real * z.imaginary + c.imaginary;
        z.real = real_temp;

        if ((z.real * z.real + z.imaginary * z.imaginary) > 4.0) {
            return iterations; // Point escapes
        }
        iterations++;
    }

    return MAX_ITERATIONS; // Point is in the Mandelbrot set
}

// Function to draw the Mandelbrot set
void draw_fractal(t_fractal* fractal) {
    printf("Drawing the fractal...\n"); // Debug
    int y = 0;
    while (y < HEIGHT) {
        int x = 0;
        while (x < WIDTH) {
            t_complex c = pixel_to_complex(x, y, fractal);
            int iterations = mandelbrot(c);
            uint32_t color = (iterations == MAX_ITERATIONS) ? 0x000000FF : 0x00FF00FF; // Black for inside, green for escape
            mlx_put_pixel(fractal->img, x, y, color);
            x++;
        }
        y++;
    }
    printf("Fractal drawing complete!\n"); // Debug
}

// Function to handle key events (for movement)
void handle_key(mlx_key_data_t keydata, void* param) {
    printf("Key pressed: %d\n", keydata.key); // Debug
    t_fractal* fractal = (t_fractal*)param;
    double move_factor = 0.1 * (fractal->x_max - fractal->x_min);

    if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS) {
        fractal->x_min -= move_factor;
        fractal->x_max -= move_factor;
    } else if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS) {
        fractal->x_min += move_factor;
        fractal->x_max += move_factor;
    } else if (keydata.key == MLX_KEY_UP && keydata.action == MLX_PRESS) {
        fractal->y_min -= move_factor;
        fractal->y_max -= move_factor;
    } else if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_PRESS) {
        fractal->y_min += move_factor;
        fractal->y_max += move_factor;
    }

    // Redraw the fractal after movement
    draw_fractal(fractal);
    mlx_image_to_window(fractal->mlx, fractal->img, 0, 0);
}

// Function to handle mouse scroll (for zoom)
void handle_scroll(double x_offset, double y_offset, void* param) {
    printf("Scroll: %f, %f\n", x_offset, y_offset); // Debug
    t_fractal* fractal = (t_fractal*)param;
    double zoom_factor = (y_offset > 0) ? 0.9 : 1.1;

    double real_center = (fractal->x_min + fractal->x_max) / 2;
    double imaginary_center = (fractal->y_min + fractal->y_max) / 2;

    double real_range = (fractal->x_max - fractal->x_min) * zoom_factor;
    double imaginary_range = (fractal->y_max - fractal->y_min) * zoom_factor;

    fractal->x_min = real_center - real_range / 2;
    fractal->x_max = real_center + real_range / 2;
    fractal->y_min = imaginary_center - imaginary_range / 2;
    fractal->y_max = imaginary_center + imaginary_range / 2;

    // Redraw the fractal after zooming
    draw_fractal(fractal);
    mlx_image_to_window(fractal->mlx, fractal->img, 0, 0);
}

int main(void) {
    printf("Initializing MLX...\n"); // Debug
    // Initialize MLX42 and open a window
    mlx_t* mlx = mlx_init(WIDTH, HEIGHT, "Mandelbrot Explorer", false);
    if (!mlx) {
        printf("Failed to initialize MLX42\n");
        return EXIT_FAILURE;
    }

    // Create an image (drawing buffer)
    printf("Creating image buffer...\n"); // Debug
    mlx_image_t* img = mlx_new_image(mlx, WIDTH, HEIGHT);
    if (!img) {
        printf("Failed to create image\n");
        mlx_terminate(mlx);
        return EXIT_FAILURE;
    }

    // Initialize fractal boundaries and store the mlx instance
    t_fractal fractal = {
        .x_min = -2.0, .x_max = 1.0,
        .y_min = -1.5, .y_max = 1.5,
        .img = img,
        .mlx = mlx  // Store the mlx instance in the fractal struct
    };

    // Draw the initial Mandelbrot set
    draw_fractal(&fractal);
    mlx_image_to_window(mlx, fractal.img, 0, 0);

    // Register input handlers for movement and zoom
    printf("Registering input handlers...\n"); // Debug
    mlx_key_hook(mlx, handle_key, &fractal);
    mlx_scroll_hook(mlx, handle_scroll, &fractal);

    // Start the event loop
    printf("Starting event loop...\n"); // Debug
    mlx_loop(mlx);

    // Cleanup
    printf("Terminating MLX...\n"); // Debug
    mlx_terminate(mlx);
    return EXIT_SUCCESS;
}
