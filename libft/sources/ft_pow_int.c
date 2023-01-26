/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 17:07:56 by nasamadi          #+#    #+#             */
/*   Updated: 2023/01/24 12:55:00 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

intmax_t	ft_pow_int(intmax_t num, int power)
{
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	return (num * (ft_pow_int(num, power - 1)));
}
