//문제

// #1 : 로봇 배터리 상태 분석 시스템
/*
#include <stdio.h>

double calc_average(double *arr, int count);
void check_battery_status(double *arr, int count, double mean);

int main()
{
    double arr[10];
    int i;
    int count;

    count = sizeof(arr)/sizeof(arr[0]);

    printf("----------로봇 배터리 전압 10개 데이터 입력----------\n");
    for (i = 0; i < count; i++)
    {
        scanf("%lf", &arr[i]); if(arr[i] < 10.0 || arr[i] > 13) return 1;
    }

    double mean;

    mean = calc_average(arr, count);
    check_battery_status(arr, count, mean);

    return 0;
}

double calc_average(double *arr, int count)
{
    int i;
    double total = 0;
    for (i = 0; i < count; i++)
    {
        total += arr[i];
    }

    return total / count;
}


void check_battery_status(double *arr, int count, double mean)
{
    int i;
    int num = 0;

    for (i = 0; i < count; i++)
    {
        if (arr[i] < 11.0)
        {
            num++;
        }
    }

    if (num >= 3)
    {
        printf("배터리 위험 - 충전필요\n");
    }
    else if (mean < 11.5) //else if 띄어쓰기 해야되네 
    {
        printf("배터리 저하 - 전력 절약모드 권장\n");
    }
    else{
        printf("정상 전압 상태\n");
    }
} //실제론 들어오자마자 바로 처리해버리는 스트리밍 처리방식 아주 많이 이용.
 */

 // #2 : 로봇 좌표 이동 함수
 /*
 #include <stdio.h>

 typedef struct position
 {
    int x;
    int y;
 } Position;

void move(Position *p, int dx, int dy);

int main()
{
    Position *p;
    int dx;
    int dy;

    p -> x = 0;
    p -> y = 0;

    printf("처음 위치 : (%d, %d)\n", p -> x, p -> y);

    printf("처음 이동 입력\n");
    scanf("%d%d", &dx, &dy);

    move(p, dx, dy);
    printf("첫 번째 이동 후 위치: (%d, %d)\n", p -> x, p -> y);

    printf("두번째 이동 입력\n");
    scanf("%d%d", &dx, &dy);

    move(p, dx, dy);
    printf("두 번째 이동 후 위치: (%d, %d)\n", p -> x, p -> y);

    return 0;

}

void move(Position *p, int dx, int dy)
{
    p -> x += dx;
    p -> y += dy;
} */

// #3 : 차동구동 로봇 속도 계산
/*
#include <stdio.h>

typedef struct wheelspeed {
    double left;
    double right;
} WheelSpeed;

typedef struct robotspeed{
    double linear;
    double angular;
} RobotSpeed;

RobotSpeed computeSpeed(WheelSpeed w, double wheel_radius, double wheel_distance);

int main()
{
    WheelSpeed w;
    RobotSpeed r_dot;
    double wheel_radius, wheel_distance;
    

    printf("왼쪽 바퀴 속도(rad/s) : ");
    scanf("%lf", &(w.left));
    printf("오른쪽 바퀴 속도(rad/s) : ");
    scanf("%lf", &(w.right));
    printf("바퀴 반지름 R (m) : " );
    scanf("%lf",&wheel_radius);
    printf("바퀴 간 거리 L (m) : ");
    scanf("%lf", &wheel_distance);

    r_dot = computeSpeed(w, wheel_radius, wheel_distance);

    printf("선속도 : %lf.2 m/s \n", r_dot.linear);
    printf("각속도 : %lf.2 rad/s \n", r_dot.angular);

    return 0;
}

RobotSpeed computeSpeed(WheelSpeed w, double wheel_radius, double wheel_distance)
{
    RobotSpeed result;
    
    result.linear = wheel_radius *(w.right + w.left) / 2;
    result.angular = wheel_radius * (w.right - w.left) / wheel_distance;

    return result;
} //포인터로 하면 더 빠르지만 뭐 문제에서 이렇게 하라는데 뭐...
 */

 // 14. 파일 입출력

 // #1 : 파일 개방과 폐쇄. 파일을 열고 닫는 프로그램
 /*
 #include <stdio.h>

 int main()
 {
    FILE *fp;

    fp = fopen("a.txt", "r");
    if (fp == NULL)
    {
        printf("파일이 열리지 않았습니다.\n");
        return 1;
    }

    printf("파일이 열렸습니다.\n");
    fclose(fp);

    return 0;
 } */

 // #2 : 파일의 내용을 화면에 출력하기.
