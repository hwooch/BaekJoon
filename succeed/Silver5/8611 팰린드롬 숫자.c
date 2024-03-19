#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

// 8611 _ 팰린드롬 숫자

// 문제
// 팰린드롬은 앞에서 부터 읽었을 때와 뒤에서 부터 읽었을 때가 같은 문자열을 말한다.
// 예를 들어, "ala"과 "aa"는 팰린드롬이고, "adam"은 팰린드롬이 아니다.
// 
// 모든 정수는 (an an-1 ... a1 a0)k 와 같이 k진법으로 나타낼 수 있다.
// 모든 ai 는 k보다 작은 음이 아닌 정수이어야 한다.
// 
// 
// (an an - 1 ... a1 a0)k가 나타내는 값은 a_n * k^n + a_{ n - 1 }*k^ { n - 1 } + ... + a_1 * k + a_0 이다.
// 예를 들어, 10진법 숫자 123의 값은 1*100 + 2*10 + 3 이고, 8진법 숫자 123의 값은 (1*64 + 2*8 + 3) 이다.
// 
// 10진법 숫자 n 이 주어졌을 때, 2, 3, ..., 10진법으로 나타냈을 때, 팰린드롬인 것을 모두 구하는 프로그램을 작성하시오.
// 
// 입력
// 첫째 줄에 n 이 주어진다. (1<=N<=10^1000)
// 
// 출력
// 
// n을 2,3,...,10 진법으로 나타냈을 때, 팰린드롬인 경우가 없다면, "NIE"를 출력한다.
// 그 외의 경우에는 팰린드롬이 되는 진법 b와 n을 b진법으로 나타낸 수 m을 출력한다.
// 출력은 b가 증가하는 순서대로 한다.

char user[1002];
char user_copy[1002];
char result[10000];

int calculate(char* user, int jinbub, int len) {
    int copy_len = len;
    int count = 0;

    while (copy_len > 0) {
        int ten = 0;  // 올림수
        for (int i = 0; i < copy_len; i++) {
            int one = user[i] - '0';  // 현재 자리수
            int new_one = ten * 10 + one;  // 이전 올림수와 현재 자리수를 합친 값
            user[i] = (new_one / jinbub) + '0';  // 새로운 자리수
            ten = new_one % jinbub;  // 새로운 올림수
        }
        result[count++] = ten + '0';  // 결과 저장

        // 앞자리가 0인 경우 제거
        while (copy_len > 0 && user[0] == '0') {
            for (int i = 1; i < copy_len; i++) {
                user[i - 1] = user[i];
            }
            user[copy_len - 1] = '\0';
            copy_len--;
        }
    }

    int end = 0;

    int check = 0;
    int WRONG = 0;

    for (int i = end; i <= count / 2; i++) {
        if (result[i] != result[count - 1 - check]) {
            WRONG = 1;
            break;
        }
        check++;
    }
    if (WRONG == 0) {
        printf("%d ", jinbub);
        for (int i = count - 1; i >= end; i--) {
            printf("%c", result[i]);
        }
        printf("\n");
        return 1;
    }

    return 0;
}
int main() {
    scanf("%s", &user);
    int len = strlen(user);

    int answer_count = 0;

    int K = 0;

    for (int jinbub = 2; jinbub <= 10; jinbub++) {
        strcpy(user_copy, user);
        if (calculate(user_copy, jinbub, len)) {
            answer_count++;
        }
    }
    if (answer_count == 0) {
        printf("NIE");
    }
}