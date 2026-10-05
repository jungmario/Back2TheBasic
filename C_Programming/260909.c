// #3 : 버퍼를 사용하는 입력 함수. 버퍼를 사용하는 문자 입력
/*
#include <stdio.h>

int main ()
{
    char ch;
    int i;

    for (i = 0; i < 3; i++)
    {
        scanf(" %c", &ch); //문자열이 아니라 문자이기 때문에 &를 붙임
        printf("%c \n", ch); //if 입력을 문자 하나가 아닌 tiger 같이 긴거로 한다면? 하나씩 입력하려해도 t하고 엔터 누르니 tt \n\n ii이렇게 나오네 %c앞에 스페이스 넣으니까 잘 되는데 %c뒤에 스페이스 넣으면 잘 안됨
    }

    return 0;
}*/

// #4 : 입력 문자의 아스키 코드 값을 출력하는 프로그램
/*
#include <stdio.h>

int main()
{
    int res;
    char ch;

    while(1)
    {
        res = scanf("%c", &ch);
        if (res == EOF) break;
        printf("%d ", ch);
    }

    return 0;
}*/

// #5 : getchar 함수를 사용한 문자열 입력
/*

#include <stdio.h>

void my_gets(char *str, int size);

int main()
{
    char str[7];

    my_gets(str, sizeof(str));
    printf("입력한 문자열 : %s\n", str);

    return 0;
}

void my_gets(char *str, int size)
{
    int ch;
    int i = 0;

    ch = getchar();
    
    while((ch != '\n') && (i < size -1)) // ch != \n는 그 전에 끝나는 경우 i < size -1 이거는 넘을 경우 끊고 null 문자
    {
        str[i] = ch;
        i++;
        ch = getchar(); // 버퍼에 있는걸 가져오게 됨 없으면 입력받는거고.
    }

    str[i] = '\0';
} */

// #6 : 버퍼의 내용을 지워야 하는 경우
/*
#include <stdio.h>

int main()
{
    int num, grade;

    printf("학번 입력 : ");
    scanf("%d", &num);
    getchar(); //이거 지우고 115 엔터 하면 115만 num에 드가고 남아있는 \n이 아래서 grade에 드가버림, getchar()하고 아무것도 안받음으로써 날려버리는 것.
    printf("학점 입력 : ");
    grade = getchar();
    printf("학번 : %d, 학점 : %c \n", num, grade);

    return 0;
} */


// 8. 문자열 : 컴퓨터가 어떤 방식으로 처리하는지.

// #1 : 문자열 상수 구현 방법. 문자열 상수가 주소란 증거
/*
#include <stdio.h>

int main()
{
    printf("apple이 저장된 시작 주소 값 : %p\n", "apple");
    printf("두 번째 문자의 주소 값 : %p\n", "apple" + 1); //왜 주소값이 똑같냐... 신기하네 어디서 기억하는거여 -> 컴파일러가 읽고 뭐야 다 같네, 한가지 주소에 할당해버림 메모리 아낄라고. 다만 이 경우 다른곳에서 다 공유중이기때문에 읽기 전용으로 작성됨
    //char *pa = "apple";
    //pa[0] = 'b'; //따라서 이렇게 원본 열람해서 바꾸는게 안됨. 컴파일러가 이미 읽기전용으로 저장해버려서. 문법적으론 맞지만...ㄴㄴㄴ 아예 새롭게 문자열 파버려서 또다른 "apple" 생성해버리는 방법 외엔...
    printf("첫 번째 문자 : %c\n", *"apple"); //%c로 하나 읽어오려면 있어야함
    printf("두 번째 문자 : %c\n", *("apple" + 1)); //외않되
    printf("배열로 표현한 세 번째 문자 : %c\n", "apple"[2]);

    return 0;
} */

// #2 : char 포인터로 문자열을 사용하는 방법
/*
#include <stdio.h>

int main()
{
    char *dessert = "apple";

    printf("오늘 후식은 %s입니다.\n", dessert);
    printf("%s의 주소 : %p\n", dessert, dessert); // 문자열 포인터는 *안붙여도 그 값(?) 문자열이 나와서 보이는 방식만 바꿔주면 되네 %s랑 %p로
    dessert = "banana";
    printf("내일 후식은 %s입니다. \n", dessert);
    printf("%s의 주소 : %p\n", dessert, dessert);

    return 0;
}*/

// #3 : scanf 함수를 사용한 문자열 입력
/*
#include <stdio.h>

int main()
{
    char str[80];

    printf("문자열 입력 : ");
    scanf("%s", str); //"%s " 이러면 어케 되는거여 어우 헷갈려
    printf("첫 번째 단어 : %s\n", str);
    scanf("%s", str);
    printf("버퍼에 남아 있는 두 번째 단어 : %s\n", str);

    return 0;
} */

