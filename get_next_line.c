/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbotelho <bbotelho@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 23:51:31 by bbotelho          #+#    #+#             */
/*   Updated: 2023/11/12 23:47:25 by bbotelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*memory(char **to_alocate, int *error)
{
	int	i;

	*to_alocate = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!*to_alocate)
	{
		*error = 1;
		return 0;
	}
	i = 0;
	while (i < BUFFER_SIZE)
	{
		(*to_alocate)[i++] = '\0';
	}
	*error = 0;
}

// void	change(char **buff, char **line)
// {

// 	memory(&res);
// 	memory(&line);

// }
void	*read_file(int fd, size_t *n_bytes, char **buff)
{
	n_bytes = (size_t*)read(fd, (*buff), BUFFER_SIZE);
	if (*n_bytes < 0)
	{
		free(*buff);
		return NULL;
	}
	
}

void my_loop(char **buff, char **line, size_t *n_bytes, int fd)
{
	int i;
	int	error;
	
	memory(buff, &error);
	memory(line, &error);
	if (error)
		return ;
	read_file(fd, n_bytes, buff);
	i = 0;
	while(i++ < BUFFER_SIZE)
	{
		**line = **buff;
		(*buff)++;
		(*line)++;
	}
	(*line)[++i] = 0;
	free((*buff));
}

char	*get_next_line(int fd)
{
	static char	*buff = NULL;
	char		*line;
	size_t			n_bytes;

	n_bytes = 0;
	line = NULL;
	if (BUFFER_SIZE <= 0 || fd < 0 || fd > 3)
		return (NULL);
	my_loop(&buff, &line, &n_bytes, fd);
	
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
