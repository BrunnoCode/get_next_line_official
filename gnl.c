/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbotelho <bbotelho@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 22:50:56 by bbotelho          #+#    #+#             */
/*   Updated: 2023/12/08 01:04:23 by bbotelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void      mem(char **buff, int *check)
{
    *buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (!*buff)
        *check = -1;
}

char    *linejoin(char *line, char *buff, int *check)
{
   int  i;
   int  j;
   
   mem(*line, *check);
   i = ft_length()
}

void    read_line(int fd, char **line, char **buff, int *check)
{
    int time;

    time = 0;
    while((*check = (int)read(fd, *buff, BUFFER_SIZE)) >= 0)
    {
       *line = linejoin(*line, *buff, *check);
    }
}

char    *get_next_line(int fd)
{
    static char    *buff = NULL;
    static char *line;
    int check;
    
    line = NULL;
    if(!buff)
       mem(&buff, &check);
    if(fd < 0 || BUFFER_SIZE <= 0 || check == -1)
        return (NULL);
    read_line(fd, &line, &buff, &check);

    
    if(!line || check == -1)
    {
        free(line);
        return (NULL);
    }
    return (line);
}