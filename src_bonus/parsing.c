/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoulios <ngoulios@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 16:54:54 by ngoulios          #+#    #+#             */
/*   Updated: 2024/11/01 17:48:12 by ngoulios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

static int		parsing_julia(int argc, char **argv);
static int		parsing_double(const char *str);
static void		parsing_julia_constants(t_complex *julia_c, char **argv);

int	parsing_validity(int argc, char **argv, t_complex *julia_c)
{
	if (argc < 2)
	{
		print_usage();
		return (-1);
	}
	else if (argc == 2 && (ft_strncmp(argv[1], "mandelbrot", 10) == 0))
		return (1);
	else if (argc == 4 && (ft_strncmp(argv[1], "julia", 5) == 0))
	{
		if (parsing_julia(argc, argv))
		{
			parsing_julia_constants(julia_c, argv);
			return (2);
		}
	}
	print_usage();
	return (-1);
}

static void	parsing_julia_constants(t_complex *julia_c, char **argv)
{
	julia_c->real = ft_atof(argv[2]);
	printf("%f\n", julia_c->real);
	julia_c->imaginary = ft_atof(argv[3]);
	printf("%f\n", julia_c->imaginary);
}

static int	parsing_julia(int argc, char **argv)
{
	if (argc == 4 && ft_strncmp(argv[1], "julia", 5) == 0)
	{
		if (!parsing_double(argv[2]) || !parsing_double(argv[3]))
		{
			ft_printf("Invalid argument for unsigned double");
			return (0);
		}
		return (1);
	}
	return (0);
}

static int	parsing_double(const char *str)
{
	int		point;
	int		index;

	point = 0;
	index = 0;
	if (str[index] == '-' || str[index] == '+')
		index++;
	if (str[index] == '\0' || str[index] == '.')
		return (0);
	while (str[index])
	{
		if (str[index] == '.')
		{
			if (++point > 1)
				return (0);
		}
		else if (!ft_isdigit((unsigned char)str[index]))
			return (0);
		index++;
	}
	if (str[index - 1] == '.')
		return (0);
	return (1);
}
