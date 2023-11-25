/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_next.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbotelho <bbotelho@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 21:21:34 by bbotelho          #+#    #+#             */
/*   Updated: 2023/11/25 16:40:31 by bbotelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void    *my_free(char **str)
{
    free(*str);
    *str = NULL;
    return (NULL);
}

char    *ft_alloc(char *line)
{
    int i;

    line = (char *)malloc(sizeof(char) * ( BUFFER_SIZE + 1));
    if(!line)
        return (NULL);
    while(*line)
    {
        line[i++] = '\0';
    }
    return (line);
    
}

int ft_length(char *str)
{
    int i;

    i = 0;
    while(str[i] != '\0')
        i++;
    return (i);
        
}

char    *str_join(char *storage, char *line)
{
    int i;
    int j;
    char *res;
    
    j = 0;
   if(!storage)
    { 
        storage = malloc(sizeof(char) * 1);
        if(!storage)
            return (NULL);
        storage[0] = '\0';
    }
    res = (char*)malloc(((ft_length(storage) + 1) + ft_length(line)) * sizeof(char));
    if(!res)
        return(my_free(&storage));
    i = -1;
    while(storage[++i] != '\0')
        res[i] = storage[i];
    while(line[j] != '\0')
        res[i++] = line[j++];
    res[i] = '\0';
    free(storage);
    return (res);
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


char    *read_file(char *storage, int fd)
{
    char *line;
    int n_bytes;

    line = NULL;
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

char *ft_line(char *storage)
{
    char    *line;
    int i;
    int j;
    
    line = NULL;
    if(!storage)
        return(my_free(&storage));
    i = ft_length(storage);
    line = (char *)malloc(sizeof(char) * (i + 1));
    if(!line)
    {
        free(line);
        my_free(&storage);
        return (NULL);
    }
    j = 0;
    while(i > j && storage[j] != '\n')
    {
         line[j] = storage[j];
         j++;
    }
    line[j] = '\0';
    free(storage);
    
    return (line);
    
}



char    *get_next_line(int fd)
{
    static char *storage = NULL;
    char    *line;
    
    if(fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    storage = read_file(storage, fd); 
    line = ft_line(storage);
    
   
    return (line);
}