/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbotelho <bbotelho@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:42:36 by bbotelho          #+#    #+#             */
/*   Updated: 2023/11/13 14:11:06 by bbotelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"








void	*ft_get_line(char *storage, char *final_line, int fd)
{
	int n_bytes;
	 if(!storage || !final_line)
	 	return (NULL);
	n_bytes = 0;
	n_bytes = read(fd, storage, BUFFER_SIZE)
	
	
}



char	*get_next_line(int fd)
{
	static	char *storage = NULL;
	char *final_line;
	
	if(BUFFER_SIZE <=0 || fd != 3)
		return (NULL);
	ft_get_line(&storage, &final_line, fd);
	if(!final_line)
		return (NULL);
	return (final_line);
}