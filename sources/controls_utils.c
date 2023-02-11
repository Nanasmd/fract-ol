/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 13:20:56 by nasamadi          #+#    #+#             */
/*   Updated: 2023/02/11 20:52:56 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fractol.h>

int    ft_close_win(t_fractol *fractol)
{
	mlx_loop_end(fractol->mlx);
	if (fractol->image->image)
	{
		mlx_destroy_image(fractol->mlx, fractol->image->image);
		free_image(fractol->image);
	}
	mlx_destroy_window(fractol->mlx, fractol->window);
	mlx_destroy_display(fractol->mlx);
	free(fractol);
	free(fractol->mlx);
	exit (0);
}
