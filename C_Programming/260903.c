//연산자 우선순위와 연산 방향 (전날 진도 다 못나간 부분 마무리)
/*
#include <stdio.h>

int main()
{
    int a = 10, b = 5;
    int res;

    res = a / b * 2; //우선 순위가 같으므로 왼쪽부터 차례로 연산
    printf("res = %d\n", res);

    res = ++a * 3;  // 증감 연산자는 최우선 연산자. a값을 1증가시키고 3을 곱함
    printf("res = %d\n", res);

    res = a > b && a != 5; // a > b의 결과연산 -> a != 5의 결과 연산 -> && 연산
    printf("res = %d\n",res);

    res = a % 3 == 0; // a % 3의 값이 0과 같은지 확인.(=이 최후순위 연산자, 단항연산자(하나로 끝나는거. ++a)가 이항 연산자(숫자 두개이상. * / + - ...)보다 우선순위 높음. 산술 > 관계 > 논리 연산자 순으로 우선순위가 높고 같다면 괄호가 있는 것부터, 괄호가 없다면 왼쪽부터 연산)
    printf("res = %d\n", res);

    return 0;
} */

// C언어 class 2 선택문, 연습문제, 반복문, 함수, 배열

//1. 선택문 : if문 만약에~ 참이면 하고 거짓이면 지나가~ Flow chart그려보기

//#1 : if 문의 기본 형식
/*
#include <stdio.h>

int main()
{
    int a = 20;
    int b = 0;

    if (a > 10) // 소괄호 붙여주고 아래는 중괄호 [조건식]이 참이니 아래 실행, a랑 b크기 바꿔서 거짓이 되게 해본다거나 가능
    {           // 실행할 문장이 한 문장이면 중괄호 생략 가능, 두 문장 이상이면 무조건 중괄호 필요.
        b = a; // [실행문] b = a 대입문 실행
    }

    printf("a : %d, b = %d\n", a, b);

    return 0; //if는 사실상 관계연산자,논리연산자로 대체할 수 있는 부분이 많다.
} */

//#2 : if ~ else문의 사용
/*
#include <stdio.h>

int main()
{
    int a = -1 ;

    if (a >= 0)
    {
        a = 1;
    }
    else
    {
        a = -1; // else문은 이렇게 쓴다.
    }

    printf("a : %d\n", a);

    return 0;
} */

//#3 : if ~ else if ~ else문 사용 3가지 이상의 경우 중 하나를 선택시 사용가능
/*
#include <stdio.h>

int main()
{
    int a = 0, b = 0;

    if (a > 0)
    {
        b = 1;
    }
    else if (a == 0) //디테일하게 하려면 ((a < 10) && (a >= 0))이렇게 조건문도 가능. 0 <= a < 10 이건 안됨
    {
        b = 2;
    }
    else
    {
        b = 3;
    }

    printf("b : %d\n", b);

    return 0;
} */

//#4 : if문 중첩 if문의 실행문으로 if문 사용
/*
#include <stdio.h>

int main()
{
    int a =20, b = 10;

    if (a > 10)
    {
        if (b >= 0)
        {
            b = 1;
        }
        else
        {
            b = -1; // 이런거 솔직히 애초에 if문에서 if ((a > 10) && (b >= 0))이렇게 선행조건으로 진행 가능한데,if 중첩시켜서 논리구조를 길게 만드는 건 좋지 않다.
        }
    } //모든 경우에 대해 else if로 다 체크하는 것 보다는 중간에 if 중첩으로 끊어주면 실행 효율을 높일 수 있다. ex) 1이면 '일'출력... 6이면 '육'출력 할때 다 하나하나 해주는 거 보다는 한 3에서 끊어서 if (a <= 3)일때로 구분해주면 건너뛰게 해줄 수 있잖아.

    printf("a : %d, b : %d\n", a, b);

    return 0;
} // 중괄호를 잘 작성해야 else가 엉뚱한 if와 결합되지 않게 할 수 있다. 중괄호가 없으면 가장 가까운 if에 결합되므로
*/

