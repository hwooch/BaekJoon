#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 20053 _ 최소, 최대 2

// 문제
// N개의 정수가 주어진다.
// 이때, 최솟값과 최댓값을 구하는 프로그램을 작성하시오.
// 
// 입력
// 첫째 줄에 테스트 케이스의 개수 T(1 ≤ T ≤ 10)가 주어진다.
// 각 테스트 케이스는 두 줄로 이루어져 있다.
// 
// 각 테스트 케이스의 첫째 줄에 정수의 개수 N(1 ≤ N ≤ 1, 000, 000)이 주어진다.
// 둘째 줄에는 N개의 정수를 공백으로 구분해서 주어진다.
// 모든 정수는 - 1, 000, 000보다 크거나 같고, 1, 000, 000보다 작거나 같은 정수이다.
// 
// 출력
// 각 테스트 케이스마다 주어진 정수 N개의 최솟값과 최댓값을 공백으로 구분해 한 줄에 하나씩 차례대로 출력한다.



int main() {

	int N;
	scanf("%d", &N);

	int size = 0;
	int max = 0;
	int min = 0;
	int number = 0;

	while (N--) {
		scanf("%d", &size);
		scanf("%d", &number);
		max = number;
		min = number;

		for (int i = 1; i < size; i++) {
			scanf("%d", &number);
			if (min > number) {
				min = number;
			}
			if (max < number) {
				max = number;
			}
		}
		printf("%d %d\n", min, max);
	}
}