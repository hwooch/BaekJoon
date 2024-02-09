#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// 11005 _ ���� ��ȯ 2

// ����
// 10���� �� N�� �־�����.�� ���� B�������� �ٲ� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.
// 
// 10������ �Ѿ�� ������ ���ڷ� ǥ���� �� ���� �ڸ��� �ִ�. �̷� ��쿡�� ������ ���� ���ĺ� �빮�ڸ� ����Ѵ�.
// 
// A: 10, B : 11, ..., F : 15, ..., Y : 34, Z : 35
// 
// �Է�
// ù° �ٿ� N�� B�� �־�����. (2 �� B �� 36) N�� 10�ﺸ�� �۰ų� ���� �ڿ����̴�.
// 
// ���
// ù° �ٿ� 10���� �� N�� B�������� ����Ѵ�.

int number[31];

int main() {
	int N;
	scanf("%d", &N);

	int B;
	scanf("%d", &B);

	int count = 0;
	while (B <= N) {
		number[count] = N % B;
		N = N / B;
		count++;
	}
	number[count] = N;
	for (int i = count; i >= 0; i--) {
		if (number[i] >= 10) {
			printf("%c", number[i] + 55);
		}
		else {
			printf("%d", number[i]);
		}
	}
}