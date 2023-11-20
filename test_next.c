/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_next.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbotelho <bbotelho@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 21:21:34 by bbotelho          #+#    #+#             */
/*   Updated: 2023/11/20 17:25:14 by bbotelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *str_join(char *storage, char *line)
{
    int i;
    int j;
    char *res;
    
   if(!storage)
    { 
        storage = malloc(sizeof(char) * 1);
        if(!storage)
            return (NULL);
        storage[0] = '\0';
    }
    res = (char*)malloc((ft_length(storage) + 1) + ft_length(line) * sizeof(char));
    if(!res)
        return(my_free(&storage));
    
    
}

char    *ft_findnl(char *str)
{
    unsigned int i;
    
    i = 0;
    while(str[i])
    {
        if(str[i] == '\n')
            return (&str[i]);
        i++;
    }
    return (NULL);
   
}

void    *my_free(char **str)
{
    free(*str);
    *str = NULL;
    return (NULL);
}

char    *ft_alloc(char *line)
{
    char *res;
    int i;

    res = (char *)malloc(sizeof(char) * ( BUFFER_SIZE + 1));
    if(!res)
        return (NULL);
    while(*res)
    {
        res[i++] = '\0';
    }
    return (res);
    
}


char    *read_file(char *storage, int fd)
{
    char *line;
    int n_bytes;

    line = ft_alloc(line);
    if(!line)
        return (my_free(&storage));
    
    n_bytes = 1;
    while(n_bytes > 0 && !ft_findnl(line))
    {
        n_bytes = read(fd, line, BUFFER_SIZE);
        if(n_bytes < 0)
        {
            free(line);
            return(my_free(&storage));
        }
        else if(n_bytes > 0)
        {
            storage = str_join(storage, line);
        }
    }
    free(line);
    return (storage);
}






char    *get_next_line(int fd)
{
    static char *storage = NULL;
    char    *line;
    
    if(fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    storage = read_file(storage, fd); 
    
   
    return (line);
}