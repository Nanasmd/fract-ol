/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 12:57:21 by nasamadi          #+#    #+#             */
/*   Updated: 2023/02/02 15:41:00 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, size_t n)
{
	size_t	i;
	size_t	len;
	char	*result;

	len = ft_strnlen(s1, n);
	result = ft_strnew(len);
	if (!result)
		return (NULL);
	i = -1;
	while (++i < len)
		result[i] = s1[i];
	result[i] = '\0';
	return (result);
}
