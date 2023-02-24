/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_julia.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 13:21:39 by nasamadi          #+#    #+#             */
/*   Updated: 2023/02/23 18:00:22 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	iterate_julia(t_fractol *fractol)
{
	int			iteration;
	t_complex	z;

	iteration = 0;
	z = init_complex(fractol->c.re, fractol->c.im);
	while (pow(z.re, 2.0) + pow(z.im, 2.0) <= 4
		&& iteration < fractol->max_iteration)
	{
		z = init_complex(
				pow(z.re, 2.0) - pow(z.im, 2.0) + fractol->k.re,
				2.0 * z.re * z.im + fractol->k.im);
		iteration++;
	}
	return (iteration);
}

t_bool	is_julia_fixed(t_fractol *fractol)
{
	if (fractol)
		return (fractol->is_julia_fixed);
	return (false);
}

void	toggle_julia_fixed(t_fractol *fractol)
{
	fractol->is_julia_fixed = !fractol->is_julia_fixed;
	if (fractol->is_julia_fixed)
		fractol->k = init_complex(-0.4, 0.6);
}

void	update_julia_k(int x, int y, t_fractol *fractol)
{
	double	re;
	double	im;

	if (!fractol->is_julia_fixed)
	{
		re = (x - WIDTH / 2.0) * 4.0 / WIDTH;
		im = (y - HEIGHT / 2.0) * 4.0 / WIDTH;
		fractol->k = init_complex(re, im);
		draw_fractal(fractol);
		draw_fractal(fractol);
	}
}
