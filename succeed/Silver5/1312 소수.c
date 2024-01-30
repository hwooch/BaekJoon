#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 1312 _ 소수

// 문제
// 피제수(분자) A와 제수(분모) B가 있다.두 수를 나누었을 때, 소숫점 아래 N번째 자리수를 구하려고 한다
// 예를 들어, A = 3, B = 4, N = 1이라면, A÷B = 0.75 이므로 출력 값은 7이 된다.
//
// 입력
// 첫 번째 줄에 A와 B(1 ≤ A, B ≤ 100, 000), N(1 ≤ N ≤ 1, 000, 000)이 공백을 경계로 주어진다.
//
// 출력
// A÷B를 했을 때, 소숫점 아래 N번째 수를 출력한다.

int main() {
	int a;
	int b;
	int N;

	scanf("%d", &a);
	scanf("%d", &b);
	scanf("%d", &N);

	int answer;

	while (N--) {

		answer = (a * 10) / b;
		a = (a * 10) % b;

	}
	if (answer >= 10) { //첫번째로 나눈 몫이 두자릿수 이상일때
		answer = answer % 10;
	}


	printf("%d", answer);
}