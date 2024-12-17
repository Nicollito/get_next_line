/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimadela <nimadela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 14:17:53 by nimadela          #+#    #+#             */
/*   Updated: 2024/12/17 16:08:13 by nimadela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	sort_stock(char *s, char *stock)
{
	int	i;
	
	i = check_line(s);
	if (!i)
		return;
	ft_strcpy(stock, &s[i]);
}

char	*sort_line(char *s)
{
	char	*res;
	int		i;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\n')
		i++;
	res = malloc(sizeof(char) * i + 1);
	if (!res)
		return (NULL);
	res[i + 1] = '\0';
	while (i)
	{
		res[i] = s[i];
		i--;
	}
	return (res);
}

char	*fill_line(int fd)
{
	ssize_t	b_read;
	char	*res;
	char	*buffer;
	char	*tmp;

	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	while (b_read && !check_line(res))
	{
		b_read = read(fd, buffer, BUFFER_SIZE);
		if (b_read == -1)
		{
			free(buffer);
			return (NULL);
		}
		if (!res)
		{
			res = malloc(sizeof(char) * BUFFER_SIZE + 1);
			if (!res)
			{
				free(buffer);
				return (NULL);
			}
			ft_strcpy(res, buffer);
		}
		else
		{
			res = ft_strjoin(res, buffer);
			if (!res)
			{
				free(buffer);
				return (NULL);
			}
		}
	}
	free(buffer);
	return (res);
}

char	*get_next_line(int fd)
{
	static char	stock[BUFFER_SIZE + 1];
	char		*buffer;
	char		*line;

	buffer = fill_line(fd);
	line = sort_line(buffer);
	sort_stock(buffer, stock);
	free(buffer);
	return (line);
}
