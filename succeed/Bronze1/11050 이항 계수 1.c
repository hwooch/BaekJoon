#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 11050 _ 이항 계수 1

// 문제
// 자연수 n과 정수 k가 주어졌을 때 이항 계수 nCk 를 구하는 프로그램을 작성하시오.
// 
// 입력
// 첫째 줄에 n과 k가 주어진다. (1<=n<=10,0<=k<=n)
// 
// 출력
//  
// nCk 의 값을 출력한다.

int main() {

	int N;
	scanf("%d", &N);

	int K;
	scanf("%d", &K);

	int answer = 1;

	for (int i = N; i > K; i--) {
		answer = answer * i;
	}
	for (int i = N - K; i > 1; i--) {
		answer = answer / i;
	}
	printf("%d", answer);
}