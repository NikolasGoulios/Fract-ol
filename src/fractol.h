/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoulios <ngoulios@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 19:17:46 by ngoulios          #+#    #+#             */
/*   Updated: 2024/09/30 16:17:45 by ngoulios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

/*what other includes do I need? Maybe the math.h and the classic ones*/

# include <stdlib.h>
# include <limits.h>
# include <unistd.h>
# include <MLX42/MLX42.h>


typedef struct s_complex
{
	double	real;
	double	imaginary;
}	t_complex;

typedef struct s_fractol
{
	
}	t_fractol

# define WIDTH	1200
# define HEIGHT	1200

/*DO MLX functions needs to be declaired here or ... ? Maybe not*/

/* */
#endif