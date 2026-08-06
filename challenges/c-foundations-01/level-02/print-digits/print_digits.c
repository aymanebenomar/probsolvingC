#include <unistd.h>

void print_digits(void)
{
    char num = '0';
    while (num <= '9')
    {
        write(1, &num, 1);
        num++;
    }
}
