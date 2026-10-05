// 터틀봇 파이(현업에서 장난감으로 봄 응 모르는 사람들이 그렇게 봐), 버거 한화 협동로봇, OMX(모방학습). VLM, VLA 경험 / 자율주행에 대한 이해(parameter 하나하나에 대한 이해) / 자율주행 패키지 하나하나에 대한 이해(고민과 이해가 필요) 무슨 특징이 있고 수정하니까 무슨 영향이 가고 이런 거/ 하드웨어를 막 이만큼 만드는 건 좀... 하드웨어는 적당히, 주행 이해 깊이를 가져가는게 훨씬 좋음. 로보티즈는 덕후 좋아함./ 고생해서 풀어내고 나만의 스킬을 찾고. 문제에 맞닥뜨렸을 때. 집요함과 끈기/ 할거면 제대로 하라는 거지 제대로 하는게 깊이를 가져가라는거고,뭔가를 대하는 태도/ 서울대도 취업안돼서 옴

// #4 : 포인터의 뺄셈과 관계 연산
/*
#include <stdio.h>

int main()
{
    int ary[5] = {10, 20, 30, 40, 50};
    int *pa = ary; // ary + 2가 되네 아 ary = ary + 2 / ary++ 가 안되는거구나
    int *pb = pa + 3; //실제 계산 : pa + 3*sizeof(int)

    printf("pa : %u\n", pa);
    printf("pb : %u\n", pb);
    pa++;
    printf("pb - pa : %u\n", (pb - pa) * sizeof(int)); // 포인터끼리 이거 뺄셈이 되면... 나중에 *pa *pb끼리 뺄셈해야하는데 실수하고 이러면 디버깅도 어렵고 빡세겄는데

    printf("앞에 있는 배열 요소의 값 출력 : ");
    if (pa < pb) printf("%d\n", *pa);
    else printf("%d\n", *pb);

    return 0;
} */

// #5 : 교재 307p 확인문제
/*
#include <stdio.h>
int main()
{
    double ary[5] = { 1.2, 3.5, 7.4, 0.5, 10.0};
    double *pa = ary;
    double *pb = ary + 2;

    printf("pb[-2]의 값 : %lf\n", pb[-2]); //이렇게가 되네....걍 새로운 배열이냐구
    printf("++(*ary)의 값 : %lf\n", ++(*ary));


    return 0;
} */

// #6: 문제 하나 LiDAR센서 분해능 : 360도를 몇개로 나눠서 찍을까 / 하드웨어 선택시 : 너 왜 여기 5V 넣었니, 니 경험말고 Official한 Reference가 뭔데. 하드웨어 만들때 공식 정격을 좀 지키길 그러면 좋을 듯. / 발전문제 하나 더 있음. 나중에 시간날 때 풀어보기.
/*
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL)); // 랜덤 초기화

    double distance_data[360];
    double *pd = distance_data;

    int i;

    //data생성
    for (i = 0; i < 360; i++)
    {
        distance_data[i] = rand() % 400 + 100;
    }

    double min_dist = distance_data[0]; //이러면 되네
    int min_angle = 0; // min_index라고 하는게 일반적

    for (i = 0; i < 360; i++)
    {
        if (min_dist > distance_data[i])
        {
            min_dist = distance_data[i];
            min_angle = i;
        }
    }

    printf("최소 거리 : %lf, 그때의 각도 : %d\n", min_dist, min_angle);

    return 0;
} */

// #7 : 배열을 처리하는 '함수' . 배열의 값을 출력하는 함수. / 오늘 본 긍정적인 뉴스가 있나, 인문학도 중요하다. 사람 잘 살자고 만든거다. General Specialist( T자형 인재 )
/*
#include <stdio.h>

void print_ary(int *pa);

int main()
{
    int ary[5] = { 10, 20, 30, 40, 50 };

    print_ary(ary);

    return 0;
}

void print_ary(int *pa)
{
    int i;

    for (i = 0; i < (sizeof(pa)/sizeof(pa[0])); i++) // sizeof에 한정에서 그냥 pa는 배열이 되지 않는다. 따라서 따로 배열 요소의 개수를 함수에 넣어줘야함. 포인터만으로는 배열의 사이즈를 알 수 없다.
    {
        printf("%d \n", pa[i]);
    }
} */

// #8 : 배열에 값을 입력하는 함수.
/*
#include <stdio.h>

void input_ary(double *pa, int size);
double find_max(double *pa, int size);

int main()
{
    double ary[5];
    double max;
    int size;

    size = sizeof(ary)/sizeof(ary[0]);

    input_ary(ary, size);
    max = find_max(ary, size);
    printf("배열의 최댓값 : %.1lf\n",max);

    return 0;
}

void input_ary(double *pa, int size)
{
    int i;

    printf("%d개의 실수값 입력 \n", size);
    for (i = 0; i < size; i++)
    {
        scanf("%lf", &pa[i]); // 또는 pa + i
    }
}

double find_max(double *pa, int size)
{
    double max;
    int i;

    max = pa[0];
    for( i = 1; i < size; i++)
    {
        if (max < pa[i])
        {
            max = pa[i];
        }
    }

    return max;
} */


