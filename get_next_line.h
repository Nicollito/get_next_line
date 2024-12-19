/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimadela <nimadela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 13:07:43 by nimadela          #+#    #+#             */
/*   Updated: 2024/12/19 14:26:38 by nimadela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <string.h>
# include <unistd.h>
# include <stdlib.h>

char	*ft_strcpy_until(char *dest, char *src, char delim);
char	*get_next_line(int fd);
char	*fill_line(int fd, char *line);
char	*check_stash(char *stash);
int		check_line(char *s);
ssize_t	ft_strlen(char *s);
char	*ft_strjoin(char *s1, char *s2);

#endif