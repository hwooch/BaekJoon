#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// 8958 _ OX퀴즈

// 문제
// "OOXXOXXOOO"와 같은 OX퀴즈의 결과가 있다.
// O는 문제를 맞은 것이고, X는 문제를 틀린 것이다.
// 문제를 맞은 경우 그 문제의 점수는 그 문제까지 연속된 O의 개수가 된다.
// 예를 들어, 10번 문제의 점수는 3이 된다.
//
//"OOXXOXXOOO"의 점수는 1 + 2 + 0 + 0 + 1 + 0 + 0 + 1 + 2 + 3 = 10점이다.
//
// OX퀴즈의 결과가 주어졌을 때, 점수를 구하는 프로그램을 작성하시오.
//
// 입력
// 첫째 줄에 테스트 케이스의 개수가 주어진다.
// 각 테스트 케이스는 한 줄로 이루어져 있고, 길이가 0보다 크고 80보다 작은 문자열이 주어진다.
// 문자열은 O와 X만으로 이루어져 있다.
//
// 출력
// 각 테스트 케이스마다 점수를 출력한다.


int main() {
	int T;
	scanf("%d", &T);
	char user[82];
	int check = 0;
	int count = 0;
	int len = 0;

	while (T--) {
		scanf("%s", user);

		count = 0;
		check = 0;
		len = strlen(user);

		if (user[0] == 'O') { // 만약 첫 글자가 O라면
			count++;
			if (check == 0) {
				check = 1;
			}
		}

		for (int i = 1; i < len; i++) { // 두번째 글자부터 반복한다
			if (user[i] == 'O') { // 두번째 글자가 O라면
				count++;
				if (check == 0) {
					check = 1;
				}
			}
			else if (user[i] == 'X') {
				check = 0;
			}

			if (user[i] == 'O' && user[i - 1] == 'O' && check > 0) { // 연속으로 O가 나왔을때

				count = count + check;
				check++;
			}
		}
		printf("%d\n", count);
	}
}