// #4 : gets 함수로 한 줄의 문자열 입력
/*
#include <stdio.h>

int main()
{
    char str[80];

    printf("공백이 포함된 문자열 입력 : ");
    gets(str);
    printf("입력한 문자열은 %s입니다.", str);

    return 0;
} */


// #5 : fgets 함수의 문자열 입력 방법
/*
#include <stdio.h>

int main()
{
    char str[80];

    printf("공백을 포함한 문자열을 입력하세요");
    fgets(str, sizeof(str), stdin);
    printf("입력된 문자열은 %s입니다\n", str);

    return 0;
} */ 

// #6 : 표준 입력 함수의 버퍼 공유 문제 : 개행 문자로 인해 gets 함수가 입력을 못하는 경우
/*
#include <stdio.h>

int main()
{
    int age;
    char name[20];
    
    printf("나이 입력 :");
    scanf("%d", &age);

    printf("이름 입력 : ");
    gets(name); //버퍼에 남아있던 \n이 \0로 바뀌어서 들어감 실제로 키보드 입력 안받음
    printf("나이 : %d, 이름 : %s\n", age, name);

    return 0;
}*/

// #7 : 문자열을 출력하는 puts, fputs 함수

// #8 : 문자열 처리하는 몇가지 방법. strcpy 함수의 사용법.
/*
#include <stdio.h>
#include <string.h>

int main()
{
    char str1[80] = "strawberry"; //이러면 strawberry하고 \0뒤에 저장되는 것
    char str2[80] = "apple";
    char *ps1 = "banana";
    char *ps2 = str2;

    printf("최초 문자열 : %s\n", str1);
    strcpy(str1, str2); //str1 주소에 든 걸 str2주소에 있는 거로 바꿔넣어라.
    printf("바뀐 문자열 : %s\n", str1);
    strcpy(str1,ps1);
    printf("바뀐 문자열 : %s\n", str1);
    strcpy(str1, "banana");
    printf("바뀐 문자열 : %s\n", str1);

    return 0;
} */

// #9 : 원하는 개수의 문자만을 복사하는 strncpy 함수
/*
#include <stdio.h>
#include <string.h>

int main()
{
    char str[20] = "mango tree";
    char str2[20] = "apple-pie";

    strncpy(str, str2, 5); //공백도 복사하네.

    printf("%s\n", str);

    return 0;
} */

// #10 : 문자열을 붙이는 strcat(다붙이기), strncat(몇개만 붙이기) 함수
/*
#include <stdio.h>
#include <string.h>

int main()
{
    char str[80] = "straw";

    strcat(str, "berry"); //berry 죄다.
    printf("%s\n", str);
    strncat(str, "piece", 3); //piece의 앞글자 3개만 
    printf("%s\n", str);

    return 0;
} */

// #11 : 문자열 길이를 계산하는 strlen 함수. 두 문자열 중 길이가 긴 단어 출력
/*
#include <stdio.h>
#include <string.h>

int main()
{
    char str1[80], str2[80];
    char *resp;

    printf("2개의 과일 이름 입력 : ");
    scanf("%s %s", str1, str2);
    if (strlen(str1) > strlen(str2))
    {
        resp = str1;
    }
    else{
        resp = str2;
    }

    printf("이름이 긴 과일은 : %s\n", resp);

    return 0;
} */


// #12 : 문자열을 비교하는 strcmp, strncmp 함수 : a,b,c 순 비교, 앞글자 같으면 두번째 글자끼리 비교, 사전(dictionary)순 정리. stringcompare 시간날 때 만들어보기
/*
#include <stdio.h>
#include <string.h>

int main()
{
    char str1[80] = "pear";
    char str2[80] = "peach";

    printf("사전에 나중에 나오는 과일 이름 :");
    if (strcmp(str1, str2) > 0) // str1이 나중이면 1 같으면 0, 먼저면 -1 
    {
        printf("%s\n", str1);
    }
    else{
        printf("%s\n", str2);
    }

    return 0;
} */

// #13 : 기습 문제, my_strcat함수 구현해보기
/*
#include <stdio.h>

void my_strcat(char *str1, char *str2);
void my_strncat(char *str1, char *str2, int n);

int main()
{
    char str[80] = "straw";

    my_strcat(str, "berry");
    printf("%s\n", str);
    my_strncat(str, "piece", 3);
    printf("%s\n", str);
    
    return 0;
}

void my_strcat(char *str1, char *str2)
{
    int i = 0, j = 0;

    while (str1[i] != '\0')
    {
        i++;
    }

    while (str2[j] != '\0')
    {
        str1[i + j] = str2[j];
        j++;
    }

    str1[ i+j ] = '\0';
}

void my_strncat(char *str1, char *str2, int n)
{
    int i = 0, j = 0;

    while (str1[i] != '\0')
    {
        i++;
    }

    for (j = 0; j < n; j++)
    {
        str1[i + j] = str2[j];
    }

    str1[ i + j] = '\0';
} */