//#5 : switch ~ case 문
/*
#include <stdio.h>

int main()
{
    int rank, m = 0;

    printf("rank를 입력해주세요 :");
    scanf("%d", &rank); //scanf 사용법 확인
    printf("입력된 rank : %d\n", rank);

    switch (rank)
    {
        case 1: // rank가 1이면 case 뒤에 나오는 숫자랑 같은지 확인, : 쓰는 거 기억
            m = 300;
            printf("%d등을 하셨군요\n", rank);
            break; //이 switch 블록을 벗어나라. switch ~ case문에선 break가 없으면 그 아래 case까지 실행해버림. break가 필요
        case 2: // case문에서는 뒤에 정수만 나와야한다. if문 처럼 하나하나 검사하지 않고 리스트를 쭉 만들어둔뒤 값이 들어오면 점프뛰는 방식라 속도가 빠르다. 정확히 타겟팅해서 날아가야하기 때문에 딱 떨어지는 고정된 간격을 가진 정수로 하는 것. 물론 내부적으로 정수처럼 보이는 ASCII코드로 변환되는 작은 따옴표로 묶인 문자 'A','q'같은거, 1+2같은 계산, 상태를 변호로 묶어두는 enum
            m = 200;
            printf("%d등을 하셨군요\n", rank);
            break;
        case 3:
            m = 100;
            printf("%d등을 하셨군요\n", rank);
            break;
        default: //위의 3경우가 다 아니면
            m = 10;
            printf("ㄲㅂ ㅋㅋ\n");
            break;
    }

    printf("m : %d\n", m);
    
    return 0;
}
*/

// 연습 문제 1 : 이동로봇의 모터 적정성 여부 판단
/*
#include <stdio.h>

int main()
{
    int N,m;
    float SF,DM,R,torque,G,c,g,W,F_min,F_motor; //변하지 않는 g,c는 const double로 하는게 더 낫다. //ROS에서는 소수점 오차 누적을 막기 위해 double이 표준이다..?

    //이동로봇 설계 사양 입력 받기
    printf("-----이동로봇 설계 사양-----\n");

    printf("총 하중(kg): ");
    scanf("%d",&m);

    printf("구동 바퀴 수 : ");
    scanf("%d",&N);

    printf("안전계수 : ");
    scanf("%f",&SF);

    printf("설계마진 (20%% == 1.2로 입력) : ");
    scanf("%f",&DM);

    //모터 및 바퀴 사양 입력 받기
    printf("-----모터 및 바퀴 사양-----\n");

    printf("모터 정격토크(N*m) : ");
    scanf("%f",&torque);

    printf("감속비 : ");
    scanf("%f",&G);

    printf("바퀴 반지름(m) : ");
    scanf("%f",&R);

    //F_min 계산
    c = 0.018; //구름 저항 계수 : 일반적인 고무바퀴 & 아스팔트
    g = 9.81; //[m / s^2]
    W = (float)m * g; // [N] // float로 안바꿔도 됨 알아서 바꿔줌 (암시적 형변환)

    F_min = c * W * SF * DM;
    printf("필요한 최소 견인력 : %.2f\n", F_min);

    //F_motor : 모터 정격 견인력 계산
    F_motor = torque * G * (float)N / R;
    printf("모터가 낼 수 있는 견인력 : %.2f\n",F_motor);

    // 모터 적정성 여부 판정 및 처리
    if (F_min <= F_motor)
    {
        printf("판정 : 만족\n");
    }
    else
    {
        printf("불만족 (더 큰 모터나 감속비가 필요합니다!)\n");
    }

    return 0;

} */


//연습문제 2 : 이동로봇의 배터리 용량 선정, 최적 배터리 양 필요
/*
#include <stdio.h>

int main()
{
    double I_load, vel, R; //모터 관련 사전 선정 정보
    double V, C, eta; // 배터리 관련 사전 선정 정보
    
    printf("----- 모터 선정 정보 -----\n");
    printf("평균 전류(A) : ");
    if (scanf("%lf",&I_load) != 1) return 1;

    printf("평균 선속도(km/h) : ");
    if(scanf("%lf", &vel) != 1) return 1;

    printf("예비율(R, 0 ~ 1) : ");
    if(scanf("%lf", &R) != 1) return 1;

    printf("----- 배터리 선정 정보 -----\n");

    printf("공칭 전압(V) : ");
    if (scanf("%lf",&V) != 1) return 1;

    printf("용량(Ah) : ");
    if (scanf("%lf", &C));

    printf("시스템 효율(eta, 0 ~ 1) : ");
    if (scanf("%lf",&eta) != 1) return 1;

    if (V <= 0 || C <= 0 || I_load <= 0 || vel < 0 || R < 0 || R >= 1 || eta <= 0 || eta > 100)
    {
        printf("입력값 범위를 확인하세요 \n");
        return 1;
    }

    //계산
    const double E_usable = V * C * eta * (1 - R);
    const double P = V * I_load / eta ;
    const double t = E_usable / P ;
    const double d = vel * t;

    printf("[결과]\n");
    printf("사용 가능 에너지 E_usable : %.2lf Wh\n", E_usable);
    printf("런타임 t \t : %.2lf h (%.1lf min)\n", t, t*60);
    printf("주행거리 d \t : %.2lf km\n",d);
    printf("(계산 가정 : 전압강하/온도영향 무시, 평균전류 일정, 전류는 부하측 기준)\n");

    return 0;
} */

