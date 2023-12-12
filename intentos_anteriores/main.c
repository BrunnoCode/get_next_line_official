/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbotelho <bbotelho@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:44:42 by bbotelho          #+#    #+#             */
/*   Updated: 2023/12/12 12:13:40 by bbotelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("nota.txt", O_RDONLY);
	if (fd == -1)
		return (0);
	do
	{
		line = develop(fd);
		//line = get_next_line(fd);
		if (line)
		{
			printf("%s", line);
			free(line);
		}
	} while (line);
	close(fd);
	return (0);
}
