/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   official.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbotelho <bbotelho@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 20:20:38 by bbotelho          #+#    #+#             */
/*   Updated: 2023/12/06 19:38:19 by bbotelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void    ft_trialloc(char **storage, int *error)
{
    int i;
    
    *storage = malloc(sizeof(char) * (BUFFER_SIZE + 1))
    if(!*storage)
    {
        free(*storage)
        *storage = NULL;
        *error = -1;
    }
    else
    {
        i = BUFFER_SIZE + 1;
        while(0 < i)
            *storage[i--] = '\0';
    }
}

void    ft_fill_line(char **line, char **storage, int *error)
{
    if(NULL != *storage) //SE *STORAGE APUNTE A EJ: *HO\nLA | QUE HAREMOS?
    {
        *storage[error] = '\0';
        while(*(*storage) != '\n' && *(*storage) != '\0')
        {
            // FALTA ALOCAR MEMORIA A LINE BYTE A BYTE
            *(*line)++ = *(*storage)++;
        }
        if(*(*storage) == '\n')
        {
            *++(*line) = malloc(sizeof(char) + 1);
            *(*line) = '\n';
            *++(*line) = '\0';
        }
    }    
}

void    ft_reading(int fd, char **storage, char **line, int *error)
{
    *error = 1;
    while(*error > 0)
    {   
        *error = read(fd, *storage, BUFFER_SIZE);
        if(*storage != NULL && *error != -1)
                ft_fill_line(line, storage, error);
    }
}

char	*get_next_line(int fd)
{
	static char	*storage = NULL;
	char		*line;
    int error;

    error = 0;
    // HAGO UN MALLOC ESPECIAL ANTES DE PASSAR STORAGE
    ft_trialloc(&storage, &error);
    //AVERIGUO ERROR PARA ASEGURAR DE QUE FT_TRIALLOC HA TENIDO EXITO
	if (fd < 0 || BUFFER_SIZE <= 0 || error == -1)
		return (NULL);
    ft_reading(fd, &storage, &line, &error);
    // IMPLEMENTAR VERIFICACION DE ERRORES
    if(error <= 0)
    {
        // TENGO QUE RETIFICAR
        free(storage);
        free(line);
    }
    else
        return (line);
    //
    return (NULL);
}