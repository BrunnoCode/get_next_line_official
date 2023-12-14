/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inventando.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbotelho <bbotelho@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 18:03:34 by bbotelho          #+#    #+#             */
/*   Updated: 2023/12/14 01:36:21 by bbotelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *ready_to_read(int fd, char *checkpoint)
{
    char    *buffer;
    int bytes_read;
    
    buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if(!buffer)
        return(NULL);
    buffer[0] = '\0';
    bytes_read = 1;
    while (bytes_read > 0 && !found_nl(buffer))
    {
        bytes_read = read(fd, buffer, BUFFER_SIZE);
        if (bytes_read < 0)
        
    }
    
}

void    create_line(char **line, char **checkpoint)
{
    int i;
    
    if (!*checkpoint)
        return (NULL)
    i = BUFFER_SIZE + 1;

    *line = malloc(sizeof(char) * i);
    if (!*line)
        return (free(line), line = NULL)
    *checkpoint[i] = '\0';
    while (i > 0)
     *line[i] = *checkpoint[i--];
}

char    *get_next_line(int fd)
{
    static char *checkpoint[BUFFER_SIZE + 1];
    char    *line;
    char    *rest;
   
    line = NULL;
    if (fd < 0 || read(fd, 0, 0) < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    checkpoint = ready_to_read(fd, checkpoint);
    while (bytes_read > 0)
    {
        bytes_read = read(fd, checkpoint, BUFFER_SIZE);
        create_line(&line, &checkpoint);
        if (!line)
            return (free(line), NULL);
    }
    if (bytes_read < 0)
        return (free(line), NULL);
    if (found_nl(checkpoint))
        return (save_checkpoint(line, checkpoint))
    return (line);
}
