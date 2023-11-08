/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbotelho <bbotelho@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 23:51:31 by bbotelho          #+#    #+#             */
/*   Updated: 2023/11/08 18:20:30 by bbotelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_lector(int fd, char **sto)
{
	int	bytes;

	if (!(bytes = read(fd, *sto, BUFFER_SIZE) > 0))
	{
		free(*sto);
		return ;
	}
	while (*sto != (char *)'\n' || *sto != (char *)'\0')
	{
		(sto++);
	}
	sto[bytes + 1] = 0;
}

char	*get_next_line(int fd)
{
	static char	*storage;

	storage = NULL;
	if (BUFFER_SIZE <= 0 || fd < 0 || fd > 1024)
		return (NULL);
	if (!(storage = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1)))
		return (NULL);
	ft_lector(fd, &storage);
	if (!storage)
		free(storage);
	return (storage);
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
