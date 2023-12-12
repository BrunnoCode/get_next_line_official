/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   develop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbotelho <bbotelho@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 15:33:02 by bbotelho          #+#    #+#             */
/*   Updated: 2023/12/12 15:45:39 by bbotelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *develop(int fd)
{
    static char *line[BUFFER_SIZE];
    char    *buffer;
    //char    *line_return;
    int read_check;
    
    read_check = 1;
    if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
        return (NULL);
    buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (!buffer)
        return (NULL);
    while (read_check > 0)
    {
        read_check = read(fd, buffer, BUFFER_SIZE);
        line = ready_to_read(line, buffer, &read_check);
        if (!buffer || !line || read_check < 0) 
            special_free(&buffer, &line);
       // if (foundnl(line))
           // line = words_aft_newline(line, &buffer, &read_check);
    }
    return (line);
}