/*
 #include <stdio.h>

 int main()
 {
    FILE *fp;
    int ch;

    fp = fopen("a.txt", "r"); //읽기모드로 열거야.
    if (fp == NULL)
    {
        printf("파일이 열리지 않았습니다.\n");
        return 1;
    }

    while (1)
    {
        ch = fgetc(fp);
        if (ch == EOF)
        {
            break;
        }
        putchar(ch);
    }
    fclose(fp);

    return 0;
 } */

 // #3 : 문자 출력 함수 fputc. 문자열을 한 문자씩 파일로 출력하기
 /*
 #include <stdio.h>

 int main()
 {
    FILE *fp;
    char str[] = "banana"; //근데 이러고 banana로 하고 다시하면 기존 apple 다 날라가고 banana가 써짐. 덮어버림.
    int i;

    fp = fopen("b.txt", "w"); //근데 "a"로 하면 add 모드. 리셋이 아니라 뒤에 붙임.
    if (fp == NULL)
    {
        printf("파일을 만들지 못해습니다.\n");
        return 1;
    }

    i = 0;
    while (str[i] != '\0')
    {
        fputc(str[i], fp); //fp에 한글자씩 str 문자열의 문자를 넣음.
        i++;
    }
    fputc('\n', fp); //"a" 모드일 때 이거 덕에 다음 줄에 붙는 것
    fclose(fp);

    return 0;
 } */

 // #4 : + 개방 모드, fseek, rewind, feof 함수. a+ 모드로 파일의 내용을 확인하며 출력
 /*
 #include <stdio.h>
 #include <string.h>

 int main()
 {
    FILE *fp;
    char str[20];

    fp = fopen("a.txt", "a+");
    if (fp == NULL)
    {
        printf("파일을 만들지 못했습니다.\n");
        return 1;
    }

    while (1)
    {
        printf("과일 이름 : ");
        scanf("%s", str);
        if (strcmp(str, "end") == 0)
        {
            break;
        }
        else if (strcmp(str, "list") == 0)
        {
            fseek(fp, 0, SEEK_SET);
            while (1)
            {
                fgets(str, sizeof(str), fp);
                if (feof(fp))
                {
                    break;
                }
                printf("%s", str);
            }
        }
        else{
            fprintf(fp, "%s\n", str);
        }
    }
    fclose(fp);

    return 0;
 } */

 // #5 : fgets와 fputs : 한 줄씨 입출력. 여러 줄의 문장을 입력하여 한 줄로 출력
 /*
 #include <stdio.h>
 #include <string.h>

 int main()
 {
    FILE  *ifp, *ofp;
    char str[80];
    char *res;

    ifp = fopen("./Test/a.txt", "r"); //현재 내 작업위치가 아닌 다른 곳에 있다면 경로를 다 적어줘야한다. 이건 상대경로로 적어준 것. 절대 경로는 앞에 /가 있으면 절대경로로 인식.
    if (ifp == NULL)
    {
        printf("입력 파일을 열지 못했습니다.\n");
        return 1;
    }

    ofp = fopen("b.txt", "w");
    if (ofp == NULL)
    {
        printf("출력 파일을 열지 못했습니다.\n");
        return 1;
    }

    while (1)
    {
        res = fgets(str, sizeof(str), ifp);
        if (res == NULL)
        {
            break;
        }
        str[strlen(str) - 1] = '\0';
        fputs(str, ofp);
        fputs(" ", ofp);
    }

    fclose(ifp);
    fclose(ofp);

    return 0;
 } */

 // 기습 문제. log.txt 열고 에러 몇번, 경고 몇번, 어떤 에러가 있었는지 세기.
 //나
 /*
 #include <stdio.h>
 #include <string.h>

 int main()
 {
    FILE *fp;
    int ch;
    int error_count = 0, warning_count = 0;
    int sensor = 0, low_battery = 0, motor_oveload = 0;
    int sensor_count = 0;

    fp = fopen("log.txt", "r");
    if (fp == NULL)
    {
        printf("파일을 만들지 못했습니다.\n");
        return 1;
    }

    while (1)
    {
        ch = fgetc(fp);

        if (ch == 'E')
        {
            error_count++;
        }
        else if (ch == 'W')
        {
            warning_count++;
        }

        if (ch == 'S')
        {
            sensor++;
        }
        else if(ch == 'e' && sensor == 1)
        {
            sensor_count++;
            sensor = 0;
        }
        else
        {
            sensor = 0;
        }

        if (ch == 'L')
        {
            low_battery++;
        }

        if (ch == 'M')
        {
            motor_oveload++;
        }
        if (feof(fp))
        {
            break;
        }

    }
    fclose(fp);

    printf("ERROR가 난 횟수 : %d\nWARNING이 난 횟수 : %d\n", error_count, warning_count);
    printf("[ERROR] Sensor failed : %d번, [ERROR] Motor overload : %d번, [WARNING] Low battery : %d번\n", sensor_count, motor_oveload, low_battery);
    return 0;
 }//sudo apt install open-vm-tools open -vm-tools-desktop -y
 */

 //제미나이... 흠 더 발전시켜서 ERROR면 그 줄 나머지 다 불러오는 식으로 에러 내용 가져오는 것도 좋을 듯. 아니면 무슨 에러가 뜰 지 모르는 상황.
 /*
#include <stdio.h>
#include <string.h>

int main()
{
    FILE *fp;
    char line[256];
    
    int error_count = 0, warning_count = 0;
    int sensor_failed = 0, low_battery = 0, motor_overload = 0;

    fp = fopen("log.txt", "r");
    if (fp == NULL)
    {
        printf("파일을 열지 못했습니다.\n");
        return 1;
    }

    while (fgets(line, sizeof(line), fp) != NULL)
    {
        int len = strlen(line);

        // [핵심 수정 부분] 
        // 맨 끝 글자가 '\n' 또는 '\r'인 경우에만 널 문자('\0')로 바꿔서 지워줌
        // 이렇게 하면 엔터가 없는 줄의 정상적인 알파벳이 억울하게 잘려나가는 일을 막을 수 있습니다.
        while (len > 0 && (line[len - 1] == '\n' || line[len - 1] == '\r'))
        {
            line[len - 1] = '\0';
            len--; // 혹시 \r\n 두 개가 연달아 있으면 둘 다 지우기 위해 길이를 줄임
        }

        if (strcmp(line, "[ERROR] Sensor failed") == 0)
        {
            error_count++;
            sensor_failed++;
        }
        else if (strcmp(line, "[ERROR] Motor overload") == 0)
        {
            error_count++;
            motor_overload++;
        }
        else if (strcmp(line, "[WARNING] Low battery") == 0)
        {
            warning_count++;
            low_battery++;
        }
    }

    fclose(fp);

    printf("ERROR가 난 횟수 : %d\nWARNING이 난 횟수 : %d\n", error_count, warning_count);
    printf("[ERROR] Sensor failed : %d번\n[ERROR] Motor overload : %d번\n[WARNING] Low battery : %d번\n", 
           sensor_failed, motor_overload, low_battery);
           
    return 0;
} */

