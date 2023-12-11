/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbotelho <bbotelho@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 12:14:07 by bbotelho          #+#    #+#             */
/*   Updated: 2023/12/11 12:40:03 by bbotelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void    *special_free(char **pt1, char **pt2)
{
    if (*pt1 && *pt2)
    {
        free(*pt1);
        free(*pt2);
    }
    if(*pt1 == NULL && *pt2 != NULL)
    {
        free(*pt2);
        return (NULL);
    }
    if(*pt1 != NULL && *pt2 == NULL)
    {
        free(*pt1);
        return (NULL);
    }
    return (NULL);
}
int main()
{
    char *pt1 = NULL;
    char *pt2 = NULL;
    printf("%s")
}