#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 11441 _ 합 구하기

// 문제
// N개의 수 A1, A2, ..., AN이 입력으로 주어진다.
// 총 M개의 구간 i, j가 주어졌을 때, i번째 수부터 j번째 수까지 합을 구하는 프로그램을 작성하시오.
// 
// 입력
// 첫째 줄에 수의 개수 N이 주어진다. (1 ≤ N ≤ 100, 000) 
// 둘째 줄에는 A1, A2, ..., AN이 주어진다. (-1, 000 ≤ Ai ≤ 1, 000) 
// 셋째 줄에는 구간의 개수 M이 주어진다. (1 ≤ M ≤ 100, 000)
// 넷째 줄부터 M개의 줄에는 각 구간을 나타내는 i와 j가 주어진다. (1 ≤ i ≤ j ≤ N)
// 
// 출력
// 총 M개의 줄에 걸쳐 입력으로 주어진 구간의 합을 출력한다.

int number[100000] = { 0, };
int sum[100000] = { 0, };

int main() {

	int N;
	scanf("%d", &N);
	scanf("%d", &number[0]);
	sum[0] = number[0];

	for (int i = 1; i < N; i++) {
		scanf("%d", &number[i]);
		sum[i] = sum[i - 1] + number[i];
	}
	int M;
	scanf("%d", &M);
	int left, right;


	for (int i = 0; i < M; i++) {
		scanf("%d %d", &left, &right);
		if (left == right) {
			printf("%d\n", sum[right - 1] - sum[left - 2]);
		}
		else if (left == 1) {
			printf("%d\n", sum[right - 1]);
		}
		else {
			printf("%d\n", sum[right - 1] - sum[left - 2]);
		}
	}
}