/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 17:03:44 by nasamadi          #+#    #+#             */
/*   Updated: 2023/02/24 06:29:38 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H

# define FRACTOL_H

# define WIDTH		1000
# define HEIGHT		1000

# define THREADS	10

# include "../libft/includes/libft.h"
# include "key_linux.h"
# include <math.h>
# include <mlx.h>
# include "../minilibx-linux/mlx.h"
# include <stdint.h>

/*
** Color
*/

/*
** channel — un tableau de 4 octets, 
** représentant les canaux de couleur alpha, rouge, vert et bleu d'une couleur
*/

typedef struct s_color
{
	int8_t			channel[4];
}					t_color;

/*
**  Complex number
*/

/*
** re — reel 
** im — imaginaire
*/

typedef struct s_complex
{
	double			re;
	double			im;
}					t_complex;

/*
** Image
*/

/*
** image          — pointeur sur image
** data_addr      — pointeur sur donnees
** bits_per_pixel — profondeur de couleur (nombre de bits par pixel)
** size_line      — taille d'une ligne de pixels
** endian         — endian (ordre de stockage des octets) de l'image
*/

typedef struct s_image
{
	void			*image;
	char			*data_addr;
	int				bits_per_pixel;
	int				size_line;
	int				endian;
}					t_image;

/*
** Fract'ol
*/

/* mlx            — connection MiniLibX*/
/* window         — fenêtre MiniLibX*/
/* image          — image MiniLibX*/
/* max_iteration  — nombre maximum d'itérations*/
/* min            — parties ré et im min d'un ensemble*/
/* max            — parties ré et im max d'un ensemble*/
/* factor         — facteur qui relie les nbr complexes aux pixels de l'image*/
/* c              — nombre complexe "c" (pour les fractales de Mandelbrot)*/
/* k              — nombre complexe "k" (pour les fractales de Julia)*/
/* is_julia_fixed — indicateur booléen si le nombre complexe "k" est fixé*/
/* start_line     — début des thread  (multi-threading)*/
/* finish_line    — la fin des thread (multi-threading)*/
/* color_shift    — changement de couleurs*/
/* formula        — formule fractale*/
/* is_help        — indicateur booléen si l'aide à l'écran est affichée*/

typedef struct s_fractol
{
	void			*mlx;
	void			*window;
	t_image			*image;
	int				max_iteration;
	t_complex		min;
	t_complex		max;
	t_complex		factor;
	t_complex		c;
	t_complex		k;
	t_bool			is_julia_fixed;
	int				start_line;
	int				finish_line;
	int				color_shift;
	int				(*formula)(struct s_fractol *fractol);
	t_bool			is_help;
}					t_fractol;

/*
** Formula
*/

/*
** name    — nom de la fractale
** formula — fonction de la fractale
** pour stocker toutes les formules disponibles 
** et sélectionner la formule appropriée pour dessiner une fractale spécifique
*/

typedef struct s_formula
{
	char			*name;
	int				(*formula)(t_fractol *fractol);
}					t_formula;

/*
** Functions
*/

/*
** Init
*/
t_image				*init_image(void *mlx);

t_complex			init_complex(double re, double im);

void				set_defaults(t_fractol *fractol);

void				free_image(t_image *image);

int					(*get_formula(char *name))(t_fractol *fractol);

/*
** Draw
*/

void				draw_fractal(t_fractol *fractol);

void				draw_help(t_fractol *fractol);

/*
** Fractals
*/

int					iterate_mandelbrot(t_fractol *fractol);

int					iterate_julia(t_fractol *fractol);

void				toggle_julia_fixed(t_fractol *fractol);

int					get_julia_starting_values(t_fractol *fractol,
						int argc, char **argv);

void				handle_args(t_fractol *fractol, int argc, char **argv);

void				update_julia_k(int x, int y, t_fractol *fractol);

t_bool				is_julia_set(t_fractol *fractol);

int					iterate_burning_ship(t_fractol *fractol);

int					iterate_mandelbar(t_fractol *fractol);

int					iterate_celtic_mandelbrot(t_fractol *fractol);

int					iterate_celtic_mandelbar(t_fractol *fractol);

int					iterate_celtic_perpendicular(t_fractol *fractol);

int					iterate_perpendicular_mandelbrot(t_fractol *fractol);

int					iterate_perpendicular_burning_ship(t_fractol *fractol);

int					iterate_perpendicular_buffalo(t_fractol *fractol);

/*
** Color
*/

t_color				get_color(int iteration, t_fractol *fractol);

/*
** Controls
*/

int					ft_close_win(t_fractol *fractol);

int					key_press_help(int key, t_fractol *fractol);

int					key_press(int key, t_fractol *fractol);

int					change_max_iteration(int key, t_fractol *fractol);

int					zoom(int button, int x, int y, t_fractol *fractol);

void				handle_key(int key, t_fractol *fractol);

int					julia_motion(int x, int y, t_fractol *fractol);

/*
** Free
*/

void				init_window_hooks(t_fractol *fractol, char *name);

void				free_fractol(t_fractol *fractol);

/*
** Print
*/

void				print_help(void);

/*
** Init Fractol
*/

t_fractol			*init_fractol(char *name, void *mlx);

void				terminate(char *s);

#endif
