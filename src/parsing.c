/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoulios <ngoulios@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 16:54:54 by ngoulios          #+#    #+#             */
/*   Updated: 2024/12/04 21:09:42 by ngoulios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

static int		parsing_julia(int argc, char **argv);
static int		parsing_double(const char *str);
static void		parsing_julia_constants(t_complex *julia_c, char **argv);

/* 
 * Determines the validity of the command-line arguments.
 * - Accepts: argc (argument count), argv (argument vector), julia_c (Julia constant pointer).
 * - Returns: 
 *    - 1 for Mandelbrot,
 *    - 2 for Julia (after validating constants),
 *    - -1 for invalid input (prints usage).
 */
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

/* 
 * Parses and assigns Julia set constants from command-line arguments.
 * - Accepts: julia_c (pointer to t_complex), argv (argument vector).
 * - Updates: julia_c->real and julia_c->imaginary using ft_atof.
 */
static void	parsing_julia_constants(t_complex *julia_c, char **argv)
{
	julia_c->real = ft_atof(argv[2]);
	julia_c->imaginary = ft_atof(argv[3]);
}

/* 
 * Validates the arguments specific to the Julia set.
 * - Accepts: argc (argument count), argv (argument vector).
 * - Returns: 1 if the arguments are valid (two valid doubles for constants),
 *            0 otherwise (prints error message for invalid double).
 */
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

/* 
 * Checks if a string represents a valid double (real number).
 * - Accepts: str (input string).
 * - Returns: 1 if the string is a valid double,
 *            0 if invalid (e.g., multiple '.', invalid characters, empty string).
 */
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
			if (++point > 1) // increment the int used as a flag and if there is more that one incrementation that mean that we have more . so not a valid double.
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