// 기습 문제 #2 fast.log
/*
#include <stdio.h>
#include <string.h>

int main()
{
    FILE *fp;
    char str[256];
    int hours_count[24] = {0};
    int ping_count = 0, max_count;
    int ip4_count = 0;

    char ip_data[50][100] = {0};
    int ip_count[50] = {0};
    int unique_ip_count = 0;
    int i;

    fp = fopen("fast.log", "r");
    if (fp == NULL)
    {
        printf("파일을 만들지 못했습니다.\n");
        return 1;
    }

    while(1)
    {
        fgets(str, sizeof(str), fp);
        if (feof(fp)) break;

        hours_count[((str[11] -'0')*10 + str[12] - '0')]++; // 1. 시간 몇번 나왔는지. 문자인 숫자를 진짜 숫자로 바꾸는법. 실수인 경우 추가적인 함수가 필요함. stdlib에서 가져오는.

        //주소 기억

        // 주소 이쁘게 정리
        char *pdest = strstr(str, "-> ") + 3; //주소 찾기.
        int len = strlen(pdest);
        while (len > 0 && (pdest[len - 1] == '\n' || pdest[len - 1] == '\r'))
        {
            pdest[len - 1] = '\0';
            len--;
        }

        int found = 0;

        for (i = 0; i < unique_ip_count; i++)
        {
            if (strcmp(ip_data[i], pdest) == 0 )
            {
                ip_count[i]++;
                found = 1;
                break;
            }
        }

        if (found == 0)
        {
            strcpy(ip_data[unique_ip_count], pdest);
            ip_count[unique_ip_count] = 1;
            unique_ip_count++;
        }

        if(str[123] == 'C') //IPv6
        {
            ip4_count++;
        }

        ping_count++; // 2. ping을 보낸 횟수. 좀이따 IPv4가 나온 횟수 / 2만큼 빼줘야 진짜 ping_count!!
    }

    //통계 결과 출력
    printf("ping을 보낸 횟수 : %d\n", ping_count - ip4_count / 2);

    int max_hour = 0;
    for (i = 0; i < 24; i++)
    {
        if (hours_count[max_hour] < hours_count[i])
        {
            max_hour = i;
        }
    }
    printf("가장 많이 핑을 보낸 시간대 : %d시 ~ %d시 (%d회)\n", max_hour, max_hour + 1, hours_count[max_hour]);


    int max_dest = 0;
    for (i = 0; i < unique_ip_count; i++)
    {
        if (ip_count[max_dest] < ip_count[i])
        {
            max_dest = i;
        }
    }
    
    printf("가장 많이 핑을 받은 목적지 : %s(%d회)\n", ip_data[max_dest], ip_count[max_dest]);

    return 0; //이걸 해버릴 때까지 시간을 주셔버리네, 로그는 만들어내고 싶으면 언제든지 만들어낼 수 있다.
}
 */
