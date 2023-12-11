/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbotelho <bbotelho@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 12:14:07 by bbotelho          #+#    #+#             */
/*   Updated: 2023/12/11 14:26:10 by bbotelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void    *special_free(char **pt1, char **pt2)
{
    if (*pt1 && *pt2)
    {
        free(*pt1);
        free(*pt2);
        pt1 = NULL;
        pt2 = NULL;
    }
    if(*pt1 == NULL && *pt2 != NULL)
    {
        free(*pt2);
        pt2 = NULL;
        return (NULL);
    }
    if(*pt1 != NULL && *pt2 == NULL)
    {
        free(*pt1);
        pt1 = NULL;
        return (NULL);
    }
    return (NULL);
}
