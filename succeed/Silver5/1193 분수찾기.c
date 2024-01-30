#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// 1193 _ 분수찾기

// 문제
// 무한히 큰 배열에 다음과 같이 분수들이 적혀있다.
//
//	1 / 1	1 / 2	1 / 3	1 / 4	1 / 5	…
//	2 / 1	2 / 2	2 / 3	2 / 4	…	…
//	3 / 1	3 / 2	3 / 3	…	…	…
//	4 / 1	4 / 2	…	…	…	…
//	5 / 1	…	…	…	…	…
//  …	…	…	…	…	…
// 
// 이와 같이 나열된 분수들을 1 / 1 → 1 / 2 → 2 / 1 → 3 / 1 → 2 / 2 → … 과 같은 지그재그 순서로 차례대로 1번, 2번, 3번, 4번, 5번, … 분수라고 하자.
//
// X가 주어졌을 때, X번째 분수를 구하는 프로그램을 작성하시오.
//
// 입력
// 첫째 줄에 X(1 ≤ X ≤ 10, 000, 000)가 주어진다.
//
// 출력
// 첫째 줄에 분수를 출력한다.

int main() {
	int user;
	scanf("%d", &user);


	int count = 1;
	int count_add = 2;
	int count_number = 2;

	if (user == 1) {
		printf("1/1");
		exit(0);
	}
	while (1) { // 입력 받은 수보다 작은 값을 추출하기 위한 무한루프
		if (user > count) { // ex) 입력받은 값이 10이라면 1+2+3+4까지 더한 후
			count += count_add;
			count_add++;
		}
		if (user <= count) { // 1+2+3+4에서 4를 빼는 동작
			count -= count_add - 1;
			break;
		}
		count_number++;
	}
	int sum = count_number + 1; //sum 값은 분자와 분모의 더한값을 나타냄

	if (sum % 2 == 0) { // sum이 짝수라면 큰 값이 왼쪽
		printf("%d/%d", sum - (user - count), user - count);
	}
	else { // 홀수라면 큰 값이 오른쪽부터 시작
		printf("%d/%d", user - count, sum - (user - count));
	}
}