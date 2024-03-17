#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <math.h>

// 17214번 _ 다항 함수의 적분

// 문제
// 다항식(polynomial)은 문자의 거듭제곱의 상수 배들의 합을 표현하는 수식이다.
// 예를 들어 x^2 + 2x + 3 같은 식을 의미한다.
// 그중 변수가 하나인 것을 일변수 다항식이라고 하고 이는 다음과 같이 표현한다.
// 
// f(x) = ax^n + bx^(n - 1) + ... + cx + d
// 
// 최대 일차 일변수 다항식이 주어졌을 때 그 함수를 적분한 결과를 출력하는 프로그램을 작성하시오.
// 
// 입력
// 첫째 줄에 최대 일차 일변수 다항식이 주어진다.
// 항의 개수는 최대 2개이고, 변수는 항상 x로 주어지며, 각 항은 공백 문자로 구분되지 않는다.
// 주어지는 계수는 절댓값이 10, 000을 넘지 않는 0이 아닌 2의 배수이고 주어지는 상수는 절댓값이 10, 000을 넘지 않는 정수이다.
// 차수가 같은 항은 한 번만 주어진다.
// 단, 계수의 절댓값이 1인 경우에는 1을 생략한다.
// 다항식은 차수가 큰 것부터 작아지는 순서대로 주어진다.
// 
// 출력
// 주어진 일변수 다항식을 적분한 결과를 입력 형식과 동일하게 출력한다.
// 적분상수는 "W"로 x^2은 "xx"로 표현한다.

char fx[20];

int main() {
	scanf("%s", fx);
	int len = strlen(fx);
	int memoryi = -1;
	int sum = 0;
	int count = 0;
	for (int i = 0; i < len; i++) { // x가 나올때까지 반복
		if (fx[i] == 'x') {
			memoryi = i;
			break;
		}
	}
	if (memoryi == -1) { // x가 나오지 않은 상수항이라면
		if (fx[0] == '0') { // 상수항이 0이라면
			printf("W");
		}
		else {
			if (fx[0] == '-') { // 상수항이 음수라면
				for (int i = 1; i < len; i++) {
					sum = sum + pow(10, count++) * (fx[i] - '0');
				}
				if (sum == 1) {
					printf("-x+W");
				}
				else {
					printf("%sx+W", fx);
				}
			}
			else { // 상수항이 양수라면
				for (int i = 0; i < len; i++) {
					sum = sum + pow(10, count++) * (fx[i] - '0');
				}
				if (sum == 1) {
					printf("x+W");
				}
				else {
					printf("%sx+W", fx);
				}
			}
		}
		return 0;
	}

	sum = 0;
	count = 0;
	//printf("memoryi = %d\n", memoryi); // x가 있는 위치
	if (fx[0] == '-') {
		printf("-");
		for (int i = memoryi - 1; i >= 1; i--) { // x가 있는 위치에서 - 바로 뒤의 위치까지 숫자들을 더함
			sum = sum + pow(10, count++) * (fx[i] - '0');
		}
	}
	else {
		for (int i = memoryi - 1; i >= 0; i--) { // x가 있는 위치에서 숫자들을 더함
			sum = sum + pow(10, count++) * (fx[i] - '0');
		}

	}
	sum = sum / 2;
	if (sum == 1) {
		printf("xx");
	}
	else {
		printf("%dxx", sum);
	}
	// 일차항, 상수항까지 완료

	sum = 0;
	count = 0;

	for (int i = len - 1; i >= memoryi + 2; i--) { // 일차항 뒤에 상수항 구하기
		sum = sum + pow(10, count++) * (fx[i] - '0');
	}
	if (sum == 0) { // 일차항 뒤에 상수항이 0이라면
		printf("+W");
	}
	else {
		if (fx[memoryi + 1] == '-') { // 상수항 부분이 음수라면
			if (sum == 1) {
				printf("-x");
			}
			else {
				printf("-%dx", sum);
			}
		}
		else {  // 상수항 부분이 양수라면
			if (sum == 1) {
				printf("+x");
			}
			else {
				printf("+%dx", sum);
			}
		}
		printf("+W"); // 마지막에 적분상수 출력
	}
}