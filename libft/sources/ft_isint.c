/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 12:50:47 by nasamadi          #+#    #+#             */
/*   Updated: 2023/02/01 16:28:45 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

t_bool	ft_check_int(const char *str, int *i, int *sign)
{
	unsigned int		result;
	unsigned int		border;
	int					digits;

	result = 0;
	border = (unsigned int)(FT_INT_MAX / 10);
	digits = 0;
	ft_check_sign(str, i, sign);
	while (ft_isdigit(str[*i]))
	{
		if (((result > border || (result == border && (str[*i] - '0') > 7))
				&& *sign == 1)
			|| ((result > border || (result == border && (str[*i] - '0') > 8))
				&& *sign == -1))
			return (false);
		result = result * 10 + (str[(*i)++] - '0');
		digits++;
	}
	return (!str[*i] && digits);
}

t_bool	ft_isint(const char *str, t_bool strict)
{
	int	i;
	int	sign;

	i = 0;
	sign = 1;
	if (!strict)
	{
		while (ft_isspace(str[i]))
			i++;
	}
	return (ft_check_int(str, &i, &sign));
}
