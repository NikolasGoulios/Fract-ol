/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoulios <ngoulios@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 22:22:39 by ngoulios          #+#    #+#             */
/*   Updated: 2024/10/11 13:47:42 by ngoulios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	complex_sum(t_complex comp1, t_complex comp2)
{
	return (t_complex)
	{
		.real = comp1.real + comp2.real,
		.imaginary = comp1.imaginary + comp2.imaginary
	};
}

t_complex	complex_square(t_complex comp)
{
	return (t_complex)
	{
		.real = (comp.real * comp.real) - (comp.imaginary * comp.imaginary),
		.imaginary = 2 * comp.real * comp.imaginary
	};
}
