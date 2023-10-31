/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbotelho <bbotelho@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 23:51:31 by bbotelho          #+#    #+#             */
/*   Updated: 2023/10/31 17:44:37 by bbotelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	ssize_t	*total_len;
	static int count = 0;
	if(count ==  5)
		return (NULL);
	// verifico se nao tem erro
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	// fim verificacao de erro
	// total_len recebe o tamanho necessario de memoria para armazenar a quantidade de buffer
	total_len = (ssize_t *)malloc(sizeof(char) * BUFFER_SIZE);
	// fim de malloc
	// verifico se deu certo
	if (total_len == NULL)
		return (NULL);
	// fim da verificacao
	// total_len recebe a leitura total do buffer
	read(fd, total_len, BUFFER_SIZE);
	count++;
	return ("timur");
}

int	main(void)
{
	int	fd;

	char	*line;
	fd = open("test.txt", O_RDONLY);
	do
	{
		line = get_next_line(fd);
		if(!line)
			return(0);
		printf("%s", line);
	}while(line);
	close(fd);
	return (0);
}
