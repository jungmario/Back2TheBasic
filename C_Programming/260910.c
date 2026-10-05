// #7 : 포인터 배열 선언과 사용. 포인터 배열로 여러 개의 문자열 출력
/*
#include <stdio.h>

int main()
{
    char *pary[5];
    int i;

    pary[0] = "dog"; // "dog"는 문자열 상수
    pary[1] = "elephant";
    pary[2] = "horse";
    pary[3] = "tiger";
    pary[4] = "lion";

    for ( i = 0; i < 5; i++)
    {
        printf("%d번째 포인터가 가르키는 문자열 : %s\n" , i+1 , pary[i]);
        printf("문자열 상수의 주소 : %p\n", pary[i]); //pary[i] : i번째 포인터가 가르키는 값의 주소(문자열이니까). %p : 그 주소값. &pary[i] : pary[i]가 있는 주소
    }

    return 0;
} */


// #8 : 2차원 배열처럼 활용하는 포인터 배열. 여러 개의 1차원 배열을 2차원 배열처럼 사용
/*#include <stdio.h>

int main()
{
    int ary1[4] = {1, 2, 3, 4};
    int ary2[4] = {11, 12, 13, 14};
    int ary3[4] = {21, 22, 23, 24};

    int *pary[3] = { ary1, ary2, ary3 };
    int i, j;

    for (i = 0; i < 3; i++)
    {
        for ( j = 0; j < 4; j++)
        {
            printf("%5d", pary[i][j]); // if) pary[0][1] -> pary[0](ary1)의 [1] -> pary[1] 걍 이중배열처럼 쓸수있다... 이렇게 해도 자동으로 *(pary[0] + 1) : 첫번째 배열 주소 + 1*sizeof() 이렇게 된대... 왜하냐 : 걍 주소만 넣어두니 매모리 낭비가 없음. 각 배열은 딱 필요한 만큼의 바이트만 차지하게 됨. 그리고 변수기에, 그 값은 그자리에 두고 포인터가 가르키는 방향만 바꾸면 두개 전환하는 연산도 순식간에 끝남.
        }
        printf("\n");
    }

    return 0;
}
*/

// #9 : 기습 문제, 가로세로 합구하기
/*
#include <stdio.h>

int main()
{
    int ary[5][6] = {
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0}
    };

    //값 채우기
    int i, j;
    int count = 1;

    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 5; j++)
        {
            ary[i][j] = count;
            ary[4][5] += count;
            count++;
            
        }
    }

    // 각 마지막 열 값 채우기
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 5; j++)
        {
            ary[i][5] += ary[i][j];
        }
    }
    // 각 마지막 행 값 채우기
    for (j = 0; j < 5; j++)
    {
        for (i = 0; i < 4; i++)
        {
            ary[4][j] += ary[i][j];
        }
    }

    //배열 출력
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 6; j++)
        {
            printf("%d ", ary[i][j]);
        }

        printf("\n");
    }
    
    return 0;

} */
/*
#include <stdio.h>

int main()
{
    // 코드를 획기적으로 줄이는 방법: 배열 전체를 한 번에 0으로 초기화
    int ary[5][6] = {0}; 

    int i, j;
    int count = 1;

    // 1. 데이터 채우기 + 모든 합계 누적을 한 번의 루프로 통합
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 5; j++)
        {
            ary[i][j] = count;      // 빈칸에 1~20 숫자 넣기
            
            ary[i][5] += count;     // [가로 합계] 현재 행의 마지막 칸에 누적
            ary[4][j] += count;     // [세로 합계] 현재 열의 마지막 칸에 누적
            ary[4][5] += count;     // [전체 총합] 맨 오른쪽 아래 칸에 누적
            
            count++;
        }
    }

    // 2. 결과 출력
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 6; j++)
        {
            printf("%4d ", ary[i][j]); // 숫자가 예쁘게 정렬되도록 %4d 사용
        }
        printf("\n");
    }
    
    return 0;
} //최적화 된 버전 */

// 11. 응용 포인터

