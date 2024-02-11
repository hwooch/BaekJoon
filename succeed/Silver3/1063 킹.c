#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 1063 _ ŷ

// ����
// 8 * 8ũ���� ü���ǿ� ���� �ϳ� �ִ�. ŷ�� ���� ��ġ�� �־�����.
// ü���ǿ��� ���� ��ġ�� ������ ���� �־�����.
// ���ĺ� �ϳ��� ���� �ϳ��� �̷���� �ִµ�, ���ĺ��� ���� ��¡�ϰ�, ���ڴ� ���� ��¡�Ѵ�.
// ���� ���� ���� ���� A�̰�, ���� ������ ���� H���� �̰�, ���� ���� �Ʒ��� 1�̰� ���� ���� 8�̴�.
// ���� ���, ���� �Ʒ� �ڳʴ� A1�̰�, �� ������ ĭ�� B1�̴�.

// ŷ�� ������ ���� ������ �� �ִ�.

// R : �� ĭ ����������
// L : �� ĭ ��������
// B : �� ĭ �Ʒ���
// T : �� ĭ ����
// RT : ������ �� �밢������
// LT : ���� �� �밢������
// RB : ������ �Ʒ� �밢������
// LB : ���� �Ʒ� �밢������

// ü���ǿ��� ���� �ϳ� �ִµ�, ���� ���� ������ �̵��� ����, ���� ŷ�� ������ ����� ���� �������� �� ĭ �̵���Ų��.
// �Է����� ŷ�� ��� �������� �ϴ��� �־�����.
// �Է����� �־��� ��� �������� ŷ�̳� ���� ü���� ������ ���� ��쿡�� �� �̵��� �ǳ� �ٰ� ���� �̵��� �Ѵ�.
// ŷ�� ���� ������ ��ġ�� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

// �Է�
// ù° �ٿ� ŷ�� ��ġ, ���� ��ġ, �����̴� Ƚ�� N�� �־�����.
// ��° �ٺ��� N���� �ٿ��� ŷ�� ��� �������� �ϴ��� �־�����.
// N�� 50���� �۰ų� ���� �ڿ����̰�, �����̴� ������ ���� ���� �ִ� 8���� �� �ϳ��̴�.

// ���
// ù° �ٿ� ŷ�� ������ ��ġ, ��° �ٿ� ���� ������ ��ġ�� ����Ѵ�.

int chess[8][8] = { 0, }; // 8*8�� ü���� ����

// 00  01  02  03  04  05  06  07
//(a8)(b8)(c8)(d8)(e8)(f8)(g8)(h8)
//
// 60  61  62  63  64  65  66  67
//(a2)(b2)(c2)(d2)(e2)(f2)(g2)(h2)
//
// 70  71  72  73  74  75  76  77
//(a1)(b1)(c1)(d1)(e1)(f1)(g1)(h1)

// ������ ü������ ǥ���� ���̴�. f2�� ������ ��ǥ�� (6, 5)�̴�.
int main() {

    char king[3], stone[3];

    int T;

    scanf("%s", king);
    scanf("%s", stone);

    int number_king = 8 - (king[1] - 49) - 1; // x��ǥ�� �Է��� ������ ���ڰ� �����Ѵ�.
    int letter_king = king[0] - 65; // y��ǥ�� �Է��� ������ ���ĺ��� �����Ѵ�.


    int number_stone = 8 - (stone[1] - 49) - 1;
    int letter_stone = stone[0] - 65;


    // chess[][]�� ��� ������ 0���� �Ǿ��ְ� ���� 1�� ŷ�� 2�� ǥ���Ѵ�
    chess[number_stone][letter_stone] = 1;
    chess[number_king][letter_king] = 2;

    scanf("%d", &T);

    char move[3];

    while (T--) {
        scanf("%s", move);

        int dx = 0, dy = 0; // x�� y�� ��ȭ��

        if (strcmp(move, "R") == 0) { // ���������� ���°��̶��
            dy = 1; // 65�� f2���� 66�� g2�� ���°��̱� ������ y��ǥ (5->6) ����
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
            continue; // ŷ�� ü���� ������ ����� ��� �̵����� ����
        }

        if (chess[number_king + dx][letter_king + dy] == 1) { // ŷ�� ������ ��ġ�� ���� �ִ� ���
            if (number_stone + dx < 0 || number_stone + dx > 7 || letter_stone + dy < 0 || letter_stone + dy > 7) {
                continue; // ���� �̵��� ��ġ�� ü���� ������ ����� ��� �̵����� ����
            }
            else {
                chess[number_stone + dx][letter_stone + dy] = 1; // ���� �̵���Ŵ
                chess[number_stone][letter_stone] = 0; // ���� �ִ� ��ġ�� ��ĭ���� ����
                letter_stone += dy;
                number_stone += dx;
            }
        }

        // ŷ �̵�
        chess[number_king + dx][letter_king + dy] = 2; // ŷ�� �̵���Ŵ
        chess[number_king][letter_king] = 0; // ŷ�� �ִ� ��ġ�� ��ĭ���� ����
        letter_king += dy;
        number_king += dx;
    }
    // �ٽ� ���������� ���
    printf("%c", letter_king + 'A');
    printf("%d\n", 8 - number_king);

    printf("%c", letter_stone + 'A');
    printf("%d\n", 8 - number_stone);
}