#include <stddef.h>

void *memmove(void *dst, const void *src, size_t n)
{
    unsigned char *d = (unsigned char *)dst;
    const unsigned char *s = (const unsigned char *)src;

    if (d > s)
    {
        d += n;
        s += n;
        while (n > 0)
        {
            d--;
            s--;
            *d = *s;
            n--;
        }
    }
    else
    {
        while (n > 0)
        {
            *d = *s;
            d++;
            s++;
            n--;
        }
    }
    return (dst);
}