#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 2083 _ 럭비 클럽

// 문제
// 올 골드 럭비 클럽의 회원들은 성인부 또는 청소년부로 분류된다.
// 
// 나이가 17세보다 많거나, 몸무게가 80kg 이상이면 성인부이다.
// 그 밖에는 모두 청소년부이다.클럽 회원들을 올바르게 분류하라.
// 
// 입력
// 각 줄은 이름과 두 자연수로 이루어진다.두 자연수는 순서대로 나이와 몸무게를 나타낸다.
// 입력의 마지막 줄은 # 0 0 이다.이 입력은 처리하지 않는다.
// 
// 이름은 알파벳 대 / 소문자로만 이루어져 있고, 길이는 10을 넘지 않는다.
// 
// 출력
// 입력 받은 각 회원에 대해 이름과 분류를 출력한다.
// 성인부 회원이면 'Senior', 청소년부 회원이면 'Junior'를 출력한다.

int main() {
    char name[11] = { 'a' };
    int age = 1; //  숫자 입력변수
    int height = 1; //  숫자 입력변수
    while (age != 0 && height != 0 && name[0] != '#') {

        scanf("%s", name);
        scanf("%d", &age);
        scanf("%d", &height);

        if (age == 0 && height == 0 && name[0] == '#') {
            break;
        }
        else if (age > 17 || height >= 80) {
            printf("%s ", name);
            printf("Senior\n");
        }
        else {
            printf("%s ", name);
            printf("Junior\n");
        }
    }
}