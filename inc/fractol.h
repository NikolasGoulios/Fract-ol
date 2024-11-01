/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoulios <ngoulios@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 22:23:01 by ngoulios          #+#    #+#             */
/*   Updated: 2024/11/01 20:08:14 by ngoulios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h> 
# include <stdio.h>
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

/* Event Handling Functions */
void			handle_key(mlx_key_data_t keydata, void *param);
void			handle_key_arrow(void *param);
void			handle_scroll(double x_offset, double y_offset, void *param);
void			window_close_hook(void *param);

/*Fractal Drawing Functions*/
void			draw_fractal(t_fractal *fractal);
t_complex		pixel_to_complex(int x, int y, t_fractal *fractal);

/*Fractal Set Functions*/
int				mandelbrot(t_fractal *f);
int				julia(t_fractal *f);
int				burning_ship(t_fractal *f);
int				tricorn(t_fractal *f);

/*Argument Parsing and Parameter Setup*/
int				parse_arguments(int argc, char **argv, t_complex *julia_c);
void			mandelbrot_param(t_fractal *f);
void			set_julia_params(t_fractal *f);
void			burning_ship_param(t_fractal *f);
void			tricorn_param(t_fractal *f);

/* Color Utility Functions */
uint32_t		get_color(uint32_t iterations, uint32_t max_iter, t_fractal *f);

/* Utility Functions */
void			print_usage(void);
int				parsing_validity(int argc, char **argv, t_complex *julia_c);
void			init_fractal(t_fractal *fractal, t_complex *julia_c);
void			setup_mlx_hooks(t_fractal *fractal);
void			cleanup_fractal(t_fractal *fractal);

#endif
