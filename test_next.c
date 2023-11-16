/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_next.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbotelho <bbotelho@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 21:21:34 by bbotelho          #+#    #+#             */
/*   Updated: 2023/11/16 22:25:52 by bbotelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


int   read_file(char **storage, char **line, int fd)
{
    int checkpoint;
    *storage = malloc(sizeof(char) * (BUFFER_SIZE +1));
    *line = malloc(sizeof(char) * (BUFFER_SIZE +1));
    if(!*storage || !*line)
    {
        checkpoint = 0;
        return (checkpoint);
    }
    if((read(fd, *storage, BUFFER_SIZE)) > 0)
    {    
        i = 0;
         while((*storage) && (*storage) != '\n' )
        {
            (*line)++ = (*storage)++;
            i++;
        }
        checkpoint  = i
    }
    return (0);  
}



char    *get_next_line(int fd)
{
    static char *storage = NULL;
    char    *line;
    int bolean;
    
    if(fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    
    bolean = read_file(storage, line, fd);
    if(!line || bolean == 0)
    {
        free(line);
        free(storage);
        return (NULL);
    }
    return (line);
}