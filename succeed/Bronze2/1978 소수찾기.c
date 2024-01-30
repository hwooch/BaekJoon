#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// 1978 _ 소수 찾기
// 
// 문제
// 주어진 수 N개 중에서 소수가 몇 개인지 찾아서 출력하는 프로그램을 작성하시오.
// 
// 입력
// 첫 줄에 수의 개수 N 이 주어진다. 
// N은 100 이하이다. 
// 다음으로 N개의 수가 주어지는데 수는 1000 이하의 자연수이다.
// 
// 출력
// 주어진 수들 중 소수의 개수를 출력한다.

int number[100];

int main() {
    int N;
    scanf("%d", &N);
    int answer = 0;
    for (int i = 0; i < N; i++) {
        scanf("%d", &number[i]);
        int count = 0;
        int devide = 1;
        while (devide <= number[i]) {
            if (number[i] % devide == 0) {
                count++;
            }
            devide++;
            if (count > 2) {
                break;
            }
        }
        if (count == 2) {
            answer++;
        }
    }
    printf("%d", answer);
}