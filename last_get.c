/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_get.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbotelho <bbotelho@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 12:34:32 by bbotelho          #+#    #+#             */
/*   Updated: 2023/12/05 14:04:53 by bbotelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line"

// FUNCION DE LIBERACION Y CONTROL DE ERRORES
void    ft_error_free(char *s1, char *s2, int error)
{
    
}
// FUNCION FT_LENGTH
int ft_length(char *str)
{
    if(*str)
    {
        int i;
        i = 0;
        while(str[i] != '\0')
            i++;
        return (i);
    }
    return (0);
}
//  FIN DE LA FUNCION FT_LENGTH

char    *ft_reading(int fd, char *storage, int error)
{
    char    *buff;
    
    buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if(!buff)
           
}

// FUNCION PRINCIPAL
char    *get_next_line(int fd)
{
    static char *storage = NULL;
    char    *line;
    int error;

    if(fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    error = 1;

    while(error > 0)
    {
        storage = ft_reading(fd, storage, &error); // este es un\ntexto test\ncontando\n
        if(storage)
        {
            line = ft_strjoin(line, storage, &error);
            if(!line)
            {
                free(line);
                error = -1;
                return (NULL);
            }
        }
    }
    if(!line)
        return (NULL);
    return (line);
}
// FIN FUNCION PRNCIPAL
int main()
{
    int fd;
    char    *line = "start";
    fd = open("test.txt", O_RDONLY);

    while(line)
    {
        line = get_next_line(fd);
        if(!line)
        {
            printf("%s\n", line);
            free(line);
        }
    }
    close(fd);
    return(0);
}