#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//����
//�ڿ��� N�� �־����� ��, N���� 1���� �� �ٿ� �ϳ��� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.
//
//�Է�
//ù° �ٿ� 100, 000���� �۰ų� ���� �ڿ��� N�� �־�����.
//
//���
//ù° �ٺ��� N��° �� ���� ���ʴ�� ����Ѵ�.

int main() {
	int user;
	scanf("%d", &user);

	for (int i = user; i >= 1; i--) {
		printf("%d\n", i);
	}

}