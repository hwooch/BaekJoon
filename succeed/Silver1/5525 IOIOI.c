#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

// 5525 _ IOIOI

// 문제
// N + 1개의 I와 N개의 O로 이루어져 있으면, I와 O이 교대로 나오는 문자열을 PN이라고 한다.
// 
// P1 IOI
// P2 IOIOI
// P3 IOIOIOI
// PN IOIOI...OI(O가 N개)
// I와 O로만 이루어진 문자열 S와 정수 N이 주어졌을 때, S안에 PN이 몇 군데 포함되어 있는지 구하는 프로그램을 작성하시오.
// 
// 입력
// 첫째 줄에 N이 주어진다.둘째 줄에는 S의 길이 M이 주어지며, 셋째 줄에 S가 주어진다.
// 
// 출력
// S에 PN이 몇 군데 포함되어 있는지 출력한다.
// 
// 제한
// 1 ≤ N ≤ 1, 000, 000
// 2N + 1 ≤ M ≤ 1, 000, 000
// S는 I와 O로만 이루어져 있다.

char user[1000001];

int main() {
    int N, M, count = 0, result = 0;
    scanf("%d", &N);
    scanf("%d", &M);
    scanf("%s", user);

    for (int i = 1; i < M - 1; i++) {
        if (user[i - 1] == 'I' && user[i] == 'O' && user[i + 1] == 'I') { // IOI패턴을 찾으면
            count++; // count증가
            if (count == N) { // 패턴이 N번연속 나왔다면
                count--; // 맨 앞의 패턴 하나를 줄이고 다음에 또 나오는지 확인한다.
                result++;
            }
            i++; // 2계단을 건너뛴다 (O를 중심으로 있기 때문에 'IOI'XX다음에는 IO'IXX'가 IOI인지 구별하는것)
            // 이 과정이 없다면 'IOI'XX 다음에 I'OIX'X를 검사한다
        }
        else {
            count = 0; // 연속으로 나오지 않았다면 처음부터 다시
        }
    }
    printf("%d", result);
    return 0;
}
