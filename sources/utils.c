/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 13:25:41 by nasamadi          #+#    #+#             */
/*   Updated: 2023/01/27 14:28:26 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include "../includes/error_message.h"
#include "../libft/includes/libft.h"

void	terminate(char *s)
{
	ft_putendl_fd(s, 2);
	exit(0);
}
