#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// 1343 _ 폴리오미노

// 문제
// 민식이는 다음과 같은 폴리오미노 2개를 무한개만큼 가지고 있다.AAAA와 BB
//
// 이제 '.'와 'X'로 이루어진 보드판이 주어졌을 때, 민식이는 겹침없이 'X'를 모두 폴리오미노로 덮으려고 한다.
// 이때, '.'는 폴리오미노로 덮으면 안 된다.
//
// 폴리오미노로 모두 덮은 보드판을 출력하는 프로그램을 작성하시오.
//
// 입력
// 첫째 줄에 보드판이 주어진다.보드판의 크기는 최대 50이다.
//
// 출력
// 첫째 줄에 사전순으로 가장 앞서는 답을 출력한다.만약 덮을 수 없으면 - 1을 출력한다.

int main() {
	char board[51];
	scanf("%s", board);
	char temp = board[0]; // 비교변수

	int first = 1; // X의 위치를 찾게 도와주는 변수
	if (board[0] == 'X') { // 만약 X가 먼저 나왔다면
		first = 0;
	}

	int count = 1;

	int check[51];
	int check_int = 0;

	// X가 나온 개수 저장, .이 나온 개수 저장
	for (int i = 1; board[i] != '\0'; i++) {
		if (temp == board[i]) { // 비교해서 그 전의 문자와 같다면 카운트+1
			count++;
		}
		else { // 다른 문자가 왔다면 그 전까지 연속으로 나왔던 문자열 수를 저장
			check[check_int] = count;
			check_int++;
			count = 1;
			temp = board[i];
		}
	}
	// 만약 입력이 XX...XXXX 라면 check배열에 2 3 4가 저장되어 있을 것
	check[check_int] = count;
	check_int++;

	for (int i = 0; i < check_int; i++) {
		if (first % 2 == 0) { // 만약 X로 시작한다면
			if ((check[i] % 2 == 1) && (i % 2 == 0)) { // X로 시작하고 X의 개수가 홀수라면
				printf("-1");
				exit(0);
			}
		}
		else { // .으로 시작한다면
			if ((check[i] % 2 == 1) && (i % 2 == 1)) { // .로 시작하고 X의 개수가 홀수라면
				printf("-1");
				exit(0);
			}
		}
	}
	// 이 과정까지 마쳤다면 모두 채울수 있다는 결론이 나옴.

	for (int i = 0; i < check_int; i++) {
		if (first % 2 == 0) { // 만약 X로 시작한다면
			if (check[i] % 4 == 2) { // X의 개수가 2, 6, 10 ... 이라면
				for (int j = 0; j < (check[i] / 4); j++) {
					printf("AAAA"); // 개수를 4로 나눈 몫 만큼 출력 반복
				}
				printf("BB"); // 그 다음 나머지인 2를 출력
			}
			else { // X의 개수가 4의 배수로 떨어진다면
				for (int j = 0; j < check[i]; j++) { // X의 개수를 원래대로 출력
					printf("A");
				}
			}
		}
		else { // .으로 시작한다면
			for (int j = 0; j < check[i]; j++) {
				printf(".");
			}
		}
		first++; // 이 문장을 통해 X 와 . 의 출력을 번갈아 가게 할 수 있음
	}
}