// #14 : 문제, 3개 문자열이상 순서대로 나올 수 있게 하는 코드 작성, 더 발전시킬 필요있음
/*
#include <stdio.h>
#include <string.h>

void my_strcmp3(char *str1, char *str2, char *str3);

int main()
{
    char str1[80] = "apple";
    char str2[80] = "peach";
    char str3[80] = "pear";

    my_strcmp3(str1, str2, str3);

    return 0;
}

void my_strcmp3(char *str1, char *str2, char *str3)
{
    if (strcmp(str1, str2) > 0)
    {
        if (strcmp(str1, str3) > 0)
        {
            if (strcmp(str3, str2) > 0)
            {
                printf("%s\n%s\n%s\n",str2, str3, str1);
            }
            else
            {
                printf("%s\n%s\n%s\n",str3, str2, str1);
            }
        }
        else{
            printf("%s\n%s\n%s\n",str2, str1, str3);
        }
    }
    else{
        if (strcmp(str2, str3) > 0)
        {
            if (strcmp(str3, str1) > 0)
            {
                printf("%s\n%s\n%s\n",str1, str3, str2);
            }
            else
            {
                printf("%s\n%s\n%s\n",str3, str1, str2);
            }
        }
        else{
            printf("%s\n%s\n%s\n",str1, str2, str3);
        }
    }
} */

// 9. 변수

// #1 : 지역변수. 두 함수에서 같은 이름의 지역 변수를 사용한 경우
/*
#include <stdio.h>

void assign();

int main()
{
    auto int a = 0; //auto는 신경 ㄴㄴ

    assign();
    printf("main 함수 a : %d\n", a);

    return 0;
}

void assign(void)
{
    int a;

    a = 10;//여기서 a랑 밖에 a랑 다름. 각자 그 중괄호 안에서만 사용가능 싫으면 포인터쓰셈 ㅋ
    printf("assign 함수 a : %d\n", a);
} */

// #2 : 블록 안에서 사용하는 지역 변수
/*
#include <stdio.h>

int main()
{
    int a = 10, b = 20;
    printf("블록 밖 a의 주소값 : %p, b의 주소값 : %p\n", &a, &b);

    printf("교환 전 a와 b의 값 : %d, %d\n", a, b);
    {
        int a, b, temp; //이렇게 안에서 중괄호를 사용함으로써 지역변수 선언 가능 아래와 같이 주소값 찍어보면 블록 밖 a랑 안 a랑 다르며 블록 밖으로 나가면 지워진다.

        printf("블록 안 a의 주소값 : %p, b의 주소값 : %p\n", &a, &b);

        temp = a; //이러면 가장 가까운 a와 결합(블록 안 a)
        a = b;
        b = temp;

    }
    printf("교환 후 a와 b의 값 : %d, %d\n",a, b); //안바뀜

    return 0;
} */

// #3 : 전역 변수
/*
#include <stdio.h>

void assign10();
void assign20();

int a;

int main()
{
    printf("함수 호출 전 a 값 : %d\n", a);

    assign10();
    assign20();

    printf("함수 호출 후 a 값 : %d\n", a);

    return 0;
}

void assign10()
{
    a = 10;
}

void assign20()
{
    int a;
    a = 20;
} */

// #4 : 정적 지역 변수 . auto 지역 변수와 static 지역 변수의 비교
/*
#include <stdio.h>

void auto_func();
void static_func();

int main()
{
    int i;

    printf("일반 지역 변수(auto)를 사용한 함수...\n");
    for (i = 0; i < 3; i++)
    {
        static_func();
    }

    printf("정적 지역 변수(static)를 사용한 함수 ...\n");

    for (i = 0; i < 3; i++)
    {
        static_func();
    }

    return 0;
}

void auto_func()
{
    auto int a = 0;

    a++;
    printf("%d\n", a);
}

static int a; // 밑에 함수 안에 들어가도 되고 밖에 이렇게 있어도 되나?
void static_func()
{
    a++;
    printf("%d\n",a);
}
*/

// #5 : 레지스터 변수
/*
#include <stdio.h>

int main()
{

} */

// #6 : 값을 복사해서 전달하는 방법은 안됨. 주소를 전달해야한다.
/*
#include <stdio.h>

void add_ten(int a);

int main()
{
    int a = 10;

    add_ten(a);//
} */

// #7 : 주소를 반환하는 함수.
/*
#include <stdio.h>

int *sum(int a, int b);

int main()
{
    int *resp;

    resp = sum(10, 20);
    printf("두 정수의 합 : %d\n", *resp);

    return 0;
}

int *sum(int a, int b)
{
    static int res;

    res = a + b;

    return &res;
} */

