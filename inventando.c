/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inventando.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbotelho <bbotelho@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 18:03:34 by bbotelho          #+#    #+#             */
/*   Updated: 2023/12/14 16:22:40 by bbotelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
/*
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
    
}*/
void    *alloc_and_free(char **buff) 
{
    if (!*buff)
    {
        *buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
        if (!*buff)
        {
           buff = NULL;
           return (buff);
        }
        else
        {
            *buff[0] = '\0';   
            return; 
        }
    }
    free(*buff);
    buff = NULL;
    return (buff);
}

int    create_line(char **line, char **buff, int error)
{
    int i;
    
    if (!*buff || error == -1)
        return (-1)
    i = BUFFER_SIZE + 1;

    *line = malloc(sizeof(char) * i);
    if (!*line)
        return (free(line), -1);
    *buff[i] = '\0';
    while (i > 0)
     *line[i] = *buff[i--];
    return (1);
}

char    *get_next_line(int fd)
{
    static char *checkpoint[BUFFER_SIZE + 1];
    char    *line;
    char    *buff;
    int bytes_read;
   
    bytes_read = 1;
    line = NULL;
    if (fd < 0 || read(fd, 0, 0) < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    alloc_and_free(&buff);
    while (bytes_read > 0 && !found_nl(buff))
    {
        bytes_read = read(fd, buff, BUFFER_SIZE);
        bytes_read = create_line(&line, &buff, bytes_read); 
    }
    if (found_nl(buff) && bytes_read > 0)
        final_line(&line, &buff, &checkpoint);
    
    return (line);
}
