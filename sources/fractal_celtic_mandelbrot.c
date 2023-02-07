/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_celtic_mandelbrot.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 13:21:24 by nasamadi          #+#    #+#             */
/*   Updated: 2023/02/01 14:02:12 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	iterate_celtic_mandelbrot(t_fractol *fractol)
{
	int			iteration;
	t_complex	z;

	iteration = 0;
	z = init_complex(fractol->c.re, fractol->c.im);
	while (pow(z.re, 2.0) + pow(z.im, 2.0) <= 4
		&& iteration < fractol->max_iteration)
	{
		z = init_complex(
				fabs(pow(z.re, 2.0) - pow(z.im, 2.0)) + fractol->c.re,
				2.0 * z.re * z.im + fractol->c.im);
		iteration++;
	}
	return (iteration);
}
