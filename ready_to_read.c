#include "get_next_line.h"

static char *with_nl(char *res, char *buffer, int *read_check)
{
    if (!*read_check)
}

char	*ready_to_read(char *line, char *buffer, int *read_check)
{
	char	*res;

	if (foundnl(buffer))
	{
		res = with_nl(res, buffer, *read_check);
        free(buffer);
        return (res);
	}
	if (*read_check >= 0 && buffer)
	{
		res = malloc(sizeof(char) * (ft_len(line, *read_check) + ft_len(buffer,
						*read_check) + 1));
		if (!res || *read_check < 0)
		{
			special_free(&res, &buffer);
			if (line)
				free(line);
			line = NULL;
			return (NULL);
		}
	}
	free(buffer);
	return (NULL);
}
