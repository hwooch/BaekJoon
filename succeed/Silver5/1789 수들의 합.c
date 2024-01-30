#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <limits.h>

// 1789 _ 수들의 합

// 문제
// 서로 다른 N개의 자연수의 합이 S라고 한다.
// S를 알 때, 자연수 N의 최댓값은 얼마일까 ?
//
// 입력
// 첫째 줄에 자연수 S(1 ≤ S ≤ 4, 294, 967, 295)가 주어진다.
//
// 출력
// 첫째 줄에 자연수 N의 최댓값을 출력한다.

int main() {
    unsigned long long user;
    scanf("%llu", &user);

    int count = 0;
    unsigned long long sum = 0;

    while (sum <= user) { // 자연수들의 합이 조건 안이라면
        sum = sum + count;
        count++;
    }
    printf("%d", count - 2);
}