#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 2877 _ 4와 7

// 문제
// 창영이는 4와 7로 이루어진 수를 좋아한다.
// 창영이가 좋아하는 수 중에 K번째 작은 수를 구해 출력하는 프로그램을 작성하시오.
// 
// 입력
// 첫째 줄에 K(1 ≤ K ≤ 10^9)가 주어진다.
// 
// 출력
// 첫째 줄에 창영이가 좋아하는 숫자 중 K번째 작은 수를 출력한다.

int number[40] = { 0, };

int main() {
	int user;
	scanf("%d", &user);

	int count = 0;
	int two = 2;

	while ((user - two) > 0) {
		user = user - two;
		two = two * 2;
		count++;
	}
	user--;

	int check = 0;
	while (user > 1) {
		number[check] = user % 2;
		user = user / 2;
		check++;
	}
	number[check] = user;

	for (int i = count; i >= 0; i--) {
		if (number[i] == 0) {
			printf("4");
		}
		else {
			printf("7");
		}
	}
}