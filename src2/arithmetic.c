/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arithmetic.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoulios <ngoulios@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 22:22:39 by ngoulios          #+#    #+#             */
/*   Updated: 2024/10/10 22:22:40 by ngoulios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "fractol.h"

t_complex ft_complex_sum(t_complex comp1, t_complex comp2)
{
	return (t_complex){
		.real = comp1.real + comp2.real,
		.i = comp1.i + comp2.i
	};
}

t_complex ft_complex_square(t_complex comp)
{
	return (t_complex){
		.real = (comp.real * comp.real) - (comp.i * comp.i),
		.i = 2 * comp.real * comp.i
	};
}
