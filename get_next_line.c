/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbotelho <bbotelho@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 23:51:31 by bbotelho          #+#    #+#             */
/*   Updated: 2023/11/12 01:42:17 by bbotelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*memoria(char **reservar, int *err)
{
	int	i;

	*reservar = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!*reservar)
	{
		*err = 1;
		return ;
	}
	i = 0;
	while (i < BUFFER_SIZE)
	{
		(*reservar)[i++] = '\0';
	}
	*err = 0;
}

// void	change(char **next, char **line)
// {

// 	memoria(&res);
// 	memoria(&line);

// }
void	*lector(int fd, int *n_bytes, char **next)
{
	if (*n_bytes < 0)
	{
		free(*next);
		return ;
	}
}

void bucle(char **next, char **line, int *n_bytes, int fd)
{
	int i;
	int	err;
	
	memoria(next, &err);
	if (err)
		return ;
	lector(fd, n_bytes, next);
	i = 0;
	while((*next)[i++] != '\0' && (*next)[i] != '\n')
	{
		//change(*next, *line);
	}
}

char	*get_next_line(int fd)
{
	static char	*next = NULL;
	char		*line;
	int			n_bytes;

	n_bytes = 0;
	line = NULL;
	if (BUFFER_SIZE <= 0 || fd < 0 || fd > 1024)
		return (NULL);
	bucle(&next, &line, &n_bytes, fd);
	
	return (line);
}

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
		return (0);
	do
	{
		line = get_next_line(fd);
		if (line)
		{
			printf("%s", line);
			free(line);
		}
	} while (line);
	close(fd);
	return (0);
}
