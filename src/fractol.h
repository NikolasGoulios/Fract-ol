/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoulios <ngoulios@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 22:23:01 by ngoulios          #+#    #+#             */
/*   Updated: 2024/10/18 15:50:56 by ngoulios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <stdlib.h> 
# include <limits.h> // Maybe not
# include <unistd.h> // change it and use ft_printf
# include <stdio.h>
# include <MLX42/MLX42.h>
# include "../lib/libft/libft.h" 

# define WIDTH	1200
# define HEIGHT	1200
#define MAX_ITERATIONS 100

typedef struct s_complex
{
	double	real;
	double	imaginary;
}			t_complex;

typedef struct s_fractal
{
	mlx_image_t	*img;
	mlx_t		*mlx;
	uint32_t	color;
	t_complex	julia_c;
	double		red;
	double		grn;
	double		blu;
	double		a;
	double		x0;
	double		y0;
	double		x_max;
	double		y_max;
	double		x_min;
	double		y_min;
	int			precision;
	double		julia_real;
	double		julia_imaginary;
	int 		(*fractal_func)(struct s_fractal *f);
	int			disco_mode;
	int			fractal_type;
	double		zoom;
	int			mono_color;
}				t_fractal;


// Events
/*void			on_close(void *arg);
void			on_keyboard(mlx_key_data_t k_data, void *arg);
void			on_scroll(double xdelta, double ydelta, void *arg);

// Colors
uint32_t		co_generator(int i, t_fractol *f);
void			co_random(t_fractol *f);

Sets
int				in_mandelbrot(t_fractol *f);
int				in_julia(t_fractol *f);

// Complex arithmetic
t_complex		complex_sum(t_complex comp1, t_complex comp2);
t_complex		complex_square(t_complex comp);

// Init
int				initialize_fractol(t_fractol *f);
void			draw_fractals(void *param);

// Utils
void			ft_putstr_fd(char *s, int fd); // Ft_printf
long double 	str_to_ld(const char *s);
void			print_usage(void);
int				is_valid(t_fractol *f, int argc, char **argv);*/
t_complex pixel_to_complex(int x, int y, t_fractal* fractal);
void handle_key(mlx_key_data_t keydata, void* param);
void handle_scroll(double x_offset, double y_offset, void* param);
void draw_fractal(t_fractal* fractal);
void handle_close(mlx_key_data_t keydata, void *param);
void window_close_hook(void *param);

//Sets
int				mandelbrot(t_fractal *f);
int				julia(t_fractal *f);
uint32_t get_color(int iterations);
int parse_arguments(int argc, char **argv, t_complex *julia_c);
void mandelbrot_param(t_fractal *f);  // Declare mandelbrot_param function
void set_julia_params(t_fractal *f);  // Declare set_julia_params function

#endif
