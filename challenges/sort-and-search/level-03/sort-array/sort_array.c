void sort_array(int *tab, unsigned int size)
{
    int i = 0;
    int j = 0;
    int temp;

    while (i < (int)size)
    {
        j = i + 1;
        while (j < (int)size)
        {
            if (tab[i] > tab[j])
            {
                temp = tab[i];
                tab[i] = tab[j];
                tab[j] = temp;
            }
            j++;
        }
        i++;
    }
}

/* #include <stdio.h>
int main()
{
    int tab[] = {1, 0, 5, 3, 4, 2, 9};
    unsigned int n = 7;
    sort_array(tab, n);
    int i = 0;
    while (i < (int)n)
    {
        printf("%d", tab[i++]);
    }
    return 0;
} */