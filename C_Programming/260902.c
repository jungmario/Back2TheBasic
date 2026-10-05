/* 작성자 : 정부현
    제목  : 문자열을 화면에 출력

#include <stdio.h> // standard input output : 기본적인 함수를 가지고 있음

int main(void) // int 라는 정수열을 가지는 main함수고 필요한값은 없다(void)
{
    printf("Be happy"); // 문자열 Be happy 출력
    printf("My friend"); // 문자열 My friend 출력, 매줄 세미콜론;으로 끝남을 알림

    return 0; //정상적으로 여기까지 왔으면 0을 뱉어라. 이 프로그램이 실행되고 진행되는 다음 프로그램에 정상적으로 여기까지 왔음을 알림. 그러면 다음 프로그램에서 그 값을 받아서 실행되는거.
}
    */



//2번
/* 작성자 : 정부현
    제목  : 제어문자를 사용한 출력(커서 개념이 필요.)

#include <stdio.h>

int main()
{
    printf("Be happy\n"); // \n : 줄바꿈
    printf("12345678901234567890\n"); // \t : 탭버튼
    printf("My\tfriend\n");
    printf("Goot\bd\tchance\n"); // \b: 커서 한칸 왼쪽, 다른 글자 쓰면 바뀜
    printf("Cow\rW\a\n"); // \r : 맨앞으로 이동 /a : 벨소리내기

    return 0;
} */

//3번
/* 작성자 : 정부현
    제목  : 정수와 실수 출력

#include <stdio.h>

int main()
{
    printf("%d\n",10); // %d : 정수를 받는 변환문자
    printf("%lf\n", 3.4); // %lf : 실수를 받는 변환문자, 소수점 이하 6자리까지 출력
    printf("%.1lf\n", 3.45); // 소수점 이하 첫째 자리까지 출력(둘째 자리에서 반올림)
    printf("%.10lf\n",3.4);

    printf("%d과 %d의 합은 %d입니다.\n", 10, 20, 10+20);
    printf("%.1lf - %.1lf = %.1lf\n", 3.4, 1.2, 3.4 - 1.2);

    return 0;
} */

//3번
/* 작성자 : 정부현
    제목  : 10진수, 8진수, 16진수 각 세 가지 진법의 정수 상수
#include <stdio.h>

int main()
{
    printf("%d\n", 12); // 10진수
    printf("%d\n", 014); // 8진수 앞에 0붙이면됨
    printf("%d\n", 0xc); // 16진수 앞에 0x붙이면됨

    return 0;
} */

//4번
/* 지수 형태의 실수 상수

#include <stdio.h>

int main()
{
    printf("%.1lf\n", 1e6); // 지수 형태 실수를 소수점 형태로
    printf("%.7lf\n", 3.14e-5); // 지수형태를 실수(소수)형태로
    printf("%le\n", 0.0000314); // 지수 형태로 출력
    printf("%.2le\n",0.0000314); // 지수형태로 소수점 이하 둘째자리까지

    return 0;
} */


//5번
/* 문자와 문자열 데이터 출력
#include <stdio.h>

int main ()
{
    printf("%c\n",'A'); //문자 상수(글자하나) 출력 c:character , '' 큰 따옴표
    printf("%s\n","A"); //문자열 상수(여러개) 출력 s:string , "" 작은 따옴표
    printf("%c은 %s입니다.\n",'1',"first");

    return 0;
} */

//6번 : 변수의 선언과 사용

/*
#include <stdio.h>

int main ()
{
    int a; // int형 (정수) 변수 a선언
    int b, c; // 2개의 int형 변수 동시 선언 가능
    double da; // double형 변수 da선언
    char ch; //char형 변수 ch선언

    a=10;
    b=a;
    c=a+20;
    da=3.5;
    ch='A';

    printf("변수 a의 값 : %d\n",a);
    printf("변수 b의값 : %d\n",b);
    printf("변수 c의 값: %d\n",c);
    printf("변수 da의 값:%.1lf\n",da);
    printf("변수 ch의 값:%c\n",ch);

    return 0;
} */

//7번 : char형 변수의 사용
/*
#include <stdio.h>

int main()
{
    char ch1 ='A'; // 문자로 초기화, 저장된 값은 문자의 아스키 코드 값
    char ch2 = 65; // 문자 'A'의 아스키 코드 값에 해당하는 정수로 초기화

    printf("문자 %c의 아스키 코드 값 : %d\n", ch1, ch1); //같은 걸 %c로, %d로 표현을 다르게
    printf("아스키 코드 값이 %d인 문자 : %c\n", ch2, ch2); 

    return 0;
} */

