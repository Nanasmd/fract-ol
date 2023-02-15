/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 13:19:38 by nasamadi          #+#    #+#             */
/*   Updated: 2023/02/15 17:27:53 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include "../includes/error_message.h"
#include "../libft/includes/libft.h"
#include "../minilibx-linux/mlx.h"

t_image	*init_image(void *mlx)
{
	t_image		*image;

	image = (t_image *)ft_memalloc(sizeof(t_image));
	if (!image)
		terminate(ERR_IMAGE_INIT);
	image->image = mlx_new_image(mlx, WIDTH, HEIGHT);
	if (!(image->image))
		terminate(ERR_IMAGE_INIT);
	image->data_addr = mlx_get_data_addr(
			image->image,
			&(image->bits_per_pixel),
			&(image->size_line),
			&(image->endian));
	return (image);
}

void	free_image(t_image *image)
{
	if (!image)
		return ;
	if (image->image)
		free(image);
}

t_complex	init_complex(double re, double im)
{
	t_complex	complex;

	complex.re = re;
	complex.im = im;
	return (complex);
}

void	set_defaults(t_fractol *fractol)
{
	fractol->max_iteration = 50;
	fractol->min = init_complex(-2.0, -2.0);
	fractol->max.re = 2.0;
	fractol->max.im = fractol->min.im
		+ (fractol->max.re - fractol->min.re)
		* HEIGHT / WIDTH;
	fractol->k = init_complex(-0.4, 0.6);
	fractol->color_shift = 0;
}
