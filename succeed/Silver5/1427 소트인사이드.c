#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

// 1427 _ 소트인사이드

// 문제
// 배열을 정렬하는 것은 쉽다.수가 주어지면, 그 수의 각 자리수를 내림차순으로 정렬해보자.
//
// 입력
// 첫째 줄에 정렬하려고 하는 수 N이 주어진다.N은 1, 000, 000, 000보다 작거나 같은 자연수이다.
//
// 출력
// 첫째 줄에 자리수를 내림차순으로 정렬한 수를 출력한다.

void sort(int box[], int size) {
	int temp = 0;
	for (int i = 0; i < SIZE - 1; i++) {
		for (int j = 0; j < SIZE - 1; j++) {
			if (box[j] < box[j + 1]) {
				temp = box[j];
				box[j] = box[j + 1];
				box[j + 1] = temp;
			}
		}
	}
}

int main() {
	int user;
	scanf("%d", &user);
	int count = 0; // 자릿수

	int box[SIZE];
	for (int i = 0; i < SIZE; i++) {
		box[i] = user % 10;
		user = user / 10; // box 배열에 user 숫자를 역순으로 저장
		if (user != 0) {
			count++;
		}
	}

	sort(box, SIZE);

	for (int i = 0; i < count + 1; i++) {
		printf("%d", box[i]);
	}
}