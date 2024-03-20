#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 28456 _ Array Rotation

// 문제
// 스킵이는 N * N 크기의 2차원 배열을 가지고 있다.
// 너무 귀여운 배열을 관찰하던 스킵이는 배열이 멋대로 돌아가는 걸 발견했다.
// 배열이 돌아가는 연산에는 두 가지가 있다.
// 
// 1 i:i(1 <= i <= N)번째 행을 선택한다. 선택한 행의 마지막 원소를 삭제하고 첫 번째 원소 앞에 추가한다.
// 
// 2 : 새로운 배열 A를 만든다.원래 있던 배열의 모든 원소에 대해 i번째 행 j번째 열의 원소는 A의 j번째 행(N - i + 1)번째 열의 원소가 된다.
// 그 후 가지고 있는 배열을 A로 만든다. 배열에 수행한 연산이 순서대로 주어진다. 모든 연산을 수행했을 때 최종적으로 돌아간 배열의 원소를 출력해 주자.
// 
// 입력
// 첫 번째 줄에 2차원 배열의 크기 N이 주어진다. (1 <= N <= 100)
// 그다음 줄부터 N개의 줄에는 배열의 원소가 공백으로 구분되어 주어진다. 배열의 모든 원소는 1000 이하의 양의 정수이다.
// 그다음 줄에는 배열에 수행한 연산의 개수 Q가 주어진다.(1 <= Q <= 100)
// 그다음 줄부터 Q개의 줄에는 배열에 수행한 연산이 차례대로 주어진다.
// 
// 출력
// 첫 번째 줄부터 N개의 줄에 모든 연산을 수행한 배열을 출력한다.같은 행의 원소는 공백으로 구분하고 각 행마다 개행문자로 구분한다.

int table[101][101];
int copy[101][101];

int main() {
    int N;
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            scanf("%d", &table[i][j]);
        }
    }
    int T;
    scanf("%d", &T);

    int user;
    int user_1;
    int temp;

    while (T--) {
        scanf("%d", &user);
        if (user == 1) { // 1번연산이라면
            scanf("%d", &user_1);

            temp = table[user_1][N];

            for (int i = N - 1; i >= 1; i--) {
                table[user_1][i + 1] = table[user_1][i];
            }

            table[user_1][1] = temp;

        }
        else { // 2번연산이라면
            for (int i = 1; i <= N; i++) {
                for (int j = 1; j <= N; j++) {
                    copy[j][N - i + 1] = table[i][j];
                }
            }
            for (int i = 1; i <= N; i++) {
                for (int j = 1; j <= N; j++) {
                    table[i][j] = copy[i][j];
                }
            }
        }
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            printf("%d ", table[i][j]);
        }
        printf("\n");
    }
}