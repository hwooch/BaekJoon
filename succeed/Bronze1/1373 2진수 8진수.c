#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

// 1373 _ 2진수 8진수

// 문제
// 2진수가 주어졌을 때, 8진수로 변환하는 프로그램을 작성하시오.
// 
// 입력
// 첫째 줄에 2진수가 주어진다.주어지는 수의 길이는 1, 000, 000을 넘지 않는다.
// 
// 출력
// 첫째 줄에 주어진 수를 8진수로 변환하여 출력한다.

char number[1000001];
int main() {
	scanf("%s", number);

	int len = strlen(number);
	int answer = 0;

	int count = 4;

	if (len % 3 == 0) {
		for (int i = 0; i < len; i++) {
			answer = answer + ((number[i] - 48) * count);
			count = count / 2;
			if (count == 0) {
				count = 4;
				printf("%d", answer);
				answer = 0;
			}
		}
	}
	else if (len % 3 == 1) {
		printf("%d", number[0] - 48);
		for (int i = 1; i < len; i++) {
			answer = answer + ((number[i] - 48) * count);
			count = count / 2;
			if (count == 0) {
				count = 4;
				printf("%d", answer);
				answer = 0;
			}
		}
	}
	else if (len % 3 == 2) {
		printf("%d", (number[0] - 48) * 2 + (number[1] - 48));
		for (int i = 2; i < len; i++) {
			answer = answer + ((number[i] - 48) * count);
			count = count / 2;
			if (count == 0) {
				count = 4;
				printf("%d", answer);
				answer = 0;
			}
		}
	}
}