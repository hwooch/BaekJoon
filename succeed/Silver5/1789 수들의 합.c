#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <limits.h>

// 1789 _ ������ ��

// ����
// ���� �ٸ� N���� �ڿ����� ���� S��� �Ѵ�.
// S�� �� ��, �ڿ��� N�� �ִ��� ���ϱ� ?
//
// �Է�
// ù° �ٿ� �ڿ��� S(1 �� S �� 4, 294, 967, 295)�� �־�����.
//
// ���
// ù° �ٿ� �ڿ��� N�� �ִ��� ����Ѵ�.

int main() {
    unsigned long long user;
    scanf("%llu", &user);

    int count = 0;
    unsigned long long sum = 0;

    while (sum <= user) { // �ڿ������� ���� ���� ���̶��
        sum = sum + count;
        count++;
    }
    printf("%d", count - 2);
}