/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   official.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbotelho <bbotelho@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 20:20:38 by bbotelho          #+#    #+#             */
/*   Updated: 2023/12/05 21:07:15 by bbotelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void    ft_reading(int fd, char **storage, int *error)
{
    while(error >= 0 && !check_nl())
    {
        error = read(fd, *storage, BUFFER_SIZE);
    }
}

char	*get_next_line(int fd)
{
	static char	*storage = NULL;
	char		*line;
    int error;

    error = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
    ft_reading(fd, &storage, &error);
    if(error != -1)
    {
        ft_fill_line(&line)
    }
    free(storage);
    free(line);
    return (NULL);
}