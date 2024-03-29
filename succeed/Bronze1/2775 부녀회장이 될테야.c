#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 2775 _ 부녀회장이 될테야

// 문제
// 평소 반상회에 참석하는 것을 좋아하는 주희는 이번 기회에 부녀회장이 되고 싶어 각 층의 사람들을 불러 모아 반상회를 주최하려고 한다.
//
// 이 아파트에 거주를 하려면 조건이 있는데, 
// “a층의 b호에 살려면 자신의 아래(a - 1)층의 1호부터 b호까지 사람들의 수의 합만큼 사람들을 데려와 살아야 한다” 는 계약 조항을 꼭 지키고 들어와야 한다.
//
// 아파트에 비어있는 집은 없고 모든 거주민들이 이 계약 조건을 지키고 왔다고 가정했을 때, 
// 주어지는 양의 정수 k와 n에 대해 k층에 n호에는 몇 명이 살고 있는지 출력하라.
// 단, 아파트에는 0층부터 있고 각층에는 1호부터 있으며, 0층의 i호에는 i명이 산다.
//
// 입력
// 첫 번째 줄에 Test case의 수 T가 주어진다.
// 그리고 각각의 케이스마다 입력으로 첫 번째 줄에 정수 k, 두 번째 줄에 정수 n이 주어진다
//
// 출력
// 각각의 Test case에 대해서 해당 집에 거주민 수를 출력하라.

int home[15][14] = { 0, };

int main() {
    for (int i = 0; i < 14; i++) {
        home[0][i] = i + 1; // 0층의 각 호수마다 살고있는 인원 수 저장
        home[i][0] = 1; // 모든 층의 1호에는 항상 1명이 있음
    }
    home[14][0] = 1; // 모든 층의 1호에는 항상 1명이 있음

    for (int i = 1; i < 15; i++) {
        for (int j = 1; j < 14; j++) {
            home[i][j] = home[i - 1][j] + home[i][j - 1];
            // 각 호수의 사람들은 같은층의 호수-1 에 살고있는 사람의 수와 바로 밑층 같은호수 사람의 수를 더한것과 같음
        }
    }

    int T;
    scanf("%d", &T);

    int a, b;

    while (T--) {
        scanf("%d %d", &a, &b);
        printf("%d\n", home[a][b - 1]); // 반복해서 출력하기만 하면 된다
    }
}