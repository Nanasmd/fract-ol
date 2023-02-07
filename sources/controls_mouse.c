/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls_mouse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 13:20:49 by nasamadi          #+#    #+#             */
/*   Updated: 2023/02/06 15:48:30 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include "../includes/key_linux.h"

static double	interpolate(double start, double end, double interpolation)
{
	return (start + ((end - start) * interpolation));
}

int	zoom(int button, int x, int y, t_fractol *fractol)
{
	t_complex	mouse;
	double		interpolation;
	double		zoom;

	if (!fractol->is_help
		&& (button == MOUSE_SCROLL_UP || button == MOUSE_SCROLL_DOWN))
	{
		mouse = init_complex(
				(double)x / (WIDTH / (fractol->max.re - fractol->min.re))
				+ fractol->min.re,
				(double)y / (HEIGHT / (fractol->max.im - fractol->min.im))
				* -1 + fractol->max.im);
		if (button == MOUSE_SCROLL_UP)
			zoom = 0.80;
		else
			zoom = 1.20;
		interpolation = 1.0 / zoom;
		fractol->min.re = interpolate(mouse.re, fractol->min.re, interpolation);
		fractol->min.im = interpolate(mouse.im, fractol->min.im, interpolation);
		fractol->max.re = interpolate(mouse.re, fractol->max.re, interpolation);
		fractol->max.im = interpolate(mouse.im, fractol->max.im, interpolation);
		draw_fractal(fractol);
	}
	return (0);
}

int	julia_motion(int x, int y, t_fractol *fractol)
{
	if (!fractol->is_help && !fractol->is_julia_fixed)
	{
		fractol->k = init_complex(
				4 * ((double)x / WIDTH - 0.5),
				4 * ((double)(HEIGHT - y) / HEIGHT - 0.5));
		draw_fractal(fractol);
	}
	return (0);
}
