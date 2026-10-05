// #2 : 동적 할당 영역을 배열처럼 사용
/*
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *pi;
    int i, sum = 0;

    pi = (int *)malloc(5 * sizeof(int));

    //printf("i의 값 : %d\n", i);

    if (pi == NULL)
    {
        printf("메모리가 부족합니다!\n");
        exit(1);
    }

    printf("다섯 명의 나이를 입력하세요 : ");
    for (i = 0; i < 5; i++)
    {
        scanf("%d", &pi[i]);
        sum += pi[i];
    }

    printf("다섯 명의 평균 나이 : %.1lf\n", (sum / 5.0));
    free(pi);

    return 0;
} */

// #3 : calloc, realloc 함수를 사용한 양수 입력
/*
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *pi;
    int size = 5;
    int count = 0;
    int num;
    int i;

    pi = (int *)calloc(size, sizeof(int));


    while (1)
    {
        printf("양수만 입력하세요 => ");
        scanf("%d", &num);
        if (num <= 0) break;
        if (count == size)
        {
            size += 5;
            pi = (int *)realloc(pi, size * sizeof(int)); //부족하면 늘려주기 
        }
        pi[count++] = num;
    }

    for (i = 0; i < count; i++)
    {
        printf("%5d", pi[i]);
    }
    free(pi);


    return 0;
} */

// #4 : 동적 할당을 사용한 문자열 처리
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char temp[80];
    char *str[3];
    int i;

    for (i = 0; i < 3; i++)
    {
        printf("문자열을 입력하세요 :");
        gets(temp);
        str[i] = (char *)malloc(strlen(temp) + 1); //strlen는 널 문자 취급안함. 그래서 +1
        strcpy(str[i], temp); //str[i]는 배열명이자 주소
    }

    for (i = 0; i < 3; i++)
    {
        printf("%s\n", str[i]);
    }

    for (i = 0; i < 3; i++)
    {
        free(str[i]);
    }

    return 0;
} */

// #5 : 동적 할당 영역의 문자열을 함수로 출력
 
// #6 : 명령행 인수를 출력하는 프로그램

// 13. 사용자 정의 자료형. 구조체, 여러가지 데이터를 하나의 블록에 모아놓기. int double 이런거 묶을 수 있음(데이터 시트 만들 때)
/*
#include <stdio.h>

struct student
{
    int num;
    double grade;
}; //여기 맨 뒤에 세미콜론있다!!, 이전에 배열에는 ary[0], ary[1],... 이랬는데 구조체는 이름으로 접근하면 된다. s1.num, s1.grade 이렇게

int main()
{
    struct student s1;

    s1.num = 2;
    s1.grade = 2.7;
    printf("학번 : %d\n", s1.num);
    printf("학점 : %.1lf\n", s1.grade);

    return 0;
}*/

// #2 구조체 변수의 크기 확인 : 변수 선언 순서에 따른 패딩바이트 변화. 배치를 잘하면 용량이 줄어든다.
/*
#include <stdio.h>

struct student
{
    char ch1;
    char ch2;
    char ch3;
    short num;
    int score;
    int grade;
    
};

int main()
{
    struct student s1;
    printf("%lu\n", sizeof(s1));

    return 0;
} */

// #3 : 다양한 구조체 멤버. 배열과 포인터를 멤버로 갖는 구조체 사용
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct profile{
    char name[20];
    int age;
    double height;
    char *intro;
};

int main()
{
    struct profile yuni;
    strcpy(yuni.name, "서하윤");
    yuni.age = 17;
    yuni.height = 164.5;

    yuni.intro = (char *)malloc(80);
    printf("자기소개 : ");
    gets(yuni.intro);

    printf("이름 : %s\n", yuni.name);
    printf("나이 : %d\n", yuni.age);
    printf("키 : %.1lf\n", yuni.height);
    printf("자기소개 : %s\n", yuni.intro);
    free(yuni.intro); //각 형식에 맞게 쓰임.

    return 0;
}
*/ 

// #4 : 다른 구조체를 멤버로 갖는 구조체 사용
/*
#include <stdio.h>

struct profile
{
    int age;
    double height;
};

struct student
{
    struct profile pf; //이렇게 사용
    int id;
    double grade;
};

int main()
{
    struct student yuni;

    yuni.pf.age = 17;
    yuni.pf.height = 164.5; //student 안에 profile 만들어서 구분 되게 뭔가 학번, 점수랑 키/몸무게는 느낌이 다름
    yuni.id = 315;
    yuni.grade = 4.3;

    printf("나이 : %d\n", yuni.pf.age);
    printf("키 : %.1lf\n", yuni.pf.height);
    printf("학번 : %d\n", yuni.id);
    printf("학점 : %.1lf\n", yuni.grade);

    return 0;
} */

