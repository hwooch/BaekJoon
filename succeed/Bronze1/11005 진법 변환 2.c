#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// 11005 _ 진법 변환 2

// 문제
// 10진법 수 N이 주어진다.이 수를 B진법으로 바꿔 출력하는 프로그램을 작성하시오.
// 
// 10진법을 넘어가는 진법은 숫자로 표시할 수 없는 자리가 있다. 이런 경우에는 다음과 같이 알파벳 대문자를 사용한다.
// 
// A: 10, B : 11, ..., F : 15, ..., Y : 34, Z : 35
// 
// 입력
// 첫째 줄에 N과 B가 주어진다. (2 ≤ B ≤ 36) N은 10억보다 작거나 같은 자연수이다.
// 
// 출력
// 첫째 줄에 10진법 수 N을 B진법으로 출력한다.

int number[31];

int main() {
	int N;
	scanf("%d", &N);

	int B;
	scanf("%d", &B);

	int count = 0;
	while (B <= N) {
		number[count] = N % B;
		N = N / B;
		count++;
	}
	number[count] = N;
	for (int i = count; i >= 0; i--) {
		if (number[i] >= 10) {
			printf("%c", number[i] + 55);
		}
		else {
			printf("%d", number[i]);
		}
	}
}