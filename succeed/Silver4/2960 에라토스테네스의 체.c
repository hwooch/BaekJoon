#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

// 2960 _ 에라토스테네스의 체

// 문제
// 에라토스테네스의 체는 N보다 작거나 같은 모든 소수를 찾는 유명한 알고리즘이다.
// 
// 이 알고리즘은 다음과 같다.
// 
// 2부터 N까지 모든 정수를 적는다.
// 아직 지우지 않은 수 중 가장 작은 수를 찾는다.이것을 P라고 하고, 이 수는 소수이다.
// P를 지우고, 아직 지우지 않은 P의 배수를 크기 순서대로 지운다.
// 아직 모든 수를 지우지 않았다면, 다시 2번 단계로 간다.
// N, K가 주어졌을 때, K번째 지우는 수를 구하는 프로그램을 작성하시오.
// 
// 입력
// 첫째 줄에 N과 K가 주어진다. (1 ≤ K < N, max(1, K) < N ≤ 1000)
// 
// 출력
// 첫째 줄에 K번째 지워진 수를 출력한다.

int a[1001] = { 1,1, };
int main() {
    int count = 0;
    int N, K;
    scanf("%d %d", &N, &K);


    for (int i = 2; i <= N; i++) {	// 최대값의 제곱근까지 반복
        if (a[i] == 0) {		//i가 소수이면
            count++;
            if (count == K) {
                printf("%d", i);
                return 0;
            }
            for (int j = 2; i * j <= N; j++) {	// 자신을 제외한 i의 배수 제거
                if (a[i * j] == 0) {
                    a[i * j] = 1;
                    count++;
                    // printf("%d %d %d %d\n", count, i, j, i * j);
                    if (count == K) {
                        printf("%d", i * j);
                        return 0;
                    }
                }
            }
        }
    }

}