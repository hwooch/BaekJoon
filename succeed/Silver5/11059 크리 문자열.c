#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

// 11059 _ 크리 문자열

// 문제
// 숫자로만 이루어진 문자열 S가 주어진다.
// S의 연속된 부분 문자열 중에서 길이가 짝수이고, 앞의 절반의 합과 뒤의 절반의 합이 같은 부분 문자열을 크리 문자열이라고 한다.
// 빈 문자열은 크리 문자열이 아니다.
// 
// S의 크리 문자열 중에서 가장 길이가 긴 것을 찾는 프로그램을 작성하시오.
// 
// 예를 들어 S = "67896789" 인 경우에 정답은 "67896789"이 된다.
// 또, S = "6789789" 인 경우에 정답은 "789789"가 된다.
// S = "6789678" 인 경우에 정답은 "9678" 이다.
// 
// 입력
// 첫째 줄에 문자열 S가 주어진다.
// S는 숫자로만 이루어져 있으며, 길이는 1, 000을 넘지 않는다.
// 항상 크리 문자열이 존재하는 입력만 주어진다.
// 
// 출력
// 첫째 줄에 S의 크리 문자열 중에서 가장 긴 것의 길이를 출력한다.
   
int main() {
    char user[1001];
    scanf("%s", user);

    int answer = 0;
    int len = strlen(user);


    for (int start = 0; start < len; start++) {

        for (int length = 2; start + length <= len; length += 2) {
            int left = 0, right = 0;


            for (int i = start; i < start + length / 2; i++) {
                left += user[i] - '0';
            }
            for (int i = start + length / 2; i < start + length; i++) {
                right += user[i] - '0';
            }


            if (left == right) {

                if (length > answer) {
                    answer = length;
                }
            }
        }
    }

    printf("%d", answer);

    return 0;
}