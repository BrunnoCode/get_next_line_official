/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_get.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbotelho <bbotelho@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 12:34:32 by bbotelho          #+#    #+#             */
/*   Updated: 2023/11/27 12:34:55 by bbotelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line"

char    *get_next_line(int fd)
{
    static char *storage = NULL;
    char    *line;
    
    if(fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
}