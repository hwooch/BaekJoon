#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 4153 _ �����ﰢ��

// ����
// ���� ����Ʈ�ε��� �� ������ ���̰� 3, 4, 5�� �ﰢ���� ���� �ﰢ���ΰ��� �˾Ƴ´�.
// �־��� ������ ���̷� �ﰢ���� �������� �ƴ��� �����Ͻÿ�.
// 
// �Է�
// �Է��� �������� �׽�Ʈ���̽��� �־����� �������ٿ��� 0 0 0�� �Էµȴ�.
// �� �׽�Ʈ���̽��� ��� 30, 000���� ���� ���� ������ �־�����, �� �Է��� ���� ���̸� �ǹ��Ѵ�.
// 
// ���
// �� �Է¿� ���� ���� �ﰢ���� �´ٸ� "right", �ƴ϶�� "wrong"�� ����Ѵ�.


int main() {

    int len[3] = { 0, };
    while (1) {
        scanf("%d %d %d", &len[0], &len[1], &len[2]);

        if (len[0] == 0 || len[1] == 0 || len[2] == 0) {
            return 0;
        }

        int max = len[0];
        int top = 0;
        int min1 = 1;
        int min2 = 2;

        if (max < len[1]) {
            max = len[1];
            top = 1;
            min1 = 0;
            min2 = 2;
        }
        if (max < len[2]) {
            max = len[2];
            top = 2;
            min1 = 0;
            min2 = 1;
        }
        if (len[top] * len[top] == len[min1] * len[min1] + len[min2] * len[min2]) {
            printf("right\n");
        }
        else {
            printf("wrong\n");
        }

    }
    return 0;
}