#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 11441 _ �� ���ϱ�

// ����
// N���� �� A1, A2, ..., AN�� �Է����� �־�����.
// �� M���� ���� i, j�� �־����� ��, i��° ������ j��° ������ ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
// 
// �Է�
// ù° �ٿ� ���� ���� N�� �־�����. (1 �� N �� 100, 000) 
// ��° �ٿ��� A1, A2, ..., AN�� �־�����. (-1, 000 �� Ai �� 1, 000) 
// ��° �ٿ��� ������ ���� M�� �־�����. (1 �� M �� 100, 000)
// ��° �ٺ��� M���� �ٿ��� �� ������ ��Ÿ���� i�� j�� �־�����. (1 �� i �� j �� N)
// 
// ���
// �� M���� �ٿ� ���� �Է����� �־��� ������ ���� ����Ѵ�.

int number[100000] = { 0, };
int sum[100000] = { 0, };

int main() {

	int N;
	scanf("%d", &N);
	scanf("%d", &number[0]);
	sum[0] = number[0];

	for (int i = 1; i < N; i++) {
		scanf("%d", &number[i]);
		sum[i] = sum[i - 1] + number[i];
	}
	int M;
	scanf("%d", &M);
	int left, right;


	for (int i = 0; i < M; i++) {
		scanf("%d %d", &left, &right);
		if (left == right) {
			printf("%d\n", sum[right - 1] - sum[left - 2]);
		}
		else if (left == 1) {
			printf("%d\n", sum[right - 1]);
		}
		else {
			printf("%d\n", sum[right - 1] - sum[left - 2]);
		}
	}
}