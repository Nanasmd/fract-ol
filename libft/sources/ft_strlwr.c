/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlwr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 13:12:35 by nasamadi          #+#    #+#             */
/*   Updated: 2023/02/01 17:11:57 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strlwr(char *s)
{
	size_t	i;

	if (s)
	{
		i = 0;
		while (s[i])
		{
			s[i] = (char)ft_tolower(s[i]);
			i++;
		}
	}
	return (s);
}
