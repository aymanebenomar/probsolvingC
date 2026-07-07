#include <unistd.h>

void print_digits(void)
{
    char nums = '0';
    while (nums <= '9')
    {
        write(1, &nums, 1);
        nums++;
    }
}

