/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validity.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoulios <ngoulios@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 16:23:14 by ngoulios          #+#    #+#             */
/*   Updated: 2024/10/08 17:20:28 by ngoulios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int is_valid_number(const char *str);

int is_valid(t_fractol *f, int argc, char **argv)
{

	if (strcmp(argv[1], "Mandelbrot") == 0)
		return (argc == 2); 
	else if (strcmp(argv[1], "Julia") == 0)
		return (argc == 4 && is_valid_number(argv[2]) && is_valid_number(argv[3]));
	else
		return (0);
}

int is_valid_number(const char *str)
{
    int i = 0;
    int dot_seen = 0;

    while (ft_isspace(str[i]))
        i++;
    if (str[i] == '-' || str[i] == '+')
        i++;
    while (str[i])
    {
        if (!ft_isdigit(str[i]))
        {
            if (str[i] == '.' && !dot_seen)
                dot_seen = 1;
            else
                return (0); 
        }
        i++;
    }

    return (i > 0); 
}