// #1 : 이중 포인터 개념. 포인터와 이중 포인터의 관계
/*
#include <stdio.h>

int main()
{
    int a = 10;
    int *pi;
    int **ppi;
    int ***pppi;

    pi = &a;
    ppi = &pi;
    pppi = &ppi;
    


    printf("-------------------------------\n");
    printf("변수    변숫값     &연산     *연산     **연산     ***연산\n");
    printf("-------------------------------\n");
    printf("   a%10d%10u\n", a, &a);
    printf("  pi%10u%10u%10d\n", pi, &pi, *pi);
    printf(" ppi%10u%10u%10u%10d\n", ppi, &ppi, *ppi, **ppi);
    printf("pppi%10u%10u%10u%10u%10d\n", pppi, &pppi, *pppi, **pppi, ***pppi);
    printf("-------------------------------\n");

    return 0;
} */

/* 참고.
#include <stdio.h>

int main()
{
    int a = 1, b = 2, c = 3;

    a = b = c; //이게 되네;;

    printf("%d\n",a);

    return 0;
} */

// #2 : 이중 포인터 활용 1 : 포인터 값을 바꾸는 함수의 매개변수. 매개변수 : parameter. 포인터 방향 바꾸기
/*
#include <stdio.h>

void swap_ptr(char **ppa, char **ppb);

int main()
{
    char *pa = "success";
    char *pb = "failure";

    printf("pa -> %s, pb -> %s\n", pa, pb);
    swap_ptr(&pa, &pb);
    printf("pa -> %s, pb -> %s\n", pa, pb);

    return 0;
}

void swap_ptr(char **ppa, char **ppb)
{
    char *pt;

    pt = *ppa;

    *ppa = *ppb;
    *ppb = pt;
}*/

// #3 : 이중 포인터 활용 2 : 포인터 배열의 값을 출력하는 함수
/*
#include <stdio.h>

void print_str(char **pps, int cnt);

int main()
{
    char *ptr_ary[] = {"eagle", "tiger", "lion", "squirrel"};
    int count;

    count = sizeof(ptr_ary) / sizeof(ptr_ary[0]);
    print_str(ptr_ary, count);

    return 0;
}

void print_str(char **pps, int cnt)
{
    int i;

    for (i = 0; i < cnt; i++)
    {
        printf("%s\n", pps[i]);
    }
} */

// #4 : 주소로 쓰이는 배열명과 배열의 주소 비교
/*
#include <stdio.h>

int main()
{
    int ary[5];

    printf("  ary의 값 : %u\t", ary);
    printf(" ary의 주소 : %u\n", &ary);
    printf("  ary + 1 : %u\t", ary + 1);
    printf(" &ary + 1 : %u\n", &ary + 1);

    return 0;
} */

// #5 : 2차원 배열과 배열 포인터. 배열 포인터로 2차원 배열의 값 출력
/*
#include <stdio.h>

int main()
{
    int ary[3][4] = { {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    int (*pa)[4]; //1줄당 4개다.
    int i, j;

    pa = ary;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 4; j++)
        {
            printf("%5d", pa[i][j]);
        }
        printf("\n");
    }

    return 0;
} */

// #6 : 2차원 배열과 배열 포인터. 2차원 배열의 값을 출력하는 함수
/*
#include <stdio.h>

void print_ary(int (*)[4]);

int main()
{
    int ary[3][4] = { {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};

    print_ary(ary);

    return 0;
}

void print_ary(int (*pa)[4])
{
    int i, j;

    for (i = 0; i <3; i++)
    {
        for (j = 0; j < 4; j++)
        {
            printf("%5d", pa[i][j]);
        }
        printf("\n");
    }
} */

// #7 : 함수 포인터를 사용한 함수 호출
/*
#include <stdio.h>

int sum(int, int);

int main()
{
    int (*fp)(int, int);
    int res;

    fp = sum;
    res = fp(10,20);
    printf("result : %d\n", res);

    return 0;
}

int sum(int a, int b)
{
    return (a+b);
} */

