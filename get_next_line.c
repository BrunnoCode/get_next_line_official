/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbotelho <bbotelho@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 23:51:31 by bbotelho          #+#    #+#             */
/*   Updated: 2023/11/08 19:36:39 by bbotelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_join(char **line, char **sto)
{
	while(*sto != NULL)
	{
		*line = *sto;
		line++;
		sto++;
	}
}

int	str_len(char *sto)
{
	int i;

	i = 0;
	while(*sto != 0)
	{
		i++;
	}
	return (i);
}

void	ft_lector(int fd, char **sto)
{
	int	bytes;
	*sto[0] = '\0';

	bytes = read(fd, *sto, BUFFER_SIZE); 
	if(bytes < 0)
	{
		free(sto);
		return ;
	}
	while (*sto != (char *)'\n' && *sto != (char *)'\0')
	{
		sto++;
	}
	*sto[bytes] = 0;
}

char	*get_next_line(int fd)
{
	static char	*storage = NULL;
	char *line;

	if (BUFFER_SIZE <= 0 || fd < 0 || fd > 1024)
		return (NULL);
	if (!(storage = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1)))
		return (NULL);
	ft_lector(fd, &storage);
	if (!storage)
		free(storage);
	line = (char*)malloc(sizeof(char) * str_len(storage));
		if(!line)
			return(0);
		ft_join(&line, &storage);
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
