#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 1500 _ �ִ� ��

// ����
// �����̴� ���� S�� K�� �־����� ��, ���� S�� K���� ���� ������ ã������ �Ѵ�.
// ���� �������� ��� �� ���� ������ �ִ�� �Ϸ��� �Ѵ�.
// 
// ������ �ִ��� ���� ����Ѵ�.
// 
// ���� S = 10, K = 3�̸�, 3, 3, 4�� ���� 36���� �ִ��̴�.
// 
// �Է�
// ù° �ٿ� �� �� S�� K�� �־�����.K�� 20���� �۰ų� ����, S�� 100���� �۰ų� ������ K���� ũ�ų� ����.
// 
// ���
// ù° �ٿ� ������ ����Ѵ�.���� 9223372036854775807���� �۴�.

int main() {
	int N;
	int T;
	scanf("%d %d", &N, &T);

	long long int number[100] = { 0, };

	long long int sum = 1;

	for (int i = 0; i < T; i++) {
		number[i] = N / T;
	}

	int middle = N % T;

	for (int i = 0; i < middle; i++) {
		number[i]++;
		sum = sum * number[i];
	}

	for (int i = middle; i < T; i++) {
		sum = sum * number[i];
	}
	printf("%lld", sum);

}