// #5 : 구조체 변수의 초기화와 대입 연산. 최고 학점의 학생 데이터 출력
/*
#include <stdio.h>

struct student
{
    int id;
    char name[20];
    double grade;
};

int main()
{
    struct student s1 = {315, "홍길동", 2.4}, 
                   s2 = {316, "이순신", 3.7}, 
                   s3 = {317, "세종대왕", 4.4};

    struct student max;

    max = s1; //이렇게 구조체에 걍 넣어버릴 수가 있네. 결국 이것도 주소긴 함. 구조체명도 주소다.

    if (s2.grade > max.grade) max = s2;
    if (s3.grade > max.grade) max = s3;

    printf("학번 : %d\n", max.id);
    printf("이름 : %s\n", max.name);
    printf("학점 : %.1lf\n", max.grade);

    return 0;
} */

// #6 : 구조체 변수를 함수의 매개변수에 사용하기. 구조체를 반환하여 두 변수의 값 교환.
/*
#include <stdio.h>

struct vision
{
    double left;
    double right;
};

struct vision exchange (struct vision robot); //struct vision이라는 형태로 입력 받고 출력한다.

int main()
{
    struct vision robot;

    printf("시력 입력 : ");
    scanf("%lf%lf", &(robot.left), &(robot.right));
    robot = exchange(robot);
    printf("바뀐 시력 : %.1lf %.1lf\n", robot.left, robot.right);

    return 0;
}

struct vision exchange (struct vision robot)
{
    double temp;

    temp = robot.left;
    robot.left = robot.right;
    robot.right = temp; //이건 뭐 output을 받으니까 걍 바꿔도 적용되는 거 아닌감. output을 void라 해도 되는가

    return robot;
} */

// #7 : 구조체 활용. 구조체 포인터와 -> 연산자.
/*
#include <stdio.h>

struct score
{
    int kor;
    int eng;
    int math;
};

int main()
{
    struct score yuni = {90, 80, 70};
    struct score *ps = &yuni; //ps는 구조체를 바라보는 포인터.

    printf("국어 : %d\n", (*ps).kor); //이렇게 써도됨
    printf("영어 : %d\n", ps -> eng); //ps(주소값)의 eng
    printf("수학 : %d\n", ps -> math);

    return 0;
} */

// #8 : 구조체 배열
/*
#include <stdio.h>

struct address{
    char name[20];
    int age;
    char tel[20];
    char addr[80];
};

int main()
{
    struct address list[5] = {
        {"홍길동", 23, "111-1111","울릉도 독도"},
        {"이순신", 35, "222-2222", "서울 건천동"},
        {"장보고", 19, "333-3333", "완도 청해진"},
        {"유관순", 15, "444-4444", "충남 천안"},
        {"안중근", 45, "555-5555", "황해도 해주"} //이렇게 구조체를 여러개.
    };

    int i;

    for (i = 0; i < 5; i++)
    {
        printf("%10s%5d%15s%20s\n", list[i].name, list[i].age, list[i].tel, list[i].addr);
    }

    return 0;
} */

// #9 : 구조체 배열을 처리하는 함수
/*
#include <stdio.h>

struct address{
    char name[20];
    int age;
    char tel[20];
    char addr[80];
};

void print_list(struct address *lp);

int main()
{
    struct address list[5] = {
        {"홍길동", 23, "111-1111","울릉도 독도"},
        {"이순신", 35, "222-2222", "서울 건천동"},
        {"장보고", 19, "333-3333", "완도 청해진"},
        {"유관순", 15, "444-4444", "충남 천안"},
        {"안중근", 45, "555-5555", "황해도 해주"} //이렇게 구조체를 여러개.
    };

    print_list(list);

    return 0;
}

void print_list(struct address *lp)
{
    int i;

    for (i = 0; i < 5; i++)
    {
        printf("%10s%5d%15s%20s\n",
                   (lp + i) -> name, (lp + i) -> age, (lp+i)->tel, (lp+i)->addr);
    }
} */

// #10 : 자기 참조 구조체. 자기 참조 구조체로 list 만들기. 이건 좀 어려운데... 주소값을 신경써서.
/*
#include <stdio.h>

struct list
{
    int num;
    struct list *next;
};

int main()
{
    struct list a = {10, 0}, b = {20, 0}, c = {30, 0};
    struct list *head = &a, *current;

    a.next = &b;
    b.next = &c;

    printf("head -> num : %d\n", head -> num);
    printf("head -> next -> num : %d\n", head -> next -> num);

    printf("list all : ");
    current = head;
    while (current != NULL)
    {
        printf("%d  ", current -> num);
        current = current -> next;
    }
    printf("\n");

    return 0;
} */

