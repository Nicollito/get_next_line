/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_gnl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimadela <nimadela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 15:06:53 by nimadela          #+#    #+#             */
/*   Updated: 2024/12/17 10:17:18 by nimadela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <mcheck.h>

int main(void)
{
    int fd;
    char *line;

    fd = open("nbr.txt", O_RDONLY);
    if (fd == -1)
    {
        printf("Erreur lors de l'ouverture du fichier\n");
        return (1);
    }

	while ((line = get_next_line(fd)))
	{
		printf("%s", line);
		free(line);
	}
	// free(line);
    close(fd);
    return (0);
}