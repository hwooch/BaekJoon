#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

// 1564 _ 팩토리얼5

// 문제
// 팩토리얼5란, N!의 0이 아닌 뒤 5자리를 말한다.
// 
// N이 주어졌을 때, 팩토리얼5를 구하는 프로그램을 작성하시오.
// 
// 입력
// 첫째 줄에 정수 N이 주어진다.N은 1, 000, 000보다 작거나 같다.또, 9보다 크거나 같다.
// 
// 출력
// 첫째 줄에 N의 팩토리얼5를 계산한다.

int main() {

	int N;
	scanf("%d", &N);

	long long int answer = 36288;

	int zero = 0;

	if (N == 9) {
		printf("36288");
	}
	else {
		for (int i = 10; i <= N; i++) {
			answer = answer * i;
			while (answer % 10 == 0) {
				answer = answer / 10;
			}

			if (answer >= 1000000000000) {
				answer = answer % 1000000000000;
			}
		}
		if ((answer % 100000) / 10000 == 0) {
			printf("%d%d", zero, answer % 100000);
		}
		else {
			printf("%d", answer % 100000);
		}
	}
}