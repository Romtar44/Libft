/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtournet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 16:12:42 by rtournet          #+#    #+#             */
/*   Updated: 2021/05/26 16:28:00 by rtournet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*lg;

	if (count == 0 || size == 0)
	{
		lg = malloc(0);
		if (!lg)
			return (NULL);
		return (lg);
	}
	lg = malloc(size * count);
	if (!lg)
		return (NULL);
	ft_bzero(lg, (size * count));
	return (lg);
}
