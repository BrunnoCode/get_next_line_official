/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbotelho <bbotelho@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 23:51:31 by bbotelho          #+#    #+#             */
/*   Updated: 2023/10/31 12:47:56 by bbotelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*line;
	char *text_readed;
	char	*adress;

	adress = &fd;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = read(fd, text_readed, BUFFER_SIZE);
	if(line < 0)
		return (NULL);
	while()


}

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("test.txt", O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (line == 0)
			break ;
		printf("%s", line);
	}
	close(fd);
	return (0);
}
