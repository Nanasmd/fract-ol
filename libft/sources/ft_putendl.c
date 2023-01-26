/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 17:58:48 by nasamadi          #+#    #+#             */
/*   Updated: 2023/01/24 12:55:18 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putendl(char const *s)
{
	ssize_t	result;

	if (s == NULL)
		return ;
	result = write(1, s, ft_strlen(s));
	if (result == -1)
		ft_putstr("Error");
	result = write(1, "\n", 1);
	if (result == -1)
		ft_putstr("Error");
}
