/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimadela <nimadela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 13:07:43 by nimadela          #+#    #+#             */
/*   Updated: 2024/12/12 15:18:26 by nimadela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>

#ifndef BUFFER_SIZE 
# define BUFFER_SIZE 1
#endif

char		*get_next_line(int fd);
char		**ft_split(char const *s);
char		*ft_strjoin(char const *s1, char const *s2);
int			ft_strlen(char *s);

#endif