/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 13:25:33 by nasamadi          #+#    #+#             */
/*   Updated: 2023/01/27 14:27:50 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include "../libft/includes/libft.h"

void	print_help(void)
{
	ft_putendl("Usage: ./fractol <name>");
	ft_putendl(NULL);
	ft_putendl("You can specify from 1 to 10 names of fractals");
	ft_putendl(NULL);
	ft_putendl("List of available fractals:");
	ft_putendl(" * Mandelbrot");
	ft_putendl(" * Julia");
	ft_putendl(" * Burning Ship");
	ft_putendl(" * Mandelbar");
	ft_putendl(" * Celtic Mandelbrot");
	ft_putendl(" * Celtic Mandelbar");
	ft_putendl(" * Celtic Perpendicular");
	ft_putendl(" * Perpendicular Mandelbrot");
	ft_putendl(" * Perpendicular Burning Ship");
	ft_putendl(" * Perpendicular Buffalo");
}
