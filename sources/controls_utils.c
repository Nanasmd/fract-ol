/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 13:20:56 by nasamadi          #+#    #+#             */
/*   Updated: 2023/02/23 17:57:42 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fractol.h>

int	get_julia_starting_values(t_fractol *fractol, int argc, char **argv)
{
	if (!ft_strequ(argv[1], "Julia") && argc == 1)
	{
		fractol->is_julia_fixed = true;
		fractol->k = (t_complex){-0.4, 0.6};
		return (1);
	}
	fractol->is_julia_fixed = false;
	if (!ft_strchr(argv[1], '.') || !ft_strchr(argv[2], '.'))
		return (print_help(), 0);
	fractol->k = (t_complex){ft_atof(argv[1]), ft_atof(argv[2])};
	if (fractol->k.re > 2.0 || fractol->k.re < -2.0
		|| fractol->k.im >= 2.0 || fractol->k.im <= -2.0)
		return (print_help(), 0);
	return (1);
}

void	handle_args(t_fractol *fractol, int argc, char **argv)
{
	if (!ft_strequ(argv[1], "Julia") && argc > 5)
		print_help();
	get_julia_starting_values(fractol, argc, argv);
}

int	ft_close_win(t_fractol *fractol)
{
	mlx_loop_end(fractol->mlx);
	return (0);
}
