/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsubchr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 13:00:32 by nasamadi          #+#    #+#             */
/*   Updated: 2023/02/01 17:27:53 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsubchr(const char *s, char c)
{
	char	*ptr;

	ptr = ft_strchrs(s, c);
	if (!ptr)
		return (NULL);
	return (ft_strsub(s, 0, ptr - s));
}
