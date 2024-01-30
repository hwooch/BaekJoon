#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

// 1929 _ 소수 구하기
// 
// 문제
// M이상 N이하의 소수를 모두 출력하는 프로그램을 작성하시오.
//
// 입력
// 첫째 줄에 자연수 M과 N이 빈 칸을 사이에 두고 주어진다.
// (1 ≤ M ≤ N ≤ 1, 000, 000) M이상 N이하의 소수가 하나 이상 있는 입력만 주어진다.
//
// 출력
// 한 줄에 하나씩, 증가하는 순서대로 소수를 출력한다.

int main() {

	int N, M;
	scanf("%d", &N);
	scanf("%d", &M);

	for (int i = N; i <= M; i++) {
		if (i == 1) {
			continue;
		}
		int count = 0;
		for (int j = 1; j <= (int)sqrt(i); j++) {
			if (i % j == 0) {
				count++;
				if (count > 1) {
					break;
				}
			}
		}
		if (count == 1) {
			printf("%d ", i);
		}
	}
	return 0;
}