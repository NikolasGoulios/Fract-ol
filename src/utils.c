/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoulios <ngoulios@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 16:02:35 by ngoulios          #+#    #+#             */
/*   Updated: 2024/11/01 13:57:09 by ngoulios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	print_usage(void)
{
	ft_putstr(
		"------------------------------------------------------------"
		"--------------------\n"
		"#######                                          \n"
		"#       #####    ##    ####  #####  ####  #      \n"
		"#       #    #  #  #  #    #   #   #    # #      \n"
		"#####   #    # #    # #        #   #    # #      \n"
		"#       #####  ###### #        #   #    # #      \n"
		"#       #   #  #    # #    #   #   #    # #      \n"
		"#       #    # #    #  ####    #    ####  ######\n"
		"------------------------------------------------------------"
		"--------------------\n");
	ft_putstr("usage:\n ./fractol [fractal_name] [Complex Plane]"
		"\n\nfractals:\n mandelbrot (Default)\n julia"
		"example:\n ./fractol mandelbrot"
		"example:\n ./fractol julia -0.5 0.4"
		"More options:\n"
		" ESC to exit\n"
		" R for Reverse to defaut view.\n"
		"------------------------------------------------------------"
		"--------------------\n");
}

void cleanup_fractal(t_fractal *fractal) 
{
    if (fractal->img) 
	{
        mlx_delete_image(fractal->mlx, fractal->img);
        fractal->img = NULL;
    }
    if (fractal->mlx) 
	{
       mlx_terminate(fractal->mlx);
        fractal->mlx = NULL;
    }
	else if (fractal) 
	{
		free(fractal);
		fractal = NULL;
	}
	ft_printf(CLEAN_COMPLETE);
}
