/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsignedlen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 13:03:44 by nasamadi          #+#    #+#             */
/*   Updated: 2023/02/02 16:03:53 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_unsignedlen(uintmax_t number, unsigned int base)
{
	size_t	size;

	if (base >= 2)
	{
		size = 1;
		number = number / base;
		while (number)
			size++;
	}
	else
		size = 0;
	return (size);
}
