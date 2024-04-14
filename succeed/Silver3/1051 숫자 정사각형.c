#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

// 1051 _ 숫자 정사각형

// 문제
// N×M크기의 직사각형이 있다.
// 각 칸에는 한 자리 숫자가 적혀 있다.
// 이 직사각형에서 꼭짓점에 쓰여 있는 수가 모두 같은 가장 큰 정사각형을 찾는 프로그램을 작성하시오.
// 이때, 정사각형은 행 또는 열에 평행해야 한다.
// 
// 입력
// 첫째 줄에 N과 M이 주어진다.
// N과 M은 50보다 작거나 같은 자연수이다.
// 둘째 줄부터 N개의 줄에 수가 주어진다.
// 
// 출력
// 첫째 줄에 정답 정사각형의 크기를 출력한다.

int table[50][50] = { 0 };

int main() {
	int x, y;
	scanf("%d %d", &x, &y);

	char user[51];
	for (int i = 0; i < x; i++) {
		scanf("%s", user);
		for (int j = 0; j < strlen(user); j++) {
			table[i][j] = user[j] - '0';
		}
	}

	int min = (x < y ? x : y) + 1;
	//printf("%d\n\n", min);

	while (min--) {
		//printf("%d\n", min);
		for (int i = 0; i <= x - min; i++) {
			for (int j = 0; j <= y - min; j++) {
				if (table[i][j] == table[i + min - 1][j + min - 1] && table[i][j] == table[i + min - 1][j] && table[i][j] == table[i][j + min - 1]) {
					printf("%d", min * min);
					return 0;
				}
			}
		}
	}
	printf("1");
}