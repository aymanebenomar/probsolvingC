#include <unistd.h>
void write_str(char *str)
{
    while (*str)
        write(1, str++, 1);
}
