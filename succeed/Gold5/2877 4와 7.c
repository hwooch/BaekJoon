#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 2877 _ 4�� 7

// ����
// â���̴� 4�� 7�� �̷���� ���� �����Ѵ�.
// â���̰� �����ϴ� �� �߿� K��° ���� ���� ���� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.
// 
// �Է�
// ù° �ٿ� K(1 �� K �� 10^9)�� �־�����.
// 
// ���
// ù° �ٿ� â���̰� �����ϴ� ���� �� K��° ���� ���� ����Ѵ�.

int number[40] = { 0, };

int main() {
	int user;
	scanf("%d", &user);

	int count = 0;
	int two = 2;

	while ((user - two) > 0) {
		user = user - two;
		two = two * 2;
		count++;
	}
	user--;

	int check = 0;
	while (user > 1) {
		number[check] = user % 2;
		user = user / 2;
		check++;
	}
	number[check] = user;

	for (int i = count; i >= 0; i--) {
		if (number[i] == 0) {
			printf("4");
		}
		else {
			printf("7");
		}
	}
}