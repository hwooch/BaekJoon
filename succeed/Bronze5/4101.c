#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//문제
//두 양의 정수가 주어졌을 때, 첫 번째 수가 두 번째 수보다 큰지 구하는 프로그램을 작성하시오.
//
//입력
//입력은 여러 개의 테스트 케이스로 이루어져 있다.각 테스트 케이스는 한 줄로 이루어져 있으며, 두 정수가 주어진다.
//두 수는 백만보다 작거나 같은 양의 정수이다.입력의 마지막 줄에는 0이 두 개 주어진다.
//
//출력
//각 테스트 케이스마다, 첫 번째 수가 두 번째 수보다 크면 Yes를, 아니면 No를 한 줄에 하나씩 출력한다.

int main() {
    int user1 = 1; //  숫자 입력변수
    int user2 = 1; //  숫자 입력변수

    while (user1 != 0 && user2 != 0) {
        scanf("%d", &user1);
        scanf("%d", &user2);

        if (user1 == 0 && user2 == 0) {
            break;
        }
        else if (user1 - user2 <= 0) {
            printf("No\n");
        }
        else {
            printf("Yes\n");
        }
    }
}