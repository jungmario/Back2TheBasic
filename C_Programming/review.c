// #1 : Linux 환경에서 long의 size는 8바이트다
/*
#include <stdio.h>

int main()
{
    long a;

    printf("%lu\n", sizeof(a));

    return 0;
} */

// #2 : C에서 함수 안과 밖의 변수
/*
#include <stdio.h>

int sum();

int main()
{
    int a = 10;
    int b = 20;
    int c = 0;

    c = sum();

    printf("%d\n", c);

    return 0;
}

int sum()
{
    return a + b; // 이렇게 못읽어옴. 파이썬은 가능, 읽기말고 쓰기일때는 둘이 똑같이 작동하지만.
} */

// #3 : C 배열에서 -1로 인덱스가 가능한가?
/*
#include <stdio.h>

int main()
{
    int arr[5] = {1, 2, 3, 4, 5};

    printf("%d\n", arr[-1]); // 이상한 값 튀어나옴, arr(주소)에서 한칸(int니까 4바이트) 뒤로가서 그거 읽어옴ㅋㅋ

    return 0;
}*/

// #4 : unsigned int, int 차이
/*
#include <stdio.h>

int main()
{
    unsigned int a = 4294967295;
    int b = 4294967295;
    printf("%u\n", a - 1);
    printf("%d\n", b - 1);

    return 0;
}  */

// #5 : char, short, long 형 변수
/*
#include <stdio.h>

int main()
{
    char ch = 65;
    short sh = 30000;
    long a = 123;

    printf("%hhd \n", ch);
    printf("%c \n", ch);
    printf("%hd \n", sh);
    printf("%lu \n", sizeof(a));

    return 0;
} */

