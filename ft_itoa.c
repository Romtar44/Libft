/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtournet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 16:48:00 by rtournet          #+#    #+#             */
/*   Updated: 2021/06/03 13:09:15 by rtournet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_digit_len(long c)
{
	size_t	i;

	i = 0;
	if (c < 0)
	{
		++i;
		c = c * -1;
	}
	if (c == 0)
		return (1);
	while (c)
	{
		c = c / 10;
		++i;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	size_t	i;
	size_t	j;
	char	*str;
	long	num;

	i = 0;
	num = n;
	j = ft_digit_len(num);
	str = (char *)malloc(sizeof(char) * j + 1);
	if (!str)
		return (NULL);
	str[j--] = 0;
	if (num == 0)
		str[0] = 48;
	if (num < 0)
	{
		str[i] = '-';
		num = num * -1;
	}
	while (num > 0)
	{
		str[j--] = (num % 10) + 48;
		num = num / 10;
	}
	return (str);
}
