//연습문제 5 : 차륜 반경 오차에 따른 이동로봇의 직진 편차 추정
/*
#include <stdio.h>
#include <math.h>

int main()
{
    double W;
    double L;

    double r,D_L, r_L, D_R, r_R, e_L, e_R, N;
    const double pi = 3.1415926535;
    N = 100;

    double R_c;
    double delta, d_drift;

    printf("입력 ) \n");
    printf("r ="); if (scanf("%lf",&r) != 1) return 1;
    printf("W = "); if (scanf("%lf",&W) != 1) return 1;
    printf("eL = "); if (scanf("%lf",&e_L) != 1) return 1;
    printf("eR = "); if (scanf("%lf",&e_R) != 1) return 1;
    printf("L = "); if (scanf("%lf",&L) != 1) return 1;

    printf("\n \n 출력 )\n");

    //계산
    r_L = r * (1 + e_L / 100.0); //오차율로 입력을 받음.
    r_R = r * (1 + e_R / 100.0);

    D_L = 2 * pi * r_L * N;
    D_R = 2 * pi * r_R * N;

    R_c = W / 2 * (D_L + D_R) / (D_R - D_L);

    delta = L / R_c;

    d_drift = R_c * (1 - cos(delta));

    printf("좌/우 바퀴 반경 : %lf m / %lf m\n", r_L, r_R);
    printf("곡률반경 R_c = %lf m\n", R_c);
    printf("편류각 delta = %.2lf deg\n", delta * 180 / pi);
    printf("편류거리 d_drift = %.2lf m\n", d_drift);

    return 0;
    
}

//PPT와 다르게 나와서 PPT에 있는 코드 그대로... 똑같이 나오네 결과가 그냥 PPT에 잘못 적힘

#include <stdio.h>

#include <math.h>

int main(void) {

    double r, W, epsL_pct, epsR_pct, L;

    printf("바퀴 반지름 r(m): "); if (scanf("%lf", &r) != 1) return 1;

    printf("트랙폭 W(m): "); if (scanf("%lf", &W) != 1) return 1;

    printf("좌측 바퀴 오차율 εL(%%): "); if (scanf("%lf", &epsL_pct) != 1) return 1;

    printf("우측 바퀴 오차율 εR(%%): "); if (scanf("%lf", &epsR_pct) != 1) return 1;

    printf("주행 거리 L(m): "); if (scanf("%lf", &L) != 1) return 1;

    // 단위 검증

    if (r <= 0 || W <= 0 || L <= 0) {

    printf("입력값을 확인하세요.\n");

    return 1;


    }

    // 퍼센트 → 비율

    double epsL = epsL_pct / 100.0;

    double epsR = epsR_pct / 100.0;


    // 좌우 바퀴 반경

    double rL = r * (1.0 + epsL);

    double rR = r * (1.0 + epsR);

    // 곡률반경 Rc

    double Rc = (W / 2.0) * (rL + rR) / (rR - rL);

    // 편류각 δ = L / Rc (라디안)

    double delta_rad = L / Rc;

    double delta_deg = delta_rad * 180.0 / M_PI;

    // 편류거리

    double drift = Rc * (1.0 - cos(delta_rad));

    printf("\n[결과]\n");

    printf("좌/우 바퀴 반경: %.4f m / %.4f m\n", rL, rR);

    printf("곡률반경 Rc = %.2f m\n", Rc);

    printf("편류각 δ = %.2f deg\n", delta_deg);

    printf("편류거리 d_drift = %.3f m\n", drift);

    return 0;
}

*/

//3. 반복문 : 계속 반복 실행해야 할 때 사용, 길게 코드를 적지않고 깔끔하게 코드 작성 가능.

// #1 while 문을 사용한 반복문 : 반복 횟수가 정해져 있지 않고, 특정 조건이 만족되는 동안 계속 실행해야 할 때 사용
/*
#include <stdio.h>

int main()
{
    int a = 1;

    while (a < 100000) // a 가 10보다 작으면 계속 반복
    {
        a = a * 2;
    }

    printf(" a : %d\n",a);

    return 0;
} */

