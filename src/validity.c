/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validity.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoulios <ngoulios@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 16:23:14 by ngoulios          #+#    #+#             */
/*   Updated: 2024/09/30 16:47:18 by ngoulios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int validity(t_fractol *f,int argc, char **argv)
{
	if (argc == 2)
	{
		if (!ft_strcmp(argv[1], "Mandelbrot")
			f-> func = &mandelbrot;
		else
			return (1);
	}
	else if (argc == 4 && !ft_strcmp(argv[1], "Julia"))
	{
		if (!double_check(argv[2] || !double_check(argv[3]))
			return (1);
		f ->julia_c_real = ft_atoi(argv[2]);
		f ->julia_c_imaginary = ft_atold(argv[3]);
		f ->func = &julia; 
	}
	else
		return 1;
	return 0;
}

static int double_validity(char *str)
{
	
}