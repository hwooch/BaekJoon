#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

// 1259 _ 팰린드롬수

// 문제
// 어떤 단어를 뒤에서부터 읽어도 똑같다면 그 단어를 팰린드롬이라고 한다. 'radar', 'sees'는 팰린드롬이다.
// 
// 수도 팰린드롬으로 취급할 수 있다.
// 수의 숫자들을 뒤에서부터 읽어도 같다면 그 수는 팰린드롬수다. 
// 121, 12421 등은 팰린드롬수다. 123, 1231은 뒤에서부터 읽으면 다르므로 팰린드롬수가 아니다.
// 또한 10도 팰린드롬수가 아닌데, 앞에 무의미한 0이 올 수 있다면 010이 되어 팰린드롬수로 취급할 수도 있지만, 
// 특별히 이번 문제에서는 무의미한 0이 앞에 올 수 없다고 하자.
// 
// 입력
// 입력은 여러 개의 테스트 케이스로 이루어져 있으며, 각 줄마다 1 이상 99999 이하의 정수가 주어진다.
// 입력의 마지막 줄에는 0이 주어지며, 이 줄은 문제에 포함되지 않는다.
// 
// 출력
// 각 줄마다 주어진 수가 팰린드롬수면 'yes', 아니면 'no'를 출력한다.

int len_number(int N, int number[]) {
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
	for (int i = count - 1; i >= 0; i--) {
		number[i] = N % 10;
		N = N / 10;
	}
	return count;
}

int main() {

	int N;
	int number[5];
	while (1) {
		int check = 0;
		scanf("%d", &N);
		if (N == 0) {
			return 0;
		}
		else {
			int len = len_number(N, number);

			for (int i = 0; i < len / 2; i++) {
				if (number[i] != number[len - 1 - i]) {
					check++;
				}
			}
			if (check > 0) {
				printf("no\n");
			}
			else {
				printf("yes\n");
			}
		}
	}
}