// #2 for 문을 사용한 반복문 : 반복 횟수나 범위가 정해져 있을 때 코드를 반복하기 위해.
/*
#include <stdio.h>

int main()
{
    int a = 1;
    int i;

    for (i = 0; i < 3; i++)
    {
        a = a * 2;
    }

    printf(" a : %d\n",a);

    return 0;
}
*/

/*
#include <stdio.h>


int main()
{
    int a = 0;
    int i;
    for (i = 0; i <= 5000; i ++)
    {
        a = a + i;
    }

    printf("a : %d\n", a);

    return 0;
} */

// #3 : do ~ while문 : While문과 유사, 다만 초기 조건이 맞지 않으면 실행하지 않는 While문과 다르게 최소 한번은 실행
/*
#include <stdio.h>

int main ()
{
    int a = 1;

    do
    {
        a = a * 2
    } while (a < 10);
    printf("a : %d\n", a);

    return 0;
} */

// #4 : 반복문의 활용, 중첩 반복문(2차원, 3차원, ...) (0,0), (0,1), (0,2), ...
/*
#include <stdio.h>

int main()
{
    int i, j;

    for(i = 0; i < 3; i++)
    {
        for (j = 0; j < 5; j++) //각 반복문이 모두 다른 제어변수를 사용해야 한다. 같은 제어변수를 사용하면 안쪽 i값이 저장되어 바깥쪽 i범위에 안맞아서 의도한대로 작동하지 않음. 보통 i.j.k 사용
        {
            printf("*");
        }
        printf("\n");
    }
} */
//구구단 만들어보기
/*
#include <stdio.h>

int main()
{
    int i,j;

    for(i = 1; i < 10; i++)
    {
        printf("---------%d단 시작--------\n", i);

        for(j = 1; j < 10 ; j++)
        {
            printf("%d * %d = %d\n", i, j, i * j);
        }
    }

    return 0;
} */

// #5 : 반복문의 활용, break 분기문 특정 경우 만났을때 반복문 종료. 10까지 더하다가 30보다 크면 그만하는 반복문.
/*
#include <stdio.h>

int main()
{
    int i;
    int sum = 0;

    for (i = 1; i <= 10; i++)
    {
        sum += i;

        if (sum > 30) break;
    }

    printf("누적한 값 : %d\n",sum);
    printf("마지막으로 더한 값 : %d\n", i);

    return 0;
} */

// #6 : 반복문의 활용, Continue 분기문 ; 내가 원하는 조건 몇가지는 스킵하고 싶을 때.
/*
#include <stdio.h>

int main()
{
    int i;
    int sum = 0;

    for (i = 0; i <= 100; i++)
    {
        if(( i % 10 ) == 0)
        {
            continue;
        }

        sum += i; // 얘가 건너뛰어지는거다

        if (sum >= 3000) break;
    }

    printf(" sum = %d\n", sum);

    return 0;
}
*/

// #7 : 반복문의 활용, 무한 반복문 : while (1) -> 계속 조건 참임. 반복 횟수 없음. break로 무한 반복문 탈출.
/*
#include <stdio.h>

int main()
{
    while(1)
    {
        printf("Be happy! \n");
    }
    
    return 0;
} */

// 4. 함수 : input을 넣으면 output이 나오는 것

// #1 2개의 함수로 만든 프로그램
/*
#include <stdio.h>

int sum(int x, int y); //선언시에 매개변수 명 생략 가능하다. x랑 y는 여기선 없어도 됨

int main() //코드 몸통이 있어야 설명하기 편함
{
    int a = 10, b = 20;
    int result;

    result = sum(a, b);
    printf("result : %d\n", result);

    return 0;
}

int sum(int x, int y)
{
    int temp;

    temp = x + y;

    return temp;
} */

// #2 매개변수가 없는 함수 숫자 입력받는 함수
/*
#include <stdio.h>

int get_num(void);

int main()
{
    int result;

    result = get_num();

    printf("반환값 : %d\n", result);
    return 0;
}

int get_num()
{
    int num;

    printf("양수 입력 : ");
    scanf("%d",&num);

    return num;
} */

// #3 반환값이 없는 함수 : 이거 왜 안되냐 이거
/*
#include <stdio.h>

void print_char(char ch, int count);

int main()
{
    print_char('@', 5);

    return 0;
}

void print_char(char ch, int count)
{
    int i;

    for (i = 0; i < count; i++)
    {
        printf("%c",ch);

    }

    printf("\n");

    return;
} */

