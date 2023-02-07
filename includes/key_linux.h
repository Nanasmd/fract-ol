/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_linux.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 11:46:49 by nasamadi          #+#    #+#             */
/*   Updated: 2023/02/01 12:32:49 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEY_LINUX_H

# include <mlx.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "fractol.h"
# include <stdio.h>
# include <stdlib.h>

# define KEY_LINUX_H

# define MOUSE_SCROLL_UP 4
# define MOUSE_SCROLL_DOWN 5

# define ARROW_LEFT 65361
# define ARROW_RIGHT 65363
# define ARROW_DOWN 65364
# define ARROW_UP 65362

# define NUM_PAD_PLUS 65451
# define NUM_PAD_MINUS 65453

# define MAIN_PAD_ESC 65307
# define MAIN_PAD_SPACE 32
# define MAIN_PAD_C 99
# define MAIN_PAD_H 104
# define MAIN_PAD_R 114
# define MAIN_PAD_PLUS 61
# define MAIN_PAD_MINUS 45

#endif
