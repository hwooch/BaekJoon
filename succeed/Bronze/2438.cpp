#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//����
//ù° �ٿ��� �� 1��, ��° �ٿ��� �� 2��, N��° �ٿ��� �� N���� ��� ����
//
//�Է�
//ù° �ٿ� N(1 �� N �� 100)�� �־�����.
//
//���
//ù° �ٺ��� N��° �ٱ��� ���ʴ�� ���� ����Ѵ�.

int main() {
    int a;
    scanf("%d", &a); // �� ��

    for (int i = 0; i < a; i++) {
        for (int j = 0; j <= i; j++) {
            printf("*");
        }
        printf("\n");
    }

}