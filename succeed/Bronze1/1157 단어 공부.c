#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 1157 _ 단어 공부

// 문제
// 알파벳 대소문자로 된 단어가 주어지면, 이 단어에서 가장 많이 사용된 알파벳이 무엇인지 알아내는 프로그램을 작성하시오.
// 단, 대문자와 소문자를 구분하지 않는다.
//
// 입력
// 첫째 줄에 알파벳 대소문자로 이루어진 단어가 주어진다.주어지는 단어의 길이는 1, 000, 000을 넘지 않는다.
//
// 출력
// 첫째 줄에 이 단어에서 가장 많이 사용된 알파벳을 대문자로 출력한다.
// 단, 가장 많이 사용된 알파벳이 여러 개 존재하는 경우에는 ? 를 출력한다.

char user[1000001];

int main() {
	int alpha[26];
	scanf("%s", &user);

	for (int i = 0; i < 26; i++) {
		alpha[i] = 0; // 알파벳 빈도수 배열
	}

	int len = strlen(user);

	for (int i = 0; i < len; i++) {
		if ('a' <= user[i] && user[i] <= 'z') { // 소문자라면
			alpha[user[i] - 'a']++;
		}
		else if ('A' <= user[i] && user[i] <= 'Z') { // 그렇지 않고 대문자라면
			alpha[user[i] - 'A']++;
		}
	}


	int max = 0; // 배열의 최고값
	int check = 0;
	int memoryi = 0;

	for (int i = 0; i < 26; i++) { // 알파벳 배열을 반복하면서
		if (max < alpha[i]) { // 최고값이 더 큰게 나왔다면
			max = alpha[i];  // 삽입 후에
			check = 0;     // 최고값의 중복개수를 검사할 수 있는 변수
			memoryi = i; // 알파벳 저장
		}
		else if (max == alpha[i]) { // 더 크지 않고 최고값이 똑같다면
			check++; // 중복개수 추가
		}
	}

	if (check > 0) { // 중복이 있었다면 ? 출력
		printf("?");
	}
	else { // 중복이 없었다면 알파벳 출력
		printf("%c", memoryi + 65);
	}
}