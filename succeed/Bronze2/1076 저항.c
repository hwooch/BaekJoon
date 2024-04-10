#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <math.h>

// 1076 _ 저항

// 문제
// 전자 제품에는 저항이 들어간다.저항은 색 3개를 이용해서 그 저항이 몇 옴인지 나타낸다.
// 처음 색 2개는 저항의 값이고, 마지막 색은 곱해야 하는 값이다.
// 저항의 값은 다음 표를 이용해서 구한다.
// 
// 색	    값	곱
// black	0	1
// brown	1	10
// red	    2	100
// orange	3	1, 000
// yellow	4	10, 000
// green	5	100, 000
// blue	    6	1, 000, 000
// violet	7	10, 000, 000
// grey	    8	100, 000, 000
// white	9	1, 000, 000, 000
// 예를 들어, 저항의 색이 yellow, violet, red였다면 저항의 값은 4, 700이 된다.
// 
// 입력
// 첫째 줄에 첫 번째 색, 둘째 줄에 두 번째 색, 셋째 줄에 세 번째 색이 주어진다.
// 위의 표에 있는 색만 입력으로 주어진다.
// 
// 출력
// 입력으로 주어진 저항의 저항값을 계산하여 첫째 줄에 출력한다.

int table1[10] = { 0,1,2,3,4,5,6,7,8,9 };
int table2[10] = { 1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000 };

int main() {
    char user[8];
    int N = 2;
    long long sum = 0;
    for (int i = 1; i >= 0; i--) {
        scanf("%s", user);

        if (strcmp(user, "black") == 0) {
            sum = sum + table1[0] * pow(10, i);
        }
        else if (strcmp(user, "brown") == 0) {
            sum = sum + table1[1] * pow(10, i);
        }
        else if (strcmp(user, "red") == 0) {
            sum = sum + table1[2] * pow(10, i);
        }
        else if (strcmp(user, "orange") == 0) {
            sum = sum + table1[3] * pow(10, i);
        }
        else if (strcmp(user, "yellow") == 0) {
            sum = sum + table1[4] * pow(10, i);
        }
        else if (strcmp(user, "green") == 0) {
            sum = sum + table1[5] * pow(10, i);
        }
        else if (strcmp(user, "blue") == 0) {
            sum = sum + table1[6] * pow(10, i);
        }
        else if (strcmp(user, "violet") == 0) {
            sum = sum + table1[7] * pow(10, i);
        }
        else if (strcmp(user, "grey") == 0) {
            sum = sum + table1[8] * pow(10, i);
        }
        else if (strcmp(user, "white") == 0) {
            sum = sum + table1[9] * pow(10, i);
        }
    }
    scanf("%s", user);
    if (strcmp(user, "black") == 0) {
        sum = sum * table2[0];
    }
    else if (strcmp(user, "brown") == 0) {
        sum = sum * table2[1];
    }
    else if (strcmp(user, "red") == 0) {
        sum = sum * table2[2];
    }
    else if (strcmp(user, "orange") == 0) {
        sum = sum * table2[3];
    }
    else if (strcmp(user, "yellow") == 0) {
        sum = sum * table2[4];
    }
    else if (strcmp(user, "green") == 0) {
        sum = sum * table2[5];
    }
    else if (strcmp(user, "blue") == 0) {
        sum = sum * table2[6];
    }
    else if (strcmp(user, "violet") == 0) {
        sum = sum * table2[7];
    }
    else if (strcmp(user, "grey") == 0) {
        sum = sum * table2[8];
    }
    else if (strcmp(user, "white") == 0) {
        sum = sum * table2[9];
    }
    printf("%lld", sum);
}