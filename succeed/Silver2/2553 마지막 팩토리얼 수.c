#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 2553 _ ������ ���丮�� ��

// ����
// N!�� ���� ����� �Ŀ�, 0�� �ƴ� ���� ���� �ڸ� ���� ���Ͻÿ�.
// 
// ���� ���, 4!= 24 �̱� ������, 0�� �ƴ� ���� ���� �ڸ� ���� 4�̴�.
// ��, 5!= 120�̱� ������, 0�� �ƴ� ���� ���� �ڸ� ���� 2 �̴�.
// 
// �Է�
// ù° �ٿ� N�� �־�����.
// N�� 20, 000���� �۰ų� ���� �ڿ��� �̴�.
// 
// ���
// ù° �ٿ� N!�� 0�� �ƴ� ������ �ڸ����� ����Ѵ�.

int main() {
	int N;
	scanf("%d", &N);

	long long int sum = 1;
	int temp;

	for (int i = 1; i <= N; i++) {
		temp = i;
		while (temp % 10 == 0) {
			temp = temp / 10;
		}

		sum = sum * temp;
		while (sum % 10 == 0) {
			sum = sum / 10;
		}
		sum = sum % 10000000;
	}
	sum = sum % 10;
	printf("%lld", sum);
}