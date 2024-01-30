#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 1085 _ 직사각형에서 탈출

// 문제
// 한수는 지금(x, y)에 있다.직사각형은 각 변이 좌표축에 평행하고, 왼쪽 아래 꼭짓점은(0, 0), 오른쪽 위 꼭짓점은(w, h)에 있다.
//  직사각형의 경계선까지 가는 거리의 최솟값을 구하는 프로그램을 작성하시오.
// 
// 입력
// 첫째 줄에 x, y, w, h가 주어진다.
// 
// 출력
// 첫째 줄에 문제의 정답을 출력한다.
// 
// 제한
// 1 ≤ w, h ≤ 1, 000
// 1 ≤ x ≤ w - 1
// 1 ≤ y ≤ h - 1
// x, y, w, h는 정수

int compare(int x, int y) { // 더 작은값을 반환해주는 함수
	if (x > y) {
		return y;
	}
	return x;
}

int main() {
	int userx, usery;
	int x, y;

	scanf("%d", &userx);
	scanf("%d", &usery);
	scanf("%d", &x);
	scanf("%d", &y);


	int answerx, answery;

	answerx = compare(userx, x - userx);
	answery = compare(usery, y - usery);
	printf("%d", compare(answerx, answery));
}