#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 1915 _ 가장 큰 정사각형

// 문제
// n×m의 0, 1로 된 배열이 있다.
// 이 배열에서 1로 된 가장 큰 정사각형의 크기를 구하는 프로그램을 작성하시오.
// 
// 0    1	 0	  0
// 0    1	 1	  1
// 1    1	 1	  0
// 0    0	 1	  0
// 위와 같은 예제에서는 가운데의 2×2 배열이 가장 큰 정사각형이다.
// 
// 입력
// 첫째 줄에 n, m(1 ≤ n, m ≤ 1, 000)이 주어진다.
// 다음 n개의 줄에는 m개의 숫자로 배열이 주어진다.
// 
// 출력
// 첫째 줄에 가장 큰 정사각형의 넓이를 출력한다.

int arr[1001][1001];
int dp[1001][1001];

int min(int a, int b, int c) { // 세 수중 가장 작은값 리턴
    if (a < b) return a < c ? a : c;
    else return b < c ? b : c;
}

int main() {
    int n, m;
    char temp[1002];
    scanf("%d %d", &n, &m);

    int max = 0; // 가장 큰 정사각형의 크기를 저장

    // 배열 입력 받기
    for (int i = 0; i < n; i++) {
        scanf("%s", temp);
        for (int j = 0; j < m; j++) {
            arr[i][j] = temp[j] - '0';
            dp[i][j] = arr[i][j]; // dp 배열 초기화
            if (dp[i][j] > max) {
                max = dp[i][j];
            }// 최대 정사각형 크기 갱신
        }
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (arr[i][j] == 1) {
                dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - 1], dp[i][j - 1]) + 1;
                if (dp[i][j] > max) {
                    max = dp[i][j];
                }
            }
        }
    }
    printf("%d", max * max); // 가장 큰 정사각형의 넓이 출력
    return 0;
}
