/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 18:38:27 by nasamadi          #+#    #+#             */
/*   Updated: 2023/01/24 12:55:25 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putendl_fd(char const *s, int fd)
{
	ssize_t	result;

	if (s == NULL)
		return ;
	result = write(fd, s, ft_strlen(s));
	if (result == -1)
		ft_putstr("Error");
	result = write(fd, "\n", 1);
	if (result == -1)
		ft_putstr("Error");
}
