/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbotelho <bbotelho@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 17:08:34 by bbotelho          #+#    #+#             */
/*   Updated: 2023/12/07 18:21:55 by bbotelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *found_nl(char *buffer)
{
    int i;
    
    if(*buffer)
    {
        i = 0;
        while (buffer[i])
        {
            if (buffer[i] == '\n')
                return ((char *)&buffer[i])
            i++;
        }
    }
    return (0);
}

char    *ft_reading(int fd)
{
    char    *buffer;
    int bytes;
    
    buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if(!buffer)
        return(NULL);
    while(bytes >= 0 && !found_nl(buffer))
    {
        bytes = read(fd, buffer, BUFFER_SIZE);
        if(bytes == BUFFER_SIZE)
            buffer[bytes + 1] = '\0';
        
    }
    return (buffer);
} 

char	*get_next_line(int fd)
{
	static s_no	*head;
	char    *storage;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
    storage = ft_reading(fd);
	
}