#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 2440 _ �� ���-3

// ����
// ù° �ٿ��� �� N��, ��° �ٿ��� �� N - 1��, ..., N��° �ٿ��� �� 1���� ��� ����
// 
// �Է�
// ù° �ٿ� N(1 �� N �� 100)�� �־�����.
// 
// ���
// ù° �ٺ��� N��° �ٱ��� ���ʴ�� ���� ����Ѵ�.

int main() {
	int user;
	scanf("%d", &user);

	for (int i = 1; i <= user; i++) {
		for (int j = i; j <= user; j++) {
			printf("*");

		}
		printf("\n");
	}

}