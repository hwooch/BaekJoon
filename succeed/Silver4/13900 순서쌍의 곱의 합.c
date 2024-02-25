#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 13900 _ 순서쌍의 곱의 합

// 문제
// N개의 정수 중 서로 다른 위치의 두 수를 뽑는 모든 경우의 두 수의 곱의 합을 구하라.
// 
// 예를 들어 N = 3이고 주어진 정수가 2, 3, 4일 때, 두 수를 뽑는 모든 경우는 
// (2, 3), (2, 4), (3, 4)이며 이때 각각의 곱은 6, 8, 12이다.따라서 총합은 26이다.
// 
// 입력
// 첫 번째 줄에는 입력 받을 정수의 개수 N(2 ≤ N ≤ 100, 000)
// 
// 두 번째 줄에는 N 개의 정수가 주어진다.이때 입력 받는 정수들의 범위는 0이상 10, 000 이하이다.
// 
// 출력
// 모든 경우의 곱의 합을 출력한다.

int arr[100000] = { 0, };
long long int sum_arr[100000] = { 0, };

int main() {
	int N;
	scanf("%d", &N);

	long long int sum = 0;

	scanf("%d", &arr[0]);
	sum_arr[0] = arr[0];

	for (int i = 1; i < N; i++) {
		scanf("%d", &arr[i]);
		sum_arr[i] = sum_arr[i - 1] + arr[i];
	}

	for (int i = 0; i < N; i++) {
		sum = sum + arr[i] * (sum_arr[N - 1] - sum_arr[i]);
	}
	printf("%lld", sum);
}