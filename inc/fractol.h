/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoulios <ngoulios@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 22:23:01 by ngoulios          #+#    #+#             */
/*   Updated: 2024/11/06 19:10:21 by ngoulios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include "MLX42/MLX42.h" 
# include "../lib/libft/libft.h" 

# define WINDOW_TITLE "Fractal Og"
# define WIDTH  500
# define HEIGHT 500
# define K_RED 0.51
# define K_GREEN 0.51
# define K_BLUE 0.51
# define CLEAN_COMPLETE "Cleanup completed, memory freed succecfully\n"

typedef struct s_complex
{
	double	real;
	double	imaginary;
}			t_complex;

typedef struct s_fractal
{
	mlx_image_t	*img;
	mlx_t		*mlx;
	int			(*fractal_func)(struct s_fractal *);
	int			fractal_type;
	double		julia_real;
	double		julia_imaginary;
	uint32_t	max_iter;
	double		move_step;
	double		x_min;
	double		x_max;
	double		y_min;
	double		y_max;
	double		zoom;
	uint32_t	color;
	double		red;
	double		green;
	double		blue;
	double		a;
	int32_t		pixel_x;
	int32_t		pixel_y;

}				t_fractal;

/**
 * Handles keyboard input events.
 *
 * @param keydata Data about the key event.
 * @param param Pointer to fractal data.
 */
void	handle_key(mlx_key_data_t keydata, void *param);

/**
 * Handles arrow key inputs for panning.
 *
 * @param param Pointer to fractal data.
 */
void	handle_key_arrow(void *param);

/**
 * Handles mouse scroll events for zooming.
 *
 * @param x_offset Horizontal scroll offset.
 * @param y_offset Vertical scroll offset.
 * @param param Pointer to fractal data.
 */
void	handle_scroll(double x_offset, double y_offset, void *param);

/**
 * Handles the window close event.
 *
 * @param param Pointer to fractal data.
 */
void	window_close_hook(void *param);

/**
 * Renders the fractal image onto the buffer.
 *
 * @param fractal Pointer to fractal data.
 */
void	draw_fractal(t_fractal *fractal);

/**
 * Maps pixel coordinates to a complex number.
 *
 * @param x Pixel x-coordinate.
 * @param y Pixel y-coordinate.
 * @param fractal Pointer to fractal data.
 * @return Complex number corresponding to the pixel.
 */
t_complex		pixel_to_complex(int x, int y, t_fractal *fractal);

/**
 * Calculates iterations for the Mandelbrot set.
 *
 * @param f Pointer to fractal data.
 * @return Number of iterations before escape.
 */
int		mandelbrot(t_fractal *f);

/**
 * Calculates iterations for the Julia set.
 *
 * @param f Pointer to fractal data.
 * @return Number of iterations before escape.
 */
int		julia(t_fractal *f);

/**
 * Calculates iterations for the Burning Ship fractal.
 *
 * @param f Pointer to fractal data.
 * @return Number of iterations before escape.
 */
int		burning_ship(t_fractal *f);

/**
 * Parses and validates command-line arguments.
 *
 * @param argc Argument count.
 * @param argv Argument vector.
 * @param julia_c Pointer to store Julia constants.
 * @return Fractal type or error code.
 */
int		parse_arguments(int argc, char **argv, t_complex *julia_c);

/**
 * Initializes parameters for the Mandelbrot set.
 *
 * @param f Pointer to fractal data.
 */
void	mandelbrot_param(t_fractal *f);

/**
 * Initializes parameters for the Julia set.
 *
 * @param f Pointer to fractal data.
 */
void	set_julia_params(t_fractal *f);

/**
 * Initializes parameters for the Burning Ship fractal.
 *
 * @param f Pointer to fractal data.
 */
void	burning_ship_param(t_fractal *f);

/**
 * Calculates the color of a pixel.
 *
 * @param iterations Iteration count.
 * @param max_iter Maximum iterations.
 * @param f Pointer to fractal data.
 * @return Color value in ARGB format.
 */
uint32_t	get_color(uint32_t iterations, uint32_t max_iter, t_fractal *f);

/**
 * Displays usage instructions.
 */
void	print_usage(void);

/**
 * Validates command-line arguments.
 *
 * @param argc Argument count.
 * @param argv Argument vector.
 * @param julia_c Pointer to store Julia constants.
 * @return Fractal type or error code.
 */
int		parsing_validity(int argc, char **argv, t_complex *julia_c);

/**
 * Initializes the fractal structure.
 *
 * @param fractal Pointer to fractal data.
 * @param julia_c Pointer to Julia constants.
 */
void	init_fractal(t_fractal *fractal, t_complex *julia_c);

/**
 * Sets up event hooks for MLX.
 *
 * @param fractal Pointer to fractal data.
 */
void	setup_mlx_hooks(t_fractal *fractal);

/**
 * Frees resources before exiting.
 *
 * @param fractal Pointer to fractal data.
 */
void	cleanup_fractal(t_fractal *fractal);

#endif
