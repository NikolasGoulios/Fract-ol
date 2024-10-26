/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoulios <ngoulios@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 16:54:54 by ngoulios          #+#    #+#             */
/*   Updated: 2024/10/26 18:55:12 by ngoulios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int parsing_julia(int argc, char **argv);
static int parsing_double(const char *str);
static void parsing_julia_constants(t_complex *julia_c, char **argv);

int parsing_validity(int argc, char **argv, t_complex *julia_c)
{
    if (argc < 2)
    {
        print_usage();
        return -1;
    }

    if (argc == 2 && (ft_strncmp(argv[1], "mandelbrot", 10) == 0))
    {
        ft_printf("Mandelbrot Set selected\n");
        return 1;
    }
    else if (argc == 4 && (ft_strncmp(argv[1], "julia", 5) == 0))
    {
        if (parsing_julia(argc, argv))
        {
            ft_printf("Julia Set selected\n");
            parsing_julia_constants(julia_c, argv);
            return 2;
        }
    }

    print_usage();
    return -1;
}

static void parsing_julia_constants(t_complex *julia_c, char **argv)
{
	julia_c->real = ft_atof(argv[2]);
	julia_c->imaginary = ft_atof(argv[3]);
}

static int parsing_julia(int argc, char **argv) 
{
	if (argc == 4 && ft_strncmp(argv[1], "julia", 5) == 0) 
	{
		if (!parsing_double(argv[2]) || !parsing_double(argv[3]))
			{
				ft_printf("Invalid argument for unsigned double A and/or double B"); //Change it your style
				return (0);
			}
		return(1);
	}
	return (0);
}

static int parsing_double(const char *str)
{
    int decimal_point = 0;
    int i = 0;

    if (str[i] == '-' || str[i] == '+')
        i++;
    if (str[i] == '\0' || str[i] == '.')
        return (0);
    while (str[i])
    {
        if (str[i] == '.')
        {
            if (++decimal_point > 1)
                return (0);
        }
        else if (!ft_isdigit((unsigned char)str[i]))
            return (0);
        i++;
    }
    if (str[i - 1] == '.')
        return (0);

    return (1);
}
