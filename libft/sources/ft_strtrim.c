/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 13:08:42 by nasamadi          #+#    #+#             */
/*   Updated: 2023/02/01 14:33:02 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_clearable(char c)
{
	return (c == ' ' || c == '\n' || c == '\t'
		|| c == '\v' || c == '\f' || c == '\r');
}

char	*ft_strtrim(char const *s)
{
	size_t			start;
	size_t			end;
	size_t			substr_len;

	if (!s)
		return (NULL);
	if (*s == '\0')
		return (ft_strnew(0));
	start = 0;
	end = ft_strlen(s) - 1;
	while (is_clearable(s[start]) && s[start])
		start++;
	while (is_clearable(s[end]) && s[end] && end > start)
		end--;
	substr_len = end + 1 - start;
	return (ft_strsub(s, start, substr_len));
}
