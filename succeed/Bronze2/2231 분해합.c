#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

// 2231 _ 분해합

// 문제
// 어떤 자연수 N이 있을 때, 그 자연수 N의 분해합은 N과 N을 이루는 각 자리수의 합을 의미한다.
// 어떤 자연수 M의 분해합이 N인 경우, M을 N의 생성자라 한다.
// 예를 들어, 245의 분해합은 256(= 245 + 2 + 4 + 5)이 된다.
// 따라서 245는 256의 생성자가 된다.물론, 어떤 자연수의 경우에는 생성자가 없을 수도 있다.
// 반대로, 생성자가 여러 개인 자연수도 있을 수 있다.
//
// 자연수 N이 주어졌을 때, N의 가장 작은 생성자를 구해내는 프로그램을 작성하시오.
//
// 입력
// 첫째 줄에 자연수 N(1 ≤ N ≤ 1, 000, 000)이 주어진다.
//
// 출력
// 첫째 줄에 답을 출력한다.생성자가 없는 경우에는 0을 출력한다.

int len_number(int N) {
	int Ncopy = N;
	int count = 0;
	while (1) {
		if (Ncopy > 0) {
			Ncopy = Ncopy / 10;
			count++;
		}
		if (Ncopy == 0) {
			break;
		}
	}
	return count;
}

int main() {

	int N;
	scanf("%d", &N);

	int answer = 0;

	int temp = 0;
	int test = 0;

	while (1) {
		test = temp; // 0부터 1씩 증가시키며 비교해나감
		test++;
		temp = test;

		int len = len_number(test); // 자리수를 구하고

		answer = temp; // 원래의 수 를 더한 후
		for (int i = 0; i < len; i++) { // 각 자리의 숫자를 더해나감
			answer = answer + test % 10;
			test = test / 10;
		}
		if (answer == N) { // 만약 생성자가 처음 나타났다면 생성자 출력하고 프로그램 종료
			printf("%d", temp);
			return 0;
		}
		if (temp == N) { // 생성자가 나타나지 않았다면 0출력 후 프로그램 종료
			printf("0");
			return 0;
		}
	}
}