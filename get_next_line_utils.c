/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimadela <nimadela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 12:55:03 by nimadela          #+#    #+#             */
/*   Updated: 2024/12/12 15:25:47 by nimadela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char    *ft_substr(char const *s, unsigned int start, size_t len)
{
    unsigned int    i;
    char            *string;

    i = 0;
    if (!s)
        return (NULL);
    if (start >= ft_strlen(s))
        len = 0;
    if (len >= ft_strlen(s) - start)
        len = ft_strlen(s) - start;
    string = (char *)malloc(sizeof(char) * len + 1);
    if (string == NULL)
        return (NULL);
    while (len > 0)
    {
        string[i] = s[start];
        i++;
        start++;
        len--;
    }
    string[i] = '\0';
    return (string);
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

char	**ft_split(char const *s)
{
	char			**res;

	res = malloc(sizeof(char *) * 3);
	if (!res)
		return (NULL);
	res = fill_tab(2, res, s, '\n');
	if (res == NULL)
		return (NULL);
	return (res);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	char	*res;

	if (!s1)
		return ((char *)s2);
	if (!s2)
		return ((char *)s1);
	str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (NULL);
	res = str;
	while (*s1)
		*str++ = *s1++;
	while (*s2)
		*str++ = *s2++;
	*str = '\0';
	return (res);
}