// #11 : 공용체, 유니온. 공용체를 사용한 학번과 학점 데이터 처리
/*
#include <stdio.h>

union student{
    int num;
    double grade; // 메모리 하나 가지고 아껴쓰는거
};

int main()
{
    union student s1 = { 315 };

    printf("학번 : %d\n", s1.num);
    s1.grade = 4.4;
    printf("학점 : %.1lf\n", s1.grade);
    printf("학번 : %d\n", s1.num);

    return 0;
} */

// #12 :type def를 이용한 자료형 재정의 . 이거 구조체 쓴다하면 무조건 씀.
/*
#include <stdio.h>

typedef struct student{
    int num;
    double grade;
} Student; //이렇게 해도 된다?!?, 원래 형태가 이렇다고 생각하는게 편하다.

//typedef struct student Student; // 너무 기니까 그냥 줄이는 용
void print_data(Student *ps);

int main()
{
    Student s1 = { 315, 4.2};

    print_data(&s1);

    return 0;
}

void print_data(Student *ps)
{
    printf("학번 : %d\n", ps -> num);
    printf("학점 : %.1lf\n", ps -> grade);
} */ //tap 잘 쓰면 좋음

// 연습문제 몇가지
/*
#include <stdio.h>

typedef struct student{
    double mean;
    char name[20];
    int num;
    int kor;
    int eng;
    int math;
    int total;
    int rate;
    char grade;
} Student;

char calculate_grade(double mean);
void arrange(Student **ps);

int main()
{
    Student student_list[5];
    double mean;

    // 값 입력 받기
    int i,j ;

    for ( i = 0; i < 5; i++)
    {
        printf("학번 : ");
        scanf("%d", &student_list[i].num);

        printf("이름 : ");
        scanf("%s", student_list[i].name); //gets쓰니 입력 버퍼 문제 발견

        printf("국어, 영어, 수학 점수 : ");
        scanf("%d %d %d", &student_list[i].kor, &student_list[i].eng, &student_list[i].math);

        student_list[i].rate = 0; 
    }
    
    //학점 계산 및 정렬 전 데이터 출력

    printf("# 정렬 전 데이터...\n");

    for (i = 0; i < 5; i++)
    {
        student_list[i].total = student_list[i].kor + student_list[i].eng + student_list[i].math;
        student_list[i].mean = (double)student_list[i].total / 3.0;
        student_list[i].grade = calculate_grade(mean);

        printf("%5d %15s %4d %4d %4d %6d %.1lf %c\n",student_list[i].num, student_list[i].name, student_list[i].kor, student_list[i].eng, student_list[i].math, student_list[i].total, student_list[i].mean ,student_list[i].grade);
    }

    //정렬 후 데이터 출력

    printf("# 정렬 후 데이터...");
    
    arrange(student_list);

    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            if (student_list[j].rate == i + 1)
            {
                printf("%5d %15s %4d %4d %4d %6d %.1lf %c\n",student_list[i].num, student_list[i].name, student_list[i].kor, student_list[i].eng, student_list[i].math, student_list[i].total, student_list[i].mean ,student_list[i].grade);
            }
        }
          
    }
    return 0;
}

void arrange(Student **ps)
{
    int i, j;
    int max, max_index;
    int rate = 1;
    for (i = 0; i < 5; i++)
    {
        if (ps[i] -> rate == 0)
        {
            max = ps[i] -> total;
            for (j = 0; j < 5; j++)
            {
                if (max <= ps[j]->total && ps[i]->rate == 0)
                {
                    max = ps[j]->total;
                    max_index = j;
                }
            }
            if ( i == max_index)
            {
                ps[i]->rate = rate;
                rate++;
            }
        }
    }
}

char calculate_grade(double mean)
{
    if (mean >= 90)
    {
        return 'A';
    }
    else if (mean >= 80)
    {
        return 'B';
    }
    else if (mean >= 70)
    {
        return 'C';
    }
    else
    {
        return 'F';
    }
}
*/
//제미나이가 짜준 코드
/*
#include <stdio.h>

typedef struct student{
    char name[20];
    int num;
    int kor;
    int eng;
    int math;
    int total;
    int rate;
    char grade;
} Student;

char calculate_grade(double mean);
// 2. 1중 포인터로 수정
void arrange(Student *ps); 

int main()
{
    Student student_list[5];
    double mean;
    int i, j;

    // 값 입력 받기
    for (i = 0; i < 5; i++)
    {
        printf("학번 : ");
        scanf("%d", &student_list[i].num);

        printf("이름 : ");
        scanf("%s", student_list[i].name);

        printf("국어, 영어, 수학 점수 : ");
        scanf("%d %d %d", &student_list[i].kor, &student_list[i].eng, &student_list[i].math);

        student_list[i].rate = 0; 
    }
    
    printf("\n# 정렬 전 데이터...\n");
    for (i = 0; i < 5; i++)
    {
        student_list[i].total = student_list[i].kor + student_list[i].eng + student_list[i].math;
        mean = (double)student_list[i].total / 3.0;
        student_list[i].grade = calculate_grade(mean);

        printf("%5d %15s %4d %4d %4d %6d %.1lf %c\n", student_list[i].num, student_list[i].name, student_list[i].kor, student_list[i].eng, student_list[i].math, student_list[i].total, mean, student_list[i].grade);
    }

    // 1. void 키워드 제거하고 함수 정상 호출
    arrange(student_list);

    printf("\n# 정렬 후 데이터...\n");
    
    // 4. 등수(1등~5등)대로 출력하기 위한 루프 수정
    for (i = 1; i <= 5; i++) // 1등부터 5등까지 찾기
    {
        for (j = 0; j < 5; j++) // 학생 5명 전체 스캔
        {
            if (student_list[j].rate == i) // i등인 학생을 찾으면
            {
                // j번 학생의 진짜 평균 다시 계산
                double current_mean = (double)student_list[j].total / 3.0; 
                
                // student_list[i]가 아닌 student_list[j] 출력
                printf("%5d %15s %4d %4d %4d %6d %.1lf %c\n", student_list[j].num, student_list[j].name, student_list[j].kor, student_list[j].eng, student_list[j].math, student_list[j].total, current_mean, student_list[j].grade);
            }
        }
    }
    
    return 0;
}

// 3. 최적화된 등수 산출 알고리즘
void arrange(Student *ps)
{
    int i, j;
    
    for (i = 0; i < 5; i++) // 기준 학생 (i)
    {
        int rank = 1; // 기본 등수는 1등으로 시작
        
        for (j = 0; j < 5; j++) // 비교 대상 학생 (j)
        {
            // 나(i)보다 남(j)의 총점이 더 높다면 내 등수가 1등수씩 밀려남
            if (ps[j].total > ps[i].total)
            {
                rank++;
            }
        }
        ps[i].rate = rank; // 최종 계산된 등수를 rate에 저장 (-> 대신 . 사용)
    }
}

char calculate_grade(double mean)
{
    if (mean >= 90) return 'A';
    else if (mean >= 80) return 'B';
    else if (mean >= 70) return 'C';
    else return 'F';
} */ //하... 교수님은 버블소팅? 사용 하심.

