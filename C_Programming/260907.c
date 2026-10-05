/*#include <stdio.h>

int main()
{
    int a = 014;

    printf("%d\n",a);

    return 0;
} */

// 1. 연습문제(반복, 배열)

// # 1 :로그에서 급가속/급제동 이벤트 카운트
/*
#include <stdio.h>

int main()
{
    int speed[10] = {0, 12, 18, 35, 28, 25, 15, 30, 42, 33};
    int count; //배열 요소 개수

    int acc, brk; //급가속, 급제동 횟수
    int i; // 반복문

    //초기화
    count = sizeof(speed)/sizeof(speed[0]);
    acc = 0;
    i = 0;

    for (i = 0; i < count - 1; i++)
    {
        if (speed[i+1] - speed[i] > 10)
        {
            ++acc;
        }

        if (speed[i+1] - speed[i] < -10)
        {
            ++brk;
        }

    }

    printf("급가속 횟수 : %d\n 급제동 횟수 : %d\n", acc, brk);

    return 0;

}*/

// # 2 : 로그에서 급가속/급제동 이벤트 카운트 심화
/*
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int n; // 배열 요소 개수

    printf("로그 데이터 개수를 입력하세요 :"); 
    scanf("%d", &n);
    if (n <= 11)
    {
        printf("요소개수가 너무 적습니다\n");
        
        return 1;
    }

    int speed[n]; 

    int i; //반복

    for (i = 0; i < n; i++)
    {
        speed[i] = 0;
    } // 속도 데이터 배열 초기화

    srand(time(NULL)); // 랜덤 초기화

    int dir = 1; //방향성 : 0이면 -, 1이면 +
    int pre_dir = 1; //이전 방향성
    int dir_count = 0; // 현재 방향성 유지 횟수
    int delta_speed; // 속도 변화량


    //속도 로그데이터 만들기

    for (i = 0; i < n; i++)
    {
        if (dir_count >= 10)
        {
            dir = rand() %2;

            if (dir != pre_dir)
            {
                dir_count = 0;

                pre_dir = dir;
            }

        }

        if (dir == 1) //속도 증가
        {
            delta_speed = rand() %10 + 1;
            speed[i+1] = speed[i] + delta_speed;

            ++dir_count;
        }

        if (dir == 0) //속도 감소
        {
            delta_speed = rand() %10 -10;
            speed[i+1] = speed[i] + delta_speed;

            ++dir_count;
        }

        //0 ~ 200 벗어날시 강제로 방향 바꿈
        
        if (speed[i+1] > 200)
        {
            dir = 0;
            delta_speed = rand() %10 -10;
            speed[i+1] = speed[i] + delta_speed;

            dir_count = 0;
        }

        if (speed[i+1] < 0)
        {
            dir = 1;
            delta_speed = rand() %10 +1;
            speed[i+1] = speed[i] + delta_speed;;

            dir_count = 0;
        }


    }


    //급가속, 급제동 횟수 비교

    int acc = 0;
    int brk = 0;

    for (i = 0; i < n - 1; i++)
    {
        if (speed[i+1] - speed[i] > 7)
        {
            ++acc;
        }

        if (speed[i+1] - speed[i] < -7)
        {
            ++brk;
        }

    }

    for (i = 0; i < n; i++)
    {
        printf("%4d", speed[i]);
    }
    printf("\n급가속 횟수 : %d\n 급제동 횟수 : %d\n", acc, brk);

    return 0;
} */

// #3: 배터리 잔량 히스테리시스 경보 시스템
/*
#include <stdio.h>

int main()
{
    int N; //데이터 개수
    printf("데이터 개수를 입력해주세요 :");
    scanf("%d",&N);

    int battery_data[N];
    int i; //반복
    printf("배터리 데이터를 입력해주세요\n ");
    for (i = 0; i < N; i++)
    {
        scanf("%d", &battery_data[i]); //& 붙는다!
    } //battery_data 배열 초기화



    //히스테리시스 경보 시스템
    printf("배터리 잔량을 체크합니다...\n");

    int battery_status = 0; //0 : Off, 1 : ON

    for (i = 0; i < N; i++)
    {
        if (battery_status == 0 && battery_data[i] <= 30)
        {
            printf("현재 배터리 잔량 : %d , 경고등을 켭니다.\n", battery_data[i]);

            battery_status = 1;
        }

        else if(battery_status == 1 && battery_data[i] >= 35)
        {
            printf("현재 배터리 잔량 : %d, 경고등을 끕니다.\n", battery_data[i]);

            battery_status = 0;
        }

        else{
            printf("현재 배터리 잔량 : %d\n", battery_data[i]);
        }
    }

    return 0;


} */

