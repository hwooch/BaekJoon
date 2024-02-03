#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 4153 _ 직각삼각형

// 문제
// 과거 이집트인들은 각 변들의 길이가 3, 4, 5인 삼각형이 직각 삼각형인것을 알아냈다.
// 주어진 세변의 길이로 삼각형이 직각인지 아닌지 구분하시오.
// 
// 입력
// 입력은 여러개의 테스트케이스로 주어지며 마지막줄에는 0 0 0이 입력된다.
// 각 테스트케이스는 모두 30, 000보다 작은 양의 정수로 주어지며, 각 입력은 변의 길이를 의미한다.
// 
// 출력
// 각 입력에 대해 직각 삼각형이 맞다면 "right", 아니라면 "wrong"을 출력한다.


int main() {

    int len[3] = { 0, };
    while (1) {
        scanf("%d %d %d", &len[0], &len[1], &len[2]);

        if (len[0] == 0 || len[1] == 0 || len[2] == 0) {
            return 0;
        }

        int max = len[0];
        int top = 0;
        int min1 = 1;
        int min2 = 2;

        if (max < len[1]) {
            max = len[1];
            top = 1;
            min1 = 0;
            min2 = 2;
        }
        if (max < len[2]) {
            max = len[2];
            top = 2;
            min1 = 0;
            min2 = 1;
        }
        if (len[top] * len[top] == len[min1] * len[min1] + len[min2] * len[min2]) {
            printf("right\n");
        }
        else {
            printf("wrong\n");
        }

    }
    return 0;
}