//8번 : 여러가지 정수형 변수
/*
#include <stdio.h>

int main()
{
    short sh = 32767; //short형의 최댓값 초기화
    int in = 2147483647; //int형의 최댓값 초기화
    long ln = 2147482647; //long형의 최댓값 초기화
    long long lln = 123451234512345;  //아주 큰 값 초기화

    printf("short형 변수 출력 : %d\n",sh);
    printf("int형 변수 출력 : %d\n",in);
    printf("long형 변수 출력 : %ld\n",ln);
    printf("long long형 변수 출력 : %lld\n",lln);

    return 0;
} */

//9번 : unsigned를 잘못 사용한 경우
/*
#include <stdio.h>

int main()
{
    unsigned int a;

    a = 4294967295; //큰 양수 저장
    printf("%d\n",a); // a값이 unsigned int로 하면 컴퓨터 내에 11111111...로 저장됨. 그걸 %d로 읽어오니 아 이거 -1이네 이러고 출력하는거
    printf("%u\n",a);
    a = -1;
    printf("%u\n",a); // -1로 저장하니 1111111...로 저장된걸 %u(unsigned int로 읽어옴) 로 읽어오니 젤 큰 4294967295로 읽어오는거임ㅋㅋ

    return 0; // 이때, 그렇다고 해서 int나 unsigned int 아무거나 해도 상관 없다는 건 아님. 작동방식: 4294967295를 2진법으로 변환, 컴파일러가 이것(11111....111)이 unsigned int라고 기억해놓음. 지금은 컴파일러가 기억한걸 쓰지말고 출력방식을 정해줘서 그런 것. unsigned int로 저장한 4294967295랑 1 크기비교하면 4294967295가 크다고 나옴. 근데 int로 저장한 4294967295랑 1크기 비교하면 1이 크다고 나옴 int상에서는 4294967295가 -1이기 때문에.
} */

//10번 : 실수자료형, 유효숫자 확인
/*
#include <stdio.h>

int main()
{
    float ft = 1.234567890123456789;  // 저장하는게 더 짧음
    double db = 1.234567890123456789; //더 긴 소수점까지 저장

    printf("float형 변수의 값 : %.20f\n",ft);
    printf("double형 변수의 값 : %.20lf\n",db);

    return 0;
}*/

//11번 : 문자열 저장
/*
#include <stdio.h>

int main()
{
    char fruit[20] = "strawberry";

    printf("딸기 : %s\n",fruit); // 배열명으로 저장된 문자열 출력
    printf("딸기잼 : %s %s\n", fruit, "jam"); // 문자열 상수를 직접 %s로 이렇게 출력할 수도 있다.

    return 0;
} */

//12번 : 새로운 문자열 저장
/*
#include <stdio.h>
#include <string.h> //문자열을 다루는 string.h 헤더 파일 포함

int main()
{
    char fruit[20] = "strawberry";

    printf("%s\n",fruit);
    strcpy(fruit,"banana"); //fruit에 banana 복사, 덮어씌워짐 stringcopy
    printf("%s\n",fruit);

    return 0;
} */

//13번 : const를 사용한 변수
/*
#include <stdio.h>

int main()
{
    int income = 0;
    double tax;
    const double tax_rate = 0.12;

    tax_rate = 0.15; // 이렇게 뒤에서 수정하려하면 오류가 남

    income = 456;
    tax = income * tax_rate;
    printf("세금은 : %.1lf입니다. \n", tax);

    return 0;
}*/

//14번 : scanf 함수를 사용한 키보드 입력을 받아서 변수 선언
/*
#include <stdio.h>

int main()
{
    int a;

    scanf("%d",&a); // 입력 받을 땐 &가 붙는다.
    printf("입력된 값 : %d\n", a);

    return 0;
} */

//15번 : scanf 함수를 사용한 연속 입력
/*
#include <stdio.h>

int main()
{
    int age;
    double height;

    printf("나이와 키를 입력하세요 : ");
    scanf("%d%lf", &age, &height);
    printf("나이는 %d살, 키는 %.1lfcm입니다 \n", age, height);

    return 0;
} */

// 16번 : 문자와 문자열 입력
/*
#include <stdio.h>

int main()
{
    char grade;
    char name[20];

    printf("학점 입력 : ");
    scanf("%c", &grade);
    printf("이름 입력 : ");
    scanf("%s", name); //문자열 입력은 & 사용안함!!
    printf("%s의 학점은 %c입니다.\n", name, grade);

    return 0;
}*/

//17번 : 대입, 덧셈, 뺄셈, 곱셈, 음수 연산
/*
#include <stdio.h>

int main()
{
    int a, b;
    int sum, sub, mul, inv;

    a=10;
    b=20;

    sum = a + b;
    sub = a - b;
    mul = a * b;
    inv = - a;

    printf("a의 값 : %d, b의 값 :%d\n",a,b);
    printf("덧셈 : %d\n",sum);
    printf("뺄셈 : %d\n",sub);
    printf("곱셈 : %d\n",mul);
    printf("a의 음수 연산 : %d\n",inv);

    return 0;
} */

