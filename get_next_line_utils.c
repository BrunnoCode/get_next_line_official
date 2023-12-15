/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbotelho <bbotelho@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 18:02:25 by bbotelho          #+#    #+#             */
/*   Updated: 2023/12/15 15:26:46 by bbotelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *special_free(char **checkpoint)
{
    free(*checkpoint);
    *checkpoint = NULL;
    return (*checkpoint);
}

int ft_len(char *str)
{
    int i;
    
    i = 0;
    while (str[i] != '\0')
        i++;
    return (i);
}

char	*str_join(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*res;

	j = 0;
	if (!s1)
	{
		s1 = malloc(sizeof(char) * 1);
		if (!s1)
			return (NULL);
		s1[0] = '\0';
	}
	res = malloc (sizeof(char) * ((ft_len(s1) + 1) + (ft_len(s2))));
	if (!res)
		return (special_free(&s1));
	i = -1;
	while (s1[++i] != '\0')
		res[i] = s1[i];
	while (s2[j] != '\0')
		res[i++] = s2[j++];
	res[i] = '\0';
	free(s1);
	return (res);
}

int	found_nl(char *s)
{
	int i;
	
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*sub_str(char const *s, unsigned int start, size_t len)
{
	size_t	size;
	size_t	i;
	char	*sub;

	if (!s || len == 0)
		return (NULL);
	size = 0;
	while (s[size])
		size++;
	if (start >= size)
		return (NULL);
	else if (size - start < len)
		sub = malloc((size - start + 1) * (sizeof(char)));
	else
		sub = malloc((len + 1) * (sizeof(char)));
	if (!sub)
		return (NULL);
	i = 0;
	len += start;
	while (s[start] && start < len)
		sub[i++] = s[start++];
	sub[i] = '\0';
	return (sub);
}
