#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 2440 _ 별 찍기-3

// 문제
// 첫째 줄에는 별 N개, 둘째 줄에는 별 N - 1개, ..., N번째 줄에는 별 1개를 찍는 문제
// 
// 입력
// 첫째 줄에 N(1 ≤ N ≤ 100)이 주어진다.
// 
// 출력
// 첫째 줄부터 N번째 줄까지 차례대로 별을 출력한다.

int main() {
	int user;
	scanf("%d", &user);

	for (int i = 1; i <= user; i++) {
		for (int j = i; j <= user; j++) {
			printf("*");

		}
		printf("\n");
	}

}