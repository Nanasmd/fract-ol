/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 13:46:23 by nasamadi          #+#    #+#             */
/*   Updated: 2023/02/22 14:05:53 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static double	parse_number(const char *str)
{
	double	result;
	int		decimal_found;
	double	decimal_place;

	result = 0.0;
	decimal_found = 0;
	decimal_place = 1.0;
	while (*str != '\0' && (ft_isdigit(*str) || *str == '.'))
	{
		if (*str == '.')
		{
			decimal_found = 1;
			str++;
			continue ;
		}
		if (decimal_found)
		{
			decimal_place /= 10.0;
			result += (*str - '0') * decimal_place;
		}
		else
			result = result * 10.0 + (*str - '0');
		str++;
	}
	return (result);
}

double	ft_atof(const char *str)
{
	double	result;
	int		sign;

	result = 0.0;
	sign = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	result = parse_number(str);
	return (sign * result);
}
