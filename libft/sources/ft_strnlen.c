/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 13:06:36 by nasamadi          #+#    #+#             */
/*   Updated: 2023/02/01 16:37:22 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strnlen(const char *s, size_t maxlen)
{
	char	*ptr;

	if (!s)
		return (0);
	ptr = ft_memchr(s, '\0', maxlen);
	if (ptr)
		return ((size_t)(ptr - s));
	return (maxlen);
}
