#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// 1676 _ ���丮�� 0�� ����

// ����
// N!���� �ڿ������� ó�� 0�� �ƴ� ���ڰ� ���� ������ 0�� ������ ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
//
// �Է�
// ù° �ٿ� N�� �־�����. (0 �� N �� 500)
// 
// ���
// ù° �ٿ� ���� 0�� ������ ����Ѵ�.

int main() {
    int n;
    scanf("%d", &n); // N ���丮���� ���� N �Է�

    int result[5000] = { 0 };
    result[0] = 1; // 0! = 1
    int size = 1; // �ڸ������� ���� 1�ڸ�

    for (int i = 2; i <= n; i++) { // 1�̶�� for���� ���� �ʰ� �ٷ� �����
        int over = 0; // �ø���

        for (int j = 0; j < size; j++) {
            int product = result[j] * i + over; // ������� ����ִµ� ���� 24�� �Ǿ���
            result[j] = product % 10; // result[0]�� 4�� ����ְ�
            over = product / 10; // �ø��ڸ����� 2�� ����ִ´�.
        }

        while (over) { // �ø��ڸ����� �ִٸ�
            result[size] = over % 10;
            over = over / 10; // �ø��ڸ����� 3�ڸ���� �ѹ��� �ؾ��ϴϱ�
            size++; // �ڸ����� �ϳ� �ø���.
        }
    }

    int count = 0;
    for (int i = 0; i < size; i++) {
        if (result[i] == 0) { // 0�� ������ ���ٰ�
            count++;
        }
        else {
            printf("%d", count); // 0�� �ƴϸ� ���� ����ϰ� ���α׷� ����
            return 0;
        }
    }
}