#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

// 27930 _ 당신은 운명을 믿나요?

// 문제
// 수능 시험을 앞둔 민지는 수능 전날 점집에서 점괘를 받았다.
// 이 점괘를 통해 민지는 어떤 학교에 합격할지를 해석할 수 있다.
// 점괘 S는 알파벳 대문자로 이루어진 문자열이다.
// 
// 점괘를 해석하는 방법은 다음과 같다.점괘의 첫 글자부터 차례대로 점괘를 읽는다.
// i번 글자까지 읽었을 때, 현재까지 읽은 점괘에서 순서를 유지한 채로 0개 이상의 글자를 제거하고 YONSEI나 KOREA를 얻을 수 있다면, 민지는 각각 YONSEI와 KOREA에 합격하는 것이다.
// 
// 민지는 YONSEI 또는 KOREA를 반드시 찾을 수 있음이 보장된다.
// 또한 YONSEI와 KOREA를 모두 찾을 수 있는 경우, 먼저 찾은 학교에 합격하게 된다.
// 
// 민지가 어떤 학교에 합격하게 될지를 알아보자.두 학교를 동시에 합격할 수 없음이 보장된다.
// 
// 입력
// 점괘 S가 주어진다.
// 
// 출력
// 민지가 합격할 학교를 출력한다.
// 
// 제한
// 5 <= | S | <= 500,000

char user[500010];
char check1[6] = { 'K','O','R','E','A' };
char check2[7] = { 'Y','O','N','S','E','I' };

int main() {
	scanf("%s", user);
	int count1 = 0;
	int count2 = 0;
	int len = strlen(user);
	for (int i = 0; i < len; i++) {
		if (user[i] == check1[count1]) {
			count1++;
			if (count1 == 5) {
				printf("KOREA");
				return 0;
			}
		}
		if (user[i] == check2[count2]) {
			count2++;
			if (count2 == 6) {
				printf("YONSEI");
				return 0;
			}
		}
	}
}