// 7. 문자 (아스키 코드 값과 문자 입출력 함수 / 버퍼를 사용하는 입력 함수) 에러 몇번떴는지 이런거. ERROR 글자를 읽을 줄 알아야겠지.

// #1 : 대문자를 소문자로 변경. 아스키 코드 review(A가 65 a가 97)
/*
#include <stdio.h>

int main()
{
    char small, capital = 'G';

    if (capital >= 'A' && capital <= 'Z')
    {
        small = capital + ('a' - 'A');
    }

    printf("대문자 : %c %c", capital, '\n'); //이런 거도 되네
    printf("소문자 : %c\n", small);

    return 0;
} */

// 기습 문제 1: 포인터를 이용한 변수 값 변경
/*
#include <stdio.h>

void change_variable(int *pa,int num); //바꾸고 싶은 변수 주소, 바꿀 숫자

int main()
{
    int a = 10;
    int b = 20;

    printf("포인터 사용 전, a 값 : %d, 바꿀 숫자 : %d\n",a,b);

    change_variable(&a,b);

    printf("포인터 사용 후, a의 값 : %d\n", a);
}

void change_variable(int *pa, int num)
{
    *pa = num;
} */

// 기습 문제 2: 포인터를 이용한 값 교환 (Call by Value vs Call by Reference 차이 이해.)
//Call by value
/*
#include <stdio.h>

void swap(int a, int b);

int main()
{
    int a, b;

    printf("두 값을 입력하세요 : ");
    scanf("%d %d", &a, &b); // 값 여러개 받을 땐 , 찍지말고 그냥 스페이스만 치면 된다. ,를 찍으면 입력할때도 두 숫자사이 ,를 넣어줘야 한다. 중간에 ㄱ을 넣어도 되긴함 10 ㄱ 20이라 하면. 그래도 그냥 스페이스로 띄우기만하는게 국룰 편하게 스페이스나 엔터만 눌러서 숫자를 구분할 수 있도록

    printf("교환 전 : a = %d, b = %d\n", a, b);

    swap(a,b);

    return 0;
}

void swap(int a, int b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;

    printf("교환 후 : a = %d, b = %d\n", a, b);
}*/

//Call by reference
/*
#include <stdio.h>

void swap(int *a, int *b);

int main()
{
    int a, b;

    printf("두 값을 입력하세요 : ");
    scanf("%d %d", &a, &b);

    printf("교환 전 : a = %d, b = %d\n", a, b);

    swap(&a,&b);

    printf("교환 후 : a = %d, b = %d\n", a, b);

    return 0;
}

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
} */

// 기습 문제 3 : 포인터로 배열 요소 순회
/*
#include <stdio.h>

int main()
{
    int arr[5] = { 10, 20, 30, 40, 50};
    int *ap = arr; // &해도 warning뜨지만 출력은 되네

    int i;

    int count;

    count = sizeof(arr)/sizeof(ap[0]);

    for (i = 0; i < count; i++)
    {
        printf("%d번째 배열 요소 출력 : %d\n", i+1, *(ap + i));
    }

    return 0;
}*/

// 기습 문제 4 : 문자열 포인터 - strlen() 함수 직접 구현
/*
#include <stdio.h>

int my_strlen(char *pc);

int main()
{
    char arr[100];
    int length;

    printf("문자열을 입력하세요(100 글자 이하, 띄어쓰기 불가) : ");
    scanf("%s", arr);

    length = my_strlen(arr);
    printf("문자열의 길이 : %d, 문자열 : %s\n", length, arr);

    return 0;
}

int my_strlen(char *pc)
{
    int i = 0;

    while (pc[i] != '\0') // \0문자가 아닌 동안은 계속 돌아라, 그냥 *cp 해도 됨. cp[i] 하지말고. 대신 i++말고 cp++
    {
        i++;
    }

    return i;
} */

// #2 : scanf 함수를 사용한 문자 입력. 공백이나 제어 문자의 입력
#include <stdio.h>

int main()
{
    char ch1, ch2;

    scanf("%c%c", &ch1, &ch2); //이렇게 %c%c를 붙여서 하면 공백까지 문자(아스키코드기반 변환)로 입력 받음 이러고 싶지 않으면 스페이스를 %c 앞뒤에 넣어놔라. 실행시키고 a(space), a(enter) 이런거 쳐보셈

    printf("[%c%c]\n", ch1, ch2);

    return 0;
}
// #3 : getchar 함수와 putchar 함수 사용 : 문자 하나 간단하게 입력받고 출력할 때, 문자 전용 입출력 함수.