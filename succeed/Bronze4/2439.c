#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//����
//ù° �ٿ��� �� 1��, ��° �ٿ��� �� 2��, N��° �ٿ��� �� N���� ��� ����
//
//������, �������� �������� ������ ��(���� ����)�� ����Ͻÿ�.
//
//�Է�
//ù° �ٿ� N(1 �� N �� 100)�� �־�����.
//
//���
//ù° �ٺ��� N��° �ٱ��� ���ʴ�� ���� ����Ѵ�.

int main() {
	int user;
	scanf("%d", &user);

	for (int i = 1; i <= user; i++) {
		for (int j = i; j < user; j++) {
			printf(" ");

		}
		for (int t = user - i; t < user; t++) {
			printf("*");
		}
		printf("\n");
	}

}