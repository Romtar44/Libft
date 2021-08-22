/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtournet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 17:26:58 by rtournet          #+#    #+#             */
/*   Updated: 2021/05/26 12:35:17 by rtournet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_wordcount(char const *s, char c)
{
	size_t	word;
	size_t	state;

	state = 1;
	word = 0;
	while (*s)
	{
		if (*s == c)
			state = 1;
		else
		{
			if (state == 1)
				word++;
			state = 0;
		}
		s++;
	}
	return (word);
}

size_t	ft_word_length(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (*s && *s != c)
	{
		i++;
		s++;
	}
	return (i);
}

char	**ft_free(char **str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	char	**splited;

	i = 0;
	if (s == 0)
		return (NULL);
	splited = (char **)malloc(sizeof(char *) * (ft_wordcount(s, c) + 1));
	if (!splited)
		return (NULL);
	while (ft_wordcount(s, c))
	{
		while (*s && *s == c)
			s++;
		splited[i] = (char *)malloc(sizeof(char) * (ft_word_length(s, c) + 1));
		if (!splited[i])
			return (ft_free(splited));
		j = 0;
		while (*s != c && *s)
			splited[i][j++] = *s++;
		splited[i][j] = 0;
		i++;
	}
	splited[i] = 0;
	return (splited);
}
