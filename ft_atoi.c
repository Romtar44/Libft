/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtournet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 14:01:16 by rtournet          #+#    #+#             */
/*   Updated: 2021/05/26 12:43:26 by rtournet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_len(char *str)
{
	size_t	c;

	c = 0;
	while (str[c] && ft_isdigit(str[c]))
		c++;
	if (c > 19)
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	int	result;
	int	sign;

	result = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		sign = -1;
		str++;
	}
	if (ft_len((char *)str))
	{
		if (sign == -1)
			return (0);
		return (-1);
	}
	while (ft_isdigit(*str) && *str)
		result = result * 10 + *str++ - 48;
	return (result * sign);
}
