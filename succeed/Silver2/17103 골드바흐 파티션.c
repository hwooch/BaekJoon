#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

// 17103 _ 골드바흐 파티션

// 문제
// 골드바흐의 추측 : 2보다 큰 짝수는 두 소수의 합으로 나타낼 수 있다.
// 짝수 N을 두 소수의 합으로 나타내는 표현을 골드바흐 파티션이라고 한다.
// 짝수 N이 주어졌을 때, 골드바흐 파티션의 개수를 구해보자.
// 두 소수의 순서만 다른 것은 같은 파티션이다.
// 
// 입력
// 첫째 줄에 테스트 케이스의 개수 T(1 ≤ T ≤ 100)가 주어진다.
// 각 테스트 케이스는 한 줄로 이루어져 있고, 정수 N은 짝수이고, 2 < N ≤ 1, 000, 000을 만족한다.
//
// 출력
// 각각의 테스트 케이스마다 골드바흐 파티션의 수를 출력한다.

int a[1000001] = { 1,1, };
int main() {
    int count = 0;
    for (int i = 2; i <= sqrt(1000001); i++) {
        if (a[i] == 0) {
            for (int j = 2; i * j < 1000001; j++) {
                a[i * j] = 1;
            }
        }
    } // 0이면 소수

    int T;
    scanf("%d", &T);

    int user;
    while (T--) {
        count = 0;
        scanf("%d", &user);
        for (int i = 2; i <= user / 2; i++) {
            if (a[user - i] == 0 && a[i] == 0) {
                count++;
            }
        }
        printf("%d\n", count);
    }

}