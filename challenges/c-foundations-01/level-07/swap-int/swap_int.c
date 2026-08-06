void swap_int(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/* #include <stdio.h>
int main()
{
    int a = 2;
    int b = 0;

    printf("a = %d, b = %d\n", a, b);
    swap_int(&a, &b);
    printf("a = %d, b = %d", a, b);
}
 */