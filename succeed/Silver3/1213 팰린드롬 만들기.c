#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

// 1213 _ 팰린드롬 만들기

// 문제
// 임한수와 임문빈은 서로 사랑하는 사이이다.
// 
// 임한수는 세상에서 팰린드롬인 문자열을 너무 좋아하기 때문에, 둘의 백일을 기념해서 임문빈은 팰린드롬을 선물해주려고 한다.
// 
// 임문빈은 임한수의 영어 이름으로 팰린드롬을 만들려고 하는데, 임한수의 영어 이름의 알파벳 순서를 적절히 바꿔서 팰린드롬을 만들려고 한다.
// 
// 임문빈을 도와 임한수의 영어 이름을 팰린드롬으로 바꾸는 프로그램을 작성하시오.
// 
// 입력
// 첫째 줄에 임한수의 영어 이름이 있다.알파벳 대문자로만 된 최대 50글자이다.
// 
// 출력
// 첫째 줄에 문제의 정답을 출력한다.
// 만약 불가능할 때는 "I'm Sorry Hansoo"를 출력한다.정답이 여러 개일 경우에는 사전순으로 앞서는 것을 출력한다.

int main() {
	char name[51];
	int alpha[26] = { 0, };
	char answer_name[51];
	scanf("%s", name);

	int len = strlen(name);

	for (int i = 0; i < len; i++) {
		alpha[name[i] - 'A']++;
	}

	int count = 0;
	int wrong_count = 0;
	if (len % 2 == 1) { // 길이가 홀수라면
		for (int i = 0; i < 26; i++) {
			if (alpha[i] % 2 == 1) { // 알파벳 개수가 홀수인것은 중간에다가 삽입
				wrong_count++;
				answer_name[len / 2] = i + 'A';
				alpha[i]--; // 홀수개에서 한개를 저장했으니 1을 뺌
			}
			if (alpha[i] % 2 == 0) { // 알파벳 개수가 짝수개라면
				for (int j = 0; j < alpha[i] / 2; j++) { // 양 끝에 저장
					answer_name[count] = i + 'A';
					answer_name[len - count - 1] = i + 'A';
					count++;
				}
			}
			if (wrong_count > 1) {
				printf("I'm Sorry Hansoo"); // 만약 알파벳 개수 중에 홀수가 2개 이상이면 대칭을 만들수가 없음
				return 0;
			}
		}
	}
	else { // 길이가 짝수에서
		for (int i = 0; i < 26; i++) {
			if (alpha[i] % 2 == 0) { // 알파벳 개수가 짝수개라면
				for (int j = 0; j < alpha[i] / 2; j++) { // 양 끝에 저장
					answer_name[count] = i + 'A';
					answer_name[len - count - 1] = i + 'A';
					count++;
				}
			}
			else if (alpha[i] % 2 == 1) {
				printf("I'm Sorry Hansoo"); // 만약 알파벳 개수 중에 홀수가 나온다면 대칭 불가
				return 0;
			}
		}
	}
	for (int i = 0; i < len; i++) {
		printf("%c", answer_name[i]);
	}
}