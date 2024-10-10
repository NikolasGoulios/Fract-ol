/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoulios <ngoulios@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 22:23:18 by ngoulios          #+#    #+#             */
/*   Updated: 2024/10/10 22:23:19 by ngoulios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "fractol.h"

long double	ft_atold(const char *s)
{
	char		*str;
	long double	int_part;
	long double	float_part;
	int			i;
	int			sign;

	sign = 1;
	str = (char *) s;
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	if (*str == '-')
		sign *= -1;
	if (*str == '+' || *str == '-')
		str++;
	int_part = (long double)ft_atoi(str);
	while (*str && *str != '.')
		str++;
	if (*str == '.')
		str++;
	float_part = (long double)ft_atoi(str);
	i = ft_strlen(str);
	while (i--)
		float_part /= 10;
	return (sign * (int_part + float_part));
}

