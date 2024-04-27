#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

// 2312 _ 수 복원하기

// 문제
// 양의 정수 N이 주어졌을 때, 이 수를 소인수분해 한 결과를 출력하는 프로그램을 작성하시오.
// 
// 입력
// 첫째 줄에 테스트 케이스의 수가 주어진다.
// 각 테스트 케이스마다 양의 정수 N(2 ≤ N ≤ 100, 000)이 주어진다.
// 
// 출력
// 각 테스트 케이스마다 각 인수와 그 인수가 곱해진 횟수를 한 줄씩 출력한다.
// 출력 순서는 인수가 증가하는 순으로 한다.

#define SIZE 100001

int main(void)
{
    int a[SIZE] = { 0 };
    int arr[SIZE] = { 0 }; // 소수들이 차례로 들어가있는 배열
    int i, j;
    int count = 0;

    for (i = 2; i <= sqrt(SIZE); i++) {
        if (a[i] == 0) {
            for (j = 2; i * j < SIZE; j++) {
                a[i * j] = 1;
            }
        }
    }

    for (i = 2; i < SIZE; i++) {
        if (a[i] == 0) {
            arr[count++] = i;
        }
    }

    int N;
    scanf("%d", &N);
    int user;
    while (N--) {
        scanf("%d", &user);

        for (i = 0; i < count && user > 1; i++) {
            int number = arr[i]; // 현재 소수
            int number_count = 0; // 그 소수가 곱해진 횟수
            while (user % number == 0) { // user가 현재 소수로 나누어 떨어지면
                user /= number;
                number_count++;
            }
            if (number_count > 0) { // 만약 인수가 한 번 이상 곱해졌다면
                printf("%d %d\n", number, number_count);
            }
        }
        if (user > 1) { // 반복문이 끝난 후 user가 1보다 크다면 user 자체가 소수
            printf("%d 1\n", user);
        }
    }
}