//18번 : 몫과 나머지를 구하는 연산
/*
#include <stdio.h>

int main()
{
    double apple;
    int banana;
    int orange;

    apple = 5.0/2.0;
    banana = 5/2; //정수와 정수의 나누기 연산(몫). 그냥 int로 선언하기만 하면 이렇게 되네...
    orange = 5%2; //정수와 정수의 나누기 연산(나머지), 이걸로 짝수냐 홀수냐, 뭐의 배수냐 아니냐 판단가능

    printf("apple : %.1lf\n", apple);
    printf("banana : %d\n", banana);
    printf("orange : %d\n", orange);

    return 0;
} */

//19번 : 증감 연산자
/*
#include <stdio.h>

int main()
{
    int a = 10, b=10;

    ++a;
    --b;

    printf("a : %d\n",a);
    printf("b : %d\n",b);

    return 0;

} */

//20번 전위 표기와 후위 표기
/*
#include <stdio.h>

int main()
{
    int a = 5, b = 5;
    int pre, post;

    printf("초깃값 a = %d. b = %d \n", a, b); // a랑 b둘다 6되어있음
    printf("계산 시작 \n");

    pre = (++a) * 3; //a를 1 증가시키고 계산
    post = (b++) * 3; //계산하고 b를 1 증가시켜라

    printf("전위형: (++a) * 3 = %d, 후위형: (b++) * 3 = %d\n", pre, post);
    printf("계산 후 값 a = %d. b = %d \n", a, b); // a랑 b둘다 6되어있음

    return 0;
} */

//21번 관계 연산자
/*
#include <stdio.h>

int main()
{
    int a = 10, b = 20, c = 10;
    int res;

    res = (a > b);
    printf("a > b : %d\n", res);

    res = (a >= b);
    printf("a >= b : %d\n", res);

    res = (a < b);
    printf("a < b : %d\n", res); //같은 방식으로 ==, !=, <=, < 뭐 이렇게 쭉쭉, 괄호 필요한 거 기억

    return 0;
} */

//22번 : 논리 연산자
/*
#include <stdio.h>

int main()
{
    int a = 30;
    int res;

    res = (a > 10) && (a < 20); // 둘 다 참이면 참
    printf("(a > 10) && (a < 20) : %d\n", res);

    res = (a < 10) || (a > 20); // 둘 중에 하나라도 참이면 참
    printf("a < 10 || a > 20 : %d\n", res);

    res = !(a >= 30); // 그냥 결과값 반대
    printf("! (a >= 30) : %d\n", res);

    return 0; //and, or, not을 해보았다~
}*/

//23번 : 연산의 결과값을 처리하는 방법. 연산의 결과는 저장하거나 바로 사용하지 않으면 사라진다. 계속 쓰려면 변수에 저장해놔라

//24번 : 그 외 유용한 연산자 : 형 변환 연산자, 많이 바꿈. 강의 자료 참고
/*-
#include <stdio.h>

int main()
{
    double a = 18.8, b = 2.1;
    int res;

    res = ((double)a) / ((double) b);
    printf("a = %d, b = %d\n",(int)a , (int)b);
    printf("a / b의 결과 : %.1lf\n", (double)res);

    a = (int)res;
    printf("(int) %.1lf의 결과 : %d\n", (double)res, (int)a);

    return 0;
} */

//25번 : Size of 연산자 몇바이트까지 이게 들어있나 알고싶을 때
/*
#include <stdio.h>

int main()
{
    int a = 10;
    double b = 3.4;

    printf("int형 변수의 크기 : %d\n", sizeof(a));
    printf("double형 변수의 크기 : %d\n", sizeof(b));
    printf("정수형 상수의 크기 : %d\n", sizeof(10));
    printf("수식의 결괏값의 크기")...

}*/

//26번 : 복합대입 연산자
/*
#include <stdio.h>

int main()
{
    int a =10, b = 20;
    int res = 2;

    a += 20; // a에 20을 더해라
    res *= b + 10; // res에 b + 10을 곱해라

    printf("a = %d, b = %d\nres = %d \n", a, b, res /= b + 10); //걍 기존 res 보여주고 싶어서 복잡스럽게 이렇게 해놈
    printf("res = %d\n", res);

    return 0;
} */

//27번 : 콤마 연산자 설명할게 없어보인다고 넘어갔는데 난 몰루

//28번 : 조건 연산자
/*
#include <stdio.h>

int main()
{
    int a = 10, b = 20, res;

    res = (a > b) ? a : b; // 진실이면 a, 거짓이면 b를 출력해라
    printf("큰 값 : %d\n", res);

    return 0;
}
*/

//29번: 비트 연산자 and(&)는 각 비트마다 0이랑 1 비교해서 1,1이면 1 나머지면 다 0. 뭐 이런 식. 이거 누가 씀? 생각보다 많이 쓴다... 뭐 암호 프로토콜(통신규약) 등등
// XOR(^) OR(|) NOT(~) SHIFT (<<, >>) 강의자료참고.