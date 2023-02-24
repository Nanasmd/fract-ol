/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fractol.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 13:25:41 by nasamadi          #+#    #+#             */
/*   Updated: 2023/02/24 06:29:15 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include "../includes/error_message.h"
#include "../libft/includes/libft.h"

static void	init_fractol_data(t_fractol *fractol, char *name, void *mlx)
{
	(void)mlx;
	fractol->window = mlx_new_window(fractol->mlx, WIDTH, HEIGHT, name);
	if (!fractol->window)
	{
		free_fractol(fractol);
		terminate(ERR_WINDOW_INIT);
	}
	fractol->image = init_image(fractol->mlx);
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
}

static void	init_fractol_hooks(t_fractol *fractol, char *name)
{
	(void)name;
	mlx_hook(fractol->window, 2, 0, key_press, fractol);
	mlx_key_hook(fractol->window, key_press, fractol);
	mlx_hook(fractol->window, 17, 0, ft_close_win, fractol);
	mlx_hook(fractol->window, MotionNotify, PointerMotionMask,
		julia_motion, fractol);
	mlx_hook(fractol->window, ButtonPress, ButtonPressMask, zoom, fractol);
}

t_fractol	*init_fractol(char *name, void *mlx)
{
	t_fractol	*fractol;

	fractol = (t_fractol *)ft_memalloc(sizeof(t_fractol));
	if (!fractol)
		terminate(ERR_FRACTOL_INIT);
	fractol->mlx = mlx;
	init_fractol_data(fractol, name, mlx);
	init_fractol_hooks(fractol, name);
	return (fractol);
}

void	terminate(char *s)
{
	ft_putendl_fd(s, 2);
	exit(0);
}
