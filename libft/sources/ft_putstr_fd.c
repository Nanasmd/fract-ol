/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 18:49:04 by nasamadi          #+#    #+#             */
/*   Updated: 2023/01/10 18:56:02 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putstr_fd(char const *s, int fd)
{
	ssize_t	result;

	if (s == NULL)
		return ;
	result = write(fd, s, ft_strlen(s));
	if (result == -1)
		ft_putstr("Error");
}
