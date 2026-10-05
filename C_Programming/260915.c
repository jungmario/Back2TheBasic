// 브라우저 로그 데이터 읽어오기 연습
/*
#include <stdio.h>
#include <string.h>

int main()
{
    FILE *fp;
    fp = fopen("browser_log.txt", "r");
    if (fp == NULL)
    {
        printf("파일을 읽지 못했습니다.\n");
        return 1;
    }

    int count = 0, browser_count = 0, file_count = 0, unknown_count = 0;

    char log[1000];

    int sep_days_count[30] = {0};

    int unique_browser_count = 0, unique_file_count = 0;
    int i;

    char browser_data[200][1000]; // 배열 행 작게하면 오버플로우 발생. 조심할것.
    char file_data[200][1000];

    int browser_data_count[200] = {0};
    int file_data_count[200] = {0};

    while(1)
    {
        //한줄씩 가져오기
        fgets(log, sizeof(log), fp);
        if (feof(fp)) break;

        sep_days_count[(log[8]-'0')*10 + log[9]-'0']++; // 1. 날짜 나온 회수 저장
        
        // 2. 주소 기억 및 이쁘게 정리
        char *plog = strstr(log, "| ") + 2;
        int len = strlen(plog);
        while (len > 0 && ( plog[len - 1] == '\n' || plog[len - 1] == '\r'))
        {
            plog[len - 1] = '\0';
            len --;
        }
        char *pbrowser_log = strstr(plog,"http");
        char *pfile_log = strstr(plog, "file://");

        int found = 0;

        if (pbrowser_log != NULL)
        {
            for (i = 0; i < unique_browser_count; i++)
            {
                if (strcmp(browser_data[i], pbrowser_log) == 0)
                {
                    browser_data_count[i]++;
                    found = 1;
                    break;
                }
            }

            if (found == 0)
            {
                strcpy(browser_data[unique_browser_count], pbrowser_log);
                browser_data_count[unique_browser_count] = 1;
                unique_browser_count++;
            }
            
            browser_count++;
        }
        else if(pfile_log != NULL)
        {
            for (i = 0; i < unique_file_count; i++)
            {
                if (strcmp(file_data[i], pfile_log) == 0)
                {
                    file_data_count[i]++;
                    found = 1;
                    break;
                }
            }

            if (found == 0)
            {
                strcpy(file_data[unique_file_count], pfile_log);
                file_data_count[unique_file_count] = 1;
                unique_file_count++;
            }
            
            file_count++;
        }
        else
        {
            unknown_count++;
        }
        count++;
    }

    //통계 결과 출력
    printf("총 로그 기록 개수 : %d, 총 브라우저 접속 횟수 : %d, 총 파일 열람 횟수 : %d, 총 unknown 횟수 : %d\n", count, browser_count, file_count, unknown_count);
    
    int max_day = 0;
    for (i = 0; i < 30; i++)
    {
        if (sep_days_count[max_day] < sep_days_count[i])
        {
            max_day = i;
        }
    }
    printf("가장 인터넷 접속 및 파일 열람을 많이 한 날 : %d일 (%d회)\n", max_day + 1, sep_days_count[max_day]);

    int max_browser = 0, max_file = 0;
    for (i = 0; i < unique_browser_count; i++)
    {
        if(browser_data_count[max_browser] < browser_data_count[i])
        {
            max_browser = i;
        }
    }
    for (i = 0; i < unique_file_count; i++)
    {
        if(file_data_count[max_file] < file_data_count[i])
        {
            max_file = i;
        }
    }
    
    printf("가장 많이 방문한 사이트 : %s (%d회)\n",browser_data[max_browser] ,browser_data_count[max_browser]);
    printf("가장 많이 열람한 파일 : %s (%d회)\n", file_data[max_file], file_data_count[max_file]);

    return 0;
} */

#include <stdio.h>

int main()
{
    printf("%d\n", 'A');
    
    return 0;
}