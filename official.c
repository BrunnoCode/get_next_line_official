/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   official.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbotelho <bbotelho@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 20:20:38 by bbotelho          #+#    #+#             */
/*   Updated: 2023/12/06 12:59:22 by bbotelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void    ft_fill_line(char **line, char **storage, int *error)
{
    
}

void    ft_reading(int fd, char **storage, char **line, int *error)
{
    while(error >= 0)
    {
        error = read(fd, *storage, BUFFER_SIZE);
        if(*storage != NULL)
             ft_fill_line(line, storage, error);
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
    ft_reading(fd, &storage, &line, &error);
    // IMPLEMENTAR VERIFICACION DE ERRORES
    if(error < 0)
        return (NULL);
    //
    return (NULL);
}