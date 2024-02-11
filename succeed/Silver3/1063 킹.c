#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 1063 _ 킹

// 문제
// 8 * 8크기의 체스판에 왕이 하나 있다. 킹의 현재 위치가 주어진다.
// 체스판에서 말의 위치는 다음과 같이 주어진다.
// 알파벳 하나와 숫자 하나로 이루어져 있는데, 알파벳은 열을 상징하고, 숫자는 행을 상징한다.
// 열은 가장 왼쪽 열이 A이고, 가장 오른쪽 열이 H까지 이고, 행은 가장 아래가 1이고 가장 위가 8이다.
// 예를 들어, 왼쪽 아래 코너는 A1이고, 그 오른쪽 칸은 B1이다.

// 킹은 다음과 같이 움직일 수 있다.

// R : 한 칸 오른쪽으로
// L : 한 칸 왼쪽으로
// B : 한 칸 아래로
// T : 한 칸 위로
// RT : 오른쪽 위 대각선으로
// LT : 왼쪽 위 대각선으로
// RB : 오른쪽 아래 대각선으로
// LB : 왼쪽 아래 대각선으로

// 체스판에는 돌이 하나 있는데, 돌과 같은 곳으로 이동할 때는, 돌을 킹이 움직인 방향과 같은 방향으로 한 칸 이동시킨다.
// 입력으로 킹이 어떻게 움직여야 하는지 주어진다.
// 입력으로 주어진 대로 움직여서 킹이나 돌이 체스판 밖으로 나갈 경우에는 그 이동은 건너 뛰고 다음 이동을 한다.
// 킹과 돌의 마지막 위치를 구하는 프로그램을 작성하시오.

// 입력
// 첫째 줄에 킹의 위치, 돌의 위치, 움직이는 횟수 N이 주어진다.
// 둘째 줄부터 N개의 줄에는 킹이 어떻게 움직여야 하는지 주어진다.
// N은 50보다 작거나 같은 자연수이고, 움직이는 정보는 위에 쓰여 있는 8가지 중 하나이다.

// 출력
// 첫째 줄에 킹의 마지막 위치, 둘째 줄에 돌의 마지막 위치를 출력한다.

int chess[8][8] = { 0, }; // 8*8의 체스판 생성

// 00  01  02  03  04  05  06  07
//(a8)(b8)(c8)(d8)(e8)(f8)(g8)(h8)
//
// 60  61  62  63  64  65  66  67
//(a2)(b2)(c2)(d2)(e2)(f2)(g2)(h2)
//
// 70  71  72  73  74  75  76  77
//(a1)(b1)(c1)(d1)(e1)(f1)(g1)(h1)

// 문제의 체스판을 표시한 것이다. f2는 문제의 좌표상 (6, 5)이다.
int main() {

    char king[3], stone[3];

    int T;

    scanf("%s", king);
    scanf("%s", stone);

    int number_king = 8 - (king[1] - 49) - 1; // x좌표는 입력의 뒤쪽인 숫자가 결정한다.
    int letter_king = king[0] - 65; // y좌표는 입력의 앞쪽인 알파벳이 결정한다.


    int number_stone = 8 - (stone[1] - 49) - 1;
    int letter_stone = stone[0] - 65;


    // chess[][]의 모든 범위는 0으로 되어있고 돌은 1로 킹은 2로 표시한다
    chess[number_stone][letter_stone] = 1;
    chess[number_king][letter_king] = 2;

    scanf("%d", &T);

    char move[3];

    while (T--) {
        scanf("%s", move);

        int dx = 0, dy = 0; // x와 y의 변화량

        if (strcmp(move, "R") == 0) { // 오른쪽으로 가는것이라면
            dy = 1; // 65인 f2에서 66인 g2로 가는것이기 때문에 y좌표 (5->6) 증가
        }
        else if (strcmp(move, "L") == 0) {
            dy = -1;
        }
        else if (strcmp(move, "B") == 0) {
            dx = 1;
        }
        else if (strcmp(move, "T") == 0) {
            dx = -1;
        }
        else if (strcmp(move, "RT") == 0) {
            dx = -1;
            dy = 1;
        }
        else if (strcmp(move, "LT") == 0) {
            dx = -1;
            dy = -1;
        }
        else if (strcmp(move, "RB") == 0) {
            dx = 1;
            dy = 1;
        }
        else if (strcmp(move, "LB") == 0) {
            dx = 1;
            dy = -1;
        }

        if (number_king + dx < 0 || number_king + dx > 7 || letter_king + dy < 0 || letter_king + dy > 7) {
            continue; // 킹이 체스판 범위를 벗어나는 경우 이동하지 않음
        }

        if (chess[number_king + dx][letter_king + dy] == 1) { // 킹이 움직일 위치에 돌이 있는 경우
            if (number_stone + dx < 0 || number_stone + dx > 7 || letter_stone + dy < 0 || letter_stone + dy > 7) {
                continue; // 돌이 이동할 위치가 체스판 범위를 벗어나는 경우 이동하지 않음
            }
            else {
                chess[number_stone + dx][letter_stone + dy] = 1; // 돌을 이동시킴
                chess[number_stone][letter_stone] = 0; // 돌이 있던 위치는 빈칸으로 만듬
                letter_stone += dy;
                number_stone += dx;
            }
        }

        // 킹 이동
        chess[number_king + dx][letter_king + dy] = 2; // 킹을 이동시킴
        chess[number_king][letter_king] = 0; // 킹이 있던 위치는 빈칸으로 만듬
        letter_king += dy;
        number_king += dx;
    }
    // 다시 정상적으로 출력
    printf("%c", letter_king + 'A');
    printf("%d\n", 8 - number_king);

    printf("%c", letter_stone + 'A');
    printf("%d\n", 8 - number_stone);
}