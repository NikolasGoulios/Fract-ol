/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_calculations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoulios <ngoulios@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 17:53:38 by ngoulios          #+#    #+#             */
/*   Updated: 2024/10/15 21:06:46 by ngoulios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <math.h>

#ifndef COMPLEX_H
# define COMPLEX_H

typedef struct s_complex
{
	double real;
	double imaginary;
} t_complex;

#endif

t_complex complex_add(t_complex a, t_complex b)
{
	t_complex results;
	results.real = a.real + b.real;
	results.imaginary = a.imaginary + b.imaginary;
	return results; 
}

t_complex complex_multiply(t_complex a, t_complex b)
{
	t_complex results;
	results.real = a.real * b.real - a.imaginary * b.imaginary;
	results.imaginary = a.real * b.imaginary + a.real * b.real;
	return results;
}

double complex_modulus(t_complex a)
{
	return sqrt(a.real * a.real + a.imaginary * a.imaginary);
}

int main()
{
	t_complex a = {3.0, 4.0};
	t_complex b = {1.0, 2.0};

	t_complex sum = complex_add(a, b);
	printf("SUM:  %.2f + %.2fi\n", sum.real, sum.imaginary);

	t_complex product = complex_multiply(a, b);
	printf("Product: %.2f + %.2fi\n", product.real, product.imaginary);

	double mod = complex_modulus(a);
	printf("Modulus of a : %.2f\n", mod);
}