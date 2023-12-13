/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbotelho <bbotelho@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 18:03:34 by bbotelho          #+#    #+#             */
/*   Updated: 2023/12/13 21:27:47 by bbotelho         ###   ########.fr       */
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
        
    }
    
}

char    *get_next_line(int fd)
{
    static char *checkpoint[BUFFER_SIZE + 1];
    char    *line;

    if (fd < 0 || read(fd, 0, 0) < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    checkpoint = ready_to_read(fd, checkpoint);
}