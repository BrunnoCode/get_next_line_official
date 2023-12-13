
/*
#include "get_next_line.h"

char	*ready_to_read(char *line, char *buffer, int *read_check)
{
	char	*res;
	int	i;
	int	j;

	if (*read_check >= 0 && buffer)
	{
		res = malloc(sizeof(char) * (ft_len(line, read_check) + ft_len(buffer, read_check) + 1));
		if (!res || *read_check < 0)
		{
			special_free(&res, &buffer);
			return (special_free(&line, &buffer));
		}
		i = -1;
		while (line[++i])
			res[i] = line[i];
		j = -1;
		while (buffer[++j])
			res[i + j] = buffer[j];
		special_free(&line, &buffer);
		return (res);
	}
	free(buffer);
	return (NULL);
}
/*
int	main()
{
	char *line = "hola";
	char *buffer = "buenos dias";
	int	read_check = 1;
	char *res = ready_to_read(line, buffer, &read_check);
	printf("\n%sres->\n%dcheck->", res, read_check);
	return 0;
}*/
