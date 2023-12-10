/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   develop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbotelho <bbotelho@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 15:33:02 by bbotelho          #+#    #+#             */
/*   Updated: 2023/12/10 14:35:35 by bbotelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *develop(int fd)
{
    static char *line;
    char    *buffer;
    char    *tmp;
    ssize_t read_check;
    
    read_check = 1;
    if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
        return (NULL);
    buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (!buffer)
        return (NULL);
    while(read_check < 0 && !foundnl(buffer))
    {
        read_check = read(fd, buffer, (BUFFER_SIZE + 1));
        tmp = read_join(buffer, &read_check);  
    }
}