//------------------------------------------------------------------------------------------------

//gemini가 짜준 코드
/*
#include <stdio.h>
#include <string.h>

int main()
{
    FILE *fp;
    char line[512]; // 로그 한 줄이 꽤 기니까 넉넉하게 512바이트로 잡습니다.

    // 1. 총 횟수 저장 변수
    int total_ping = 0; 
    
    // 2. 시간대별 횟수 저장 (0시~23시)
    int hours_count[24] = {0}; 
    
    // 3. 목적지 주소별 횟수 저장 (최대 50종류의 고유 IP를 담을 수 있는 배열)
    char dest_ips[50][100] = {0};
    int dest_counts[50] = {0};
    int unique_ip_count = 0;

    fp = fopen("fast.log", "r");
    if (fp == NULL)
    {
        printf("로그 파일을 열 수 없습니다.\n");
        return 1;
    }

    while (fgets(line, sizeof(line), fp) != NULL)
    {
        // [목표 1] 총 핑 횟수 누적
        total_ping++;

        // [목표 2] 시간대 추출 (11번째, 12번째 인덱스가 무조건 '시'에 해당)
        // '0' 문자(아스키코드 48)를 빼서 실제 정수값으로 만듭니다.
        int h = (line[11] - '0') * 10 + (line[12] - '0');
        if (h >= 0 && h < 24) 
        {
            hours_count[h]++;
        }

        // [목표 3] 목적지 IP 추출 및 카운트
        char *dest_ptr = strstr(line, "-> ");
        if (dest_ptr != NULL)
        {
            dest_ptr += 3; // "-> " 3글자를 건너뛰어 진짜 IP 시작점으로 포인터 이동

            // 이전처럼 엔터 찌꺼기(\r, \n) 깔끔하게 제거
            int len = strlen(dest_ptr);
            while (len > 0 && (dest_ptr[len - 1] == '\n' || dest_ptr[len - 1] == '\r'))
            {
                dest_ptr[len - 1] = '\0';
                len--;
            }

            // 배열에 이미 기록된 목적지인지 확인
            int found = 0;
            for (int i = 0; i < unique_ip_count; i++)
            {
                if (strcmp(dest_ips[i], dest_ptr) == 0) // 이미 있는 주소면
                {
                    dest_counts[i]++;
                    found = 1;
                    break;
                }
            }

            // 처음 보는 새로운 주소라면 배열에 새로 등록
            if (found == 0 && unique_ip_count < 50)
            {
                strcpy(dest_ips[unique_ip_count], dest_ptr);
                dest_counts[unique_ip_count] = 1;
                unique_ip_count++;
            }
        }
    }
    fclose(fp);

    // --- 통계 결과 출력하기 ---
    
    // 1. 최대 시간대 찾기
    int max_hour = 0;
    for (int i = 1; i < 24; i++) {
        if (hours_count[i] > hours_count[max_hour]) max_hour = i;
    }

    // 2. 최대 목적지 찾기
    int max_ip_index = 0;
    for (int i = 1; i < unique_ip_count; i++) {
        if (dest_counts[i] > dest_counts[max_ip_index]) max_ip_index = i;
    }

    printf("================ 로그 분석 결과 ================\n");
    printf("1. 총 전송된 Ping 횟수 : %d회\n", total_ping);
    printf("2. 가장 Ping이 많았던 시간대 : %02d시 (%d회)\n", max_hour, hours_count[max_hour]);
    printf("3. 가장 공격을 많이 받은 목적지 : %s (%d회)\n", dest_ips[max_ip_index], dest_counts[max_ip_index]);
    
    return 0;
} */

// 고민을 하는 힘!!