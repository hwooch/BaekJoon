#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <math.h>

// 1747 _ 소수&팰린드롬

// 문제
// 어떤 수와 그 수의 숫자 순서를 뒤집은 수가 일치하는 수를 팰린드롬이라 부른다.
// 예를 들어 79, 197과 324, 423 등이 팰린드롬 수이다.
// 
// 어떤 수 N(1 ≤ N ≤ 1, 000, 000)이 주어졌을 때, N보다 크거나 같고, 소수이면서 팰린드롬인 수 중에서, 가장 작은 수를 구하는 프로그램을 작성하시오.
// 
// 입력
// 첫째 줄에 N이 주어진다.
// 
// 출력
// 첫째 줄에 조건을 만족하는 수를 출력한다.

int array[1200001] = { 0, };

int check(int N) {
    char number[10];       // 변환한 문자열을 저장할 배열

    sprintf(number, "%d", N);    // 정수를 문자열로 저장
    int len = strlen(number);    // 문자열의 길이

    for (int i = 0; i < len / 2; i++) {
        if (number[i] != number[len - i - 1]) { //같지않으면
            return 0; //바로 0 리턴
        }
    }

    return 1; //펠린드롬수이다.
}

int main() {
    array[1] = 1;
    for (int i = 2; i <= sqrt(1200000); i++) {
        if (array[i] == 0) {
            for (int j = i * 2; j <= 1200000; j = j + i) {
                array[j] = 1;
            }
        }
    }

    int N;
    scanf("%d", &N);
    int count = 0;
    for (int i = N; i <= 1200000; i++) {
        if (array[i] == 0) {
            if (check(i)) {
                printf("%d\n", i);
                return 0;
            }
        }
    }
}
