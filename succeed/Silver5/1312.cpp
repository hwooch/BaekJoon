#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//����
//������(����) A�� ����(�и�) B�� �ִ�.�� ���� �������� ��, �Ҽ��� �Ʒ� N��° �ڸ����� ���Ϸ��� �Ѵ�
// ���� ���, A = 3, B = 4, N = 1�̶��, A��B = 0.75 �̹Ƿ� ��� ���� 7�� �ȴ�.
//
//�Է�
//ù ��° �ٿ� A�� B(1 �� A, B �� 100, 000), N(1 �� N �� 1, 000, 000)�� ������ ���� �־�����.
//
//���
//A��B�� ���� ��, �Ҽ��� �Ʒ� N��° ���� ����Ѵ�.

int main() {
	int a;
	int b;
	int N;

	scanf("%d", &a);
	scanf("%d", &b);
	scanf("%d", &N);

	int answer;

	while (N--) {

		answer = (a * 10) / b;
		a = (a * 10) % b;

	}
	if (answer >= 10) { //ù��°�� ���� ���� ���ڸ��� �̻��϶�
		answer = answer % 10;
	}


	printf("%d", answer);
}