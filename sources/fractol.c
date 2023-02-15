/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 13:25:10 by nasamadi          #+#    #+#             */
/*   Updated: 2023/02/15 17:25:00 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include "../includes/error_message.h"
#include "../libft/includes/libft.h"
#include "../minilibx-linux/mlx.h"

int	(*get_formula(char *name)) (t_fractol *fractol)
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

/*static t_fractol	*init_fractol(char *name, void *mlx)
{
	t_fractol	*fractol;

	fractol = (t_fractol *)ft_memalloc(sizeof(t_fractol));
	if (!fractol)
		terminate(ERR_FRACTOL_INIT);
	fractol->mlx = mlx;
	fractol->window = mlx_new_window(mlx, WIDTH, HEIGHT, name);
	if (!fractol->window)
	{
		free_fractol(fractol);
		terminate(ERR_WINDOW_INIT);
	}
	fractol->image = init_image(mlx);
	if (!fractol->image)
	{
		free_fractol(fractol);
		terminate(ERR_IMAGE_INIT);
	}
	set_defaults(fractol);
	fractol->is_julia_fixed = true;
	fractol->formula = get_formula(name);
	if (!fractol->formula)
	{
		free_fractol(fractol);
		terminate(ERR_FRACTAL_NAME);
	}
	fractol->is_help = false;
	mlx_hook(fractol->window, 2, 0, key_press, fractol);
	mlx_key_hook(fractol->window, key_press, fractol);
	mlx_hook(fractol->window, 17, 0, ft_close_win, fractol);
	mlx_mouse_hook(fractol->window, zoom, fractol);
	if (ft_strequ(name, "Julia"))
		mlx_hook(fractol->window, 6, 0, julia_motion, fractol);
	return (fractol);
}*/

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

int	main(int argc, char **argv)
{
	int	i;

	if (argc >= 2 && argc <= 11)
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
