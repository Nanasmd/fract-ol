/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 13:20:09 by nasamadi          #+#    #+#             */
/*   Updated: 2023/02/01 12:47:22 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

t_color	get_color(int iteration, t_fractol *fractol)
{
	t_color	color;
	double	t;

	t = (double)iteration / fractol->max_iteration;
	color.channel[0] = 0;
	color.channel[(0 + fractol->color_shift) % 3 + 1]
		= (int8_t)(9 * (1 - t) * pow(t, 3) * 255);
	color.channel[(1 + fractol->color_shift) % 3 + 1]
		= (int8_t)(15 * pow((1 - t), 2) * pow(t, 2) * 255);
	color.channel[(2 + fractol->color_shift) % 3 + 1]
		= (int8_t)(8.5 * pow((1 - t), 3) * t * 255);
	return (color);
}
