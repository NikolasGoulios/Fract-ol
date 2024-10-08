/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoulios <ngoulios@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 19:17:46 by ngoulios          #+#    #+#             */
/*   Updated: 2024/10/08 17:11:50 by ngoulios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <math.h>
# include "../lib/MLX42/include/MLX42/MLX42.h"
# include "../lib/libft/libft.h"

# define WIDTH 1500
# define HEIGHT 1500

typedef struct s_complex
{
    double real;
    double imaginary;
}   t_complex;

typedef struct s_fractol
{
    mlx_t       *mlx;
    mlx_image_t *image;
    double      x0;
    double      y0;
    double      x_min;
    double      x_max;
    double      y_min;
    double      y_max;
    int         color;
    int         disco_mode;
    int         mono_color;
    int         precision;
    double      zoom;
    int         (*func)(struct s_fractol *f);
    char        *type;
}   t_fractol;


int  initialize_fractal(t_fractol *f);
int  is_valid(t_fractol *f, int argc, char **argv);
void draw_fractals(void *param);
void draw_pixel(t_fractol *f, int x, int y);
void set_mandelbrot_params(t_fractol *f);
void set_julia_params(t_fractol *f);
void keyboard_hooks(mlx_key_data_t keydata, void *param);
void scroll_hook(double xdelta, double ydelta, void *param);
void close_hook(void *param);
void cool_display_window(t_fractol *f);

# define ERROR_INIT "Error: MLX initialization failed.\n"

#endif


