/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 12:52:03 by nasamadi          #+#    #+#             */
/*   Updated: 2023/02/02 12:26:02 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_numlen(long int n, int minus)
{
	int	numlen;

	numlen = 1;
	while (FT_ABS(n) >= 10)
	{
		n /= 10;
		numlen++;
	}
	return (numlen + minus);
}

t_bool	ft_check_sign(const char *str, int *i, int *sign)
{
	if (str[*i] == '-')
	{
		*sign = -1;
		(*i)++;
	}
	else if (str[*i] == '+')
	{
		*sign = 1;
		(*i)++;
	}
	return (true);
}

char	*ft_itoa(long int n)
{
	char	*str;
	int		numlen;
	int		i;
	int		sign;

	i = 0;
	str = NULL;
	sign = 1;
	ft_check_sign(str, &i, &sign);
	numlen = ft_numlen(n, (sign == -1));
	str = ft_strnew((size_t)numlen);
	if (str)
	{
		str[numlen--] = '\0';
		while (numlen >= (sign == -1))
		{
			str[numlen--] = (char)(FT_ABS(n % 10) + '0');
			n /= 10;
		}
		if (sign == -1)
			str[0] = '-';
	}
	return (str);
}
