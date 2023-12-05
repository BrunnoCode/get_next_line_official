/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_next.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbotelho <bbotelho@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 21:21:34 by bbotelho          #+#    #+#             */
/*   Updated: 2023/12/05 19:41:51 by bbotelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*my_free(char **str, char **str2)
{
	if (*str && str)
	{
		free(*str);
		*str = NULL;
	}
	if (*str2 && str2)
	{
		free(*str2);
		*str2 = NULL;
	}
	return (NULL);
}

int	ft_length(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_alloc(char *line)
{
	line = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!line)
		return (NULL);
	return (line);
}

char	*str_join(char *storage, char *line)
{
	int		i;
	int		j;
	char	*res;

	res = malloc((ft_length(storage) + (ft_length(line) + 1)) * sizeof(char));
	if (!res)
		return (my_free(&line, &storage));
	i = 0;
	while (storage[i] != '\0')
	{
		res[i] = storage[i];
		i++;
	}
	j = -1;
	while (line[++j] != '\0')
		res[i + j] = line[j];
	res[i + (++j)] = '\0';
	return (res);
}

char	*ft_findnl(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return ((char *)&str[i]);
		i++;
	}
	return (NULL);
}

char	*read_file(char *storage, int fd)
{
	char	*line;
	int		n_bytes;

	line = NULL;
	line = ft_alloc(line);
	if (!line)
	{
		free(line);
		return (NULL);
	}
	n_bytes = 1;
	while (n_bytes > 0 && !ft_findnl(line))
	{
		n_bytes = read(fd, line, BUFFER_SIZE);
		if (n_bytes < 0)
			return (my_free(&line, &storage));
		else if (n_bytes > 0)
			storage = str_join(storage, line);
	}
	free(line);
	return (storage);
}

char	*ft_line(char *storage)
{
	char	*line;
	int		i;
	int		j;

	line = NULL;
	if (!storage)
	{
		return (NULL);
	}
	i = ft_length(storage);
	line = (char *)malloc(sizeof(char) * (i + 1));
	if (!line)
	{
		free(line);
		return (NULL);
	}
	j = -1;
	while (storage[++j] != '\0' && storage[j - 2] != '\n') // && storage[j] != '\n')
	{
		line[j] = storage[j];
		if (storage[j] == '\n')
			j++;
	}
	line[j - 1] = '\0';
	return (line);
}

void	move_storage(char **storage)
{
	while (*(*storage) != '\n')
		(*storage)++;
	if (*(*storage) == '\n')
		(*storage)++;
}

char	*get_next_line(int fd)
{
	static char	*storage = NULL;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!storage)
	{
		storage = malloc(sizeof(char) * 1);
		if (!storage)
			return (NULL);
		storage[0] = '\0';
	}
	storage = read_file(storage, fd);
	line = ft_line(storage);
	move_storage(&storage);
	return (line);
}
