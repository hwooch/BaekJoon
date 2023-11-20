#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//문제
//다음과 같이 세 수가 연속해서 주어졌을 때 한 번의 곱셈 기호와 한 번의 나눗셈 
// 기호를 이용하여 만든 식 중 가장 큰 값을 출력하는 프로그램을 작성하시오. (세 수의 순서는 변하지 않는다.)
//
//32 ㅁ 16 ㅁ 8
//
//입력
//첫째 줄에 세 개 정수 A, B, C(1 ≤ A, B, C ≤ 1, 000, 000)가 주어진다.답은 int범위를 벗어나지 않는다.
//
//출력
//나올 수 있는 가장 큰 값을 출력한다.단, 소수점 아래는 버린다. 1e-9 이하의 오차로 인해 출력이 달라지는 입력은 주어지지 않는다.

int main() {

	double number[3];
	double user;
	double sum = 0;
	int change;

	for (int i = 0; i < 3; i++) {
		scanf("%lf", &user);
		number[i] = user;
	}


	sum = number[0] * number[1] / number[2];
	if ((number[0] / number[1] * number[2]) > sum) {
		sum = number[0] / number[1] * number[2];
	}

	change = sum;


	printf("%d", change);
	return 0;
}