// #4 : IR 센서 반사값 임계치 분류기
/*
#include <stdio.h>

int main()
{
    int N; // 센서개수
    printf("센서 개수를 입력해주세요 : ");
    scanf("%d",&N);
    if (N < 1 || N > 16)
    {
        printf("센서 개수는 1개 이상 16개 이하입니다.\n");

        return 1;
    }

    double value[N]; //센서 값
    printf("센서 값을 순서대로 입력해주세요\n");
    
    int i;

    for (i = 0; i < N; i++)
    {
        scanf("%lf", &value[i]);
    }

    const int threshold = 500;

    int label[N];
    for (i = 0; i < N; i++)
    {
        if (value[i] < threshold)
        {
            label[i] = 1;
        }

        if (value[i] >= threshold)
        {
            label[i] = 0;
        }
    }

    int black_count = 0;
    for (i = 0; i < N; i++)
    {
        black_count += label[i];
    }

    int sum_index = 0;

    for (i = 0; i < N; i++)
    {
        sum_index += i * label[i];
    }

    double index_avg = 0;
    if (black_count != 0)
    {
        index_avg = (double)sum_index / (double)black_count;
    }
    else if (black_count == 0)
    {
        printf("주변에 검정라인이 탐지되지 않습니다\n");
    }

    if (index_avg >= N/2)
    {
        printf("왼쪽으로 치우쳐져 있습니다.\n");
    }
    else if (index_avg == N/2)
    {
        printf("정확히 정중앙에 있습니다\n");
    }

    else{
        printf("오른쪽에 치우쳐져 있습니다\n");
    }

    
    return 0;
    

} */

// 6. 포인터 : 메모리의 시작 주소.

// #1 : 변수의 메모리 주소 확인
/*
#include <stdio.h>

int main()
{
    int a;
    double b;
    char c;

    printf("int형 변수의 주소 : %u\n", &a);
    printf("double형 변수의 주소 : %u\n", &b);
    printf("char형 변수의 주소 : %u\n", &c);

    return 0;
} */

// #2 : 포인터의 선언과 사용
/*
#include <stdio.h>

int main()
{
    int a;
    int *pa; //int : 나중에 읽을때 어디까지 읽을 것인가. * : 포인터 변수임을 알려줌 * : 포인터 변수이다

    pa = &a; //포인터 변수안에는 주소값(&)만 들어간다. 이거 중요함.
    *pa = 10; // *pa : pa가 가르키는 곳에 10을 넣어라. 여기서의 *과 위 선언 때의 *은 의미가 다름. 여기서의 * : pa가 가르키는 곳의 값. *:간접참조연산자

    printf("포인터로 a값 출력 : %d\n", *pa);
    printf("변수명으로 a값 출력 : %d\n", a);

    return 0;
} */

// #3 : 여러 가지 포인터 사용해보기
/*
#include <stdio.h>

int main()
{
    int a = 10, b = 15, total;
    double avg;
    int *pa, *pb;
    int *pt = &total; //이런 식으로 선언과 동시에 할당도 가능하네
    double *pg = &avg;
    pa = &a; //포인터는 주소값까지 넣어줘야 초기 세팅이 좀 완료되네
    pb = &b;

    *pt = *pa + *pb;
    *pg = *pt / 2.0;

    printf("두 정수의 값 : %d, %d\n",*pa,*pb);
    printf("두 정수의 합 : %d\n", *pt);
    printf("두 정수의 평균 : %.1lf\n", *pg);

    return 0;
} */

// #4 : 포인터에 const 사용
/*
#include <stdio.h>

int main()
{
    int a = 10, b = 20;
    const int *pa = &a; //이러면 *pa = 20; 같이 포인터로 간접 참조하여 a를 바꿀 수 없게 된다."이 포인터(ptr)를 통해서는(간접 참조로는) 값을 바꾸지 않겠다"는 약속일 뿐이다.

    printf("변수 a 값 : %d\n", *pa);

    pa = &b; // const라고 해서 가리키는 대상이 안바뀌는게 아님 그저 간접 참조를 못하게 될 뿐
    printf("변수 b 값 : %d\n", *pa); //바뀐다.

    pa = &a;
    a = 20; //직접 참조로만 바뀜
    printf("변수 a 값 : %d\n", *pa);

    return 0;

} */

