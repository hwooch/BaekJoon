#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// 11866 _ 요세푸스 문제 0

// 문제
// 요세푸스 문제는 다음과 같다.
//
// 1번부터 N번까지 N명의 사람이 원을 이루면서 앉아있고, 양의 정수 K(≤ N)가 주어진다.
// 이제 순서대로 K번째 사람을 제거한다.
// 한 사람이 제거되면 남은 사람들로 이루어진 원을 따라 이 과정을 계속해 나간다.
// 이 과정은 N명의 사람이 모두 제거될 때까지 계속된다.
// 원에서 사람들이 제거되는 순서를(N, K) - 요세푸스 순열이라고 한다.
// 예를 들어(7, 3) - 요세푸스 순열은 <3, 6, 2, 7, 5, 1, 4>이다.
//
// N과 K가 주어지면(N, K) - 요세푸스 순열을 구하는 프로그램을 작성하시오.
//
// 입력
// 첫째 줄에 N과 K가 빈 칸을 사이에 두고 순서대로 주어진다. (1 ≤ K ≤ N ≤ 1, 000)
//
// 출력
// 예제와 같이 요세푸스 순열을 출력한다.


int main() {

    int N;
    scanf("%d", &N);

    int K;
    scanf("%d", &K);

    int* table = (int*)malloc(sizeof(int) * N);
    int top = K - 1;

    for (int i = 0; i < N; i++) {
        table[i] = 1;
    }
    int count = 0;

    printf("<");

    for (int i = 0; i < N - 1; i++) {
        while (1) {
            if (table[top] == 1) { // 만약 출력되지 않은 것이라면
                table[top] = 0; // 출력했다는 표시로 0을 대입하고
                printf("%d, ", top + 1); // top 출력

                count = 0;
                while (count != K) {
                    top++;
                    top = top % N;
                    if (table[top] == 1) {
                        count++;
                    }
                }

                break; // 다음 반복으로 넘어감
            }
        }
    }
    printf("%d>", top + 1);
}