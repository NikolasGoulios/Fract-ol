/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoulios <ngoulios@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 22:23:01 by ngoulios          #+#    #+#             */
/*   Updated: 2024/10/23 18:03:48 by ngoulios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h> 
# include <stdio.h>
# include <MLX42/MLX42.h>
# include "../lib/libft/libft.h" 

# define WIDTH 1200
# define HEIGHT 1200
# define MAX_ITERATIONS 100

// Struct Definitions
typedef struct s_complex
{
	double	real;
	double	imaginary;
}			t_complex;

typedef struct s_fractal
{
    // MLX and Image Related Data
    mlx_image_t	*img;
    mlx_t		*mlx;

    // Fractal Type and Function
    int			(*fractal_func)(struct s_fractal *f);
    int			fractal_type;  // 0: Mandelbrot, 1: Julia

    // Julia Set Constants
    t_complex	julia_c;
    double		julia_real;
    double		julia_imaginary;

    // Fractal Calculation Precision
    int			precision;
    uint32_t	max_iter;  // Maximum iterations for escape time algorithm

    // View and Zoom Settings
    double		x_min;
    double		x_max;
    double		y_min;
    double		y_max;
    double		zoom;
    t_complex	z;  // Current complex number being calculated
    t_complex	c;  // Constant for Julia set

    // Color Handling
    uint32_t	color;
    double		red;
    double		grn;
    double		blu;
    double		a;  // Alpha channel
    int			mono_color;
    int			disco_mode;  // 1: Disco mode enabled, 0: disabled

    // Pixel Position for Current Fractal Render
    int32_t		pixel_x;
    int32_t		pixel_y;

}				t_fractal;


// Event Handling Functions
void			handle_key(mlx_key_data_t keydata, void* param);
void			handle_scroll(double x_offset, double y_offset, void* param);
void			window_close_hook(void *param);
void			handle_close(mlx_key_data_t keydata, void *param);

// Fractal Drawing Functions
void			draw_fractal(t_fractal* fractal);
t_complex		pixel_to_complex(int x, int y, t_fractal* fractal);

// Fractal Set Functions
int				mandelbrot(t_fractal *f);
int				julia(t_fractal *f);

// Argument Parsing and Parameter Setup
int				parse_arguments(int argc, char **argv, t_complex *julia_c);
void			mandelbrot_param(t_fractal *f);  
void			set_julia_params(t_fractal *f);  

// Color Utility Functions
uint32_t		get_color(int iterations);

// Utility Functions
void			print_usage(void);

#endif
