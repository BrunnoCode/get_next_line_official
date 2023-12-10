#include "get_next_line"

char    *read_join(char *buffer, int *read_check)
{
    char    *res;

     if (read_check >= 0 && buffer)
     {
        res = malloc(sizeof(char) * (BUFFER_SIZE + 1));
        if (!res)
        {
            read_check = -1;
            special_free(&res, &buffer);
            return (NULL);
        }
     }
     return (NULL);
}