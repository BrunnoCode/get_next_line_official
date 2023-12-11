#include "get_next_line"

char    *read_join(char *line, char *buffer, int *read_check)
{
    char    *res;

     if (read_check >= 0 && buffer)
     {
        res = malloc(sizeof(char) * (ft_len(line, read_check) + ft_len(buffer, read_check) + 1));
        if (!res)
        {
            read_check = -1;
            special_free(&res, &buffer);
            return (NULL);
        }
     }
     free(buffer);
     free(tmp);
     return (NULL);
}
