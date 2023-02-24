/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 13:25:10 by nasamadi          #+#    #+#             */
/*   Updated: 2023/02/24 06:36:27 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include "../includes/error_message.h"
#include "../libft/includes/libft.h"
#include "../minilibx-linux/mlx.h"
#include <stdlib.h>

int	(*get_formula(char *name))(t_fractol *fractol)
{
	size_t				i;
	int					(*formula)(t_fractol *fractol);
	static t_formula	formulas[] = {
	{"Mandelbrot", &iterate_mandelbrot},
	{"Julia", &iterate_julia},
	{"Burning Ship", &iterate_burning_ship},
	{"Mandelbar", &iterate_mandelbar},
	{"Celtic Mandelbrot", &iterate_celtic_mandelbrot},
	{"Celtic Mandelbar", &iterate_celtic_mandelbar},
	{"Celtic Perpendicular", &iterate_celtic_perpendicular},
	{"Perpendicular Mandelbrot", &iterate_perpendicular_mandelbrot},
	{"Perpendicular Burning Ship", &iterate_perpendicular_burning_ship},
	{"Perpendicular Buffalo", &iterate_perpendicular_buffalo}
	};

	i = 0;
	formula = NULL;
	while (i < (sizeof(formulas) / sizeof(t_formula)))
	{
		if (ft_strequ(name, formulas[i].name))
			formula = formulas[i].formula;
		i++;
	}
	return (formula);
}

void	free_fractol(t_fractol *fractol)
{
	if (fractol->image->image)
	{
		mlx_destroy_image(fractol->mlx, fractol->image->image);
		free_image(fractol->image);
	}
	if (fractol->window)
		mlx_destroy_window(fractol->mlx, fractol->window);
	free(fractol);
}

static void	start(int number, char **names)
{
	t_fractol	*fractols[10];
	void		*mlx;
	int			i;

	i = 0;
	mlx = mlx_init();
	while (i < number)
	{
		fractols[i] = init_fractol(names[i], mlx);
		draw_fractal(fractols[i]);
		i++;
	}
	mlx_loop(mlx);
	i = 0;
	while (i < number)
	{
		free_fractol(fractols[i]);
		i++;
	}
	mlx_destroy_display(mlx);
	free(mlx);
}

static void	startjul(int number, char **names)
{
	t_fractol	*fractols[10];
	void		*mlx;
	int			i;

	i = 0;
	mlx = mlx_init();
	fractols[i] = init_fractol(names[i], mlx);
	if (get_julia_starting_values(fractols[i], number, names))
	{	
		draw_fractal(fractols[i]);
		mlx_loop(mlx);
	}
	free_fractol(fractols[i]);
	mlx_destroy_display(mlx);
	free(mlx);
}

int	main(int argc, char **argv)
{
	int	i;

	if (ft_strequ(argv[1], "Julia"))
	{
		if (argc != 2 && argc != 4)
			return (print_help(), 0);
		else if (!get_formula(argv[1]))
			print_help();
		startjul(argc - 1, &argv[1]);
	}
	else if (argc >= 2 && argc <= 11)
	{
		i = 1;
		while (i < argc)
		{
			if (!get_formula(argv[i]))
				break ;
			i++;
		}
		if (i == argc)
			start(argc - 1, &argv[1]);
	}
	print_help();
	return (0);
}
