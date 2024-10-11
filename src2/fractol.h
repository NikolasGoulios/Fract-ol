/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoulios <ngoulios@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 22:23:01 by ngoulios          #+#    #+#             */
/*   Updated: 2024/10/11 13:33:28 by ngoulios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <stdlib.h> 
# include <limits.h> // Maybe not
# include <unistd.h> // change it and use ft_printf
# include <MLX42/MLX42.h>

# define WIDTH	1200
# define HEIGHT	1200

typedef struct s_complex
{
	double	real;
	double	imaginary;
}			t_complex;

typedef struct s_fractol
{
	mlx_image_t	*image;
	mlx_t		*mlx;
	uint32_t	color;
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
	int			(*func)(struct s_fractol *f);
	int			disco_mode;
	double		zoom;
	int			mono_color;
}				t_fractol;


// Events
void			on_close(void *arg);
void			on_keyboard(mlx_key_data_t k_data, void *arg);
void			on_scroll(double xdelta, double ydelta, void *arg);

// Colors
uint32_t		co_generator(int i, t_fractol *f);
void			co_random(t_fractol *f);

// Sets
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
int				is_valid(t_fractol *f, int argc, char **argv);

#endif
