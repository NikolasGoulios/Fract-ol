/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoulios <ngoulios@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 16:00:12 by ngoulios          #+#    #+#             */
/*   Updated: 2024/10/08 17:53:08 by ngoulios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int color_gradient(int iter, int max_iter);

int color_generator(int iter, t_fractol *f)
{
    return (color_gradient(iter, f->precision));
}

int color_gradient(int iter, int max_iter)
{
    double t = (double)iter / max_iter;  // Normalize the iteration count
    int red = (int)(9 * (1 - t) * t * t * t * 255);
    int green = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
    int blue = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
    return (red << 16) | (green << 8) | blue;  // Combine RGB into one int
}
