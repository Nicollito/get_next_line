/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimadela <nimadela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 12:55:03 by nimadela          #+#    #+#             */
/*   Updated: 2024/12/12 13:23:40 by nimadela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static unsigned int	count_word(char const *s, char c)
{
	unsigned int	i;
	unsigned int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

static char	**free_split(char **res)
{
	unsigned int	i;

	i = 0;
	while (res[i] != NULL)
	{
		free(res[i]);
		res[i] = NULL;
		i++;
	}
	free(res);
	res = NULL;
	return (res);
}

static char	**fill_tab(unsigned int words, char **res, char const *s, char c)
{
	unsigned int	i;
	unsigned int	start;
	unsigned int	wlen;

	i = 0;
	start = 0;
	wlen = 0;
	while (i < words)
	{
		while (s[start] && s[start] == c)
			start++;
		wlen = start;
		while (s[wlen] && s[wlen] != c)
			wlen++;
		res[i] = ft_substr(s, start, wlen - start);
		if (!res[i])
		{
			res = free_split(res);
			return (res);
		}
		start = wlen;
		i++;
	}
	res[i] = NULL;
	return (res);
}

char	**ft_split(char const *s, char c)
{
	char			**res;

	res = ft_calloc(sizeof(char *), (count_word(s, c) + 1));
	if (!res)
		return (NULL);
	res = fill_tab(count_word(s, c), res, s, c);
	if (res == NULL)
		return (NULL);
	return (res);
}