#include <stdio.h>

// 구조체 선언: 계산될 총점, 평균, 학점까지 한 번에 관리
typedef struct {
    int num;
    char name[20];
    int kor;
    int eng;
    int math;
    int total;
    double mean;
    char grade;
} Student;

// 학점 계산 함수
char get_grade(double mean)
{
    if (mean >= 90) return 'A';
    else if (mean >= 80) return 'B';
    else if (mean >= 70) return 'C';
    else return 'F';
}

// 학생들을 총점 기준 내림차순(1등부터)으로 정렬하는 함수
void sort_students(Student *list, int size)
{
    int i, j;
    Student temp;

    for (i = 0; i < size - 1; i++) // 이제 첫번째 자리는 가장 큰애가 오는 거다
    {
        for (j = i + 1; j < size; j++)
        {
            if (list[i].total < list[j].total) // 뒤의 학생 점수가 더 높으면
            {
                // ✨ 핵심 최적화: 변수를 하나하나 바꾸지 않고 구조체 덩어리를 통째로 교환!
                temp = list[i];
                list[i] = list[j];
                list[j] = temp;
            }
        }
    }
}

int main()
{
    Student list[5];
    int i;

    // 1. 값 입력 및 즉시 계산 (One-Pass 처리)
    for (i = 0; i < 5; i++)
    {
        printf("학번 : ");
        scanf("%d", &list[i].num);

        printf("이름 : ");
        scanf("%s", list[i].name);

        printf("국어, 영어, 수학 점수 : ");
        scanf("%d %d %d", &list[i].kor, &list[i].eng, &list[i].math);

        // 입력받자마자 즉시 총점, 평균, 학점을 계산해 구조체에 저장
        list[i].total = list[i].kor + list[i].eng + list[i].math;
        list[i].mean = (double)list[i].total / 3.0;
        list[i].grade = get_grade(list[i].mean);
    }
    
    // 2. 구조체 배열 정렬
    sort_students(list, 5);

    // 3. 정렬된 결과 출력
    printf("\n=============================== [총점 순 정렬 결과] ===============================\n");
    printf("%5s %15s %6s %6s %6s %8s %8s %6s\n", "학번", "이름", "국어", "영어", "수학", "총점", "평균", "학점");
    printf("-----------------------------------------------------------------------------------\n");
    
    for (i = 0; i < 5; i++)
    {
        printf("%5d %15s %6d %6d %6d %8d %8.1lf %6c\n", 
               list[i].num, list[i].name, 
               list[i].kor, list[i].eng, list[i].math, 
               list[i].total, list[i].mean, list[i].grade);
    }

    return 0;
}