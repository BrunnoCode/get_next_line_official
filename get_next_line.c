/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbotelho <bbotelho@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 23:51:31 by bbotelho          #+#    #+#             */
/*   Updated: 2023/11/06 13:26:22 by bbotelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_lector(int fd)
{
	char	*aux;
	int	i;
	i = 0;
	int lector_bytes;

	lector_bytes = read(fd, lector_bytes, BUFFER_SIZE);
	while(lector_bytes > i)
	{

	}
}


char	*get_next_line(int fd)
{
	static char	*buf;

	if(BUFFER_SIZE <= 0 || fd < 0 || fd > 1024)
		return (NULL);
	buf = malloc(BUFFER_SIZE * sizeof(char) + 1);
	if (!buf)
		return (0);
	ft_lector(fd);
}









/*
int	main(void)
{
	int		fd;
	char	*line;

	fd = open("test.txt", O_RDONLY);
	do
	{
		line = get_next_line(fd);
		if (!line)
			return (0);
		printf("%s", line);
	} while (line);
	close(fd);
	return (0);
}*/
