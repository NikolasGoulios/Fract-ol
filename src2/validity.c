/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validity.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoulios <ngoulios@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 22:23:25 by ngoulios          #+#    #+#             */
/*   Updated: 2024/10/10 22:23:30 by ngoulios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int is_valid_double(const char *str)
{
	int dot_count = 0;
	if (*str == '+' || *str == '-') 
		str++;
	if (*str == '.') 
		return 0;
	while (*str) 
	{
		if (*str == '.') 
		{
			if (++dot_count > 1) 
				return 0;
		} 
		else if (*str < '0' || *str > '9') 
			return 0;
		str++;
	}
	return (*(str - 1) != '.');
}
	
int validity_check(t_fractol *f, int argc, char **argv)
{
	if (argc == 2 && !ft_strcmp(argv[1], "Mandelbrot")) {
		f->func = &is_in_mandelbrot;
		return 1;
	}
	
	if (argc == 4 && !ft_strcmp(argv[1], "Julia")) 
	{
		if (!is_valid_double(argv[2]) || !is_valid_double(argv[3])) 
			return 0;
		f->julia_c_real = ft_atold(argv[2]);
		f->julia_c_imaginary = ft_atold(argv[3]);
		f->func = &is_in_julia;
		return 1;
	}

	return 0;
}