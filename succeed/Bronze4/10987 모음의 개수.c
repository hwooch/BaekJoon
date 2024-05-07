#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

// 10987 _ 모음의 개수

// 문제
// 알파벳 소문자로만 이루어진 단어가 주어진다.
// 이때, 모음(a, e, i, o, u)의 개수를 출력하는 프로그램을 작성하시오.
// 
// 입력
// 첫째 줄에 단어가 주어진다.
// 단어의 길이는 1보다 크거나 같고, 100보다 작거나 같으며, 알파벳 소문자로만 이루어져 있다.
// 
// 출력
// 첫째 줄에 모음의 개수를 출력한다.

int main() {
    char user[200];
    scanf("%s", user);

    int len = strlen(user);
    int count = 0;
    for (int i = 0; i < len; i++) {
        if (user[i] == 'a' || user[i] == 'e' || user[i] == 'i' || user[i] == 'o' || user[i] == 'u') {
            count++;
        }
    }
    printf("%d", count);
    return 0;
}