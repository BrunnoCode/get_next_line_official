/*#include "get_next_line.h"

int foundnl(char *buffer)
{
    int i;

    i = 0;
    while(buffer[i])
    {
        if(buffer[i] == '\n')
            return (1);
        i++;
    }
    return (0);
}
/*
#include <stdio.h>
int main()
{
    char    *frase = "'\n\0'";
    printf("%d", foundnl(frase));
    return (0);

}*/