// #4 매개변수와 반환값이 모두 없는 함수 : 걍 줄하나 추가해주는 함수
/*
#include <stdio.h>

void print_line(void);

int main ()
{
    print_line();
    printf("학번           이름          전공           학점\n");
    print_line();

    return 0;
}

void print_line()
{
    int i;

    for (i = 1; i <= 50; i++)
    {
        printf("-");
    }

    printf("\n");

    return;
} */

// #5 재귀호출함수 : 자기 자신을 다시 호출.
/*
#include <stdio.h>

void fruit();

int main()
{
    fruit();

    return 0;
}

void fruit()
{
    printf("apple \n");
    fruit();
} //fruit 무한 작성되게 가능 
 */

/*
 #include <stdio.h>

 void fruit(int count);

 int main ()
 {
    fruit(1); //시행횟수 첫번째

    return 0;
 }

 void fruit(int count)
 {
    printf("apple \n");
    if (count == 3) return; // 함수를 끝낼 땐, break가 아닌 return.
    fruit(count + 1); // count변수값 저장이 안되니 1증가시켜서 넣음.
 }*/
/*
 #include <stdio.h>

 void fruit(int count);

 int main()
 {
    fruit(1);

    return 0;
 }

 void fruit(int count)
 {
    printf("apple\n");
    if (count == 3) return;
    fruit(count + 1); // 이게 여기서 함수 호출해버림 1번 함수 진행 중, 그리고 두번째 함수 진행하다가 또 만나서, 3번째 함수 실행 하고 함수 끝나고 다시 두번째 함수 아래 jam실행하고 첫번째 함수 아래 jam실행. 실행이 안되고 멈춰있는 상태인 것.
    printf("jam\n"); //마지막 jam이 가장 처음 호출한 함수의 마지막. 불릴때마다 복사본을 만들어서 실행시킨다고 생각
 }*/

 // 5. 배열

 // #1 배열의 선언 : 5명의 나이를 저장할 배열을 선언하고 사용하는 방법
 /*
 #include <stdio.h>

 int main(void)
 {
    int ary[5]; //이러면 5개를 선언한거니 번호가 0번부터 4번까지 있는 것. 정수형이라고 C에는 자료형을 설정했다. 파이썬에선 그러지 않음. 즉, 번역하는 단계 추가. 따라서 느림. C는 빠름.


    ary[0] = 10;
    ary[1] = 20;
    ary[2] = ary[0] + ary[1];
    scanf("%d", &ary[3]); // ary[4]는 쓰레기 값이 나오는 걸 보기위해 일부러 세팅안함. 그래서 배열을 설정할 때는 모든 배열 요소를 0으로 밀어버리고 시작하는게 좋다.

    printf("%d\n", ary[2]);
    printf("%d\n", ary[3]);
    printf("%d\n", ary[4]);

    return 0;

 } */

 // #2 배열과 반복문 : 점수 받아서 평균 계산해주기, 배열은 주로 반복문으로 처리한다.
