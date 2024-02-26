#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

// 1152 _ 단어의 개수

// 문제
// 영어 대소문자와 공백으로 이루어진 문자열이 주어진다.
// 이 문자열에는 몇 개의 단어가 있을까 ? 이를 구하는 프로그램을 작성하시오.
// 단, 한 단어가 여러 번 등장하면 등장한 횟수만큼 모두 세어야 한다.
// 
// 입력
// 첫 줄에 영어 대소문자와 공백으로 이루어진 문자열이 주어진다.
// 이 문자열의 길이는 1, 000, 000을 넘지 않는다.
// 단어는 공백 한 개로 구분되며, 공백이 연속해서 나오는 경우는 없다.
// 또한 문자열은 공백으로 시작하거나 끝날 수 있다.
// 
// 출력
// 첫째 줄에 단어의 개수를 출력한다.

char adress[1000000];

int main() {
    int N;
    scanf("%[^\n]s", adress);

    int count = 1; // 마지막단어를 미리 포함

    int len = strlen(adress);

    if (('A' <= adress[0] && adress[0] <= 'Z') || ('a' <= adress[0] && adress[0] <= 'z')) { // 처음글자가 알파벳일때
        for (int i = 0; i < len; i++) {
            if (adress[i] == 32) { // 공백이 나올때마다 단어 개수 추가
                count++;
            }
        }
        if (adress[len - 1] == 32) { // 공백이 나올때마다 단어개수를 추가했으니 마지막이 공백이라면 단어 개수 - 1
            count--;
        }
    }
    else { // 처음글자가 스페이스바 일때
        for (int i = 1; i < len; i++) {
            if (adress[i] == 32) { // 공백이 나올때마다 단어 개수 추가
                count++;
            }
        }
        if (adress[len - 1] == 32) { // 공백이 나올때마다 단어개수를 추가했으니 마지막이 공백이라면 단어 개수 - 1
            count--;
        }
    }
    printf("%d", count);
}