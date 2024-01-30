#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// 1236 _ 성 지키기

// 문제
// 영식이는 직사각형 모양의 성을 가지고 있다.
// 성의 1층은 몇 명의 경비원에 의해서 보호되고 있다.
// 영식이는 모든 행과 모든 열에 한 명 이상의 경비원이 있으면 좋겠다고 생각했다.
//
// 성의 크기와 경비원이 어디있는지 주어졌을 때, 몇 명의 경비원을 최소로 추가해야 영식이를 만족시키는지 구하는 프로그램을 작성하시오.
//
// 입력
// 첫째 줄에 성의 세로 크기 N과 가로 크기 M이 주어진다.N과 M은 50보다 작거나 같은 자연수이다.
// 둘째 줄부터 N개의 줄에는 성의 상태가 주어진다.성의 상태는.은 빈칸, X는 경비원이 있는 칸이다.
//
// 출력
// 첫째 줄에 추가해야 하는 경비원의 최솟값을 출력한다.

void check(char castle[][50], int height, int width) {
	// 가로 조건 만족하는지
	int empty = 0;
	int count = 0;
	for (int i = 0; i < height; i++) {
		count = 0;
		for (int j = 0; j < width; j++) {
			if (castle[i][j] == 'X') { // x가 있다면
				count++;
			}
		}
		if (count == 0) { // x가 없다는 뜻이므로
			empty++; // 병력 추가
		}
	}


	// 세로 조건 만족하는지
	int empty2 = 0;
	count = 0;
	for (int i = 0; i < width; i++) {
		count = 0;
		for (int j = 0; j < height; j++) {
			if (castle[j][i] == 'X') { // x가 있다면
				count++;
			}
		}
		if (count == 0) { // x가 없다는 뜻이므로
			empty2++; // 병력 추가
		}
	}
	printf("%d", empty > empty2 ? empty : empty2);
}

char castle[50][50];

int main() {
	int N, M;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		scanf("%s", castle[i]);
	}
	check(castle, N, M);
}