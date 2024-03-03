#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 1500 _ 최대 곱

// 문제
// 세준이는 정수 S와 K가 주어졌을 때, 합이 S인 K개의 양의 정수를 찾으려고 한다.
// 만약 여러개일 경우 그 곱을 가능한 최대로 하려고 한다.
// 
// 가능한 최대의 곱을 출력한다.
// 
// 만약 S = 10, K = 3이면, 3, 3, 4는 곱이 36으로 최대이다.
// 
// 입력
// 첫째 줄에 두 수 S와 K가 주어진다.K는 20보다 작거나 같고, S는 100보다 작거나 같으며 K보다 크거나 같다.
// 
// 출력
// 첫째 줄에 정답을 출력한다.답은 9223372036854775807보다 작다.

int main() {
	int N;
	int T;
	scanf("%d %d", &N, &T);

	long long int number[100] = { 0, };

	long long int sum = 1;

	for (int i = 0; i < T; i++) {
		number[i] = N / T;
	}

	int middle = N % T;

	for (int i = 0; i < middle; i++) {
		number[i]++;
		sum = sum * number[i];
	}

	for (int i = middle; i < T; i++) {
		sum = sum * number[i];
	}
	printf("%lld", sum);

}