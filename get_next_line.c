/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbotelho <bbotelho@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:42:36 by bbotelho          #+#    #+#             */
/*   Updated: 2023/11/14 17:16:30 by bbotelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*file_read(char **storage, char **line, int *n_bytes, int fd)
{
	int i;
	n_bytes = (int*)read(fd, *storage, BUFFER_SIZE);
	if(*n_bytes < BUFFER_SIZE)
		return (NULL);
	(*line) = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if(!(*line))
	{
		(*n_bytes) = -1;
		free(*line);
	}
	i = 0;
	while((*storage)[i] != '\0' || (*storage)[i] == '\n')
	{
		if(*storage[i] == '\n')
			return (NULL);
		(*line)[i] = (*storage)[i];
		i++;
	}
	(*line)[++i] = '\0';
	free(storage);
	return (NULL);
}

char	*get_next_line(int fd)
{
	static	char *storage = NULL;
	char *line;
	int	n_bytes;
	
	if(BUFFER_SIZE <=0 || fd < 0)
		return (NULL);
	n_bytes = 1;
	while(n_bytes > 0)
	{
		file_read(&storage, &line, &n_bytes, fd); 
	}
	if(n_bytes <= 0 || !line)
		return (NULL);
	if(*storage == '\n')
		storage++;
	return (line);
}