// 10. 다차원 배열과 포인터 배열

// #1 : 2차원 배열 선언과 요소 사용
/*
#include <stdio.h>

int main()
{
    int score[3][4];

    int total;
    double avg;

    int i, j;

    for (i = 0; i < 3; i++)
    {
        printf("%d번째 학생의 4과목 점수 입력 : ", i+1);

        for (j = 0; j < 4; j++)
        {
            scanf("%d",&score[i][j]);
        }
    }

    for (i = 0; i < 3; i++)
    {
        total = 0;

        for (j = 0; j < 4; j++)
        {
            total += score[i][j];
        }

        avg = (double)total / (double)4;

        printf("%d 번째 학생의 과목 총합 : %d, 평균 : %.2lf\n", i+1, total, avg);
    }

    return 0;

} */

// #2 : 2차원 배열의 다양한 초기화 방법
/*
#include <stdio.h>

int main()
{
    int num[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    int i, j;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 4; j++)
        {
            printf("%5d", num[i][j]);
        }

        printf("\n");
    }

    return 0;
} */

// #3 : 2차원 char 배열
/*
#include <stdio.h>

int main()
{
    char animal[5][20];
    int i;
    int count;

    count = sizeof(animal) / sizeof(animal[0]); // animal[0]은 첫번째 행 전부의 sizeof

    for (i = 0; i < count; i++)
    {
        scanf("%s", animal[i]); // animal[i]가 원소가 아닌 i행 전체
    }

    for (i = 0; i < count; i++)
    {
        printf("%s \n", animal[i]);
    }

    return 0;
} */

// #4 : 2차원 char 배열 초기화
/*
#include <stdio.h>

int main()
{
    char animal1[5][10] = {
        {'d','o','g','\0'},
        {'t','i','g','e','r','\0'},
        {'r','a','b','b','i','t','\0'},
        {'h','o','r','s','e','\0'},
        {'c','a','t','\0'}
    };

    char animal2[][10] = {"dog","tiger","rabbit","horse","cat"};

    int i;

    for (i = 0; i < 5; i++)
    {
        printf("%s ", animal1[i]);
    }

    printf("\n");

    for (i = 0; i < 5; i++)
    {
        printf("%s ", animal2[i]);
    }

    return 0;
}*/

// #5 : 3차원 배열. 2개 반 3명 학생의 4과목 점수를 저장하는 3차원 배열
/*
#include <stdio.h>

int main()
{
    int score[2][3][4] = {
        {{72, 80, 95, 60}, {68, 98, 83, 90}, {75, 72, 84, 90}}, //첫번째 면.

        {{66, 85, 90, 88}, {95, 92, 88, 95}, {43, 72, 56, 75}} //두번째 면
    };

    int i, j, k;

    for(i = 0; i < 2; i++)
    {
        printf("%d반 점수...\n", i + 1);
        for (j = 0; j < 3; j++)
        {
            for (k = 0; k < 4; k++)
            {
                printf("%5d", score[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }

    return 0;
} */

// #6 : 기습문제, *표 합치기
/*
#include <stdio.h>

void add_star(char str1[][6], char str2[][6], char star3[][6]);

int main()
{
    char star1[5][6] ={
        {'*',' ',' ',' ',' ','\0'}, // 이렇게 해도 됨 조금 발전시키고 싶긴하네.
        {' ','*',' ',' ',' ','\0'},
        {' ',' ','*',' ',' ','\0'},
        {' ',' ',' ','*',' ','\0'},
        {' ',' ',' ',' ','*','\0'}
    };

    char star2[5][6] ={
        {' ',' ',' ',' ','*','\0'},
        {' ',' ',' ','*',' ','\0'},
        {' ',' ','*',' ',' ','\0'},
        {' ','*',' ',' ',' ','\0'},
        {'*',' ',' ',' ',' ','\0'}
    };

    char star3[5][6] = {
        {' ',' ',' ',' ',' ','\0'},
        {' ',' ',' ',' ',' ','\0'},
        {' ',' ',' ',' ',' ','\0'},
        {' ',' ',' ',' ',' ','\0'},
        {' ',' ',' ',' ',' ','\0'}
    };

    add_star(star1, star2, star3);

    int i,j;

    for( i = 0; i < 5; i++)
    {
        for(j = 0; j < 5; j++)
        {
            printf("%c ", star3[i][j]);
        }

        printf("\n");
    }
}

void add_star(char str1[][6], char str2[][6], char str3[][6]) // 함수에 넣을때 이렇게 넣어줘야하네...
{
    int i, j;

    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            if (str1[i][j] == '*' || str2[i][j] == '*')
            {
                str3[i][j] = '*';
            }
        }
    }
} */
