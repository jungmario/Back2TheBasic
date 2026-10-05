/*
#include <stdio.h>

int main()
{
    long a;

    printf("%lu\n", sizeof(a));

    return 0;
} */

#include <stdio.h>

int main()
{
    unsigned int a = 4294967295;
    int b = 4294967295;

    printf("%u\n", a + 1);
    printf("%d\n", b - 1);

    return 0;
}