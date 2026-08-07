#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>

void    *calloc(size_t nmemb, size_t size)
{
    size_t          total;
    size_t          i;
    unsigned char   *ptr;

    if (nmemb != 0 && size != 0 && nmemb > SIZE_MAX / size)
        return (NULL);

    total = nmemb * size;
    ptr = (unsigned char *)malloc(total);
    if (ptr == NULL)
        return (NULL);

    i = 0;
    while (i < total)
    {
        ptr[i] = 0;
        i++;
    }

    return (ptr);
}