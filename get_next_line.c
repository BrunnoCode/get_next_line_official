/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbotelho <bbotelho@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 18:03:34 by bbotelho          #+#    #+#             */
/*   Updated: 2023/12/15 01:25:29 by bbotelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	clean_alloc(char **buffer)
{
	int	i;

	i = BUFFER_SIZE + 1;
	*buffer = malloc(sizeof(char) * i);
	if (!*buffer)
	{
		free(*buffer);
		buffer = NULL;
		return (-1);
	}
	while (i-- > 0)
		(*buffer)[i] = '\0';
	buffer = NULL;
	return (1);
}

char	*create_line(int fd, char *checkpoint)
{
	char	*buffer;
	int		bytes_read;

	bytes_read = clean_alloc(&buffer);
	if (buffer && bytes_read > 0)
	{
		while (bytes_read > 0 && !found_nl(buffer))
		{
			bytes_read = read(fd, buffer, BUFFER_SIZE);
			if (bytes_read < 0)
			{
				free(buffer);
				return (special_free(&checkpoint), NULL);
			}
			if (bytes_read > 0)
				checkpoint = str_join(checkpoint, buffer);
		}
	}
	if (!buffer)
		return (NULL);
	free(buffer);
	return (checkpoint);
}
char	*complete_line(char *checkpoint)
{
	char	*line;
	int		i;

	if (!checkpoint)
		return (NULL);
	i = 0;
	while (checkpoint[i] != '\n' && checkpoint[i] != '\0')
		i++;
	i++;
	line = sub_str(checkpoint, 0, i);
	if (!line)
		return (NULL);
	return (line);
}
char	*save_checkpoint(char *checkpoint)
{
	char	*new_checkpoint;
	int		i;

	if (!checkpoint)
		return (NULL);
	i = 0;
	while (checkpoint[i] != '\n' && checkpoint[i] != '\0')
		i++;
	i++;
	new_checkpoint = sub_str(checkpoint, i, ft_len(checkpoint));
	free(checkpoint);
	return (new_checkpoint);
}

char	*get_next_line(int fd)
{
	static char	*checkpoint = NULL;
	char		*line;

	if (fd < 0 || read(fd, 0, 0) < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	checkpoint = create_line(fd, checkpoint);
	if (!checkpoint)
		return (NULL);
	line = complete_line(checkpoint);
	if (!line)
		return (free(checkpoint), NULL);
	checkpoint = save_checkpoint(checkpoint);
	return (line);
}