/*
 #include <stdio.h>

 int main()
 {
    int score[5];
    int i;
    int total = 0;
    double avg;

    for (i = 0; i < 5; i++)
    {
        scanf("%d",&score[i]);
    }

    for (i = 0; i < 5; i++)
    {
        printf("%5d", score[i]);
    }

    for (i = 0; i < 5; i++)
    {
        total += score[i];
    }

    avg = total / 5.0;

    printf("\n평균 : %.1lf\n", avg);

    return 0;
 } */

 // #3 sizeof 연산자를 활용한 배열 처리(바이트)
 /*
 #include <stdio.h>

 int main()
 {
    int score[8];
    int i;
    int total = 0;
    double avg;
    int count;

    count = sizeof(score) / sizeof(score[0]);

    for (i = 0; i < count ; i++)
    {
        scanf("%d",&score[i]);
    }

    for (i = 0; i < count; i++)
    {
        total += score[i];
    }

    for (i = 0; i < count ; i++)
    {
        printf("%5d", score[i] );
    }

    avg = total / (double)count;

    printf("\n평균 : %lf\n", avg);

    return 0;
 }*/ //배열이라해서 걍 숫자 다 때려박지말고 같은 의미 숫자들만 한곳에 모아놔라. / int ary[10] = {0} 이러면 맨 앞 0으로 초기화, 나머지에 다 0 들어감 결국, 다 0으로 초기화하는 것과 같음

 // #4 char형 배열의 선언과 초기화 : 문자열을 저장하는 char형 배열, 문자랑 문자열이 다르다는데 이게... 흠...
 /*
 #include <stdio.h>

 int main()
 {
    char str[80] = "applejam";

    printf("최초 문자열 : %s\n", str);
    printf("문자열 입력 : ");
    scanf("%s", str);
    printf("입력 후 문자열 : %s\n", str);
    printf("배열 전체 : %c %c\n ",str[6], str[7]); //뒤에 a,m이 남아있음

    return 0;
 } */

 // #5 문자열을 대입하는 strcpy 함수 구현해보기
 /*
 #include <stdio.h>

 char strcopy(char, char);

 int main()
 {
    char fruit[20] = "strawberry";

    printf("%s\n", fruit);
    char fruit = strcopy(fruit, "banana");
    printf("%s\n", fruit);

    return 0;

 }

 char strcopy(char a, char b)
 {
    a = b;

    return a;
 }*/
/*
 //gemini가 짜준 코드
#include <stdio.h>

// 단일 문자가 아니라 문자열의 시작 주소(char *)를 받도록 선언합니다.
void my_strcopy(char *dest, char *src);

int main()
{
    char fruit[20] = "strawberry";

    printf("복사 전: %s\n", fruit);
    
    // 새로 변수를 만들지 않고, 이미 있는 fruit 배열에 바로 덮어씁니다.
    my_strcopy(fruit, "banana"); 
    
    printf("복사 후: %s\n", fruit);

    return 0;
}

// 직접 구현한 문자열 복사 함수
void my_strcopy(char *dest, char *src)
{
    int i = 0;
    
    // 원본(src)의 글자가 널 문자('\0')를 만나기 전까지 반복
    while (src[i] != '\0') 
    {
        dest[i] = src[i];  // 한 글자씩 차례대로 복사
        i++;
    }
    
    // 반복이 끝나면 목적지(dest) 배열의 맨 끝에 널 문자를 직접 찍어주어 문자열을 닫아줍니다.
    dest[i] = '\0'; 
} */


// #6 문자열 전용 입출력 함수 : gets, puts
/*
#include <stdio.h>

int main()
{
    char str[80];
    gets(str);
    puts("입력된 문자열 : ");
    puts(str);

    return 0;

}*/

//AI가 gets써서 주면 오류날 수 있음. 오류찾기도 굉장히 힘듬. 근데 애초에 안되는데 흠...

/*
#include <stdio.h>

int main()
{
    char str[10];
    
    // stdin(표준 입력 = 키보드)을 통해, 최대 배열 크기(sizeof(str))만큼만 안전하게 받습니다.
    fgets(str, sizeof(str), stdin); //10 넘어가면 막힘 10개까지만 받아짐
    
    puts("입력된 문자열 : ");
    puts(str);

    return 0;
} */

// #7 널 문자가 없는 문자열
/*
#include <stdio.h>

int main ()
{
    char str[5];

    str[0] = 'O';
    str[1] = 'K'; //마지막에 null \0 안넣음
    printf("%s\n",str);

    return 0;
} */

// 진도 다나가고 시간남아서 개뜬금 난수 사용 연습, rand() 함수 기초
/*
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num = rand();

    printf("%d\n",num);

    return 0;
}
*/

// srand() 이용한 난수 초기화 ..? 뭐한거여
/*
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));

    return 0;
} */

// 특정 범위의 정수 난수 생성
/*
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));

    int r1 = rand() %10;
    int r2 = rand() % 100 + 1;
    int r3 = rand() % 21 - 10; // 0~20까지 뽑고 -10해라

    printf("0~9 랜덤: %d\n", r1);
    printf("1~100 랜덤: %d\n", r2);
    printf("-10 ~ 10 랜덤: %d\n", r3);

    return 0;
} */