#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//문제
//양수 A가 N의 진짜 약수가 되려면, N이 A의 배수이고, A가 1과 N이 아니어야 한다.
// 어떤 수 N의 진짜 약수가 모두 주어질 때, N을 구하는 프로그램을 작성하시오.
//
//입력
//첫째 줄에 N의 진짜 약수의 개수가 주어진다.이 개수는 50보다 작거나 같은 자연수이다.
// 둘째 줄에는 N의 진짜 약수가 주어진다. 1, 000, 000보다 작거나 같고, 2보다 크거나 같은 자연수이고, 중복되지 않는다.
//
//출력
//첫째 줄에 N을 출력한다.N은 항상 32비트 부호있는 정수로 표현할 수 있다.

int main() {
	int number[50] = { 0 };
	int T;
	int min, max;
	int user;
	scanf("%d", &T);

	for (int i = 0; i < T; i++) {
		scanf("%d", &user);
		number[i] = user;
	}
	if (T == 1) {
		printf("%d", number[0] * number[0]); //약수가 1개뿐이므로 제곱한 결과 출력
	}
	else {
		min = number[0];
		max = number[0];
		for (int i = 1; i < T; i++) {
			if (min > number[i]) {
				min = number[i];// 제일 작은값
			}
			if (max < number[i]) {
				max = number[i];// 제일 큰값
			}
		}
		printf("%d", min * max);
	}

}