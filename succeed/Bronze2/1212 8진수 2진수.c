#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

// 1212 _ 8진수 2진수

// 문제
// 8진수가 주어졌을 때, 2진수로 변환하는 프로그램을 작성하시오.
// 
// 입력
// 첫째 줄에 8진수가 주어진다.주어지는 수의 길이는 333, 334을 넘지 않는다.
// 
// 출력
// 첫째 줄에 주어진 수를 2진수로 변환하여 출력한다.
//  수가 0인 경우를 제외하고는 반드시 1로 시작해야 한다.

int main() {
	char user[333335];
	scanf("%s", &user);

	for (int i = 0; user[i] != '\0'; i++) {
		switch (user[i])
		{
		case '0': if (i == 0) { printf(""); break; }
				else { printf("000"); break; }
		case '1': if (i == 0) { printf("1"); break; }
				else { printf("001"); break; }
		case '2': if (i == 0) { printf("10"); break; }
				else { printf("010"); break; }
		case '3': if (i == 0) { printf("11"); break; }
				else { printf("011"); break; }
		case '4': printf("100"); break;
		case '5': printf("101"); break;
		case '6': printf("110"); break;
		case '7': printf("111"); break;
		}
	}
	if (strlen(user) == 1 && user[0] == '0') {
		printf("0");
	}

}