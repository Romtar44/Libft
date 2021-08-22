/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtournet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 14:27:49 by rtournet          #+#    #+#             */
/*   Updated: 2021/05/26 12:29:02 by rtournet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sstr;
	char	*str;
	size_t	i;
	size_t	j;

	i = -1;
	if (!s)
		return (NULL);
	sstr = (char *)s;
	j = ft_strlen(sstr);
	if (!len || j <= start)
		return (ft_strdup(""));
	if (j < len)
		len = j;
	str = (char *)malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	j = 0;
	while (s[++i] && j < len)
	{
		if (i >= start)
			str[j++] = s[i];
	}
	str[j] = 0;
	return (str);
}