// 연습문제 3 : 수학 함수 라이브러리 math.h 추가
/*
#include <stdio.h>
#include <math.h>

int main()
{
    double x, y;

    printf("x의 값을 입력하시오 : ");
    if (scanf("%lf",&x) != 1)
    {
        printf("숫자만 입력하세여ㅋ\n");
        return 1;
    }

    printf("y의 값을 입력하시오 : ");
    if (scanf("%lf",&y) != 1)
    {
        printf("숫자만 입력 하셈 ㅋ\n");
        return 1;
    }

    printf("계산을 시작합니다...\n");
    printf("x의 제곱근 : %lf\n", sqrt(x));
    printf("x의 y제곱 : %lf\n", pow(x,y));
    printf("sin(x) = %lf(rad), cos(x) = %lf(rad)\n", sin(x), cos(x));
    printf("log(x) = %lf\n", log(x));
    printf("x의 절댓값 : %lf\n", fabs(x));

    return 0;
} */

// 연습문제 4 : 이동로봇의 최대 견인력과 등판 가능 경사각
/*
#include <stdio.h>
#include <math.h>

int main ()
{
    int m; //로봇관련
    double T_m, G, eta; //모터관련
    int N_m;
    double r, c; //바퀴 관련 
    double SF; //설계 관련

    //모터 관련 정보 받기
    printf("-----모터 관련 정보-----\n");
    printf("로봇 무게(m, kg) : ");
    if (scanf("%d",&m) != 1) return 1;

    printf("모터 정격 토크(T_m, N*m) : ");
    if (scanf("%lf",&T_m) != 1) return 1;
    printf("구동 모터 수(N_m) : ");
    if (scanf("%d", &N_m) != 1) return 1;
    printf("감속비 : ");
    if (scanf("%lf", &G) != 1) return 1;
    printf("구동 효율(eta, 0 ~ 1) :");
    if (scanf("%lf", &eta) != 1) return 1;
    
    if (T_m <= 0 || N_m <= 0 || G <= 0 || eta <= 0 || eta > 1) return 1;

    //바퀴 관련 정보 받기
    printf("-----바퀴 관련 정보----- \n");
    printf("바퀴 반지름(r ,m) : ");
    if (scanf("%lf", &r) != 1) return 1;
    printf("구름계수(c) : ");
    if (scanf("%lf", &c) != 1) return 1;

    //설계 관련 정보 받기
    printf("-----설계 관련 정보-----\n");
    printf("안전계수(SF, 1이상) : ");
    if (scanf("%lf", &SF) != 1) return 1;

    if (r <= 0 || c <= 0 || SF <= 1) return 1;

    //F_avail 계산
    const double T_tot = N_m * T_m * G * eta;
    const double F_avail = T_tot / r;
    printf("-----Calculating F_avial-----\n");
    printf(" T_total : %.4lf, F_avail : %lf ", T_tot, F_avail);

    //등판 가능 최대각, 등판율 계산
    const double g = 9.81;

    double theta_max = asin((F_avail / SF - c * m * g) / (m * g));
    theta_max = (theta_max >= 0 ) ? theta_max : 0;
    theta_max = (theta_max >= 1) ? 1 : theta_max ;

    const double grade = tan(theta_max) * 100 ;
    const double Pi = 3.1415926535;

    printf("등판가능 최대각(degree) : %lf, 등판율 : %lf\n", theta_max * 180 / Pi, grade);

    return 0;
} */