// #8 : 함수 포인터의 활용. 함수 포인터로 원하는 함수를 호출하는 프로그램. 함수 포인터를 매개변수로.
/*
#include <stdio.h>

void func(int (*fp)(int, int)); // 함수 포인터를 매개변수로 갖는 함수
int sum(int a, int b);
int mul(int a, int b);
int max(int a, int b);

int main()
{
    int sel;

    printf("01 두 정수의 합\n");
    printf("02 두 정수의 곱\n");
    printf("03 두 정수중에서 큰 값 계산\n");
    printf("원하는 연산을 선택하세요 : ");
    scanf("%d", &sel);

    switch(sel)
    {
        case 1: func(sum); break;
        case 2: func(mul); break;
        case 3: func(mul); break;
    }

    return 0;
}

void func(int (*fp)(int, int))
{
    int a, b;
    int res;

    printf("두 정수의 값을 입력하세요 : ");
    scanf("%d%d", &a, &b);
    res = fp(a, b);
    printf("결괏값은 : %d\n", res);
}

int sum(int a, int b)
{
    return (a + b);
}

int mul(int a, int b)
{
    return (a * b);
}

int max(int a, int b)
{
    if (a > b) return a;
    else return b;
} */

// #9 : void 포인터의 사용

// 연습 문제 1 : 센서값 정규화
/*
#include <stdio.h>

void normalize(double *input, double *output, int in_min, int in_max, int out_min, int out_max);
void map(double *input, double *output);

int main()
{
    double sensor[5];
    double norm[5] = {0, 0, 0, 0, 0};

    int in_min, in_max;
    int out_min, out_max;

    printf("센서 입력값 : ");
    scanf("%lf %lf %lf %lf %lf", &sensor[0], &sensor[1], &sensor[2], &sensor[3], &sensor[4]); //& 해줘야됨
    printf("입력 범위 : ");
    scanf("%d %d", &in_min, &in_max);
    printf("출력 범위 : ");
    scanf("%d %d", &out_min, &out_max);

    normalize(sensor, norm, in_min, in_max, out_min, out_max);
    map(sensor, norm);

    return 0;
}

void normalize(double *input, double *output, int in_min, int in_max, int out_min, int out_max)
{
    int i;

    for (i = 0; i < 5; i++)
    {
        output[i] = (input[i] - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
    }
}

void map(double *input, double *output)
{
    printf("[정규화 결과]\n");
    
    int i;

    for (i = 0; i < 5; i++)
    {
        printf("센서[%d] = %.1lf -> 정규화 = %.1lf \n", i, input[i], output[i]);
    }
}*/

// 연습 문제 2 : 나이와 키를 입력한 후 바꾸어 출력
/*
#include <stdio.h>

void swap(char *ary, void *a, void *b);

int main()
{
    int age1, age2;
    double height1, height2;

    printf("첫 번째 사람의 나이와 키 입력 : ");
    scanf("%d %lf", &age1, &height1);
    printf("두 번째 사람의 나이와 키 입력 : ");
    scanf("%d %lf", &age2, &height2);

    swap("int", &age1, &age2);
    swap("double", &height1, &height2);

    printf("첫 번째 사람의 나이와 키 : %d, %.1lf\n", age1, height1);
    printf("두 번째 사람의 나이와 키 : %d, %.1lf\n", age2, height2);

    return 0;
}

void swap(char *ary, void *a, void *b)
{
    if (ary[0] == 'i')
    {
        int temp;
        temp = *(int *)a;

        *(int *)a = *(int *)b;
        *(int *)b = temp;
    }

    if (ary[0] == 'd')
    {
        double temp;

        temp = *(double *)a;
        *(double *)a = *(double *)b;
        *(double *)b = temp;
    }
} */


// 12. 메모리 동적 할 당
// #1 : 동적 할당 함수. 동적 할당한 저장 공간을 사용하는 프로그램 malloc, free 함수.
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *pi;
    double *pd;

    pi = (int *)malloc(sizeof(int));
    if (pi == NULL)
    {
        printf("# 메모리가 부족합니다.\n"); //임베디드로 가면 메모리가 부족행...
        exit(1);
    }

    pd = (double *)malloc(sizeof(double));//malloc하면 그 사이즈만큼 잡고 시작 주소를 void로 반환 하니 앞에 double형 포인터로 형변환을 해줘야함. 왜 그냥 숫자 4로 안할까 -> 시스템마다 int 사이즈가 다를 수 있다. 메모리가 빡빡하면. 그때를 대비해서 이렇게. 

    *pi = 10;
    *pd = 3.4;

    printf("정수형으로 사용 : %d\n", *pi);
    printf("실수형으로 사용 : %.1lf\n", *pd);

    free(pi); // 이렇게 놔주지 않으면, 메모리 누수가 발생한다.
    free(pd);

    return 0;

}