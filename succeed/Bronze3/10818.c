#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// 문제
// N개의 정수가 주어진다.이때, 최솟값과 최댓값을 구하는 프로그램을 작성하시오.
//
// 입력
// 첫째 줄에 정수의 개수 N(1 ≤ N ≤ 1, 000, 000)이 주어진다.
// 둘째 줄에는 N개의 정수를 공백으로 구분해서 주어진다.
// 모든 정수는 - 1, 000, 000보다 크거나 같고, 1, 000, 000보다 작거나 같은 정수이다.
//
// 출력
// 첫째 줄에 주어진 정수 N개의 최솟값과 최댓값을 공백으로 구분해 출력한다.

int user[1000000];
int main() {
	int T;
	scanf("%d", &T);

	scanf("%d", &user[0]);
	int min = user[0];
	int max = user[0];

	for (int i = 1; i < T; i++) {
		scanf("%d", &user[i]);
		if (min >= user[i]) {
			min = user[i];
		}
		if (max <= user[i]) {
			max = user[i];
		}
	}
	printf("%d %d", min, max);
}