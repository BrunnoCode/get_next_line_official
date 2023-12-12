/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_len.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbotelho <bbotelho@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 10:52:23 by bbotelho          #+#    #+#             */
/*   Updated: 2023/12/12 12:36:53 by bbotelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_len(char *str, int *read_check)
{
	int	i;

	i = 0;
	if (*read_check != -1)
	{
		/*if (!str)
		{
			str = malloc(sizeof(char) * (BUFFER_SIZE + 1));
			if (!str)
				return (*read_check = -1);
			str[0] =
		}*/
		while (str[i])
			i++;
		return (i);
	}
	return (*read_check);
}
/*
int	main(void)
{
	char	*str;
	char	*str2;
	int read_check = 0;

	str = "hola mundo";
	str2 = NULL;
	printf("str %d \n\nstr2 %d \n\n", ft_len(str, &read_check), ft_len(str2,
			&read_check));
	return (0);
}*/
