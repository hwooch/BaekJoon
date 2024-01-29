#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 9012 _ 괄호

// 문제 
// 괄호 문자열(Parenthesis String, PS)은 두 개의 괄호 기호인 ‘(’ 와 ‘)’ 만으로 구성되어 있는 문자열이다.
// 그 중에서 괄호의 모양이 바르게 구성된 문자열을 올바른 괄호 문자열(Valid PS, VPS)이라고 부른다.
// 한 쌍의 괄호 기호로 된 “()” 문자열은 기본 VPS 이라고 부른다.
// 만일 x 가 VPS 라면 이것을 하나의 괄호에 넣은 새로운 문자열 “(x)”도 VPS 가 된다.
// 그리고 두 VPS x 와 y를 접합(concatenation)시킨 새로운 문자열 xy도 VPS 가 된다.
// 예를 들어 “(())()”와 “((()))” 는 VPS 이지만 “(()(”, “(())()))”, 그리고 “(()” 는 모두 VPS 가 아닌 문자열이다.
//
// 여러분은 입력으로 주어진 괄호 문자열이 VPS 인지 아닌지를 판단해서 그 결과를 YES 와 NO 로 나타내어야 한다.
//
// 입력
// 입력 데이터는 표준 입력을 사용한다.입력은 T개의 테스트 데이터로 주어진다.
// 입력의 첫 번째 줄에는 입력 데이터의 수를 나타내는 정수 T가 주어진다.
// 각 테스트 데이터의 첫째 줄에는 괄호 문자열이 한 줄에 주어진다.
// 하나의 괄호 문자열의 길이는 2 이상 50 이하이다.
//
// 출력
// 출력은 표준 출력을 사용한다.만일 입력 괄호 문자열이 올바른 괄호 문자열(VPS)이면 “YES”, 아니면 “NO”를 한 줄에 하나씩 차례대로 출력해야 한다.

int vps(char box[], int len) {
	int left = 0; // '(' 의 개수
	int right = 0; // ')' 의 개수
	int check = 0; // 중간에 괄호검사를 하기위한 변수 
	// 양수라면 '('가 더 많은 상태. 음수라면 ')'가 더 많은 상태.

	for (int i = 0; i < len; i++) { // 글자 수만큼 반복하면서
		if (box[i] == '(') {
			left++;
			check++;
		}
		else if (box[i] == ')') {
			right++;
			check--;
		}
		if (check < 0) { // ')'가 더 많은 상태라면 괄호 실패
			return 0;
		}
		if (left > len / 2 || right > len / 2) { // 각각의 괄호의 개수가 문자열의 길이의 반을 넘어간다면 실패
			return 0;
		}
	}
	return 1; // 모든 조건을 성공했다면 성공
}

int main() {

	int T;
	scanf("%d", &T);;

	char box[51];
	int len;
	int result;

	while (T--) {
		scanf("%s", box);
		len = strlen(box); // 괄호의 길이

		if (len % 2 == 1) { // 만약 괄호의 길이가 홀수라면 괄호 실패
			printf("NO\n");
		}

		else {
			result = vps(box, len);

			if (result == 0) { // 함수가 0을 반환하면 실패
				printf("NO\n");
			}
			else if (result == 1) { // 1을 반환하면 성공
				printf("YES\n");
			}
		}
	}

}