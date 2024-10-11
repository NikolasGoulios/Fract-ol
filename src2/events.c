/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoulios <ngoulios@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 22:23:06 by ngoulios          #+#    #+#             */
/*   Updated: 2024/10/11 13:46:18 by ngoulios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	adjust_view(t_fractol *f, double dx, double dy);
static void	reset_view(t_fractol *f);
static void	reset_view(t_fractol *f);

void	keyboard_hooks(mlx_key_data_t k_data, void *arg)
{
	t_fractol	*f;

	f = (t_fractol *)arg;
	if (k_data.action != MLX_PRESS) return;

	switch (k_data.key) 
	{
		case MLX_KEY_Q: f->precision *= 1.1; break; // Keep
		case MLX_KEY_W: f->precision *= 0.9; break; // Keep 
		case MLX_KEY_ESCAPE: close_hook(f); break; // keep this
		case MLX_KEY_C: random_colors(f); break;
		case MLX_KEY_D: f->disco_mode *= -1; break;
		case MLX_KEY_M: f->mono_color = (f->mono_color + 1) % 2; break;
		case MLX_KEY_R: reset_view(f); break;
		case MLX_KEY_UP: adjust_view(f, 0, 1); break; // no 
		case MLX_KEY_DOWN: adjust_view(f, 0, -1); break; // no 
		case MLX_KEY_LEFT: adjust_view(f, -1, 0); break; // no 
		case MLX_KEY_RIGHT: adjust_view(f, 1, 0); break; // no
	}
}

void	scroll_hook(double xdelta, double ydelta, void *arg)
{
	t_fractol	*f;
	int32_t		mouse_x, mouse_y;

	(void) xdelta;
	f = (t_fractol *)arg;
	if (ydelta == 0) return;

	mlx_get_mouse_pos(f->mlx, &mouse_x, &mouse_y);

	double	coefficient = (ydelta > 0) ? 1.1 : 0.9;
	f->zoom *= coefficient;

	t_complex	offset = {
		(mouse_x * (f->x_max - f->x_min) / WIDTH + f->x_min) * (1 - coefficient),
		((HEIGHT - mouse_y) * (f->y_max - f->y_min) / HEIGHT + f->y_min) * (1 - coefficient)
	};

	f->x_max = f->x_max * coefficient + offset.real;
	f->x_min = f->x_min * coefficient + offset.real;
	f->y_max = f->y_max * coefficient + offset.i;
	f->y_min = f->y_min * coefficient + offset.i;
}

void	close_hook(void *arg)
{
	t_fractol	*f;

	f = (t_fractol *)arg;
	if (f->image)
		mlx_delete_image(f->mlx, f->image);
	if (f->mlx)
	{
		mlx_close_window(f->mlx);
		mlx_terminate(f->mlx);
	}
	exit(0);
}

static void	adjust_view(t_fractol *f, double dx, double dy)
{
	double	shift = 0.1 * f->zoom;
	f->x_max += dx * shift;
	f->x_min += dx * shift;
	f->y_max += dy * shift;
	f->y_min += dy * shift;
}

static void	reset_view(t_fractol *f)
{
	f->disco_mode = -1;
	f->mono_color = 1;
	f->precision = 100;
	f->zoom = 1;
	f->x_max = 2;
	f->y_max = 2;
	f->x_min = -2;
	f->y_min = -2;
}