// #5 : 주소와 포인터의 크기
/*
#include <stdio.h>

int main()
{
    char ch;
    int in;
    double db;

    char *pc = &ch;
    int *pi = &in;
    double *pd = &db;

    printf("char형 변수의 주소 크기 : %d", sizeof(&ch));
    printf("(64-bit 컴퓨터이기에 8바이트가 나옴)\n");
    printf("int형 변수의 주소 크기 : %d\n", sizeof(&in));
    printf("double형 변수의 주소 크기 : %d\n", sizeof(&db));

    printf("char * 포인터의 크기 : %d\n", sizeof(pc));
    printf("int * 포인터의 크기 : %d\n", sizeof(pi));
    printf("double * 포인터의 크기 : %d\n", sizeof(pd));

    printf("char * 포인터가 가리키는 변수의 크기 : %d\n", sizeof(*pc));
    printf("int * 포인터가 가리키는 변수의 크기 : %d\n", sizeof(*pi));
    printf("double * 포인터가 가리키는 변수의 크기 : %d\n", sizeof(*pd));

    return 0;
} */

// #6 :포인터의 대입 규칙. 허용되지 않는 포인터의 대입
/*
#include <stdio.h>

int main()
{
    int a = 10;
    int *p = &a;
    double *pd;

    pd = p; //p 포인터 값(a의 주소값)을 pd에 대입 -> ...? p는 int 포인터인데? 즉, 시작점은 맞아도... 어디서 끊을지가 잘못됨 형 변환을 사용한 포인터의 대입은 가능.
    printf("%lf\n", *pd);

    return 0;
}*/

// #7 : 포인터를 사용하는 이유. 포인터를 사용한 두 변수의 값 교환(함수 밖 변수를 바꿔버리네............. 미쳤네 그냥) 포인터 말고는 안돼 어케 바꿔 반환값을 받으면 모르는데 그냥 void가 output이면... 주소값으로 해버리니까 영향을 줄 수 있는 거.
/*
#include <stdio.h>

void swap(int *pa, int *pb);

int main()
{
    int a = 10, b = 20;

    printf("swap 함수 사용 전 \n a : %d, b : %d\n", a, b);
    swap(&a, &b);
    printf("사용 후 \n a : %d, b : %d\n", a, b);

    return 0;
}

void swap(int *pa, int *pb)
{
    int temp;

    temp = *pa;
    *pa = *pb;
    *pb = temp;
} */




// 7. 배열과 포인터
/*
// #1 : 배열명으로 배열 요소 사용하기. 배열명에 정수 연산을 수행하여 배열 요소 사용
#include <stdio.h>

int main()
{
    int ary[3];
    int i;

    *(ary + 0) = 10;
    *(ary + 1) = *(ary + 0) + 10;

    printf("세 번째 배열 요소에 키보드 입력: ");
    scanf("%d", ary + 2);

    for (i = 0; i < 3; i++)
    {
        printf("%5d\n", *(ary + i));
    }

    return 0;
} */

// #2 : 배열명처럼 사용되는 포인터
/*
#include <stdio.h>

int main()
{
    int ary[3];
    int *pa = ary;
    int i;

    *pa = 10; // *(pa + 0)과 같음
    *(pa + 1) = 20;
    pa[2] = pa[0] + pa[1]; // ary[2] = ary[0] + ary[1]과 완전히 같음 어차피 배열명이 곧 주소인데 ary랑 pa가 같이 작용하는거. 물론 저장된 위치는 다르겄지만

    for (i = 0; i < 3; i++)
    {
        printf("%5d\n", pa[i]);
    }

    return 0;
} */

// #3 : 배열명과 포인터의 차이. sizeof 연산의 결과가 다르다. 상수와 변수의 차이가 있다.
/*
#include <stdio.h>

int main()
{
    int ary[3] = { 10, 20, 30 };
    int *pa = ary;
    int i;

    printf("배열의 값 : ");
    for (i = 0; i < 3; i++)
    {
        printf("%d\n", *pa);
        pa++; //ary++가 안된다는 거임
    }

    return 0;
} */