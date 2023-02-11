/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_quit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 08:29:54 by nasamadi          #+#    #+#             */
/*   Updated: 2023/02/08 08:30:52 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	safe_quit(void)
{
	if (info()->img_ptr)
	{
		mlx_destroy_image(info()->mlx_ptr, info()->img_ptr);
		info()->img_ptr = NULL;
	}
	if (info()->win_ptr)
	{
		mlx_destroy_window(info()->mlx_ptr, info()->win_ptr);
		info()->win_ptr = NULL;
	}
	if (info()->mlx_ptr)
	{
		mlx_destroy_display(info()->mlx_ptr);
		info()->mlx_ptr = NULL;
	}
	exit(EXIT_SUCCESS);
	return (0);
}
