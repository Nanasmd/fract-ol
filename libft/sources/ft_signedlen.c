/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signedlen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 12:56:19 by nasamadi          #+#    #+#             */
/*   Updated: 2023/02/15 16:59:35 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_signedlen(intmax_t number, unsigned int base)
{
	size_t	size;

	size = ft_unsignedlen((uintmax_t)ft_abs(number), base);
	if (number < 0 && size)
		size++;
	return (size);
}
