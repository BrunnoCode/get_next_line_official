/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_len.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbotelho <bbotelho@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 10:52:23 by bbotelho          #+#    #+#             */
/*   Updated: 2023/12/11 11:47:34 by bbotelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_len(char *str, int *read_check)
{
	int	i;

	if (!str)
	{
		str = malloc(sizeof(char) * 2);
		if (!str)
			return (*read_check = -1);
	}
	i = 0;
	while (str[i])
		i++;
	printf("\n\n%d read_check \n", *read_check);
	return (i);
}
/*
#include <stdio.h>

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
