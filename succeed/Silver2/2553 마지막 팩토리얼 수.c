#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 2553 _ 마지막 팩토리얼 수

// 문제
// N!의 값을 계산한 후에, 0이 아닌 가장 낮은 자리 수를 구하시오.
// 
// 예를 들어, 4!= 24 이기 때문에, 0이 아닌 가장 낮은 자리 수는 4이다.
// 또, 5!= 120이기 때문에, 0이 아닌 가장 낮은 자리 수는 2 이다.
// 
// 입력
// 첫째 줄에 N이 주어진다.
// N은 20, 000보다 작거나 같은 자연수 이다.
// 
// 출력
// 첫째 줄에 N!의 0이 아닌 마지막 자리수를 출력한다.

int main() {
	int N;
	scanf("%d", &N);

	long long int sum = 1;
	int temp;

	for (int i = 1; i <= N; i++) {
		temp = i;
		while (temp % 10 == 0) {
			temp = temp / 10;
		}

		sum = sum * temp;
		while (sum % 10 == 0) {
			sum = sum / 10;
		}
		sum = sum % 10000000;
	}
	sum = sum % 10;
	printf("%lld", sum);
}