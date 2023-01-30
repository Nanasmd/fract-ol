/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 13:21:02 by nasamadi          #+#    #+#             */
/*   Updated: 2023/01/27 14:27:14 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include "../includes/error_message.h"
#include "../includes/color.h"
#include <pthread.h>
#include "../libft/includes/libft.h"
#include "../minilibx-linux/mlx.h"

static void	put_pixel(t_fractol *fractol, int x, int y, t_color color)
{
	int	i;

	i = (x * fractol->image->bits_per_pixel / 8)
		+ (y * fractol->image->size_line);
	fractol->image->data_addr[i] = color.channel[3];
	fractol->image->data_addr[++i] = color.channel[2];
	fractol->image->data_addr[++i] = color.channel[1];
	fractol->image->data_addr[++i] = color.channel[0];
}

/*static void	draw_fractal_part(t_fractol *fractol)
{
	int			y;
	int			x;
	t_color		color;

	y = fractol->start_line;
	while (y < fractol->finish_line)
	{
		fractol->c.im = fractol->max.im - y * fractol->factor.im;
		x = 0;
		while (x < WIDTH)
		{
			fractol->c.re = fractol->min.re + x * fractol->factor.re;
			color = get_color(fractol->formula(fractol), fractol);
			put_pixel(fractol, x, y, color);
			x++;
		}
		y++;
	}
}*/

static void	*draw_fractal_part(void *arg)
{
    t_fractol *fractol = (t_fractol *)arg;
	int			y;
	int			x;
	t_color		color;

	y = fractol->start_line;
	while (y < fractol->finish_line)
	{
		fractol->c.im = fractol->max.im - y * fractol->factor.im;
		x = 0;
		while (x < WIDTH)
		{
			fractol->c.re = fractol->min.re + x * fractol->factor.re;
			color = get_color(fractol->formula(fractol), fractol);
			put_pixel(fractol, x, y, color);
			x++;
		}
		y++;
	}
	return (NULL);
}

void		draw_fractal(t_fractol *fractol)
{
	pthread_t	threads[THREADS];
	t_fractol	fractols[THREADS];
	int			i;

	fractol->factor = init_complex(
		(fractol->max.re - fractol->min.re) / (WIDTH - 1),
		(fractol->max.im - fractol->min.im) / (HEIGHT - 1));
	i = 0;
	while (i < THREADS)
	{
		fractols[i] = *fractol;
		fractols[i].start_line = i * (HEIGHT / THREADS);
		fractols[i].finish_line = (i + 1) * (HEIGHT / THREADS);
		if (pthread_create(&threads[i], NULL, &draw_fractal_part, (void *)&fractols[i]))
		//corr 2 :if (pthread_create(&threads[i], NULL,
		//	draw_fractal_part, (void *)&fractols[i]))
		//	terminate(ERR_TREADS);
		//corr : if (pthread_create(&threads[i], NULL, (void *(*)(void *))draw_fractal_part, (void *)&fractols[i]))
		//if (pthread_create(&threads[i], NULL,
		//	(void *(*)(void *))draw_fractal_part, (void *)&fractols[i]))
			terminate(ERR_TREADS);
		i++;
	}
	while (i-- > 0)
		if (pthread_join(threads[i], NULL))
			terminate(ERR_TREADS);
	mlx_put_image_to_window(fractol->mlx, fractol->window,
		fractol->image->image, 0, 0);
	mlx_string_put(fractol->mlx, fractol->window, 900, 965, COLOR_TUNDORA,
		"H - Help");
}

void		draw_help(t_fractol *fractol)
{
	ft_bzero(fractol->image->data_addr,
		WIDTH * HEIGHT * (fractol->image->bits_per_pixel / 8));
	mlx_put_image_to_window(fractol->mlx, fractol->window,
		fractol->image->image, 0, 0);
	mlx_string_put(fractol->mlx, fractol->window, 460, 355, COLOR_SILVER,
		"Controls");
	mlx_string_put(fractol->mlx, fractol->window, 385, 400, COLOR_SILVER,
		"Reset          - R");
	mlx_string_put(fractol->mlx, fractol->window, 385, 430, COLOR_SILVER,
		"Color Shift    - C");
	mlx_string_put(fractol->mlx, fractol->window, 385, 460, COLOR_SILVER,
		"Move           - Arrows");
	mlx_string_put(fractol->mlx, fractol->window, 385, 490, COLOR_SILVER,
		"Zoom           - Scroll");
	mlx_string_put(fractol->mlx, fractol->window, 385, 520, COLOR_SILVER,
		"Iterations     - +/-");
	mlx_string_put(fractol->mlx, fractol->window, 385, 550, COLOR_SILVER,
		"Julia Constant - Mouse");
	mlx_string_put(fractol->mlx, fractol->window, 385, 580, COLOR_SILVER,
		"Mouse Lock     - Space");
	mlx_string_put(fractol->mlx, fractol->window, 385, 610, COLOR_SILVER,
		"Close Help     - H");
}