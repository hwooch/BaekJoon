#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <math.h>

// 1076 _ ����

// ����
// ���� ��ǰ���� ������ ����.������ �� 3���� �̿��ؼ� �� ������ �� ������ ��Ÿ����.
// ó�� �� 2���� ������ ���̰�, ������ ���� ���ؾ� �ϴ� ���̴�.
// ������ ���� ���� ǥ�� �̿��ؼ� ���Ѵ�.
// 
// ��	    ��	��
// black	0	1
// brown	1	10
// red	    2	100
// orange	3	1, 000
// yellow	4	10, 000
// green	5	100, 000
// blue	    6	1, 000, 000
// violet	7	10, 000, 000
// grey	    8	100, 000, 000
// white	9	1, 000, 000, 000
// ���� ���, ������ ���� yellow, violet, red���ٸ� ������ ���� 4, 700�� �ȴ�.
// 
// �Է�
// ù° �ٿ� ù ��° ��, ��° �ٿ� �� ��° ��, ��° �ٿ� �� ��° ���� �־�����.
// ���� ǥ�� �ִ� ���� �Է����� �־�����.
// 
// ���
// �Է����� �־��� ������ ���װ��� ����Ͽ� ù° �ٿ� ����Ѵ�.

int table1[10] = { 0,1,2,3,4,5,6,7,8,9 };
int table2[10] = { 1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000 };

int main() {
    char user[8];
    int N = 2;
    long long sum = 0;
    for (int i = 1; i >= 0; i--) {
        scanf("%s", user);

        if (strcmp(user, "black") == 0) {
            sum = sum + table1[0] * pow(10, i);
        }
        else if (strcmp(user, "brown") == 0) {
            sum = sum + table1[1] * pow(10, i);
        }
        else if (strcmp(user, "red") == 0) {
            sum = sum + table1[2] * pow(10, i);
        }
        else if (strcmp(user, "orange") == 0) {
            sum = sum + table1[3] * pow(10, i);
        }
        else if (strcmp(user, "yellow") == 0) {
            sum = sum + table1[4] * pow(10, i);
        }
        else if (strcmp(user, "green") == 0) {
            sum = sum + table1[5] * pow(10, i);
        }
        else if (strcmp(user, "blue") == 0) {
            sum = sum + table1[6] * pow(10, i);
        }
        else if (strcmp(user, "violet") == 0) {
            sum = sum + table1[7] * pow(10, i);
        }
        else if (strcmp(user, "grey") == 0) {
            sum = sum + table1[8] * pow(10, i);
        }
        else if (strcmp(user, "white") == 0) {
            sum = sum + table1[9] * pow(10, i);
        }
    }
    scanf("%s", user);
    if (strcmp(user, "black") == 0) {
        sum = sum * table2[0];
    }
    else if (strcmp(user, "brown") == 0) {
        sum = sum * table2[1];
    }
    else if (strcmp(user, "red") == 0) {
        sum = sum * table2[2];
    }
    else if (strcmp(user, "orange") == 0) {
        sum = sum * table2[3];
    }
    else if (strcmp(user, "yellow") == 0) {
        sum = sum * table2[4];
    }
    else if (strcmp(user, "green") == 0) {
        sum = sum * table2[5];
    }
    else if (strcmp(user, "blue") == 0) {
        sum = sum * table2[6];
    }
    else if (strcmp(user, "violet") == 0) {
        sum = sum * table2[7];
    }
    else if (strcmp(user, "grey") == 0) {
        sum = sum * table2[8];
    }
    else if (strcmp(user, "white") == 0) {
        sum = sum * table2[9];
    }
    printf("%lld", sum);
}